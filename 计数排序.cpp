/*
计数排序是基数排序的基础。
基本思想:
对于给定数x，寻找数组中小于x的个数，
然后将其放入相应位置，所以要记录每个字出现的次数，
若有多个数相等，则存放一次后相应数的个数-1 
*/
#include<stdio.h> 
#include<string.h>
int main()
{
	int i,n,max,a[1000],cnt[1000],ans[1000];
	//a是原数组，cnt记录每个数出现的次数，ans是排序后的数组 
	while(~scanf("%d",&n)) //输入数组大小 
	{
		max=0;
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++) 
		{ //输入原数组并记录每个数出现的次数 
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(a[i]>max) max=a[i];
		}
		for(i=1;i<=max;i++) cnt[i]+=cnt[i-1];
		for(i=n-1;i>=0;i--) ans[--cnt[a[i]]]=a[i]; //注意从右至左 
		for(i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
/*
9
1 5 2 4 2 6 3 4 2
*/
