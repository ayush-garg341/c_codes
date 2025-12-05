.intel_syntax noprefix
.global _start

.section .text

_start:
  mov rdi, offset static_request
  mov rsi, 0
  call get_file_name

  mov r12, rax
  mov rax, 1
  mov rdi, 1
  mov rsi, r12
  mov rdx, 256
  syscall

  mov rax, 60
  mov rdi, 0
  syscall

get_file_name: 
  mov rcx, 0
  mov r12, offset file_path
  jmp find_first_space
  jmp copy_path

find_first_space:
  cmp byte ptr [rdi+rsi], ' '
  je start_path
  inc rsi
  jmp find_first_space
  
start_path:
  inc rsi

copy_path:
  mov al, [rdi+rsi]
  cmp al, ' '
  je end_path
  mov byte ptr [r12 + rcx], al
  inc rcx
  inc rsi
  jmp copy_path

end_path:
  mov byte ptr [r12 + rcx], 0
  mov rax, r12
  ret

.section .bss
file_path:
  .skip 256


.section .data
static_request:
  .string "GET /tmp/tmpzm6bw_1z HTTP/1.1\r\nHost: localhost\r\nUser-Agent: python-requests/2.32.4\r\nAccept-Encoding: gzip, deflate, zstd\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n"

