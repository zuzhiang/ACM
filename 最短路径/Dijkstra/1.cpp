/*
dijkstra�㷨Ϊ��Դ���·���㷨�����ɴ���Ȩ
ԭ��:���ڵ��Ϊ���飬������ĺ�δ����ġ���ʼʱֻ�е�ǰ�ڵ��Ѵ���
���ϵĴ�δ����Ľڵ���ѡ��һ���뵱ǰ�ڵ��·����̵ģ����뵽�Ѵ���
�ڵ��С�Ȼ��������ڵ�ȥ����δ����ڵ��·���������ظ�������̣�ֱ��
�ڵ�ȫ�������ꡣ 
*/
#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f

int n,m;
int dis[101],vis[101],mp[101][101];

int dijkstra(int v) 
{
	int i,j,min,pos;
	memset(vis,0,sizeof(vis)); //ȫ���Ϊδ����	
	for(i=1;i<=n;i++)  //dis[i]��ʾ��ǰ�ڵ���i��·�����ȣ���ʼ��Ϊ��� 
		dis[i]=mp[v][i];
    dis[v]=0;
	vis[v]=1;
	//�㷨���Ĵ���
	for(i=1;i<n;i++)
	{ //����n-1�δ��� 
		min=inf;
		for(j=1;j<=n;j++) //Ѱ��δ����ĵ���·����̵� 
			if(!vis[j] && dis[j]<min)
			{
				min=dis[j];
				pos=j;
			}
		vis[pos]=1;
		for(j=1;j<=n;j++) //�øýڵ��������δ����ڵ�����·�� 
			if(!vis[j]&&dis[j]>dis[pos]+mp[pos][j])
					dis[j]=dis[pos]+mp[pos][j];			
	}
}

int main()
{
	int i,j,u,v,w;
	scanf("%d %d",&n,&m);
	//��ʼ��mp���� 
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			mp[i][j]=inf;
	for(i=1;i<=n;i++)
		mp[i][i]=0;
	for(i=0;i<m;i++)
	{ //����u��v����֮��ľ���w 
		scanf("%d %d %d",&u,&v,&w);
		mp[u][v]=w;
	}    
	dijkstra(1);
    //���
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	printf("\n");
	return 0;
}

/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
