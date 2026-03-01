.intel_syntax noprefix
.global _start

.section .text

_start:

# open the file
  mov rdi, [rsp+16]
  mov rsi, 0
  mov rax, 2
  syscall

# reserve 64 bytes
  sub rsp, 64

# read the file
  mov rdi, rax
  mov rax, 0
# mov rsi, offset buffer
  mov rsi, rsp
  mov rdx, 64
  syscall

# close the file
  mov rax, 3
  syscall

# write to stdout
  mov rax, 1
  mov rdi, 1
  syscall

# restore stack
  add rsp, 64

# exiting with code 42
  mov rax, 60
  mov rdi, 42
  syscall

; .section .bss
; buffer: 
;     .skip 64



# When the kernel starts your program, it sets up the stack like this:
# Suppose you run: ./fileops /flag
# argc = 2
# argv[0] = "./fileops"
# argv[1] = "/flag"

# HIGH MEMORY ADDRESSES
# ────────────────────────────
# 0x7fffffffe020   "/flag\0"
# 0x7fffffffe018   "./fileops\0"

# 0x7fffffffe010   NULL              ← argv[2]
# 0x7fffffffe008   0x7fffffffe020    ← argv[1]
# 0x7fffffffe000   0x7fffffffe018    ← argv[0]
# 0x7fffffffdff8   2                 ← argc
# ────────────────────────────
# LOW MEMORY ADDRESSES

# rsp = 0x7fffffffdff8
# [rsp]        = argc
# [rsp+8]      = argv[0]
# [rsp+16]     = argv[1]

# sub rsp, 64
# rsp = rsp - 64      Which moves rsp to a lower address.


# HIGH MEMORY ADDRESSES
# ────────────────────────────
# 0x7fffffffe020   "/flag\0"
# 0x7fffffffe018   "./fileops\0"

# 0x7fffffffe010   NULL              ← argv[2]
# 0x7fffffffe008   0x7fffffffe020    ← argv[1]
# 0x7fffffffe000   0x7fffffffe018    ← argv[0]
# 0x7fffffffdff8   2                 ← argc
# ────────────────────────────
# [ 64 bytes free space ]     ← rsp NOW POINTS HERE
# ────────────────────────────
# LOW MEMORY ADDRESSES

# .bss is predictable memory
  # Exists before execution
  # Allocated by loader
  # Static lifetime
  # Fixed in memory layout

# Stack is controllable memory
# Heap is dynamic memory
