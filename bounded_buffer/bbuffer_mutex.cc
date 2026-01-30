#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<thread>
#include<atomic>
#include<cassert>
#include<mutex>

struct bbuffer {
  static constexpr size_t bcapacity = 128;
  char bbuff[bcapacity];
  size_t bpos = 0;
  size_t blen = 0;
  bool write_closed = false;
  std::mutex m;


  ssize_t read(char *buff, size_t sz);
  ssize_t write(const char *buff, size_t sz);
  void shutdown_write();
};

ssize_t bbuffer::write(const char *buff, size_t sz)
{
  this->m.lock();
  assert(!this->write_closed);
  size_t pos = 0;
  // This while loop is important because this is circular bounded buffer
  while(pos < sz && this->blen < this->bcapacity)
  {
    size_t bindex = (this->bpos + this->blen) % this->bcapacity;
    size_t bspace = std::min(this->bcapacity - this->blen, this->bcapacity - bindex);
    size_t n = std::min(sz - pos, bspace);
    memcpy(&this->bbuff[bindex], &buff[pos], n);
    this->blen += n;
    pos += n;
  }
  this->m.unlock();

  if (pos == 0 && sz > 0)
  {
    return -1;
  }
  return pos;

}

ssize_t bbuffer::read(char *buff, size_t sz)
{
  this->m.lock();
  size_t pos = 0;
  while(pos < sz && this->blen > 0)
  {
    size_t bspace = std::min(this->bcapacity - this->bpos, this->blen);
    size_t n = std::min(bspace, sz-pos);
    memcpy(&buff[pos], &this->bbuff[this->bpos], n);
    pos += n;
    this->bpos = (this->bpos + n) % this->bcapacity;
    this->blen -= n;
  }
  this->m.unlock();

  if (pos == 0 && sz > 0 && !this->write_closed)
  {
    return -1;
  }
  return pos;
}

void bbuffer::shutdown_write()
{
  this->m.lock();
  this->write_closed = true;
  this->m.unlock();
}

std::atomic<size_t> nwrites;
std::atomic<size_t> nreads;


void writer_threadfunc(bbuffer& bb) {
    // Write `Hello world!\n` to the buffer a million times.
    // Result should have 13000000 characters.
    const char msg[] = "Hello world!\n";
    const size_t msg_len = strlen(msg);
    for (int i = 0; i != 1000000; ++i) {
        size_t pos = 0;
        while (pos < msg_len) {
            ssize_t nw = bb.write(&msg[pos], msg_len - pos);
            ++nwrites;
            if (nw > -1) {
                pos += nw;
            }
        }
    }
    bb.shutdown_write();
}

void reader_threadfunc(bbuffer& bb) {
    // Read from the buffer until closed and write to stdout.
    char buf[BUFSIZ];
    ssize_t nr;
    while ((nr = bb.read(buf, sizeof(buf))) != 0) {
        ++nreads;
        if (nr > -1) {
            fwrite(buf, 1, nr, stdout);
        }
    }
}


int main() {
    bbuffer bb;
    std::thread reader(reader_threadfunc, std::ref(bb));
    std::thread writer(writer_threadfunc, std::ref(bb));
    reader.join();
    writer.join();
    fprintf(stderr, "%zu reads, %zu writes\n", nreads.load(), nwrites.load());
}


