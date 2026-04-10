#include<stdio.h>
#include<stdint.h>

// Pack year, month, day into 32 bits
uint32_t pack_date(int year, int month, int day) {
    return (year << 9) | (month << 5) | day;
}


// Unpack the date
void unpack_date(uint32_t packed, int *year, int *month, int *day) {
    *day = packed & 0x1F; // 5 bits
    *month = (packed >> 5) & 0xF; // 4 bits
    *year = (packed >> 9); // remaining bits
}

int main() {

    int year = 2026;
    int month = 4;
    int day = 10;

    // this 32 bit integer ensure that what we are getting back is packed in 32 bits
    uint32_t packed = pack_date(year, month, day);

    printf("Original date: %d-%02d-%02d\n", year, month, day);
    printf("Packed value (decimal): %u\n", packed);
    printf("Packed value (hex): 0x%X\n", packed);

    int y, m, d;
    unpack_date(packed, &y, &m, &d);
    printf("Unpacked date: %d-%02d-%02d\n", y, m, d);

    return 0;
}

// For days 1 to 31 -> 5 bits as 2 ^ 5 = 32
// For month 1 to 12 -> 4 bits as 2 ^ 4 = 16
// For year considering upto 8192 -> 13 bits as 2 ^ 13 = 8192
// By packing the bits, converted 12 bytes for each y, m, d ( 96 bits ) into 32 bits
