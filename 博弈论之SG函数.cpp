//http://blog.csdn.net/luomingjun12315/article/details/45555495
/*
sg������ǲ��������̽ڵ� sgֵ���ϵ���С�Ǹ�����
��sg�ĺ���ֵΪ 0 ��Ϊ�ذ�̬����֮Ϊ��ʤ̬
����� n��ʯ�Ӱ�����ͬ��ȡ���������� n��ʯ�� sg����ֵ
�������Ϊ 0��Ϊ�ذ�̬����֮Ϊ��ʤ̬�� 
*/
#include<stdio.h>
#include<string.h>
#define N 11 //ȡʯ�ӵķ����� 
#define MAXN 1005 //����ж��ٸ�ʯ�� 

int f[N];   //����ȡ�ߵ�ʯ�Ӹ���
int sg[MAXN];  //0~n��SG����ֵ
int vis[MAXN]; //vis[]:mex{}

void getSG(int n)
{ //SG[n]Ϊ 0Ϊ�ذܵ㣬�� 0Ϊ��ʤ�� 
	int i,j;
	memset(sg,0,sizeof(sg));
	for(i=1;i<=n;i++)
	{ //�� i ��ʯ��ʱ�� SG����ֵ 
		memset(vis,0,sizeof(vis)); //ÿһ�ν���һ״̬�ĺ������ 
		for(j=0;f[j]<=i&&j<N;j++)
		{ //�����״̬��SG����ֵ���б��
			vis[sg[i-f[j]]]=1; //���Ϊ i��ʯ��ȡ f[j]����ʣ�µ� 
		}
		for(j=0;j<= n;j++)
			if(!vis[j])
			{ //��mes{}��δ���ֵ���С�ķǸ�����
				sg[i] = j;
				break;
			}
	}
}

int main()
{
	int i,n;
	for(i=0;i<=10;i++) f[i]=1<<i;	
	getSG(1001);
	while(~scanf("%d",&n))
	{		
		if(sg[n]) printf("Kiki\n");
		else printf("Cici\n");
	}
	return 0;
}
