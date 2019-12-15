//bzoj 1878: 求区间不同数的个数 (无修改)
#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAXN 50010
using namespace std;

int tol;
//若tol值相同，则L、R、sum就表示同一个节点
//L为左端点的编号，R为右端点的编号，sum表示区间[L,R]内数的个数
int a[MAXN],T[MAXN],vis[1000010]; //T记录每个元素对应的根节点
int L[MAXN*40],R[MAXN*40],sum[MAXN*40]; 

int build(int l,int r)
{ //建树,参数表示左右端点 
	int root=tol++;
	sum[root]=0; //区间内数的个数为0
	if(l<r)
	{
		int mid=(l+r)>>1;
		L[root]=build(l,mid);   //构造左子树并将左端点编号存入L
		R[root]=build(mid+1,r); //构造右子树并将右端点编号存入R
	}	
	return root;
}

int update(int pre,int pos,int val,int l,int r)
{ //更新，参数：上一线段树的根节点编号，位置，值，左右端点
	int root=tol++;
	L[root]=L[pre]; //先让其等于前面一颗树 
	R[root]=R[pre]; //先让其等于前面一颗树
	sum[root]=sum[pre]+val; //当前节点一定被修改
	if(l<r)
	{
		int m=(l+r)>>1;
		if(m>=pos) L[root]=update(L[pre],pos,val,l,m); //插入到左子树 
		else R[root]=update(R[pre],pos,val,m+1,r); //插入到右子树 
	}	
	return root;
}

int query(int pre,int pos,int l,int r)
{
	//只会查询到相关的节点 
	if(l==r) return sum[pre];
	int m=(l+r)>>1;
	if(m>=pos) return sum[R[pre]]+query(L[pre],pos,l,m);
	else return query(R[pre],pos,m+1,r);	
}

int main()
{
	int i,n,m,v,x,y,ans;
	tol=1;
	scanf("%d",&n);
	memset(vis,-1,sizeof(vis));
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	T[0]=build(1,n);
	for(i=1;i<=n;i++)
	{
		v=a[i];
		if(vis[v]==-1) T[i]=update(T[i-1],i,1,1,n);
		else
		{
			int t=update(T[i-1],vis[v],-1,1,n);
			T[i]=update(t,i,1,1,n);
		}
		vis[v]=i;
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		ans=query(T[y],x,1,n);
		printf("%d\n",ans);
	}
	return 0;
}
