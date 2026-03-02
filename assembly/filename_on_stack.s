.intel_syntax noprefix
.global _start

.section .text

_start:
  mov BYTE PTR [rsp], '/'
  mov BYTE PTR [rsp+1], 'f'
  mov BYTE PTR [rsp+2], 'l'
  mov BYTE PTR [rsp+3], 'a'
  mov BYTE PTR [rsp+4], 'g'
  mov BYTE PTR [rsp+4], 0

# open the file
  mov rdi, rsp
  mov rsi, 0
  mov rax, 2
  syscall

# reserve 64 bytes
  sub rsp, 70

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
  add rsp, 70

# exiting with code 42
  mov rax, 60
  mov rdi, 42
  syscall

# mov BYTE PTR [rsp+1], 'A' -> does not change the rsp pointer and it just do calculation of memory address on stack. Does not change the rsp pointer.

# mov BYTE PTR [rsp], '/'
# mov BYTE PTR [rsp+1], 'f'
# mov BYTE PTR [rsp+2], 'l'
# mov BYTE PTR [rsp+3], 'a'
# mov BYTE PTR [rsp+4], 'g'
# mov BYTE PTR [rsp+5], 0

# BYTE PTR: When you write to a memory address like [rsp] using an immediate value (a number or character), the CPU doesn't know how many bytes you intend to write --- one? two? eight? BYTE PTR is a size directive that tells the assembler "I mean exactly one byte." Without it, the assembler won't know what you want and will refuse to assemble the instruction.

# Single quotes: In assembly, a single-quoted character like 'f' represents that character's one-byte ASCII value. So 'f' is just a convenient way of writing 0x66, and '/' is 0x2f.

# The null byte: The last byte we write is 0 --- a special null byte. This is how Linux knows where a string ends: it reads bytes starting from the pointer you give it and stops when it hits a 0 byte. Without it, open would keep reading past "flag" into whatever else is on the stack, and you'd be trying to open a file with a nonsense name!

# After writing these bytes, rsp points to the null-terminated string "/flag", ready to pass to open.
