#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];

//����һ��������ҿ�����С��Χ��l��r��ȡֵҲ�����Ӧ�����շ���l��ֵ 

int low_bound(int n,int v)
{//Ѱ�ұ�vС����С����λ�� 
	int l=0;
	int r=n;
	int mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]>=v) r=mid;
		else l=mid+1;
	}
	if(l<n&&a[l]==v) return l; //��һ��Ķ��ֲ��Ҷ������ 
	else return 0;
}

int up_bound(int n,int v)
{//Ѱ�ұ�v�����С����λ��
	int l=0;
	int r=n;
	int mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]<=v) l=mid+1;
		else r=mid;
	}
	if(a[l-1]==v) return l; //��һ��Ķ��ֲ��Ҷ������ 
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
