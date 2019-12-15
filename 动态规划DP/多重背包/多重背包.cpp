//转换为01背包和完全背包求解，速度最快，复杂度O(V*Σlog n[i])
#include<stdio.h>
#include<string.h>

int n,v,dp[50001]; //物品数量和背包容量 

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

//01背包，当前物品价格、重量 
void  ZOP(int prz,int wt)
{
	int j;
	for(j=v;j>=wt;j--)
		dp[j]=max(dp[j],dp[j-wt]+prz);
}

//完全背包，当前物品价格、重量 
void CP(int prz,int wt) 
{
	int j;
	for(j=wt;j<=v;j++)
		dp[j]=max(dp[j],dp[j-wt]+prz);
}

//多重背包，当前物品价格、重量、数量 
void MP(int prz,int wt,int cnt) 
{
	//如果放不下全部，则转化为完全背包求解 
	if(wt*cnt>=v) CP(prz,wt); 
	else //否则，转化为01背包求解 
	{ //将cnt个相同物品分多组，每组1，2，4，8…个
	  //类似于倍增法，最后剩下的可能不是2的次幂 
		int k=1;
		while(k<cnt)
		{ //k个物品的价值和重量分别为 k*prz,k*wt
			ZOP(k*prz,k*wt);
			cnt-=k;
			k<<=1;
		}
		if(cnt>0) ZOP(cnt*prz,cnt*wt);
	}
}

int main()
{
	int i,j,k,w[105],p[105],c[105];
	scanf("%d%d",&n,&v);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&w[i],&p[i],&c[i]);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
		MP(p[i],w[i],c[i]);
	printf("%d\n",dp[v]);
	return 0;
}


