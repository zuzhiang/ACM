//https://www.2cto.com/kf/201502/377019.html
/*
Floyd�㷨������ͼ��С���������ڸ���������
��С��������ͼ��Ȩֵ��С�Ļ� 
HDU 1599: ������ͼ�������������С��,���������С���� 
*/
#include<stdio.h>
#include<string.h>
#define MAXN 105
#define inf 0x3f3f3f3f

int n,m,tol;
int dis[MAXN][MAXN],map[MAXN][MAXN];
//pre[i][j]��ʾ·��i-j�ϣ�j��ǰ����path��¼��С��
int pre[MAXN][MAXN],path[MAXN];

int min(int a,int b)
{
	return a<b?a:b;
}

void init()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			map[i][j]=inf;
			dis[i][j]=inf;
			pre[i][j]=i;
		}			
}

int floyd()
{
	int i,j,k,p,min;
	min=inf;
	for(k=1;k<=n;k++)
	{
		//�� 
		for(i=1;i<k;i++)
		for(j=1;j<i;j++)
			if(dis[i][j]!=inf&&map[j][k]!=inf&&map[k][i]!=inf
			&&dis[i][j]+map[i][k]+map[k][j]<min)
			{
				min=dis[i][j]+map[i][k]+map[k][j];
				tol=0;
				p=j;
				while(p!=i)
				{
					path[tol++]=p;
					p=pre[i][p];
				}
				path[tol++]=i;
				path[tol++]=k;
			}
		//�����· 
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(dis[i][k]!=inf&&dis[k][j]!=inf
			&&dis[i][k]+dis[k][j]<dis[i][j])
			{
				dis[i][j]=dis[i][k]+dis[k][j];
				pre[i][j]=pre[k][j];
			}				
	}
	return min;
}

int main()
{
	int i,u,v,w,ans;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			w=min(map[u][v],w); //�������ܶ����� 
			map[u][v]=w;
			map[v][u]=w;
			dis[u][v]=w;
			dis[v][u]=w;
		}
		tol=0;
		ans=floyd();
		if(ans==inf) printf("It's impossible.\n");
		else 
		{
			printf("%d\n",ans);
			//���·�� 
			//for(i=0;i<tol;i++) printf("%d%c",path[i],i==tol-1?'\n':' ');
		}		
	}
	return 0;
}
/*
3 3
1 2 1
2 3 1
1 3 1
3 3
1 2 1
1 2 3
2 3 1
*/
