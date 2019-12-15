/*
线性方法求 a%m 的逆元，要求 a、m 互质且 m 为素数 
inv[i]中保存的是i关于m的逆元
*/
#include<stdio.h>
int main()
{
	int i,a,m;
	int inv[1000];
	while(~scanf("%d %d",&a,&m))
	{
		inv[1]=1;
		for(i=2;i<m;i++)
			inv[i]=((m-m/i)%m*inv[m%i])%m;
		printf("%d\n",inv[a]);
	}	
	return 0;
}
