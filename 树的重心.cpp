/*
���壺
��������Ҳ���������ġ��ҵ�һ����,�����е����������������ڵ�������,��ô�������������������,ɾȥ���ĺ����ɵĶ����������ƽ�⡣


���ʣ�
1.�������е㵽ĳ����ľ�����У������ĵľ��������С�ģ�������������ģ���ô���ǵľ����һ����

2.��������ͨ��һ���������õ�һ���µ�������ô�µ���������������ԭ�������������ĵ�·���ϡ�

3.��һ������ӻ�ɾ��һ��Ҷ�ӣ���ô�����������ֻ�ƶ�һ���ߵľ��롣

���������ģ�����ж��������������ڵ�����С��һ��
˼·���� DFSѰ����ĳ���ڵ�Ϊ������������Ľڵ����ٵ�һ�� 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

int n,nd[20010];
int min_node,min_blc;
vector<int> T[20010];

int max(int a,int b)
{
	return a>b? a:b;
}

void dfs(int node,int pre)
{ //��������ǰ�ڵ㣬��ǰ�ڵ�ĸ��׽ڵ� 
	int i,son,max_num;
	nd[node]=1; //�Ե�ǰ�ڵ�Ϊ���������Ľڵ���� 
	max_num=0; //��������Ľڵ���� 
	for(i=0;i<T[node].size();i++)
	{ //�������ڵ�ÿ���ڵ� 
		son=T[node][i];
		if(son!=pre)
		{
			dfs(son,node); //�ݹ鴦�� 
			nd[node]+=nd[son]; //����ʱ���������Ľڵ��� 
			max_num=max(max_num,nd[son]);
		}
	}
	max_num=max(max_num,n-nd[node]);
	if(max_num<min_blc)
	{ //�ҵ���С����������Ľڵ�������� 
		min_blc=max_num;
		min_node=node;
	}
}

int main()
{
	int i,t,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) T[i].clear();
		for(i=0;i<n-1;i++)
		{ //���벢�������ı� 
			scanf("%d%d",&u,&v);
			T[u].push_back(v);
			T[v].push_back(u);
		}
		min_node=0; //��С�ĸ��ڵ� 
		min_blc=0x3f3f3f3f; //��������ڵ����Сֵ 
		dfs(1,0);
		printf("%d %d\n",min_node,min_blc);
	}
	return 0;
}
