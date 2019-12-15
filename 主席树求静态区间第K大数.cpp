#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;

int tol;
//��tolֵ��ͬ����L��R��sum�ͱ�ʾͬһ���ڵ�
//LΪ��˵�ı�ţ�RΪ�Ҷ˵�ı�ţ�sum��ʾ����[L,R]�����ĸ��� 
int L[MAXN<<5],R[MAXN<<5],sum[MAXN<<5];
int a[MAXN],b[MAXN],T[MAXN]; //T��¼ÿ��Ԫ�ض�Ӧ�ĸ��ڵ�

int build(int l,int r)
{ //����,������ʾ���Ҷ˵� 
    int mid,root=++tol;
    sum[root]=0; //���������ĸ���Ϊ0
    if(l<r)
    {
        mid=(l+r)>>1;
        L[root]=build(l,mid);   //����������������˵��Ŵ���L 
        R[root]=build(mid+1,r); //���������������Ҷ˵��Ŵ���R
    }
    return root;
}

int update(int pre,int l,int r,int pos)
{//���£������ֱ�Ϊ����һ�߶����ĸ��ڵ��ţ����Ҷ˵㣬��������ԭ�������ŵ�pos 
	//�Ӹ��ڵ����¸��µ�Ҷ�ӣ��½�����һ·���µĽڵ㣬��������һ�������ˡ�
    int mid,root=++tol;
    L[root]=L[pre]; //���������ǰ��һ���� 
    R[root]=R[pre]; //���������ǰ��һ����
    sum[root]=sum[pre]+1; //��ǰ�ڵ�һ�����޸ģ����ĸ���+1 
    if(l<r)
    {
        mid=(l+r)>>1;
        if(pos<=mid) L[root]=update(L[pre],l,mid,pos); //���뵽������ 
        else R[root]=update(R[pre],mid+1,r,pos); //���뵽������ 
    }
    return root;
}

int query(int u,int v,int l,int r,int k)
{ //��ѯ�������ֱ�Ϊ�������߶������ڵ�ı�ţ����Ҷ˵㣬��k�� 
    //ֻ���ѯ����صĽڵ� 
    int mid,num;
    if(l==r) return l;
    mid=(l+r)>>1;
    num=sum[L[v]]-sum[L[u]]; //��ǰѯ�ʵ��������������е�Ԫ�ظ���
    //���������еĸ�������k����Ҫ��ѯ��ֵ���������� 
    if(num>=k) return query(L[u],L[v],l,mid,k); 
    //�������������� 
    else return query(R[u],R[v],mid+1,r,k-num);
}

int main()
{
    int i,n,m,t,num,pos;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        num=unique(b+1,b+n+1)-b-1; //numΪ��ͬ���ĸ���
        tol=0; //��ų�ʼ�� 
        T[0]=build(1,num); //1~num������ 
        for(i=1;i<=n;i++)
        { //ʵ�����Ƕ�ÿ��Ԫ�ؽ�����һ���߶�������������ڵ�
            pos=lower_bound(b+1,b+num+1,a[i])-b;
            //pos���ǵ�ǰ����ԭ�������ŵ�pos 
            T[i]=update(T[i-1],1,num,pos); //����һ���߶����Ļ������޸� 
        }
        int l,r,k;
        while(m--)
        { //������ [l,r]�ĵ� k�� 
            scanf("%d%d%d",&l,&r,&k);
            pos=query(T[l-1],T[r],1,num,k);
            printf("%d\n",b[pos]);
        }
    }
    return 0;
}
