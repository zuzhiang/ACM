/*
二分法求最长上升子序列，时间复杂度为O(n*logn),不可以记录路径 
lis[i]:长度为i的上升子序列的最末元素，若有多个长度为i的上升子序列
,则记录最小的那个最末元素。
注意：lis数组中的元素是递增的，所以可以用二分法求解 
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
			//如果当前数比lis中最后一个数大，则加到lis数组尾部 
			if(a[i]>=lis[len]) lis[++len]=a[i]; 
			else 
			{ //否则，寻找可以替换的最小位置并替换
				pos=lower_bound(lis,lis+len,a[i])-lis;
				lis[pos]=a[i];
			}
		}
		printf("%d\n",len+1); //len是从0开始的，所以要+1 
	}
	return 0;
}
