/*
SPFA�㷨Ϊ��Դ���·�㷨���ɴ���Ȩ��
ԭ��������BF�㷨���Ż���ֻ����Щ��ǰһ���ɳ��иı���
�������ֵ�ĵ�,�ſ����������ǵ��ڽӵ�ľ������ֵ�ĸı䡣 
�жϸ�Ȩ��·����¼ÿ�������Ӵ���,����n�α�ʾ�и�Ȩ�� 

����±��1��ʼ 
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

#define inf 0x3f3f3f3f

int dis[100]; //��¼Դ�㵽�ýڵ�ľ���
int vis[100]; //��־�ýڵ��Ƿ��ڶ�����
int num[100]; //��¼�ýڵ���ӵĴ���
int mp[100][100]; //���ڽӱ�洢����֮��ľ���

int SPFA(int v,int n)
{//������Դ�� / ��ĸ��� 
	int i,q;
	//��ʼ��dis����
	for(i=0;i<=n;i++) dis[i]=inf;
	dis[v]=0;
    //��ʼ��vis�����num����
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));	
	priority_queue<int,vector<int>,greater<int> > Q; //�����ȶ��н����Ż�
	Q.push(v); //��Դ�����
	vis[v]=1;  //��־Դ���ڶ�����
	num[v]++;  //Դ����Ӵ���+1
	while(!Q.empty())
	{
		q=Q.top();
		Q.pop();
		vis[q]=0;  //��־����Ԫ��q���ڶ�����
		for(i=1;i<=n;i++) //�Ժ�q�ڵ����ڵĽڵ����ɨ��
			if(dis[q]+mp[q][i]<dis[i]) //���Դ�㵽q�ڵ�ľ���+q�ڵ㵽i�ڵ�ľ���<Դ�㵽i�ڵ�ľ���
			{
				dis[i]=dis[q]+mp[q][i]; //�����ɳڲ���
				if(!vis[i])       //�����ǰ�ڵ�i���ڶ�����
				{
					Q.push(i);    //����ǰ�ڵ�i���
					num[i]++;     //��ǰ�ڵ�i��Ӵ���+1
					vis[i]=1;     //��־�ڶ�����
					if(num[i]>n) return 0;  //�����Ӵ������ڽڵ��ܸ�������˵�����ڸ�Ȩ��·
				}
			}
	}
	return 1;
}

int main()
{
	int i,j,n,m,u,v,w,flag;	
	while(~scanf("%d %d",&n,&m))  //����ĸ����ͱߵ�����
	{
		//��ʼ��mp����
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mp[i][j]=inf;
		for(i=1;i<=n;i++)
			mp[i][i]=0;
	    //���������㼰���ǵľ���
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			mp[u][v]=w;   //��Ϊ����ͼ������洢mp[v][u] 
		}
		flag=SPFA(1,n);  //SPFA����
		//������
		if(flag==0) printf("���ڸ�Ȩ��·!\n");
		else
		{
			for(i=1;i<=n;i++)
				printf("%d ",dis[i]);
			printf("\n");
		}
	}
	return 0;
}

/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
