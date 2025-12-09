.intel_syntax noprefix
.global _start

.section .text

_start:
  mov rdi, offset static_request
  mov rsi, 0
  # get request method
  call get_request_method
  mov r15, rax

# write into stdout
  mov rax, 1
  mov rdi, 1
  mov rsi, r15
  mov rdx, 256
  syscall

  # get file path
  mov rdi, offset static_request
  mov rsi, 0
  call get_file_name
  mov r12, rax

# write into stdout
  mov rax, 1
  mov rdi, 1
  mov rsi, r12
  mov rdx, 256
  syscall

  # check if it's get
  mov rdi, r15
  call check_if_get

  # if it's post, read the body, save into a file and return
  # get the request body
  mov rdi, offset static_request
  mov rsi, 422
  call get_request_body
  mov r12, rax

  # write the body
  mov rax, 1
  mov rdi, 1
  mov rsi, r12
  syscall

  mov rax, 60
  mov rdi, 0
  syscall

check_if_get:
  cmp byte ptr[rdi+0], 'G'  
  je is_get
  cmp byte ptr[rdi+0], 'P'
  je is_post

is_get:
  mov rax, 1
  ret

is_post:
  mov rax, 0
  ret

get_request_method:
  mov rcx, 0
  mov r12, offset request_method
  jmp upto_first_space

upto_first_space:
  cmp byte ptr [rdi+rsi], ' '
  jne copy_char
  jmp end_path

copy_char:
  mov al, [rdi+rsi]
  mov byte ptr [r12+rcx], al
  inc rcx
  inc rsi
  jmp upto_first_space

get_request_body:
  mov rcx, 0
  mov r12, offset request_body
  mov r13, rsi
  dec rsi
  call get_req_body_len
  mov rcx, 0
  mov rdx, rax
  mov rsi, r13
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
  cmp rsi, r13
  je end_body
  mov al, byte ptr [rdi+rsi]
  mov byte ptr [r12+rcx], al
  inc rsi
  inc rcx
  jmp find_first_newline_backward

end_body:
  mov byte ptr [r12 + rcx], 0
  mov rax, r12
  ret

get_file_name: 
  mov rcx, 0
  mov r12, offset file_path
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

request_method:
  .skip 7

request_body:
  .skip 1024

.section .data
static_request:
  .string "POST /tmp/tmpty34stf0 HTTP/1.1\r\nHost: localhost\r\nUser-Agent: python-requests/2.32.4\r\nAccept-Encoding: gzip, deflate, zstd\r\nAccept: */*\r\nConnection: keep-alive\r\nContent-Length: 239\r\n\r\nT5iM0cpLMdAMdQuOH9ix3PrjdGj4CKcgnLyrxxMDrI6NuXzYmIBwTVw4koRFriRI98N61gv5GWgern9aKkJOZA5Ssy3WSzc62T5qxxFLiR4yxtDWAZaQ8cxboYXX4AbAlmqd5SXiomNODSiqtMciHOehy89HJn7TOK5JFjgPorzX7OnA1Dlkc1lIHCASPwyMVHp5fMFlEtvBxvXovUW3RzdJccFZ8oxRu8SIkA39HKo5zxs"

