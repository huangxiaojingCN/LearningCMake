#include <stdio.h>
#include <stdlib.h>
#include "config.h"

// 通过 MY_MATH_FLAG 编译控制
#ifdef MY_MATH_FLAG
    #include "CalcPower.h"
#else
    #include <math.h>
#endif

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

    #ifdef MY_MATH_FLAG
        double result = power(base, exponent);
        printf("使用自定义函数实现平方计算: %g ^ %d is %g\n", base, exponent, result);
    #else
        double result = pow(base, exponent);
        printf("使用系统函数实现平方计算: %g ^ %d is %g\n", base, exponent, result);
    #endif
        printf("%g ^ %d is %g\n", base, exponent, result);
    
    return 0;
}