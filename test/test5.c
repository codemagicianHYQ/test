#include <stdio.h>
#include <stdlib.h>

int* constructBeautifulArray(int n, int* returnSize) {
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    // 如果n=1，直接返回[1]
    if (n == 1) {
        result[0] = 1;
        return result;
    }
    
    // 分治法：先处理奇数位置，再处理偶数位置
    int leftSize = (n + 1) / 2;  // 向上取整
    int rightSize = n / 2;       // 向下取整
    
    // 递归构造左半部分（奇数）
    int* left = constructBeautifulArray(leftSize, returnSize);
    // 递归构造右半部分（偶数）
    int* right = constructBeautifulArray(rightSize, returnSize);
    
    // 合并结果：先放奇数部分（2*x-1），再放偶数部分（2*x）
    int index = 0;
    for (int i = 0; i < leftSize; i++) {
        result[index++] = 2 * left[i] - 1;
    }
    for (int i = 0; i < rightSize; i++) {
        result[index++] = 2 * right[i];
    }
    
    // 释放临时数组
    free(left);
    free(right);
    
    return result;
}

int main() {
    int n, returnSize;
    printf("请输入n: ");
    scanf("%d", &n);
    
    int* result = constructBeautifulArray(n, &returnSize);
    
    printf("漂亮数组: [");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(",");
    }
    printf("]\n");
    
    free(result);
    return 0;
}
