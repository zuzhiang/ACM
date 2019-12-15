//��������ķ����ж�ĳ�������ǲ������� 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef long long LL;

LL modular_multi(LL x,LL y,LL mo)  
{  
    LL t;  
    x%=mo;  
    for(t=0;y;x=(x<<1)%mo,y>>=1)  
        if (y&1)  
            t=(t+x)%mo;  
    return t;  
}  
   
LL modular_exp(LL num,LL t,LL mo)  
{  
    LL ret=1,temp=num%mo;  
    for(;t;t>>=1,temp=modular_multi(temp,temp,mo))  
        if (t&1)  
            ret=modular_multi(ret,temp,mo);  
    return ret;  
}  
   
bool miller_rabin(LL n)  
{  
    if (n==2)return true;  
    if (n<2||!(n&1))return false;  
    int t=0;  
    LL a,x,y,u=n-1;  
    while((u&1)==0) t++,u>>=1;  
    for(int i=0;i<8;i++)  
    {  
        a=rand()%(n-1)+1;  
        x=modular_exp(a,u,n);  
        for(int j=0;j<t;j++)  
        {  
            y=modular_multi(x,x,n);  
            if (y==1&&x!=1&&x!=n-1)  
                return false;  
            ///�����õ����������ģn����1�ķ�ƽ��ƽ��������n�Ǻ�����  
            ///���һ����x���㷽��x^2��1 (mod n),��x�����ڶ�ģn��˵1��������ƽ����ƽ������1��-1����x�Ƕ�ģn��˵1�ķ�ƽ��ƽ����  
            x=y;  
        }  
        if (x!=1)///���ݷ���С����,��n����������a^(n-1)��1(mod n).���n������������  
            return false;  
    }  
    return true;  
}

int main()
{
	LL n;
	printf("������һ��������:\n");
	while(~scanf("%lld",&n))
	{
		if(miller_rabin(n)) printf("%lld������\n",n);
		else printf("%lld��������\n",n);
		printf("������һ��������:\n");
	}	
	return 0;
}

