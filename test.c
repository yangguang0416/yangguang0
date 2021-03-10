//使用函数求素数和
//其中函数prime当用户传入参数p为素数时返回1，否则返回0；
//函数PrimeSum返回区间[m, n]内所有素数的和。


#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime( int p )
{
    if(p<=0 || p==1)
    {
        return 0;
    }
    else if(p==2 || p==3)
    {
        return 1;
    }
    else if(p%6!=1 && p%6!=5)
    {
        return 0;
    }
    else
    {
        int tmp=(int)sqrt(p);
        int i;
        for(i=5;i<=tmp;i+=6)
        {
            if(p%i==0 || p%(i+2)==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int PrimeSum( int m, int n )
{
    int sum=0;
    for(;m<=n;m++)
    {
        if(prime(m)!=0)
        {
            sum+=m;
        }
    }
    return sum;
}

