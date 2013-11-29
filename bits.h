#ifndef __BITS
#define __BITS

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef bool bit;
typedef uint32_t bit_array;
typedef char byte;

#define SIZE_IN_BITS(i) (sizeof(i) * 8)
#define SIZE(i) ((i) / SIZE_IN_BITS(bit_array) == 0 ? 1 : (i) / SIZE_IN_BITS(bit_array))
#define BIT_SET(a,x) ((a) |= (1<<(x)))
#define BIT_CLEAR(x,n) (x = x&~(0x01<<n))
#define BIT_CHECK(a,x) (((a) & (1<<(x))) != 0)


bit get_bit(bit_array *bits, size_t index);
void set_bit(bit_array *bits, size_t index);
void clear_bit(bit_array *bits, size_t index);

void hex2bits(bit_array *bits, size_t index, uint16_t hex);
uint16_t bits2hex(bit_array *bits, size_t index);

void char2bits(bit_array *bits, size_t index, char chr);
char bits2char(bit_array *bits, size_t index);

// void bits_left_shift(bit *bits, int len, int offset);

#endif
