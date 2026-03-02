.intel_syntax noprefix
.global _start

.section .text

_start:
    mov rdi, [rsp+16]
    movzx rdi, BYTE PTR [rdi]
    sub rdi, '0'
    cmp rdi, 2
    ja default_case

    ; load jump table base
    lea rbx, [rip + jump_table]

    ; load address from table
    mov rax, [rbx + rdi*8]

    ; jump to it
    jmp rax

case0:
    mov rax, 60
    mov rdi, 10
    syscall

case1:
    mov rax, 60
    mov rdi, 20
    syscall

case2:
    mov rax, 60
    mov rdi, 30
    syscall

default_case:
    mov rax, 60
    mov rdi, 99
    syscall

.section .rodata

jump_table:
    .quad case0
    .quad case1
    .quad case2
