#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	queue<int> Q;
	int i,n,m,u[11],v[11],w[11],dis[11],book[11];
	int inf=0x3f3f3f3f;
	int now;
	scanf("%d %d",&n,&m);
	//��ʼ��dis���飬��Դ��1��������ľ���
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
    //��ʼ��book���飬����ǰ�ڵ��Ƿ����
	for(i=1;i<=n;i++)
		book[i]=0;
	//���������������֮��ľ���
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	//�ö��н����Ż�
	Q.push(1);
	book[1]=1;
	while(!Q.empty())
	{
		now=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
			if(u[i]==now)
			{
				if(dis[v[i]]>dis[u[i]]+w[i])
				{
					dis[v[i]]=dis[u[i]]+w[i];
					if(book[v[i]]==0)
					{
						Q.push(v[i]);
						book[v[i]]=1;
					}
				}
			}
	}
	//���
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	printf("\n");
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