#include <stdio.h>
#include <math.h>
// #include <conio.h>

float fa(float x);
float dd(float a);

int main()
{
    float x, x0;
    // clrscr();
    printf("input data, x0 = ");     /* 输入迭代初值 x0 */
    scanf("%f", &x0);
    x = dd(x0);
    printf("the root of f(x) = 0 is x = %f\n", x);
    // getch();
    return 0;
}

float dd(float a)
{
    float x, x0, e;
    int i;
    printf("input eps = ");        /* 输入求解精度 eps */
    scanf("%f", &e);
    x0 = a;
    printf("x0 = %f\n", x0);
    for(i = 1; ; i++)
    {
        x = fa(x0);
        printf("x(%d) = %f\n", i, x);
        if(fabs(x - x0) < e) return(x);
        else x0 = x;
    }
}

float f(float x)
{
    float a;
    a = exp(-x) - x + 1;        /* 函数 f(x) */
    return a;
}

float fa(float x)
{
    float a;
    a = exp(-x) + 1;            /* 迭代函数 fa(x) */
    return(a);
}
