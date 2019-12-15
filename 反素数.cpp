/*
dfs求不超过 n 的最小反素数（<=n且因子最多的数中最小的） 
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
{ //当前数；第dep个质因子；约数个数；质因子个数上限（剪枝） 
	if(sum>max)
	{//更新约数个数最大值及答案 
		max=sum;
		ans=num;
	}
	//如果约数个数相同，则保存最小的数 
	if(sum==max&&ans>num) ans=num;
	if(dep>16) return; //剪枝,当dep>9时数据>1e9,当dep>16时数据>1e18
	LL tmp=num;
	for(int i=1;i<=lmt;i++)
	{ //枚举当前质因子个数 
		if(n/pri[dep]<tmp) return; //n为上限，用除法防止溢出 
		tmp*=pri[dep];
		//lmt设为i是因为下一个质因子的个数<=当前质因子的个数
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
