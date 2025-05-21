#include <stdio.h>

int main(void) {
    int n, sum = 0;
    char digits[101];  

    scanf("%d", &n);
    scanf("%s", digits);

    for (int i = 0; i < n; i++) {
        sum += digits[i] - '0'; 
    }

    printf("%d\n", sum);
    return 0;
}
