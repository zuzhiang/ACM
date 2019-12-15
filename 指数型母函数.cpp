//http://www.wutianqi.com/?p=2644
/*
例题:HDU 1521  //从n个有重复的物品中取出m个的排列数 
普通型母函数主要是来求组合的方案数，而指数型母函数是求多重排列数

指数型母函数问题：
假设有8个元素，其中a1重复3次，a2重复2次，a3重复3次。从中取r个组合，求其组合数。

指数型母函数的计算过程就是模拟手算多项式乘法的过程
*/
#include<stdio.h>
#include<string.h>
#define MAXN 111
typedef long long LL;

int num[12];
double c1[MAXN],c2[MAXN],factor[12];

void init()
{ //预处理阶乘 
	int i;
	factor[0]=1;
	for(i=1;i<12;i++) factor[i]=factor[i-1]*i;
}

void mu(int n,int m)
{ //n是物品种类，m是每种物品的数量 
	int i,j,k;
	memset(c1,0,sizeof(c1)); //c1[i]存储的是前i项相乘的最终结果 
	memset(c2,0,sizeof(c2)); //c2[i]存储的是前i项相乘的中间结果 
	for(i=0;i<=num[1];i++) //先算出第一个括号汇中各项的系数
		c1[i]=1/factor[i]; //这里省略了x，x对应的指数就是i 
	for(i=2;i<=n;i++)
	{ //计算前i项相乘的结果 
		for(j=0;j<=m;j++)  //最多只能选m个物品 
			for(k=0;k<=num[i]&&k+j<=m;k++)
				c2[j+k]+=c1[j]/factor[k];
		for(j=0;j<=m;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
}

//对于一个值 y*x^i/(n!) ,其中n是种类n，i和n的值应该是相等的，y是形成种类n的排列的方式数 
int main()
{
	int i,j,m,n,a[11];
	double ans;
	init();
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&num[i]);		
		mu(n,m);
		ans=c1[m]*factor[m];
		printf("%.0lf\n",ans);
	}
	return 0;
}
