/*
���ַ�������������У�ʱ�临�Ӷ�ΪO(n*logn),�����Լ�¼·�� 
lis[i]:����Ϊi�����������е���ĩԪ�أ����ж������Ϊi������������
,���¼��С���Ǹ���ĩԪ�ء�
ע�⣺lis�����е�Ԫ���ǵ����ģ����Կ����ö��ַ���� 
*/
#include<stdio.h> 
#include<string.h>
#include<iostream>
using namespace std;
#define MAXN 100010

int main()
{
	int i,n,len,pos;
	int a[MAXN],lis[MAXN];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		len=0;
		memset(lis,0,sizeof(lis));
		lis[0]=a[0];
		for(i=1;i<n;i++)
		{
			//�����ǰ����lis�����һ��������ӵ�lis����β�� 
			if(a[i]>=lis[len]) lis[++len]=a[i]; 
			else 
			{ //����Ѱ�ҿ����滻����Сλ�ò��滻
				pos=lower_bound(lis,lis+len,a[i])-lis;
				lis[pos]=a[i];
			}
		}
		printf("%d\n",len+1); //len�Ǵ�0��ʼ�ģ�����Ҫ+1 
	}
	return 0;
}
