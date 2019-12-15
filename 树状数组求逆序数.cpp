/*
时间复杂度：log(n) 

树状数组不能直接求一个含有小于等于0的数的序列的逆序数,此时要让所有的数都加上一个数
变为正数。

思想：树状数组的每个节点表示它所表示的下标区间内数字出现的次数 
则插入第 i 个数产生的逆序数为 i-query(n),即
已插入数的个数 - 已插入的比当前数小的数的个数。
将每次的结果相加即可。 

注意：树状数组的大小为所有数的最大值，当最大值太大时，可以先将所有数排序去重，改为
存其下标 
*/
#include<stdio.h>
#include<string.h>
#define N 500010

int n,t[N*2];

int lowbit(int x)
{ //lowbit(k)就是把k的二进制的高位1全部清空，只留下最低位的1
    return x&(-x);
}

void update(int x)
{//将第x个数加 1 
	for(int i=x;i<=N*2;i+=lowbit(i))
		t[i]++;		    
}

long long query(int x)
{//查找当前输入的数中比 x 小的数的个数 
    long long ans=0;
    for(int i=x;i>0;i-=lowbit(i))
    	ans+=t[i];
    return ans;
}

int main()
{
	int i,a;
	long long ans;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		ans=0;
		memset(t,0,sizeof(t));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a); //输入的 a 相当于下标 
			//插入数的个数 - 已插入的比当前数小的数的个数
			ans+=i-query(a+1); //a=0时有陷阱 
			update(a+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
