//http://www.cnblogs.com/pony1993/archive/2012/07/17/2594544.html
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100010

int tree[20][MAXN];   //表示每层每个位置的值 
int sorted[MAXN];     //已经排好序的数 
int toleft[20][MAXN]; //toleft[dep][i]表示第dep层从1到i有数分入左边 

void build(int l,int r,int dep)
{
	if(l==r) return;
	int i,ln,rn;
	int mid=(l+r)>>1;
	int same=mid-l+1; //表示等于中间值而且被分入左边的个数 
	for(i=l;i<=r;i++)//先假设左边的(mid-l+1)个数都等于中间值,然后把实际上小于中间值的减去
		if(tree[dep][i]<sorted[mid]) same--;
	ln=l;     //左子树开始的位置 
	rn=mid+1; //右子树开始的位置 
	for(i=l;i<=r;i++)
	{
		if(tree[dep][i]<sorted[mid]) tree[dep+1][ln++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0)
		{ //等于中位数的same个数放入左子树 
			tree[dep+1][ln++]=tree[dep][i];
			same--;
		}
		else tree[dep+1][rn++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+ln-l;
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}

//查询区间第k小的数，[L,R]为大区间,[l,r]是要查询的小区间 
int query(int L,int R,int l,int r,int dep,int k)
{
	if(l==r) return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//当前层当前区间划分到左子树的数的个数 
	int newl,newr;
	if(cnt>=k)
	{ //如果要查找的数被划分到了左子树，则去左子树查找
		newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		newr=newl+cnt-1;
		return query(L,mid,newl,newr,dep+1,k);
	}
	else
	{ //否则，去右子树查找
		newr=r+toleft[dep][R]-toleft[dep][r];
		newl=newr-(r-l-cnt);
		return query(mid+1,R,newl,newr,dep+1,k-cnt);
	 }
}

int main()
{
	int i,n,m,l,r,k,ans;
	while(~scanf("%d%d",&n,&m)) //n个数，m组询问 
	{
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++) 
		{ //下标必须从1开始 
			scanf("%d",&tree[0][i]);
			sorted[i]=tree[0][i];
		}
		sort(sorted+1,sorted+n+1);
		build(1,n,0);
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&k); 
			ans=query(1,n,l,r,0,k); //求区间[l,r]内的第k小的数
			//ans=query(1,n,l,r,0,r-l+2-k); //求区间[l,r]内的第k大的数
			printf("%d\n",ans);
		}
	}
	return 0;
}
