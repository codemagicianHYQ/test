#include <stdio.h>
#include <math.h>
// #include <conio.h>
#include <stdlib.h>

float f(float x)
{
    float a;
    a = x * x * x - 2 * x - 5;
    return a;
    /* 求函数值，如果求其他函数，只需改成其他函数即可 */
}

int main()
{
    float a, b, e, x; /* a,b分别表示有根区间的左、右端点，e是精度要求，x是区间中点值 */
    printf(" \n please input data a = ");
    scanf(" %f", &a);
    printf(" \n please input data b = ");
    scanf(" %f", &b);
    printf(" \n please input data eps = ");
    scanf(" %f", &e);
    
    x = (a + b) / 2; // 初始化x
    if(f(a) * f(b) < 0)
    {
        while(fabs(f(x)) > e) // 修改循环条件
        {
            x = (a + b) / 2;
            if(f(x) * f(a) < 0)
            {
                b = x;
                if(fabs(b - a) < e) break;
                else continue;
            }
            else
            {
                a = x;
                if(fabs(b - a) < e) break;
                else continue;
            }
        }
        printf("\n");
        x = (b + a) / 2;
        printf("the root of f(x) = 0 is x = %f\n", x);
    }
    else
        printf("\nnot root! afresh input\n"); /* 表示[a,b]区间无根，重新选择有根区间 */
    
    return 0;
}
