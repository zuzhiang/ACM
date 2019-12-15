//http://blog.csdn.net/niushuai666/article/details/6624672
/*
RMQ指的是求区间最值问题。 
*/
#include<stdio.h>
#include<math.h>

int a[50005],mi[50005][22],mx[50005][22];
//mi保存的为从i开始长度为2^j的区间的最小值， mx保存的为从i开始长度为2^j的区间的最大值
//初始化：mi[i][0] =a[i],mx[i][0]=a[i]
//状态转移方程:mi[i][j]=min(mi[i][j-1],mi[i+2^(j-1)][j-1])
//             mx[i][j]=max(mx[i][j-1],mx[i+2^(j-1)][j-1])

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

void RMQ(int n)
{ //在线预处理，dp思想 
	int i,j;
	for(i=1;i<=n;i++)
	{
		mi[i][0]=a[i];
		mx[i][0]=a[i];
	}
	//注意循环顺序,外层为j,内层为i 
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			if(i+(1<<j)-1<=n)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
				mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
			}
}

int main()
{
	int i,j,k,n,q,l,r,ans;
	scanf("%d%d",&n,&q);//数的个数和询问的个数 
	for(i=1;i<=n;i++) scanf("%d",&a[i]); //n个数 
	RMQ(n);
	while(q--)
	{
		scanf("%d%d",&l,&r); //查询的左右区间 
		k=(int)(log(r-l+1.0)/log(2.0)); //r-l+1为区间长度 
		//求区间(l,r)最大值
		//ans=max(mx[l][k],mx[r-(1<<k)+1][k]);
		//求区间(l,r)最小值
		//ans=min(mx[l][k],mx[r-(1<<k)+1][k]);
		//求区间(l,r)最大值-最小值 		
		ans=max(mx[l][k],mx[r-(1<<k)+1][k])-min(mi[l][k],mi[r-(1<<k)+1][k]);
		printf("%d\n",ans);
	}	
	return 0;
}
