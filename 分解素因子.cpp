/*
һ����n�Ĵ���sqrt(n)��������ֻ������һ���� 
���ԣ���ȥ��������Ϊ2~sqrt(n)�ĸ����������ÿ��������n��ֵ��Ϊ1��
��ǰn��ֵ���������sqrt(n)�����ӣ������ݴ�Ϊ1 �� 
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 1000010

int tol,pri[MAX],p[MAX];

void is_prime()
{
	int i,j;
	tol=0;
	memset(pri,1,sizeof(pri));
	for(i=2;i<MAX;i++)	
		if(pri[i])
		{
			p[tol++]=i;
			for(j=2*i;j<MAX;j+=i) pri[j]=0;		
		}	
}

int main()
{
	int i,n;
	is_prime();
	while(~scanf("%d",&n))
	{
		for(i=0;i<tol;i++)
		{
			if(n%p[i]==0) printf("%d ",p[i]);
			while(n%p[i]==0) n/=p[i];
			//�����ǰ�������������ҵ����������������˳� 
			if(pri[n]||n==1) break;							
		}
		if(n>1) printf("%d",n);
		printf("\n");
	}
	return 0;
}
