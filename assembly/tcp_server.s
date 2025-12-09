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
        jmp process_post_request


process_get_request:

        # get file path 
        mov rdi, offset buffer
        mov rsi, 0
        call get_file_name

        # opening the file
        mov rdi, rax
        mov rsi, 0
        mov rax, 2
        syscall 

        # read the content
        mov r10, rax
        mov rdi, r10 
        mov rsi, offset file_content
        mov rdx, 1024
        mov rax, 0
        syscall 

        mov r15, rax

        # close the file
        mov rdi, r10
        mov rax, 3
        syscall 

        # write static response
        mov rdi, r12
        mov rsi, offset static_response
        mov rdx, 19
        mov rax, 1
        syscall 

        # write dynamic response 
        mov rax, 1
        mov rdi, r12
        mov rsi, offset file_content
        mov rdx, r15
        syscall

        # close the fd 
        mov rdi, r12
        mov rax, 3
        syscall

        jmp exit


process_post_request:

        # get the post request body 
        mov rdi, offset buffer
        mov rsi, r10
        call get_request_body
        mov r11, rax
        push r11
        mov rbx, rdx

        # get file path 
        mov rdi, offset buffer
        mov rsi, 0
        call get_file_name

        # opening the file
        mov rdi, rax
        mov rsi, 65
        mov rdx, 0777
        mov rax, 2
        syscall 

        # write the post content into the file 
        mov r10, rax
        mov rdi, r10 
        pop r11
        mov rsi, r11
        mov rdx, rbx
        mov rax, 1
        syscall 

        # close the file
        mov rdi, r10
        mov rax, 3
        syscall 

        # write static response
        mov rdi, r12
        mov rsi, offset static_response
        mov rdx, 19
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


get_request_body:
        mov rcx, 0
        mov r8, offset request_body
        mov r9, rsi
        dec rsi
        call get_req_body_len
        mov rcx, 0
        mov rdx, rax
        mov rsi, r9
        sub rsi, rdx
        jmp find_first_newline_backward

get_req_body_len:
        cmp byte ptr [rdi+rsi], '\n'
        je end_body_len
        dec rsi
        inc rcx
        jmp get_req_body_len

end_body_len:
        mov rax, rcx
        ret

find_first_newline_backward:
        cmp rsi, r9
        je end_body
        mov al, byte ptr [rdi+rsi]
        mov byte ptr [r8+rcx], al
        inc rsi
        inc rcx
        jmp find_first_newline_backward

end_body:
        mov byte ptr [r8 + rcx], 0
        mov rax, r8
        ret

get_file_name: 
        mov rcx, 0
        mov r14, offset file_path
        jmp find_first_space
      
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
        mov byte ptr [r14 + rcx], al
        inc rcx
        inc rsi
        jmp copy_path
      
end_path:
        mov byte ptr [r14 + rcx], 0
        mov rax, r14
        ret

.section .data
sockaddr_in:
    .2byte 2
    .2byte 0x5000
    .4byte 0x00000000
    .8byte 0x0

static_response:
    .string "HTTP/1.0 200 OK\r\n\r\n"


.section .bss
buffer: 
    .skip 1024

file_path:
    .skip 256

file_content:
    .skip 1024

request_method:
    .skip 5

request_body:
  .skip 1024
