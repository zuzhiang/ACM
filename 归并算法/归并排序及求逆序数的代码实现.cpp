/*
归并排序算法求逆序数
思想：
	1.归并排序采用分治的思想，利用递归将待排序数组不断二分，每次将左右两个
	  已排序的数组按照从小到大或从大到小的顺序合并。最小分组的有序保证了
	  更大分组的有序。 
	2.归并排序求逆序数。对于左右两个分组来说，输入时，左分组的位置比右分组的
	  位置靠前，如果排序时右分组的一个数小于左分组某些数，则这个数就和左分组中
	  的某些数产生了逆序对。 
*/

#include<stdio.h> 
#include<stdlib.h>
#define MAXN 50005

/****************************************************************/
int cnt=0;  //记录逆序数的个数 
/****************************************************************/
int a[MAXN],tmp[MAXN];

void solve(int l,int mid,int r)
{ //对a数组的以mid为中心的左右两部分进行合并排序 ,tmp为临时数组
//先将排序的结果存入tmp数组，再转存到原数组a中 
	int i=l,j=mid+1; //i、j分别代表a数组左右两部分开始的位置 
	int k=0;
	while(i<=mid && j<=r) //当a数组左右两部分都没有处理完毕 
	{ //将a数组的左右两部分按升序 插入到tmp数组中 
		if(a[i]<=a[j]) tmp[k++]=a[i++]; //若改为从大到小排序则只需要改变该判断条件即可 
		else 
		{
			tmp[k++]=a[j++];
			/****************************************************************/
			cnt+=mid-i+1;  //a[j]和左分组未插入的每一个数都能组成逆序数对
			/****************************************************************/			
		}
	}
	//将剩余没处理的插入到tmp数组 
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	//将排序结果存回a数组 
	for(i=0;i<k;i++)
		a[l+i]=tmp[i];
}

void MergeSort(int l,int r)
{//对a数组以l为起始地址，以r为结束地址的闭区间排序 
	if(l<r)
	{
		int mid=(l+r)/2; //一分为二，进行二路归并排序 
		MergeSort(l,mid); //使左边有序 
		MergeSort(mid+1,r); //使右边有序 
		solve(l,mid,r); //将两个有序的数组合并 
	}
}

int main()
{
	int i,n;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		MergeSort(0,n-1);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		printf("逆序数对的个数为：%d\n",cnt);
	}
	return 0;
}


/*一般的合并算法 
//将有序数组a[]和b[]合并到c[]中  
void MemeryArray(int a[], int n, int b[], int m, int c[])  
{  
    int i, j, k;  
  
    i = j = k = 0;  
    while (i < n && j < m)  
    {  
        if (a[i] < b[j])  
            c[k++] = a[i++];  
        else  
            c[k++] = b[j++];   
    }  
  
    while (i < n)  
        c[k++] = a[i++];  
  
    while (j < m)  
        c[k++] = b[j++];  
} 
*/
