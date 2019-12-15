//��״����������� 
/*
ʱ�临�Ӷȣ�log(n) 

��״����ڵ㱣�����������ʾ�����ڵ���ֵ֮�� 
*/
#include<iostream>
#include<string.h>
#define N 50010 
using namespace std;
int n,m,i,a[N],sum[N*2],l,r;
//nΪԭ����Ĵ�С;mΪ��ѯ�Ĵ���;a:ԭ����;sum����״���� 
//��״������±��Ǵ�1��ʼ�� 

int lowbit(int x)
{ //lowbit(x)���ǰ� x �Ķ����Ƶĸ�λ1ȫ����գ�ֻ�������λ��1
    return x&(-x);
}

void update(int x,int p)//����x������p 
{//���� 
	int i;
	for(i=x;i<=n;i+=lowbit(i))
        sum[i]+=p;
}

int query(int x)
{//ǰk�����ĺ�
    int i,ans=0;
    for(i=x;i>0;i-=lowbit(i))
        ans+=sum[i];
    return ans;
}

int ask(int l,int r)
{//��l-r����� 
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
