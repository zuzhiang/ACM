/*
假设同余方程组为：
	x=r1(mod a1)
	x=r2(mod a2)
	………………
	x=rn(mod an)

其中不要求 r 两两互素 
求此方程组小于m的非负整数解代码：
*/
#include<stdio.h>
#include<string.h>
typedef long long LL;

LL n,a[100010],r[100010];

LL exGcd(LL a,LL b,LL &x,LL &y)
{
    LL r,t;
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    r=exGcd(b,a%b,x,y);
    t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

LL solve()
{
	LL i,c,d,t,x,y;
	for(LL i=1;i<n;i++) 
	{
		c=r[i]-r[i-1];
		d=exGcd(a[i-1],a[i],x,y);
		if(c%d!=0) return -1; //无解
		t=a[i]/d;
		x=x*(c/d);
		x=(x%t+t)%t;
		r[i]=a[i-1]*x+r[i-1];
		a[i]=a[i-1]*(a[i]/d);
	}
	return r[n-1];
}

int main()
{
	LL i,j,ans;
	scanf("%lld",&n);
	for(i=0;i<n;i++) scanf("%lld%lld",&a[i],&r[i]);
	ans=solve();
	printf("%lld\n",ans);
	return 0;
}
