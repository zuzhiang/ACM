/*
���������ǻ�������Ļ�����
����˼��:
���ڸ�����x��Ѱ��������С��x�ĸ�����
Ȼ���������Ӧλ�ã�����Ҫ��¼ÿ���ֳ��ֵĴ�����
���ж������ȣ�����һ�κ���Ӧ���ĸ���-1 
*/
#include<stdio.h> 
#include<string.h>
int main()
{
	int i,n,max,a[1000],cnt[1000],ans[1000];
	//a��ԭ���飬cnt��¼ÿ�������ֵĴ�����ans������������ 
	while(~scanf("%d",&n)) //���������С 
	{
		max=0;
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++) 
		{ //����ԭ���鲢��¼ÿ�������ֵĴ��� 
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(a[i]>max) max=a[i];
		}
		for(i=1;i<=max;i++) cnt[i]+=cnt[i-1];
		for(i=n-1;i>=0;i--) ans[--cnt[a[i]]]=a[i]; //ע��������� 
		for(i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
/*
9
1 5 2 4 2 6 3 4 2
*/
