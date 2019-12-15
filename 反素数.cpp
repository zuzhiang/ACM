/*
dfs�󲻳��� n ����С��������<=n����������������С�ģ� 
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long LL;

int max;
LL n,ans;
int pri[18]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

void dfs(LL num,int dep,int sum,int lmt)
{ //��ǰ������dep�������ӣ�Լ�������������Ӹ������ޣ���֦�� 
	if(sum>max)
	{//����Լ���������ֵ���� 
		max=sum;
		ans=num;
	}
	//���Լ��������ͬ���򱣴���С���� 
	if(sum==max&&ans>num) ans=num;
	if(dep>16) return; //��֦,��dep>9ʱ����>1e9,��dep>16ʱ����>1e18
	LL tmp=num;
	for(int i=1;i<=lmt;i++)
	{ //ö�ٵ�ǰ�����Ӹ��� 
		if(n/pri[dep]<tmp) return; //nΪ���ޣ��ó�����ֹ��� 
		tmp*=pri[dep];
		//lmt��Ϊi����Ϊ��һ�������ӵĸ���<=��ǰ�����ӵĸ���
		dfs(tmp,dep+1,sum*(i+1),i);
	}
}

int main()
{
	while(~scanf("%lld",&n))
	{
		max=0;
		ans=inf;
		int x=(int)log2(n);
		dfs(1,1,1,x);
		printf("%lld\n",ans);
	}
	return 0;
}
