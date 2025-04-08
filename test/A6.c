#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3        // 方程组的阶数
#define KMAX 100   // 最大迭代次数
#define EPS 1e-4   // 精度要求

int main() {
    // 系数矩阵
    double a[N][N] = {
        {5, 2, 1},
        {-1, 4, 2},
        {2, -3, 10}
    };
    // 常数项
    double b[N] = {-12, 20, 3};
    
    double x[N] = {0};     // 当前迭代解
    double y[N] = {0};     // 下一次迭代解
    double d, sum, norm;   // d用于存储误差，sum用于计算迭代值，norm为范数
    int k = 0;            // 迭代次数
    
    printf("初始值：\n");
    for(int i = 0; i < N; i++) {
        printf("x[%d] = %f\n", i+1, x[i]);
    }
    
    do {
        k++;
        norm = 0.0;
        
        // 计算新的迭代值
        for(int i = 0; i < N; i++) {
            sum = 0.0;
            for(int j = 0; j < N; j++) {
                if(j != i) {
                    sum += a[i][j] * x[j];
                }
            }
            y[i] = (b[i] - sum) / a[i][i];
            
            // 计算误差
            d = fabs(y[i] - x[i]);
            if(d > norm) {
                norm = d;
            }
        }
        
        // 更新解向量
        for(int i = 0; i < N; i++) {
            x[i] = y[i];
        }
        
        printf("\n第%d次迭代结果：\n", k);
        for(int i = 0; i < N; i++) {
            printf("x[%d] = %f\n", i+1, x[i]);
        }
        
        // 判断是否超过最大迭代次数
        if(k >= KMAX) {
            printf("\n超过最大迭代次数，迭代失败！\n");
            return 1;
        }
        
    } while(norm > EPS);
    
    printf("\n最终结果（迭代%d次）：\n", k);
    for(int i = 0; i < N; i++) {
        printf("x[%d] = %f\n", i+1, x[i]);
    }
    
    return 0;
} 