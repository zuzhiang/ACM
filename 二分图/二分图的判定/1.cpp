//����ͼGΪ����ͼ�ĳ�ֱ�Ҫ�����ǣ�G�������������㣬�������л�·�ĳ��Ⱦ�Ϊż����
#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;

int col[1000],g[1000][1000];
//col������Ϳɫ���飬ֵΪ0��1 �������ֲ�ͬ��ɫ��g[i][j] ��¼i��j�ڵ�֮���б� 

int bfs(int s,int n)
{
	int i,u;
	queue<int> Q;
	Q.push(s);
	col[s]=1;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
		{
			if(col[i]==-1 && g[u][i])
			{ //��ǰ����ûͿɫ��������u��ͨ
				col[i]=!col[u]; //Ϳ�ɺ�u�ڵ��෴����ɫ 
				Q.push(i);
			}
			if(g[u][i] && col[i]==col[u]) return 0; //����Ѿ�Ϳɫ�ĵ���u��ͨ����ɫ��ͬ���Ƕ���ͼ
		}
	}
	return 1;
}

int main()
{
	int i,n,m,u,v,flag; //nΪ�������,mΪ�ߵĸ���,��ı�Ŵ�1~n
	scanf("%d %d",&n,&m);
	memset(col,-1,sizeof(col)); //��ÿ���������ɫͿΪ-1������û��Ϳɫ 
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); //����ߵ������˵�
		g[u][v]=g[v][u]=1;
	}
	flag=1;
	for(i=1;i<=n;i++)
		if(col[i]==-1 && !bfs(i,n))
		{ //����ö���û��Ϳɫ����������ڵ���ͨ��֧����bfsͿɫ��������Ƕ���ͼ���־�˳�
			flag=0;
			break;
		}
	if(!flag) printf("NO\n");
	else printf("YES\n");
	return 0;
}
