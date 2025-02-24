### Compilation steps

- **Preprocessor**
   - The input file for this stage is *.c file.
   - It performs the following tasks:
        - Removing comments
        - Line Splicing (\): The backslash \ is used for line splicing, allowing you to break long lines of code into multiple lines for readability, are concatenated to form a single line.
        - Header files inclusion: For example, if the directive #include <stdio.h> is available in the program, then the preprocessor interprets the directive and replaces this directive with the content of the /usr/include/stdio.h file.
        - Macro expansion: A macro is a preprocessor directive that allows you to define a symbolic name or identifier for a sequence of code.
            - They can be constant macros, e.g., 
            ```c
            #define BUFFER_SIZE 1024
            ```
            - or function-like macros, e.g., 
            ```c
            #define MAX(a, b) ((a) > (b) ? (a) : (b))
            ```
        - Resolve the conditional compilation directives: Using special preprocessing directives, you can include or exclude parts of the program according to various conditions. For example:
        ```c
        #ifdef DEBUG 
        printf("Debugging is enabled.\n"); 
        #endif
        ```
        - Other conditional compilations are #ifndef, #if, #elif, #else. The preprocessor evaluates these conditions and determines whether the enclosed code should be included in the preprocessed output file.
        - Line Control: The C preprocessor informs the C compiler of the location in your source code where each token came from. A token in C can be defined as the smallest individual element of the C programming language that is meaningful to the compiler.
    - In nutshell, the preprocessor expands the code.
    - The output file is *.i or preprocessed file. This preprocessed file is the so-called translation unit (or more casually a compilation unit)
        ```sh
        gcc -E main.c -o main.i
        ```
    - The option -E Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output (or to a file with the -o option).

- **Compilation**
    - The input file for this stage is *.i file.
    - A tool called compiler takes the output of the preprocessor and converts it to assembly language.
    - Assembly code, often referred to as assembly language or just assembly, is a low-level programming language that uses mnemonic symbols (e.g., MOV for "move," ADD for "add") to represent CPU operations (the so-called opcode), thus making the code human-readable.
    - This is exactly the same code you may have worked with when programming microcontrollers directly in assembly language (e.g., 8051 microcontroller).
    - The output file is *.s or *.asm file.
        ```sh
        gcc -S main.i -o main.s
        ```
    - Stop after the stage of compilation proper.
    - Strictly speaking, this is the most crucial part of the compilation process and cannot be done by no one but the gcc compiler. When we use the gcc to directly generate the executable file (without breaking down all the steps), what happens under the hood is: The gcc delegates all other compilation steps (preprocessing, assembling, and linking) to `cpp`, `as`, and `ld`, respectively, and only performs the compilation step.

- **Assembling**
    - The input file for this stage is *.asm or *.s file.
    - If you use gcc to assemble the file, you must name the extension to .s. Otherwise, the -c option of gcc will try to link the file instead of assembling it.
    - Each assembly instruction typically represents a single machine code instruction, which is a set of 0's and 1's. A part of this binary sequence is the opcode, while the remainder is usually memory addresses of variables or a numeric value. While Assembly is a programming language that is independent from the CPU architecture, the machine code it represents is specific to the target CPU.
    - The tool that converts Assembly code into machine code is called assembler, and its task is called assembling.
    - In low-level microcontroller programming, the assembler converts the assembly code into a binary sequence (typically represented in hexadecimal) and embed it into the microcontroller. The micro is now ready to run.
    - On the other hand, in C/C++, the assembler converts the assembly code into a .o intermediate file, known as object file. This intermediate representation contains machine-level code, that is, non-human-readable instructions that represent the functions and variables defined in your code. The .o file is not the final executable code, though. That is, it contains machine-readable instructions but cannot be directly executed by the operating system. 
    - The output file is *.o or *.obj file.
        ```sh
        gcc -c main.s -o main.o
        ```

- **Linking**
    - The input file for this stage is *.o file.
    - The linker merges all the object code from multiple modules into a single one. If we are using a function from libraries, linker will link our code with that library function code.
    - The C Standard Libraries are typically bundled with the gcc compiler. When you install gcc or any other C compiler, it includes the necessary standard libraries required to compile and link C programs. These libraries are an integral part of the compiler distribution. Therefore, they don't exist as a separate shared library file on your system and you won't find it by looking for a .a (static library) file. The shared libraries (the .so files) are not linked at compile time, but only in the runtime.
    - For libraries outside the C standard library, you must to link it manually.
    - The output is non-readable.
        ```sh
        gcc main.o -o myprogram
        ```


