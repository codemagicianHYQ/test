#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 4  // 方程组的阶数

int main() {
    // 三对角系数矩阵的三条对角线
    float a[N] = {0, -1, -2, -2};     // 下对角线
    float b[N] = {2, 3, 4, 5};        // 主对角线
    float c[N] = {-1, -2, -2, 0};     // 上对角线
    float d[N] = {3, 1, 0, -5};       // 右端常数项
    
    float r[N] = {0};  // 用于存储中间结果
    float y[N] = {0};  // 用于存储中间结果
    float x[N] = {0};  // 解向量
    float q;
    
    // 追的过程（消元）
    r[1] = c[1] / b[1];
    y[1] = d[1] / b[1];
    
    for(int k = 2; k < N; k++) {
        q = b[k] - r[k-1] * a[k];
        r[k] = c[k] / q;
        y[k] = (d[k] - y[k-1] * a[k]) / q;
    }
    
    // 赶的过程（回代）
    y[N-1] = (d[N-1] - y[N-2] * a[N-1]) / (b[N-1] - r[N-2] * a[N-1]);
    x[N-1] = y[N-1];
    
    for(int k = N-2; k >= 1; k--) {
        x[k] = y[k] - r[k] * x[k+1];
    }
    
    // 输出结果
    printf("方程组的解为：\n");
    for(int k = 1; k <= N; k++) {
        printf("x[%d] = %f\n", k, x[k-1]);
    }
    
    return 0;
} 