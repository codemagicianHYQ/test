#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 检查数字是否在digits数组中
int isInDigits(int num, int* digits, int digitsSize) {
    for(int i = 0; i < digitsSize; i++) {
        if(digits[i] == num) return 1;
    }
    return 0;
}

// 生成所有可能的三位数
void generateNumbers(int* digits, int digitsSize, int* result, int* resultSize) {
    *resultSize = 0;
    
    // 遍历所有可能的三位数组合
    for(int i = 0; i < digitsSize; i++) {
        for(int j = 0; j < digitsSize; j++) {
            for(int k = 0; k < digitsSize; k++) {
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                // 检查是否是三位数且是偶数
                if(num >= 100 && num <= 999 && num % 2 == 0) {
                    // 检查是否已经在结果中
                    int found = 0;
                    for(int m = 0; m < *resultSize; m++) {
                        if(result[m] == num) {
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        result[*resultSize] = num;
                        (*resultSize)++;
                   }
                }
            }
        }
    }
}

// 比较函数，用于排序
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int digits[100];  // 存储输入的数字
    int digitsSize;   // 输入数字的个数
    int result[1000]; // 存储结果
    int resultSize;   // 结果的个数
    
    printf("请输入数字个数: ");
    scanf("%d", &digitsSize);
    
    printf("请输入数字 (0-9之间，用空格分隔): ");
    for(int i = 0; i < digitsSize; i++) {
        scanf("%d", &digits[i]);
    }
    
    // 生成所有可能的三位偶数
    generateNumbers(digits, digitsSize, result, &resultSize);
    
    // 对结果进行排序
    qsort(result, resultSize, sizeof(int), compare);
    
    // 输出结果
    printf("所有可能的三位偶数（按升序排列）:\n[");
    for(int i = 0; i < resultSize; i++) {
        printf("%d", result[i]);
        if(i < resultSize - 1) printf(",");
    }
    printf("]\n");
    
    return 0;
} 


