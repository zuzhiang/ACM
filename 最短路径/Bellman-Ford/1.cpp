/*
BF���·�㷨Ϊ��Դ���·�㷨�����Խ����Ȩ����
ԭ����m���߽���n-1���ɳڣ���i���ɳڵ���˼��Դ��v���ྭ��i
���ߵ���Ŀ�������· 
*/
#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f

int n,m,dis[1000];

struct node
{ //��¼��u��v֮��ľ���w 
	int u,v,w;
}a[1000];

int bf(int v)
{
	int i,j;
	for(i=0;i<=n;i++) dis[i]=inf;  //�����ʼ��Ϊ���ֵ 
	dis[v]=0;
	for(j=0;j<n-1;j++)  //����n-1��
		for(i=0;i<m;i++)
		{
			//���1����u��v�ľ���С��1ֱ�ӵ�v�ľ�������� 
			if(dis[a[i].v]>dis[a[i].u]+a[i].w)
				dis[a[i].v]=dis[a[i].u]+a[i].w;
			//�����Ƕ�����ͼ���ԣ�ֻ��Ҫ�������ַ���ļ�⼴��			
		}
	//����Ѿ��ɳ�����Ӵ���dis[a[i].v]>dis[a[i].u]+a[i].w����ڻ�· 
	for(i=1;i<=m;i++)
		if(dis[a[i].v]>dis[a[i].u]+a[i].w)
			return 0;
	return 1;
}

int main()
{
	int i,j; //dis[i]��ʾ�ڵ�1���ڵ�i�ľ��� 
	while(~scanf("%d%d",&n,&m))
	{ //nΪ�ڵ�����mΪ���� 		
		for(i=0;i<m;i++)
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);	
		bf(1);
		for(i=1;i<=n;i++)
			printf("%d ",dis[i]);
		printf("\n");
	}
	return 0;
}
//PS: ��������ݱ�ʾ��Ϊ����ͼ 
/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3

5 5
2 3 2
2 1 -3
5 1 5
4 5 2
3 4 3
*/

