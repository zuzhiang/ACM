/*
����С������ a%m ����Ԫ��Ҫ�� a��m ������ m Ϊ���� 
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
		//��a%m����Ԫ 
		ans=qpow(a,m-2,m);
		printf("a%%m����ԪΪ��%d\n",ans);
	}	
	return 0;
}
