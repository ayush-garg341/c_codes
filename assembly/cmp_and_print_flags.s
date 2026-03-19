.intel_syntax noprefix

; db is define byte

section .data
	hello:   db  "Hello", 0
	yellow:  db  "Hell", 0 

    msg_cf: db "Carry flag set", 0
    len_cf: equ $ - msg_cf

    msg_zf: db "zero flag set", 10
    len_zf: equ $ - msg_zf

    msg_none:  db "no flag set", 10
    len_none:  equ $ - msg_none

section .text
	global _start

_start:
	mov rdi, hello
    mov rsi, yellow
  
str_cmp:
.loop:
    mov     al, [rdi]        ; load src char
    mov     bl, [rsi]        ; load dst char

    cmp     al, bl
    jne     .diff            ; if different, decide

    test    al, al
    je      .equal           ; both '\0', equal

    inc     rdi
    inc     rsi
    jmp     .loop

.diff:
    ; flags already set by cmp:
    ; CF=1 if src < dst
    ; ZF=0 here
    jmp .check_flags

.equal:
    xor     eax, eax
    cmp     eax, eax

.check_flags:
    jc .carry
    jz .zero

    ; neither CF nor ZF
    mov rsi, msg_none
    mov rdx, len_none
    jmp .print

.carry:
    mov rsi, msg_cf
    mov rdx, len_cf
    jmp .print

.zero:
    mov rsi, msg_zf
    mov rdx, len_zf

.print:
    mov rax, 1     ; syscall: write
    mov rdi, 1
    syscall

    jmp .exit

.exit:
    mov rax, 60     ; syscall: exit
    xor rdi, rdi
    syscall