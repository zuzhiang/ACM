/*
����չŷ������㷨�� a%m ����Ԫ��Ҫ�� a �� m ���� 
*/
#include<stdio.h>

int extgcd(int a, int b, int& x, int& y)
{
    int r,t;
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	r=extgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return r;
}

int mod_inverse(int a, int m)
{
    int x, y;
    extgcd(a, m, x, y); //��õ�xΪһ���⣬����һ������С��
    return (x % m + m) % m; //Ҳ����дΪ��if(x>=0) x=x%m; else x=x%m+m
}

int main()
{
	int a,m,ans;
	while(~scanf("%d %d",&a,&m))
	{
		ans=mod_inverse(a,m);
		printf("a%%m����ԪΪ:%d\n",ans);
	}
	return 0;
}
