#include <stdio.h>
#include <math.h>
// #include <conio.h>
#define maxrept 1000            /* 最大迭代次数 */

float f(float x)
{
    return(x - exp(-x));        /* 函数 f(x) */
}

float df(float x)
{
    return(1 + exp(-x));        /* 函数 f(x)的导数 */
}

float iterate(float x)
{
    float x1;
    x1 = x - f(x) / df(x);      /* 牛顿迭代函数 */
    return(x1);
}

int main()
{
    float x0, x1, eps, d; 
    int k = 0;
    // clrscr();
    printf("\n please input x0 = ");    /* 输入迭代初值 x0 */
    scanf("%f", &x0);
    printf("\n please input eps = ");    /* 输入求解精度 eps */
    scanf("%f", &eps);
    printf("\n    k    xk\n");
    printf("    %d    %f\n", k, x0);
    
    do
    {
        k++;
        x1 = iterate(x0);
        printf("    %d    %f\n", k, x1);
        d = fabs(x1 - x0);
        x0 = x1;
    }
    while((d >= eps) && (k < maxrept));
    
    if(k < maxrept)
        printf("the root of f(x) = 0 is x = %f, k = %d\n", x1, k);
    else
        printf("\n the iteration is failed! \n");
    
    // getch();
    return 0;
}
