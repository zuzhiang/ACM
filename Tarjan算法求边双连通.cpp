//Tarjan�㷨���ż����еı�˫��ͨ�������ж�����֮���Ƿ����� 
//���㷨��Tarjan��ǿ��ͨ�����㷨����һ����ֻ�Ƕ���v!=pre���ж� 
/*
��˫��ͨͼ�Ķ���ȼ�������һ����������һ���򵥻���
��˫��ͨ�ļ�����ͼ��Ϊ��˫��ͨ����
�Ų����κ�һ����˫��ͨ������
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#define MAXN 50010
#define MAXM 50010
using namespace std;

int n,m,cnt,index; //cnt��˫��������indexʱ��� 
int vis[MAXN]; //��¼���Ƿ���ջ�� 
//dfn��¼�ڵ�ı�����ʱ�䣨ʱ�����
//low��¼�õ�����������Ϊ���������ܹ�׷�ݵ������ջ�нڵ�Ĵ���
int dfn[MAXN],low[MAXN];
int belong[MAXN],bridge[MAXN]; //�����ĸ���˫����¼�� 
vector<int> mp[50010];
stack<int> st;

void init()
{
	int i;
	cnt=index=0;
	memset(dfn,-1,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;i++)
		mp[i].clear();		
}

void Tarjan(int u,int pre)
{
	int i,v;
	dfn[u]=low[u]=++index;
	st.push(u);
	vis[u]=1;
	for(i=0;i<mp[u].size();i++)
	{ //������u���ڵĽڵ� 
		v=mp[u][i];
		if(dfn[v]==-1)
		{ //���û�����ʹ�,������!vis[v]��vis��ʾ�Ƿ���ջ��
			Tarjan(v,u); //�ݹ鴦�� 
			if(low[v]<low[u]) low[u]=low[v]; //��ǿ��ͨ���������нڵ�lowֵ��Ϊ���ڵ��dfnֵ			
		}		
		else if(vis[v]&&v!=pre)
		{ //������ʹ���������ջ�У��������ڻ�
			if(dfn[v]<low[u]) low[u]=dfn[v];
		}
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		while(u!=v)
		{
			v=st.top();
			st.pop();
			vis[v]=0;
			belong[v]=cnt; //�ڵ�v���ڵ�cnt��ǿ��ͨ����
		}
	}
}

void solve()
{
	int i;
	for(i=1;i<=n;i++) //���û�����ʹ���Ӹõ㿪ʼ������ֹ�е���©
		if(dfn[i]==-1) Tarjan(i,-1);
}

int main()
{
	int i,q,u,v;
	scanf("%d%d",&n,&m);	
	init();
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	solve();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&u,&v);
		if(belong[u]==belong[v]) printf("Yes\n"); //�����ͬһ��˫�������� 
		else printf("No\n");
	}
	return 0;
}
