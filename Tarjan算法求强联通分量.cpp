//http://blog.csdn.net/acmmmm/article/details/16361033
//https://www.cnblogs.com/tgycoder/p/5048898.html
/*
���ӵ��������޸��ӹ�ϵ�ı�Ϊ���ߣ�����һ������������
���ӵ��������и��ӹ�ϵ�ı�Ϊ����ߣ���һ���ɺ���߲���
ǿ��ͨ�����������ɻ���ɵ� 
ǿ��ͨ����һ����DFS��һ��������
ǿ��ͨ����������������ǽ��������µ�����ͼ��Ϊ�����޻�ͼ
*/
#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

#define MAXN 100

int n,m;
//dfn��¼�ڵ�ı�����ʱ�䣨ʱ�����
//low��¼�õ�����������Ϊ���������ܹ�׷�ݵ������ջ�нڵ�Ĵ���
int dfn[MAXN],low[MAXN];
//vis����Ƿ���ջ�У�numΪÿ��ǿ��ͨ�����Ľڵ�����belong��ǽڵ����ڵڼ���ǿ��ͨ����
int vis[MAXN],num[MAXN],belong[MAXN]; 
int cnt,index; //cntΪǿ��ͨ�����ĸ�����indexΪ�ڵ���ʵı�ţ�ÿ���ڵ㲻ͬ�� 
stack<int> s;
vector<int> map[MAXN];

void tarjan(int u)
{ 
	int i,v;
 	dfn[u]=low[u]=++index; //�µ��ʼ�� 
	s.push(u); //��ջ 
	vis[u]=1;  //�����ջ�� 
	for(i=0;i<map[u].size();i++)
	{ //������u���ڵĽڵ� 
		v=map[u][i];
		if(!dfn[v])
		{ //���û�����ʹ�,������!vis[v]��vis��ʾ�Ƿ���ջ�� 
			tarjan(v); //�ݹ鴦�� 
			if(low[v]<low[u]) low[u]=low[v]; //��ǿ��ͨ���������нڵ�lowֵ��Ϊ���ڵ��dfnֵ 
		}
		//������ʹ���������ջ�У��������ڻ�
		else if(vis[v]&&dfn[v]<low[u]) low[u]=dfn[v];	
	}
	if(dfn[u]==low[u])
	{ //�����ǿ��ͨ������������С������ʱջ��u֮�ϵ�Ԫ�ع�����һ��ǿ��ͨ���� 
		cnt++; //��cnt��ǿ��ͨ���� 
		printf("��ͨ���� %d:",cnt);
		while(u!=v)
		{ //��� Ҳ���Կ���vector����洢һ�� 
			v=s.top();
			printf(" %d",v);
			s.pop();
			vis[v]=0; //��ǲ���ջ�� 
			belong[v]=cnt; //�ڵ�v���ڵ�cnt��ǿ��ͨ���� 
			num[cnt]++;
		}
		printf("\n");
	}
}

void solve()
{
	int i;
	cnt=0;
	index=0;
	memset(dfn,0,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	for(i=1;i<=n;i++) //���û�����ʹ���Ӹõ㿪ʼ������ֹ�е���© 
		if(!dfn[i]) tarjan(i);
}

vector<int> mp[MAXN];   //������ǿ��ͨ�����γɵ���ͼ 
int chu[MAXN],ru[MAXN]; //���Ⱥ���� 

void suodian(int n)
{ //���㺯��������nΪ�ڵ���� 
	int i,j,u,v;
	memset(chu,0,sizeof(chu));
	memset(ru,0,sizeof(ru));
	for(i=1;i<=n;i++)
	{ //ɨ��ÿ���ڵ� 
		u=belong[i];   //ԭ��������ڵ�ǿ��ͨ���� 
		for(j=0;j<map[i].size();j++)
		{ //ÿ���ڵ�����ڽڵ� 
			v=belong[map[i][j]]; //ԭ���յ����ڵ�ǿ��ͨ���� 
			if(u!=v)
			{ //�������ͬһǿ��ͨ������ 
				mp[u].push_back(v); //�γ���ͼ 
				chu[u]++;
				ru[v]++;
			}
		}		
	}
}

int main()
{
	int i,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			map[u].push_back(v);
		}
		solve();
		for(i=1;i<=n;i++) printf("%d ",belong[i]);
		printf("\n");
		suodian(n); //���� 
	}
	return 0;
}
/*
6 8
1 3
1 2
2 4
3 5
3 4
4 1
4 6
5 6
*/
