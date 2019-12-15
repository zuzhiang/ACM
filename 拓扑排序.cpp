#include<stdio.h>
#include<string.h>
#define MAX 500

int n,m,dgr[MAX],map[MAX][MAX]; //drg��¼�ڵ���� 
int queue[MAX];

/*
����ֵ��
-1���л�
0�� �����Ψһ
1�� ��Ψһ�� 
*/
int tuopu()
{
	int i,j,f,pos,cnt,tol,tmp[MAX];	
	for(i=1;i<=n;i++) tmp[i]=dgr[i]; //��ڵ�����ֵ��ı䣬����tmp����洢 
	tol=0;
	f=1;
	for(i=0;i<n;i++)
	{
		cnt=0;  //���Ϊ0�Ľڵ��� 
		for(j=1;j<=n;j++)
			if(tmp[j]==0)
			{
				pos=j;
				cnt++;
			}
		if(cnt==0) return -1; //�����Ϊ0�Ľڵ㣬��һ���л� 
		else if(cnt>1) f=0;   //������������Ψһ��ע���������f=0,ֱ�ӷ��ؿ��ܻ�Ӱ��֮�����ж� 
		queue[tol++]=pos;
		tmp[pos]=-1;          //�൱��ɾ���ýڵ�
		for(j=1;j<=n;j++)     //����ýڵ����ڵı�ɾ��
			if(map[pos][j])
				tmp[j]--;
	}
	return f;
}

int main()
{
	int i,j,f,val;
	int u,v;
	while(~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map));
		memset(dgr,0,sizeof(dgr));
		f=0;
		//��������жϣ� 
		for(i=1;i<=m;i++) 
		{ //����A<B
			scanf("%d%d",&u,&v);
			if(f) continue;
			map[u][v]=1;
			dgr[v]++;
			val=tuopu();
			if(val==-1)
			{
				printf("�л���\n");
				f=1;
			}
			else if(val==1)
			{
				for(i=0;i<n;i++) printf("%d ",queue[i]);
				printf("\n");
			}
		}
		if(f==0) printf("��Ψһ��!\n");
	}
	return 0;
}
