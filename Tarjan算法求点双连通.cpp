//Tarjan�㷨���㼰���еĵ�˫��ͨ���� 
/*
��˫��ͨͼ�Ķ���ȼ������������߶�ͬ��һ���򵥻���
˫��ͨ�ļ�����ͼ��Ϊ��˫��ͨ����
����һ�����������������˫��ͨ�Ĺ�����
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector> 
#define MAXN 5010
using namespace std;

int n,m;
int index,dgr[MAXN]; //indexΪ����ÿ���ڵ��ʱ�䣬dgr��¼ÿ����Ķ� 
int dfn[MAXN],low[MAXN];
vector<int> mp[MAXN];
stack<int> st;

void Tarjan(int u,int pre)
{
	int i,v;
	dfn[u]=low[u]=++index;
	st.push(u);
	for(i=0;i<mp[u].size();i++)
	{ //�������е��ڱ� 
		v=mp[u][v];
		if(v==pre) continue;
		if(!dfn[v])
		{
			Tarjan(v,u);
			if(low[v]<low[u]) low[u]=low[v];
			if(dfn[u]<=low[v])
			{ //ջ��u��u���ϵ�Ԫ�ع���һ����˫��ͨ���� 
				while(u!=v)
				{
					v=st.top();
					st.pop();
					dgr[v]++;
				}
				st.push(u); //��u��ջ������ȱ�� 
			}
		}
		else if(dfn[v]<low[u]) low[u]=dfn[v];
	}
}

void solve()
{
	int i;
	index=0;
	memset(dfn,0,sizeof(dfn));
	memset(dgr,0,sizeof(dgr));
	for(i=1;i<=n;i++)
		if(!dfn[i]) Tarjan(i,-1);
}

int main()
{
	int i,u,v;	
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		solve();
		printf("����У�\n");
		for(i=1;i<=n;i++)
			if(dgr[i]>1) printf("%d ",i);
		printf("\n");
	}
	return 0;
}
/*
7 8
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7

5 5
1 2
2 3
3 4
4 5
5 1

6 7
1 2
1 3
2 3
3 4
4 5
4 6
5 6
*/
