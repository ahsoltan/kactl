/**
 * Author:
 * License: CC0
 * Source: Own work
 * Description: Disable padding to decrease the struct size.
 * Slows down the execution due to non-aligned memory accesses.
 */

struct sample {
  char x;
  long long y;
} __attribute__((packed));

static_assert(sizeof(sample) == 9);