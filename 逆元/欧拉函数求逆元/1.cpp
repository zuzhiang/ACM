/*
欧拉定理求 a%m 的逆元，要求 a、m 互质 
*/
#include<stdio.h>

int euler(int n)
{
    int ret=1,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
        	n=n/i;
	    	ret*=i-1;
            while(n%i==0)
		    { 
		        n=n/i;
				ret*=i;
			}
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}

int pow (int a,int b,int mod)
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b&1) r=r*base%mod;// n & 1 等价于 (n % 2) == 1，当当前位为1时，进行操作    
        base=base*base%mod;//相当于求base^2n次方
        b>>=1; // n >>= 1 等价于 n /= 2,将二进制的b右移一位
    }
    return r;
}

int main()
{
	int a,m,n,ans;
	while(~scanf("%d %d",&a,&m))
	{
		n=euler(m);
		ans=pow(a,n-1,m);
		printf("a%%m的逆元为:%d\n",ans);
	}	
	return 0;
}
