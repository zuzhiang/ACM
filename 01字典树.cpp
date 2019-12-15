/*
01字典树主要用于解决求异或最值的问题.
HDU 5536: 在一个数组中找出 (s[i]+s[j])^s[k] 最大的值，其中 i、j、k 各不相同。
先两层循环求出不同两数的和，然后在剩余的数中用 01字典树求与它们的和异或最大的结果值。
我们可以在查询 x 和 y 的和之前，先把 x 和 y 在 01字典树中去除，
可以增加一个数组 num，用来记录每个节点被访问的次数，每次改变节点的访问次数即可。 
*/
#include<stdio.h>
#include<iostream>
#define MAXN 1010
typedef long long LL;
using namespace std;

int tol; //节点编号 
LL val[32*MAXN]; //点的值 
int num[32*MAXN]; //每个节点被访问的次数
int ch[32*MAXN][2]; //边指向的节点编号 

void init()
{ //初始化 
    tol=1;
    ch[0][0]=ch[0][1]=0;
}

void insert(LL x)
{ //往 01字典树中插入 x 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        if(!ch[u][v])
        { //如果点未被访问过，则创建 
            ch[tol][0]=ch[tol][1]=0; //边值为0表示不指向任何节点
            val[tol]=0; //点值为0表示到此不是一个数 
            num[tol]=0; //每个节点被访问的次数
            ch[u][v]=tol++; //边指向的节点编号 
        }
        u=ch[u][v]; //下一节点 
        num[u]++; //每个节点被访问的次数+1
    }
    val[u]=x; //点值
}

void update(LL x,int add)
{ //更新插入或删除 x后每个节点被访问的次数 
	int u=0;
	for(int i=32;i>=0;i--)
	{
		int v=(x>>i)&1;
		u=ch[u][v];
		num[u]+=add;
	}
}

LL query(LL x)
{ //查询所有数中和 x异或结果的最大值 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        //利用贪心策略，优先寻找和当期位不同的点 
        if(ch[u][v^1]&&num[ch[u][v^1]]) u=ch[u][v^1];
        else u=ch[u][v];
    }
    return x^val[u]; //返回结果
}

int main()
{
	int i,j,t,n;
	LL a[MAXN],ans;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			insert(a[i]);
		}
		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(i==j) continue;
				update(a[i],-1);
				update(a[j],-1);
				ans=max(ans,query(a[i]+a[j]));
				update(a[i],1);
				update(a[j],1);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
