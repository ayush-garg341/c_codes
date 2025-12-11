#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>

#define DEBUG_PRINT 1

static void dbg(char* description, char* fmt, ...)
{
    (void)description;
    (void)fmt;

#if(DEBUG_PRINT == 1)

    static char buff[500];
    size_t const size = sizeof(buff);
    int n = snprintf(buff, size, "{desc:%s, } -- ",description);
    int const bytes_left = size - n;
    va_list args;
    va_start(args, fmt);
    vsnprintf(&buff[n], bytes_left, fmt, args);
    va_end(args);
    printf("%s", buff);

#endif
}

int main()
{
    dbg("Testing this custom logger", "Printing my name: %s\n", "Ayush Garg");
    return 0;
}

// static void dbg(...) :- This makes the function private to the file (file-scope internal linkage).
// Meaning: It cannot be called from other .c files.
// Only this translation unit can use it.
// Prevents namespace pollution.
// The compiler can optimize it more aggressively.
//

// static char buff[300]; -> This makes the buffer persist across function calls.
// A static variable:
//  Is allocated once, not on the stack.
//  Keeps its value between function calls.
//  Avoids allocating 300 bytes repeatedly per call.
//  Avoids stack frame bloat for debug calls.
// Why this matters?
//  Debug logging may be called many times.
//  Allocating 300 bytes on stack each time is costly.
//  Static lifetime improves performance.

// const - "I promise not to change this, optimize accordingly"
//
// But static variables retained their values across function calls, then does it mean values will get cluttered or overstep each other if called many times with different fmt and args?
// Yes, A static buffer retains whatever was written into it from the previous call.
// Each new call completely rewrites the buffer from the beginning
// So in practice: old values never cause clutter, because snprintf() and vsnprintf() overwrite the buffer starting at index 0.
// If the new output is shorter than the previous output:
// Example: 1st call writes 100 bytes, 2nd call writes only 20 bytes, thhen bytes 21–100 remain unchanged in the static buffer.
// But because printf("%s", buff) prints until the first '\0', leftover characters never appear. Why?
// Because snprintf and vsnprintf always null-terminate the string.
// So the extra leftover junk is after the null byte and not visible.
