/*
基数排序，共有编号从0到9的10个桶
从数字的最低位或最高位开始放到该位对应的桶中
依次将桶中的数据收集起来，再按照更高/低位排序
每次排序完后，就完成了对每一位的排序
全部完成后，整体是有序的 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[10000];

int get_digit(int n,int k)
{ //获取数字n的第k位数字。个位为第1位。 
	int r[11]={1,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	return (n/r[k])%10;
}

void sort(int n,int k)
{ //对最高有k位的n个数进行基数排序 
	int i,j,index,count[10]; //count记录第i个桶存放数的个数 
	int *bucket=(int *)malloc(n*sizeof(int)); //初始化桶的大小 
	for(j=1;j<=k;j++)
	{ //j为位数，从各位开始 
		for(i=0;i<10;i++) count[i]=0; //初始化 
		for(i=0;i<n;i++) count[get_digit(a[i],j)]++; //获取每个桶存放数的个数 
		for(i=1;i<10;i++) count[i]+=count[i-1]; //计算从0到第i个桶共存放了多少个数，因为bucket是一维数组。 
		for(i=n-1;i>=0;i--)
		{
			index=get_digit(a[i],j);
			bucket[count[index]-1]=a[i]; //将数放入相应的桶中 
			count[index]--;
		}
		for(i=0;i<n;i++) a[i]=bucket[i]; //从桶中收集数据 
	}
	free(bucket);
}

int main()
{
	int i,n,k,max;
	while(~scanf("%d",&n))
	{ //共n个数 
		max=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			if(a[i]>max) max=a[i];
		}		 
		k=(int)log10(max)+1; //计算最大值有多少位
		sort(n,k);
		for(i=0;i<n;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