### Difference between elf file and executable
- A Bin file is a pure binary file with no memory fix-ups or relocations, more than likely it has explicit instructions to be loaded at a specific memory address.
- Executable Linkable Format which consists of a symbol look-ups and relocatable table, that is, it can be loaded at any memory address by the kernel and automatically, all symbols used, are adjusted to the offset from that memory address where it was loaded into. Usually ELF files have a number of sections, such as 'data', 'text', 'bss', to name but a few...it is within those sections where the run-time can calculate where to adjust the symbol's memory references dynamically at run-time.


### Difference between static and dynamic linking in c
- Static linking combines all required libraries into the executable at compile-time. Dynamic Linking links external libraries during program load or runtime.
- Static Library (.a on Linux/macOS, .lib on Windows). Shared (Dynamic) Library (.so on Linux/macOS, .dll on Windows).
- Static Linking needs recompiling for library updates. Dynamic linking does not need to recompile when library updates.
- Static Linking is used for small projects, performance-critical code. Dynamic linking is used for large projects, code reuse, frequent updates.

### Creating Static library ( .a file )
- Compile the C code to object files ( .o )

    ```sh
    gcc -c mathlib.c -o mathlib.o
    ```

- Create the static library: Use ar (archiver) to bundle object files:
    
    ```sh
    ar rcs libmath.a mathlib.o
    ```

- r :-  Insert/Replace files in the archive
- c :- Create the archive if it doesn't exist
- s :- Index the archive (for faster symbol lookup)

- Link the static library

    ```sh
    gcc main.c -L. -lmath -o main
    ```

- -L. :– Look in the current directory for libraries.
- -lmath :– Link against libmath.a.

- Run the program
    ```sh
    ./main
    ```

### Creating a Dynamic Library ( .so file )
- Compile with Position-Independent Code (PIC):- This allows the code to be loaded dynamically.

    ```sh
    gcc -c -fPIC mathlib.c -o mathlib.o
    ```

- Create the Shared Library:- 
    ```sh
    gcc -shared -o libmath.so mathlib.o
    ```

- Link the Dynamic Library
    ```sh
    gcc main.c -L. -lmath -o main
    ```

- Ensure the shared library is discoverable:
    ```sh
    export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
    ./main
    ```

- LD_LIBRARY_PATH tells the dynamic linker where to find your .so file.

### Install Shared Library System-wide
- Copy the .so file to a standard location:

    ```sh
    sudo cp libmath.so /usr/local/lib
    sudo ldconfig
    ```

- Run your program without setting LD_LIBRARY_PATH

    ```sh
    ./main
    ```

### What are core files and how to add debug info in c executable?

- What are Core Files in C?
    - A core file (or core dump) is a snapshot of a program’s memory at the time it crashes. It helps diagnose and debug errors by preserving the program's state (variables, stack, heap, etc.) when the crash occurs.
    - When a program crashes due to issues like segmentation faults, illegal instructions, or floating-point exceptions, the operating system generates a core dump. This core dump is invaluable for analyzing why the crash happened.

- Check Core Dump Size Limit: Ensure the system allows core dumps:

    ```sh
    ulimit -c
    ```

- If it outputs 0, core dumps are disabled.

- Enable Core Dumps: Set an unlimited core dump size.
    ```sh
    ulimit -c unlimited
    ```

- Configure core dump location
    - By default, core dumps are often saved as core in the working directory. You can customize the filename:
    ```sh
    sudo sysctl -w kernel.core_pattern=/var/dumps/core.%e.%p
    ```
    - This saves core files in /var/dumps with the executable name (%e) and process ID (%p)

- To analyze core dumps effectively, debug symbols must be included in your executable.
- Compile with Debug Symbols Use the -g flag to embed debug information:
    ```sh
    gcc -g yourfile.c -o yourprogram
    ```

- -g:- Adds debug symbols without affecting optimization.
- -o:-  Specifies the output binary name.

- Preserve Optimization (if needed) For optimized builds with debug info:
    ```sh
    gcc -g -O2 yourfile.c -o yourprogram
    ```

- Separate Debug Symbols (Optional) To keep binaries small while maintaining debug info:

    ```sh
    gcc -g -o yourprogram yourfile.c
    objcopy --only-keep-debug yourprogram yourprogram.debug
    objcopy --strip-debug yourprogram
    ```

- Now, you can load debug symbols when needed:
    ```
    gdb yourprogram -ex "add-symbol-file yourprogram.debug" -c core
    ```
