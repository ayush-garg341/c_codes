.intel_syntax noprefix

.global _start

.section .text

_start:
  mov rdi, [rsp+16]
  cmp BYTE PTR [rdi], 'p'
  setz dil
  mov rax, 60
  syscall
