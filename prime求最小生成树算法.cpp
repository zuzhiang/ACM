/*
prime����С�������㷨
ԭ��:�Ե���в�������ѡһ���㿪ʼ�����Ѽӵ���ѡȡȨֵ��С�ıߣ�
�������ɻ�·����롣 
*/
#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
#define MAX 1000

int n,m,map[MAX][MAX];

int prime()
{
	int i,j;
	int cur,pos,sum,min;
    int vis[MAX],dis[MAX]; //dis[i]Ϊ���ڵ㵽i�ڵ�ľ��� 
    cur=1; //��ѡһ�ڵ�Ϊ���ڵ� 
    sum=0; //�ܻ��� 
    memset(vis, 0, sizeof(vis));
    vis[cur] = 1;
    //nΪ�ڵ�ĸ��� 
    for(i=1;i<=n;i++) dis[i]=map[cur][i];
    for(i=0;i<n-1;i++)
	{ //ѭ��n-1��
        min = INF;
        for(j=1;j<=n;j++)
		{ //����δ���ʵĽڵ�
            if(!vis[j] && dis[j]<min)
			{
                min=dis[j];    //��¼��С����
                pos=j;    	   //��¼�±�
            }
        }
        vis[pos]=1;      //��С������־���ʹ�
        sum+=min;  	     //�ܻ��Ѿ�������        
        for(j=1;j<=n;j++)
		{
            if(!vis[j] && dis[j]>map[pos][j])
                dis[j]=map[pos][j];
        }    
    } 
    return sum;    	//�����ܻ��Ѿ���
}

int main()
{
	int i,j,t,u,v,w,ans;
	scanf("%d",&t);
	while(t--)
	{		
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++) map[i][j]=INF;				
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]=w;
			map[v][u]=w;
		}
		ans=prime();
		printf("%d\n",ans);
	}
	return 0;
}
