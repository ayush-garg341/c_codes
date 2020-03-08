#include <stdio.h>

int main()
{
    unsigned char ch;
    for (ch = 0; ch <= 254; ch++)
    {
        printf("%d %c\n", ch, ch);
    }

    printf("%d %c\n", ch, ch);

    return 0;
}

// A negative number is always stored as 2’s compliment of its binary. For example, let us see how -128 is stored.
// Firstly, binary of 128 is calculated (10000000), then its 1’s compliment is obtained (01111111). A 1’s compliment
// is obtained by changing all 0s to 1s and 1s to 0s. Finally, 2’s compliment of this number, i.e. 10000000, gets stored.
// A 2’s compliment is obtained by adding 1 to the 1’s compliment.
// This is an 8-bit number and it can be easily accommodated in a char.
// As against this, +128 cannot be stored in a char because its binary 010000000 (left-most 0 is for positive sign) is a
// 9-bit number.
// However +127 can be stored as its binary 01111111 turns out to be a 8-bit number.

// What happens when we attempt to store +128 in a char? The first number on the negative side, i.e. -128 gets stored.
// This is because from the 9-bit binary of +128, 010000000, only the right-most 8 bits get stored.
// But when 10000000 is stored the left-most bit is 1 and it is treated as a sign bit.
// Similarly, you can verify that an attempt to store +129 in a char results in storing -127 in it.