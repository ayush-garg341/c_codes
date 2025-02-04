#ifndef HEXDUMP_H
#define HEXDUMP_H

#include<stdio.h>

// hexdump(ptr, size)
//    Print a hexdump of the `size` bytes of data starting at `ptr`
//    to the standard output. The hexdump format is:
//    0xXXXXXXXX  BB BB BB BB BB BB BB BB  BB BB BB BB BB BB BB BB  |CCCCCCCCCCCCCCCC|
//    where 0xXXXXXXXX is the address of the first byte in the line,
//    the BBs are hexadecimal values of those bytes, and the Cs show
//    the printable ASCII characters corresponding to those bytes


void hexdump(const void *ptr, size_t size);

// hexdump_object(object)
//    Like hexdump(&object, sizeof(object)).
#define hexdump_object(object) hexdump(&(object), sizeof((object)))


// fhexdump(f, ptr, size)
//    Like `hexdump(ptr, size)`, but print to file `f` rather than standard
//    output.
void fhexdump(FILE *f, const void *ptr, size_t size);

#define fhexdump_object(f, object) fhexdump((f), &(object), sizeof((object)));


// fhexdump_at(f, first_offset, ptr, size)
//    Like fhexdump, but start with offset `first_offset` instead of the
//    address of `ptr`.
void fhexdump_at(FILE* f, size_t first_offset, const void* ptr, size_t size);


#endif
