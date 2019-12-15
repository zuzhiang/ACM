#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];

//区间一定是左闭右开，缩小范围是l和r的取值也与其对应，最终返回l的值 

int low_bound(int n,int v)
{//寻找比v小的最小插入位置 
	int l=0;
	int r=n;
	int mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]>=v) r=mid;
		else l=mid+1;
	}
	if(l<n&&a[l]==v) return l; //比一般的二分查找多的条件 
	else return 0;
}

int up_bound(int n,int v)
{//寻找比v大的最小插入位置
	int l=0;
	int r=n;
	int mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]<=v) l=mid+1;
		else r=mid;
	}
	if(a[l-1]==v) return l; //比一般的二分查找多的条件 
	else return 0;
}

int main()
{
	int i,n,v,ans;
	while(~scanf("%d%d",&n,&v))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		ans=low_bound(n,v);
		printf("low_bound=%d\n",ans);
		ans=up_bound(n,v);
		printf("up_bound=%d\n",ans);
	}
	return 0;
}
