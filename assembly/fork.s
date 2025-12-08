.intel_syntax noprefix
.global _start

.section .text

_start:
  mov rax, 57
  syscall

  cmp rax, 0
  je child_process 
  jmp parent_process

child_process:
  mov rdi, 1
  mov rsi, offset static_request
  mov rdx, 161
  mov rax, 1
  syscall

  jmp exit


parent_process:
  mov rdi, 1
  mov rsi, offset accept
  mov rdx, 33
  mov rax, 1
  syscall

  jmp exit

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  
.section .data
static_request:
  .string "GET /tmp/tmpzm6bw_1z HTTP/1.1\r\nHost: localhost\r\nUser-Agent: python-requests/2.32.4\r\nAccept-Encoding: gzip, deflate, zstd\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n"

accept:
  .string "Accepting connections in parent\n\n"
