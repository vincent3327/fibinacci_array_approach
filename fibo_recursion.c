/**************************************************************
*此为使用迭代方法创建斐波那契数列的程序
20200720

***************************************************************/
#include <stdio.h>
int fibo(int n)
{
    if(0==n)
        return 1;
    else if(1==n)
        return 1;
    else
        return (fibo(n-1)+fibo(n-2));
}
int main(int argc, const char * argv[]) {
    int i = 10;
    printf("fibo(%d)=%d\n",i,fibo(i));
    return 0;
}