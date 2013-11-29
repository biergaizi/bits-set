#include <assert.h>
#include <stdio.h>
#include "bits.h"


static void test1(void)
{
    static bit_array bits[SIZE(10)] = {0};

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
    static bit_array bits[SIZE(40)] = {};

    hex2bits(bits, 0, 30767);
    hex2bits(bits, 16, 30111);

    assert(bits2hex(bits, 0) == 30767);
    assert(bits2hex(bits, 16) == 30111);

    for (size_t i = 32; i < 40; i++) {
        assert(get_bit(bits, i) == 0);
    }

    printf("Test2 Passed!\n");
}


static void test3(void)
{
    static bit_array bits[SIZE(20)] = {};

    char2bits(bits, 0, 'B');
    char2bits(bits, 8, 'C');

    assert(bits2char(bits, 0) == 'B');
    assert(bits2char(bits, 8) == 'C');

    for (size_t i = 16; i < 20; i++) {
        assert(get_bit(bits, i) == 0);
    }
    printf("Test3 Passed!\n");
}


static void test4(void)
{
    static bit_array bits[SIZE(4)] = {};

    set_bit(bits, 0);
    set_bit(bits, 1);
    clear_bit(bits, 2);

    assert(get_bit(bits, 0) == 1);
    assert(get_bit(bits, 1) == 1);
    assert(get_bit(bits, 2) == 0);

    bits_left_shift(bits, 3, 1);

    assert(get_bit(bits, 0) == 1);
    assert(get_bit(bits, 1) == 0);
    assert(get_bit(bits, 2) == 1);

    assert(get_bit(bits, 3) == 0);

    bits_left_shift(bits, 4, 1);

    assert(get_bit(bits, 0) == 0);
    assert(get_bit(bits, 1) == 1);
    assert(get_bit(bits, 2) == 0);
    assert(get_bit(bits, 3) == 1);

    printf("Test4 Passed!\n");
}


int main(void)
{

    test1();
    test2();
    test3();
    test4();
    return 0;
}
