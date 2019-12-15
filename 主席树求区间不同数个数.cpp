//bzoj 1878: �����䲻ͬ���ĸ��� (���޸�)
#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAXN 50010
using namespace std;

int tol;
//��tolֵ��ͬ����L��R��sum�ͱ�ʾͬһ���ڵ�
//LΪ��˵�ı�ţ�RΪ�Ҷ˵�ı�ţ�sum��ʾ����[L,R]�����ĸ���
int a[MAXN],T[MAXN],vis[1000010]; //T��¼ÿ��Ԫ�ض�Ӧ�ĸ��ڵ�
int L[MAXN*40],R[MAXN*40],sum[MAXN*40]; 

int build(int l,int r)
{ //����,������ʾ���Ҷ˵� 
	int root=tol++;
	sum[root]=0; //���������ĸ���Ϊ0
	if(l<r)
	{
		int mid=(l+r)>>1;
		L[root]=build(l,mid);   //����������������˵��Ŵ���L
		R[root]=build(mid+1,r); //���������������Ҷ˵��Ŵ���R
	}	
	return root;
}

int update(int pre,int pos,int val,int l,int r)
{ //���£���������һ�߶����ĸ��ڵ��ţ�λ�ã�ֵ�����Ҷ˵�
	int root=tol++;
	L[root]=L[pre]; //���������ǰ��һ���� 
	R[root]=R[pre]; //���������ǰ��һ����
	sum[root]=sum[pre]+val; //��ǰ�ڵ�һ�����޸�
	if(l<r)
	{
		int m=(l+r)>>1;
		if(m>=pos) L[root]=update(L[pre],pos,val,l,m); //���뵽������ 
		else R[root]=update(R[pre],pos,val,m+1,r); //���뵽������ 
	}	
	return root;
}

int query(int pre,int pos,int l,int r)
{
	//ֻ���ѯ����صĽڵ� 
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
