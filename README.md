bits-set
==============
Simple library to set/get every single bits.


Examples
--------------

Sorting 10 thousand integers?

bit-sets
~~~~~~~~

*bits_sort.c*

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bits.h>

int main(void)
{
    FILE *data = fopen("./1-9999-random-numbers", "r");
    bit_array array[SIZE(10000)] = {0};

    /* read the numbers to the bit_array from the file */
    char tmp[7];
    while (fgets(tmp, 7, data) != NULL) {
        tmp[strlen(tmp) - 1] = '\0';  // remove newline
        set_bit(array, atoi(tmp));
    }
    fclose(data);

    for (int i = 0; i < 10000; i++) {
        if (get_bit(array, i) == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}
```

Python
~~~~~~~

*simple_sort.py*

```python
nums = []

f = open("./1-9999-random-numbers", "r")
for line in f:
    line = line.replace("\n", "")
    nums.append(int(line))
f.close()

nums.sort()
for i in nums:
    print(i)
```

Unix
~~~~~

```bash
sort -n ./1-9999-random-numbers
```

Benchmark
~~~~~~~~~~~

All binaries were compiled with `-O2 -march=native`.

```
gcc bits_sort.c -o bits_sort -Ofast -march=native

$ /usr/bin/time ./bits_sort > result_1
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 2128maxresident)k
0inputs+64outputs (0major+177minor)pagefaults 0swaps


$ /usr/bin/time ./simple_sort.py > result_2
0.03user 0.00system 0:00.04elapsed 97%CPU (0avgtext+0avgdata 27104maxresident)k
0inputs+64outputs (0major+1956minor)pagefaults 0swaps


$ /usr/bin/time sort -n ./1-9999-random-numbers > result_3
0.00user 0.00system 0:00.00elapsed 83%CPU (0avgtext+0avgdata 4192maxresident)k
0inputs+64outputs (0major+356minor)pagefaults 0swaps

$ md5sum result_*
c348cd0b0b218c61b84aa513d03cb42e  result_1
c348cd0b0b218c61b84aa513d03cb42e  result_2
c348cd0b0b218c61b84aa513d03cb42e  result_3
```

`bits_sort`, powered by bits-set, was the fastest program. It also had the least memory usage.
