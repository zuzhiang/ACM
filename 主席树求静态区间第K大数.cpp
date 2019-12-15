#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;

int tol;
//若tol值相同，则L、R、sum就表示同一个节点
//L为左端点的编号，R为右端点的编号，sum表示区间[L,R]内数的个数 
int L[MAXN<<5],R[MAXN<<5],sum[MAXN<<5];
int a[MAXN],b[MAXN],T[MAXN]; //T记录每个元素对应的根节点

int build(int l,int r)
{ //建树,参数表示左右端点 
    int mid,root=++tol;
    sum[root]=0; //区间内数的个数为0
    if(l<r)
    {
        mid=(l+r)>>1;
        L[root]=build(l,mid);   //构造左子树并将左端点编号存入L 
        R[root]=build(mid+1,r); //构造右子树并将右端点编号存入R
    }
    return root;
}

int update(int pre,int l,int r,int pos)
{//更新，参数分别为：上一线段树的根节点编号，左右端点，插入数在原数组中排第pos 
	//从根节点往下更新到叶子，新建立出一路更新的节点，这样就是一颗新树了。
    int mid,root=++tol;
    L[root]=L[pre]; //先让其等于前面一颗树 
    R[root]=R[pre]; //先让其等于前面一颗树
    sum[root]=sum[pre]+1; //当前节点一定被修改，数的个数+1 
    if(l<r)
    {
        mid=(l+r)>>1;
        if(pos<=mid) L[root]=update(L[pre],l,mid,pos); //插入到左子树 
        else R[root]=update(R[pre],mid+1,r,pos); //插入到右子树 
    }
    return root;
}

int query(int u,int v,int l,int r,int k)
{ //查询，参数分别为：两颗线段树根节点的编号，左右端点，第k大 
    //只会查询到相关的节点 
    int mid,num;
    if(l==r) return l;
    mid=(l+r)>>1;
    num=sum[L[v]]-sum[L[u]]; //当前询问的区间中左子树中的元素个数
    //如果左儿子中的个数大于k，则要查询的值在左子树中 
    if(num>=k) return query(L[u],L[v],l,mid,k); 
    //否则在右子树中 
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
        num=unique(b+1,b+n+1)-b-1; //num为不同数的个数
        tol=0; //编号初始化 
        T[0]=build(1,num); //1~num即区间 
        for(i=1;i<=n;i++)
        { //实际上是对每个元素建立了一颗线段树，保存其根节点
            pos=lower_bound(b+1,b+num+1,a[i])-b;
            //pos就是当前数在原数组中排第pos 
            T[i]=update(T[i-1],1,num,pos); //在上一棵线段树的基础上修改 
        }
        int l,r,k;
        while(m--)
        { //求区间 [l,r]的第 k大 
            scanf("%d%d%d",&l,&r,&k);
            pos=query(T[l-1],T[r],1,num,k);
            printf("%d\n",b[pos]);
        }
    }
    return 0;
}
