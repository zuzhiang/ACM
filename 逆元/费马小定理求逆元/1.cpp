/*
费马小定理求 a%m 的逆元，要求 a、m 互质且 m 为素数 
*/
#include<stdio.h>

int  qpow(int a,int b,int mod)
{
	int ans=1;
	while(b>0)
	{		
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	int a,m,ans;
	while(~scanf("%d %d",&a,&m))
	{
		//求a%m的逆元 
		ans=qpow(a,m-2,m);
		printf("a%%m的逆元为：%d\n",ans);
	}	
	return 0;
}
