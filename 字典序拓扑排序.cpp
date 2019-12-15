/*
���ֵ����С�����������������������
 
˼·���ȶ�����Ԫ�ش�С��������Ȼ�����õݹ�ӽ���ĵ�1λ��ʼ
ѭ��Ѱ�����Ϊ0�Ľڵ㣬ʹ�����-1�������ǰλ��Ϊ��ǰֵ������
���������Ľڵ�����-1��Ȼ��ݹ�����һ��λ����������ǰ·������
��Ϻ�ȡ����ǰ�ڵ��Ӱ�졣
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100

int n,m,ans[MAXN]; //nΪ�ڵ������mΪ������ans�洢��� 
int a[MAXN],dgr[MAXN],map[MAXN][MAXN]; //a�洢�ڵ㣬dgr�洢��ȣ�map[i][j]��ʾ�д�i��j�ı� 

void solve(int depth)
{
	int i,j;
	if(depth==n)
	{ //������Ϊn���Ѿ������ֱ꣬�������� 
		for(i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	for(i=0;i<n;i++) //���ֵ��������Ϊ0�Ľڵ� 
		if(dgr[a[i]]==0) 
		{ //�����ǰ�ڵ����Ϊ0 
			dgr[a[i]]--; //���-1�����治�ڴ��� 
			ans[depth]=a[i]; //�����ǰλ��Ϊa[i] 
			for(j=0;j<n;j++) //����ǰ�ڵ�ĺ�����-1 
				if(map[a[i]][a[j]]) dgr[a[j]]--;
			solve(depth+1); //�ݹ鴦����һ��λ�� 
			dgr[a[i]]++; //ȡ����ǰ�ڵ��Ӱ�� 
			for(j=0;j<n;j++)
				if(map[a[i]][a[j]]) dgr[a[j]]++;
		}
}

int main()
{
	int i,j,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n); //����С�������� 
		memset(map,0,sizeof(map));
		memset(dgr,0,sizeof(dgr));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=1;
			dgr[v]++;
		}
		solve(0);
	}
	return 0;
}

/*
8 9
1 5 8 4 6 2 7 3
1 2
1 3
1 4
2 5
3 6
4 7
5 8
6 8
7 8

4 2
1 2 6 7
1 2
2 6

5 4
1 2 3 4 5
1 4
3 1
5 1
2 1
*/
