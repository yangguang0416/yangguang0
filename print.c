#include <stdio.h>
#include <stdlib.h>
//递归实现数组逆序,#代表输入结束 
//利用调用顺序和回退顺序相反实现3 

void print()
{
	char a;
	scanf("%c",&a);
	if(a!='#')
	{
		print();
	}
	if(a!='#')
	{
		printf("%c",a);
	}
}
int main(int argc, char *argv[]) 
{
	print();
	return 0;
}
//数组逆序 
int opposit()
{
	int i,j,t,a[10];
	
	for(i=0;i<10;i++)
	{
		scanf("%d",a[i]); 
	}
	
	for(i=0;i<5;i++)
	{
		t=a[i];
		a[i]=a[10-i-1];
		a[10-i-1]=t;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}

}
