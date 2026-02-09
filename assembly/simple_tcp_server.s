.intel_syntax noprefix
.globl _start

.section .text

_start:
        # open the socket 
        mov rdi, 2
        mov rsi, 1
        mov rdx, 0 
        mov rax, 41
        syscall

        mov r12, rax

        # bind
        mov rax, 49
        mov rdi, r12
        mov rsi, offset sockaddr_in
        mov rdx, 16
        syscall

        # listen 
        mov rax, 50
        mov rdi, r12
        mov rsi, 0
        syscall 

        mov r13, r12

        jmp iterative_server


iterative_server:

        # accept 
        mov rax, 43
        mov rdi, r12
        mov rsi, 0
        mov rdx, 0
        syscall

        mov r12, rax

        # forking
        mov rax, 57
        syscall

        cmp rax, 0
        je child_process
        jmp parent_process

child_process:

        # close the listening socket connection
        mov rdi, r13
        mov rax, 3
        syscall

        # read request 
        mov rax, 0
        mov rdi, r12
        mov rsi, offset buffer
        mov rdx, 1024
        syscall
        mov r10, rax

        cmp byte ptr [rsi+0], 'G'
        je process_get_request


process_get_request:

        # write static response
        mov rdi, r12
        mov rsi, offset static_response
        mov rdx, 34
        mov rax, 1
        syscall 

        # close the fd 
        mov rdi, r12
        mov rax, 3
        syscall

        jmp exit


parent_process:

        # close the request processing fd 
        mov rdi, r12
        mov rax, 3
        syscall

        mov r12, r13
        jmp iterative_server

exit:
        mov rdi, 0
        mov rax, 60
        syscall

.section .data
sockaddr_in:
    .2byte 2
    .2byte 0x901F
    .4byte 0x00000000
    .8byte 0x0

static_response:
    .string "HTTP/1.0 200 OK FROM TCP SERVER\r\n\r\n"


.section .bss
buffer: 
    .skip 1024

request_method:
    .skip 5
