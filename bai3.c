
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int even_count = 0;
    int odd_sum = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num % 2 == 0) {
            even_count++;
        } else {
            odd_sum += num;
        }
    }

    if (even_count == 0) {
        printf("NOT_FOUND\n");
    } else {
        printf("%d\n", odd_sum);
    }

    return 0;
}
