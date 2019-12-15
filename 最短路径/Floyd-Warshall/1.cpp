/*
Floyd-Warshall�㷨���ֳ�Floyd�㷨
Ϊ��Դ���·�㷨�����ɴ���Ȩ 
ԭ����i������k��j�ľ������iֱ�ӵ�j�ľ���
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,u,m,n,v,w,map[101][101]; //map[i][j]���涥��i�Ͷ���j֮��ľ���
	int inf=0x3f3f3f3f;
	scanf("%d %d",&n,&m); //��������ͱ���
	//��ʼ��
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			map[i][j]=inf;
	for(i=1;i<=n;i++)
		map[i][i]=0;
	//�����
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		map[u][v]=w;
	}
	//�㷨�������
	for(k=1;k<=n;k++)         //�ö���k���¶���i�Ͷ���j֮��ľ���
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
	//������
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	return 0;
}

/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
