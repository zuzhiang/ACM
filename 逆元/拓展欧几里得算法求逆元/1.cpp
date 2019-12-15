/*
用拓展欧几里得算法求 a%m 的逆元，要求 a 和 m 互质 
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
    extgcd(a, m, x, y); //求得的x为一个解，但不一定是最小的
    return (x % m + m) % m; //也可以写为：if(x>=0) x=x%m; else x=x%m+m
}

int main()
{
	int a,m,ans;
	while(~scanf("%d %d",&a,&m))
	{
		ans=mod_inverse(a,m);
		printf("a%%m的逆元为:%d\n",ans);
	}
	return 0;
}
