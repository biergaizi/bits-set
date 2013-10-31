#include <assert.h>
#include <stdio.h>
#include "bits.h"


static void test1(void)
{
    bit_array bits[SIZE(10)] = {0};

    assert(get_bit(bits, 0) == 0);

    set_bit(bits, 1);
    assert(get_bit(bits, 1) == 1);
    clear_bit(bits, 1);
    assert(get_bit(bits, 1) == 0);

    set_bit(bits, 2);
    assert(get_bit(bits, 2) == 1);
    set_bit(bits, 3);
    assert(get_bit(bits, 3) == 1);

    for (size_t i = 4; i < 10; i++) {
        assert(get_bit(bits, i) == 0);
    }
    printf("Test1 Passed!\n");
}


static void test2(void)
{
    bit_array test1_bits[SIZE(18)] = {};

    uint16_t test1_int = 30767;
    hex2bits(test1_bits, 0, test1_int);
    assert(bits2hex(test1_bits, 0) == 30767);

    printf("Test2 Passed!\n");
}


int main(void)
{

    test1();
    test2();
    return 0;
}
