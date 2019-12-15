//http://www.cnblogs.com/pony1993/archive/2012/07/17/2594544.html
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100010

int tree[20][MAXN];   //��ʾÿ��ÿ��λ�õ�ֵ 
int sorted[MAXN];     //�Ѿ��ź������ 
int toleft[20][MAXN]; //toleft[dep][i]��ʾ��dep���1��i����������� 

void build(int l,int r,int dep)
{
	if(l==r) return;
	int i,ln,rn;
	int mid=(l+r)>>1;
	int same=mid-l+1; //��ʾ�����м�ֵ���ұ�������ߵĸ��� 
	for(i=l;i<=r;i++)//�ȼ�����ߵ�(mid-l+1)�����������м�ֵ,Ȼ���ʵ����С���м�ֵ�ļ�ȥ
		if(tree[dep][i]<sorted[mid]) same--;
	ln=l;     //��������ʼ��λ�� 
	rn=mid+1; //��������ʼ��λ�� 
	for(i=l;i<=r;i++)
	{
		if(tree[dep][i]<sorted[mid]) tree[dep+1][ln++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid]&&same>0)
		{ //������λ����same�������������� 
			tree[dep+1][ln++]=tree[dep][i];
			same--;
		}
		else tree[dep+1][rn++]=tree[dep][i];
		toleft[dep][i]=toleft[dep][l-1]+ln-l;
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}

//��ѯ�����kС������[L,R]Ϊ������,[l,r]��Ҫ��ѯ��С���� 
int query(int L,int R,int l,int r,int dep,int k)
{
	if(l==r) return tree[dep][l];
	int mid=(L+R)>>1;
	int cnt=toleft[dep][r]-toleft[dep][l-1];//��ǰ�㵱ǰ���仮�ֵ������������ĸ��� 
	int newl,newr;
	if(cnt>=k)
	{ //���Ҫ���ҵ��������ֵ�������������ȥ����������
		newl=L+toleft[dep][l-1]-toleft[dep][L-1];
		newr=newl+cnt-1;
		return query(L,mid,newl,newr,dep+1,k);
	}
	else
	{ //����ȥ����������
		newr=r+toleft[dep][R]-toleft[dep][r];
		newl=newr-(r-l-cnt);
		return query(mid+1,R,newl,newr,dep+1,k-cnt);
	 }
}

int main()
{
	int i,n,m,l,r,k,ans;
	while(~scanf("%d%d",&n,&m)) //n������m��ѯ�� 
	{
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++) 
		{ //�±�����1��ʼ 
			scanf("%d",&tree[0][i]);
			sorted[i]=tree[0][i];
		}
		sort(sorted+1,sorted+n+1);
		build(1,n,0);
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&k); 
			ans=query(1,n,l,r,0,k); //������[l,r]�ڵĵ�kС����
			//ans=query(1,n,l,r,0,r-l+2-k); //������[l,r]�ڵĵ�k�����
			printf("%d\n",ans);
		}
	}
	return 0;
}
