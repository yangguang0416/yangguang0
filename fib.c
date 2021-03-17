#include <stdio.h>
#include <stdlib.h>
int Fib(int i)		//µÝ¹é 
{
	if(i<2)
	{
		return i==0?0:1;
	}
	return Fib(i-1) + Fib(i-2);
} 

int main(int argc, char *argv[]) //µü´ú 
{
	int i;
	int a[40];
	
	a[0] = 0;
	a[1] = 1;
	printf("%d %d ",a[0],a[1]);
	
	for(i=2;i<40;i++)
	{
		a[i]=a[i-1] + a[i-2];
		printf("%d ",a[i]);
		
	}
	return 0;
}
