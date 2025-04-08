#include <stdio.h>
#include <stdbool.h>

// 判断是否是3的幂次方
bool isPowerOfThree(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

// 判断是否是4的幂次方
bool isPowerOfFour(int n) {
    if (n < 1) return false;
    while (n % 4 == 0) {
        n /= 4;
    }
    return n == 1;
}

int main() {
    int n;

    printf("请输入一个整数: ");
    scanf("%d", &n);

    if (isPowerOfThree(n)) {
        printf("%d 是3的幂次方。\n", n);
    } else {
        printf("%d 不是3的幂次方。\n", n);
    }

    if (isPowerOfFour(n)) {
        printf("%d 是4的幂次方。\n", n);
    } else {
        printf("%d 不是4的幂次方。\n", n);
    }

    return 0;
}
