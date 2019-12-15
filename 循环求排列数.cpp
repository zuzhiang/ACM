#include<stdio.h>
int main()
{
	int i,j;
	__int64 c[100][100];
	for(i=1;i<100;i++)
	{
		c[i][0]=c[i][i]=1;
		c[i][1]=i;
		for(j=2;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(i=1;i<10;i++)
		for(j=1;j<=i;j++)
			printf("C(%d,%d)=%I64d\n",i,j,c[i][j]);
	return 0;
}