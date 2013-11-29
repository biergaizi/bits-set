#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "bits.h"


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
        // Why Reversed Order? Cause By Litten-Endian Machines?
        // I don't know. I need to test it on Big-Endian with QEMU.
        if (BIT_CHECK(hex, 15 - i)) {
            set_bit(bits, i + index);
        }
    }
}


uint16_t bits2hex(bit_array *bits, size_t index)
{
    uint16_t result = 0;

    for (short i = 0; i < 16; i++) {
        if (get_bit(bits, i + index)) {
            BIT_SET(result, 15 - i);
        }
    }
    return result;
}


void char2bits(bit_array *bits, size_t index, char chr)
{
    for (short i = 0; i < 8; i++) {
        if (BIT_CHECK(chr, 7 - i)) {
            set_bit(bits, i + index);
        }
    }
}


char bits2char(bit_array *bits, size_t index)
{
    char result = 0;

    for (short i = 0; i < 8; i++) {
        if (get_bit(bits, i + index)) {
            BIT_SET(result, 7 - i);
        }
    }
    return result;
}


void bits_left_shift(bit_array *bits, int len, int offset)
{
    assert(len > 0);

    // A very stupid algorithm, but easy to understand.
    bit_array tmp[SIZE(len)];
    for (int i = 0; i < offset; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (get_bit(bits, j + 1)) {
                set_bit(tmp, j);
            }
            else {
                clear_bit(tmp, j);
            }
        }

        if (get_bit(bits, 0)) {
            set_bit(tmp, len - 1);
        }
        else {
            clear_bit(tmp, len - 1);
        }

        for (int j = 0; j < len; j++) {
            if (get_bit(tmp, j)) {
                set_bit(bits, j);
            }
            else {
                clear_bit(bits, j);
            }
        }
    }
}
