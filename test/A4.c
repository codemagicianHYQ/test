#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3  // 方程组的阶数

int main() {
    // 系数矩阵
    double a[N][N] = {
        {2, 2, 3},
        {4, 7, 7},
        {-2, 4, 5}
    };
    // 常数项
    double b[N] = {3, 1, -7};
    // 解向量
    double x[N] = {0, 0, 0};
    
    double r, s;
    int i, j, k, p;
    int flag = 1;
    
    // 输出原始矩阵
    printf("原始矩阵：\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%8.2f", a[i][j]);
        }
        printf(" |%8.2f\n", b[i]);
    }
    printf("\n");
    
    // 消元过程
    for(k = 0; k < N-1; k++) {
        // 选主元
        p = k;
        for(i = k+1; i < N; i++) {
            if(fabs(a[i][k]) > fabs(a[p][k])) {
                p = i;
            }
        }
        
        if(p != k) {
            // 交换行
            for(j = k; j < N; j++) {
                r = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = r;
            }
            r = b[k];
            b[k] = b[p];
            b[p] = r;
        }
        
        // 判断主元是否为0
        if(fabs(a[k][k]) < 1e-10) {
            printf("方程组无解或有无穷多解\n");
            flag = 0;
            break;
        }
        
        // 消元计算
        for(i = k+1; i < N; i++) {
            r = a[i][k] / a[k][k];
            for(j = k; j < N; j++) {
                a[i][j] = a[i][j] - r * a[k][j];
            }
            b[i] = b[i] - r * b[k];
        }
    }
    
    // 回代过程
    if(flag) {
        if(fabs(a[N-1][N-1]) < 1e-10) {
            printf("方程组无解或有无穷多解\n");
            return 1;
        }
        
        x[N-1] = b[N-1] / a[N-1][N-1];
        for(i = N-2; i >= 0; i--) {
            s = 0;
            for(j = i+1; j < N; j++) {
                s += a[i][j] * x[j];
            }
            x[i] = (b[i] - s) / a[i][i];
        }
        
        // 输出结果
        printf("方程组的解为：\n");
        for(i = 0; i < N; i++) {
            printf("x[%d] = %lf\n", i+1, x[i]);
        }
    }
    
    return 0;
}
