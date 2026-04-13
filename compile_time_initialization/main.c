/*
   Compile-time initialization means: The value of a variable is decided and stored during compilation, not when the program runs.
   - Faster startup (no runtime work)
   - Stored in .data / .rodata section
   - Often enables further compiler optimizations
*/

#include<stdio.h>
#include<stdint.h>

// Compile time lookup
static const uint8_t days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Compile time macro ( bit packing )
#define PACK_DATE(y, m, d) (((y) << 9 ) | ((m) << 5) | (d))

// Unpack functions

static inline int get_day(uint32_t packed) {
    return (packed & 0x1F);
}

static inline int get_month(uint32_t packed) {
    return ((packed >> 5) & 0xF);
}

static inline int get_year(uint32_t packed) {
    return (packed >> 9);
}

// Event structure

typedef struct {
    uint32_t date; // packed date
    int value;
} Event;

// Compile time initialized dataset, will be computed at compile time.

static const Event events[] = {
    { PACK_DATE(2026, 4, 10), 100 },
    { PACK_DATE(2026, 4, 11), 200 },
    { PACK_DATE(2026, 5, 1),  150 },
    { PACK_DATE(2027, 1, 5),  300 }
};

// Usage: process events

void process_events() {
    int n = sizeof(events) / sizeof(events[0]);

    for (int i = 0; i < n; i++) {
        uint32_t d = events[i].date;

        int year  = get_year(d);
        int month = get_month(d);
        int day   = get_day(d);

        printf("Event %d → %d-%02d-%02d | value=%d\n",
               i, year, month, day, events[i].value);

        // Example: validate using lookup table
        if (day > days_in_months[month - 1]) {
            printf("  ⚠ Invalid date!\n");
        }
    }
}

int main() {
    process_events();
    return 0;
}

// Data construction → at compile time
// Data usage        → at runtime
