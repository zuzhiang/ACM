/*
��ֻ�ܽ�����������ʱ�����ٽ�������Ϊ�����е���������
�����Խ�����������ʱ�����ٽ�������Ϊ�����г��� - ѭ���ڸ��� 
*/
/*
�ô����ʺ��ڵ�����Ϊ 1~n ʱ��������ǿ����� map������� 
*/
#include<stdio.h> 
#include<string.h>
#define maxn 100010

int a[maxn],vis[maxn];

int main()
{
	int i,n,x,num,ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		num=0; //ѭ���ڸ��� 
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		{ //����ÿһ��λ�� 
			if(!vis[i])
			{ //���δ���ʹ� 
				x=i;
				while(!vis[x])
				{ //Ѱ�Ҹ���������ѭ���� 
					vis[x]=1;
					x=a[x];
				}
				num++; //ѭ���ڸ���+1 
			}
		}
		ans=n-num;
		printf("%d\n",ans);
	}
	return 0;
}
