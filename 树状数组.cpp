//树状数组求区间和 
/*
时间复杂度：log(n) 

树状数组节点保存的是它所表示区间内的数值之和 
*/
#include<iostream>
#include<string.h>
#define N 50010 
using namespace std;
int n,m,i,a[N],sum[N*2],l,r;
//n为原数组的大小;m为查询的次数;a:原数组;sum：树状数组 
//树状数组的下标是从1开始的 

int lowbit(int x)
{ //lowbit(x)就是把 x 的二进制的高位1全部清空，只留下最低位的1
    return x&(-x);
}

void update(int x,int p)//将第x个数加p 
{//更新 
	int i;
	for(i=x;i<=n;i+=lowbit(i))
        sum[i]+=p;
}

int query(int x)
{//前k个数的和
    int i,ans=0;
    for(i=x;i>0;i-=lowbit(i))
        ans+=sum[i];
    return ans;
}

int ask(int l,int r)
{//求l-r区间和 
    return query(r)-query(l-1);
}

int main()
{
    cin>>n>>m;
    memset(sum,0,sizeof(sum));
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    for(i=1;i<=m;i++)
    {
        cin>>l>>r;
        cout<<ask(l,r)<<endl;
    }
    return 0;
}
