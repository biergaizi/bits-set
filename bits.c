#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "bits.h"

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define CHAR_ENDIAN(x) (7 - x)
#define HEX_ENDIAN(x) (15 - x)

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define CHAR_ENDIAN(x) (x)
#define HEX_ENDIAN(x) (x)

#else
#error "Unsupported Architecture"

#endif

bit get_bit(bit_array *bits, size_t index)
{
    size_t segment = index / SIZE_IN_BITS(bit_array);
    size_t pos = index % SIZE_IN_BITS(bit_array);
    return BIT_CHECK(bits[segment], pos);
}


void set_bit(bit_array *bits, size_t index)
{
    size_t segment = index / SIZE_IN_BITS(bit_array);
    size_t pos = index % SIZE_IN_BITS(bit_array);
    BIT_SET(bits[segment], pos);
}


void clear_bit(bit_array *bits, size_t index)
{
    size_t segment = index / SIZE_IN_BITS(bit_array);
    size_t pos = index % SIZE_IN_BITS(bit_array);
    BIT_CLEAR(bits[segment], pos);
}


void hex2bits(bit_array *bits, size_t index, uint16_t hex)
{
    for (short i = 0; i < 16; i++) {
        if (BIT_CHECK(hex, HEX_ENDIAN(i))) {
            set_bit(bits, i + index);
        }
    }
}


uint16_t bits2hex(bit_array *bits, size_t index)
{
    uint16_t result = 0;

    for (short i = 0; i < 16; i++) {
        if (get_bit(bits, i + index)) {
            BIT_SET(result, HEX_ENDIAN(i));
        }
    }
    return result;
}


void char2bits(bit_array *bits, size_t index, char chr)
{
    for (short i = 0; i < 8; i++) {
        if (BIT_CHECK(chr, CHAR_ENDIAN(i))) {
            set_bit(bits, i + index);
        }
    }
}


char bits2char(bit_array *bits, size_t index)
{
    char result = 0;

    for (short i = 0; i < 8; i++) {
        if (get_bit(bits, i + index)) {
            BIT_SET(result, CHAR_ENDIAN(i));
        }
    }
    return result;
}

void bits_shift(bit_array *bits, int len, int offset)
{
    offset %= len;
    if (offset < 0) {
        offset = len - (-offset);
    }

    for (int i = 0; i < offset; i++) {
       bool tmp =  get_bit(bits, 0);
       for (int j = 1; j < len; j++) {
            get_bit(bits, j) ? set_bit(bits, 0) : clear_bit(bits, 0);
            tmp ? set_bit(bits, j) : clear_bit(bits, j);
            tmp = get_bit(bits, 0);
       }
    }
}

inline void bits_left_shift(bit_array *bits, int len, int offset)
{
    bits_shift(bits, len, -offset);
}
