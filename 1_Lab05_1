#include <stdio.h>
#include <math.h>

int main() {
    long long min, max;
    scanf("%lld %lld", &min, &max);

    int size = max - min + 1;
    int check[size];
    for (int i = 0; i < size; i++) check[i] = 1;

    for (long long i = 2; i * i <= max; i++) {
        long long sq = i * i;
        long long start = (min + sq - 1) / sq * sq;

        for (long long j = start; j <= max; j += sq)
            check[j - min] = 0;
    }

    int result = 0;
    for (int i = 0; i < size; i++)
        if (check[i]) result++;

    printf("%d\n", result);
    return 0;
}
