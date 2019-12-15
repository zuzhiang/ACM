//http://www.renfei.org/blog/bipartite-matching.html
#include<stdio.h>
#include<string.h>

int vis[666]; //�ڵ��Ƿ���ʹ�
int link[666]; //��ýڵ������ӽڵ�ı��
int map[666][666];//ֵΪ1��ʾu��v�ڵ��б�
int gn,gm; //����ͼ�����ֵĽڵ����������ֵĽڵ��Ŷ��Ǵ�1��ʼ

int find(int u)
{ //�������㷨
	int i;
	for(i=1;i<=gm;i++)
	{
		if(map[u][i] && vis[i]==0) //����ڵ�i��v��������δ�����ҹ� 
		{
			vis[i]=1;	//���iΪ�Ѳ��ҹ�  
			if(link[i]==-1 || find(link[i])) //���iδ��ǰһ��ƥ��M�У�����i��ƥ��M�У����Ǵ���i���ڵĽڵ��������������·��  
			{
				link[i]=u; //��¼���ҳɹ���¼������ƥ��M������ȡ������
				return 1;  //���ز��ҳɹ�
			}
		}
	}
	return 0;
}

int main()
{
	int i,n,u,v,num;
	scanf("%d %d",&gn,&gm);
	memset(map,0,sizeof(map));
	for(i=1;i<=gm;i++)
		link[i]=-1;
	scanf("%d",&n);//����
	while(n--)
	{
		scanf("%d %d",&u,&v);//�����ڵ�ı��
		map[u][v]=1;
	}
	num=0;
	for(i=1;i<=gn;i++)
	{
		memset(vis,0,sizeof(vis));
		if(find(i)) num++;
	}
	printf("num=%d\n",num);
	return 0;
}

/*

4 4 7
1 1
1 3
2 1
3 1
3 2
4 3
4 4


3 3 4
1 1
1 3
2 2
3 2

*/
