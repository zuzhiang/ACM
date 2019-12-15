/*
ŷ�������� a%m ����Ԫ��Ҫ�� a��m ���� 
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
        if(b&1) r=r*base%mod;// n & 1 �ȼ��� (n % 2) == 1������ǰλΪ1ʱ�����в���    
        base=base*base%mod;//�൱����base^2n�η�
        b>>=1; // n >>= 1 �ȼ��� n /= 2,�������Ƶ�b����һλ
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
		printf("a%%m����ԪΪ:%d\n",ans);
	}	
	return 0;
}
