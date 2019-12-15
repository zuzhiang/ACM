//http://www.cnblogs.com/scau20110726/archive/2013/05/07/3065418.html 
#include<stdio.h>
#include<string.h>
#define N 50010

struct node
{ //线段树节点表示区间 
	//lsum表示该区间从最左端开始有多少连续为空
	//lsum表示该区间从最右端开始有多少连续为空
	//sum表示该区间最大连续为空的长度
	//mark为延迟标记，为0、1表示整段为空或非空，-1表示不确定 
	int lsum,rsum,sum,mark;
} T[N*4];

int max(int a,int b)
{
	return a>b?a:b;
}

void pushup(int rt,int L,int R)
{ //将子孙信息传递给父亲
	//父亲节点的最大连续空间为左右子树中连续空间和跨越左右子树的连续空间的最大值 
	T[rt].sum=max(max(T[rt<<1].sum,T[rt<<1|1].sum),T[rt<<1].rsum+T[rt<<1|1].lsum);	
	int m=(L+R)>>1;
	//如果左孩子的 sum为整个区间，则父亲的lsum为左孩子的lsum + 右孩子的 lsum
	if(T[rt<<1].sum==m-L+1) T[rt].lsum=T[rt<<1].lsum+T[rt<<1|1].lsum;
	else T[rt].lsum=T[rt<<1].lsum;
	//如果右孩子的 sum为整个区间，则父亲的rsum为左孩子的rsum + 右孩子的 rsum
	if(T[rt<<1|1].sum==R-m) T[rt].rsum=T[rt<<1].rsum+T[rt<<1|1].rsum;
	else T[rt].rsum=T[rt<<1|1].rsum;
}

void pushdown(int rt,int L,int R)
{ //将父亲信息传递给儿子 
	if(T[rt].mark!=-1)
	{ //如果延迟标记不为-1则处理
		//将父亲节点的延迟标记传给孩子 
		T[rt<<1].mark=T[rt<<1|1].mark=T[rt].mark;
		T[rt].mark=-1;
		int m=(L+R)>>1;
		//根据自己的延迟标记确定 lsum、rsum、sum 的值 
		if(T[rt<<1].mark) T[rt<<1].lsum=T[rt<<1].rsum=T[rt<<1].sum=0;
		else T[rt<<1].lsum=T[rt<<1].rsum=T[rt<<1].sum=m-L+1;
		if(T[rt<<1|1].mark) T[rt<<1|1].lsum=T[rt<<1|1].rsum=T[rt<<1|1].sum=0;
		else T[rt<<1|1].lsum=T[rt<<1|1].rsum=T[rt<<1|1].sum=R-m;			
	}
}

void build(int rt,int L,int R)
{ //建树 
	T[rt].lsum=T[rt].rsum=T[rt].sum=R-L+1;
	T[rt].mark=0;
	if(L==R) return;
	int m=(L+R)>>1;
	build(rt<<1,L,m);
	build(rt<<1|1,m+1,R);
}

void update(int rt,int L,int R,int l,int r,int x)
{ //更新 
	if(l<=L&&R<=r)
	{
		T[rt].mark=x;
		//根据自己的延迟标记确定 lsum、rsum、sum 的值
		if(T[rt].mark) T[rt].lsum=T[rt].rsum=T[rt].sum=0;
		else T[rt].lsum=T[rt].rsum=T[rt].sum=R-L+1;
		return;
	}
	pushdown(rt,L,R);
	int m=(L+R)>>1;
	if(l<=m) update(rt<<1,L,m,l,r,x);
	if(r>m) update(rt<<1|1,m+1,R,l,r,x);
	pushup(rt,L,R);	
}

int query(int rt,int L,int R,int x)
{ //查询 
	if(T[rt].lsum==x) return L; //如果当前区间的 lsum比 x 大则返回左端点 
	pushdown(rt,L,R);
	int m=(L+R)>>1;
	if(T[rt<<1].sum>=x) return query(rt<<1,L,m,x); //如果在左子树中 
	else if(T[rt<<1].rsum+T[rt<<1|1].lsum>=x) return m-T[rt<<1].rsum+1; //如果横跨左右子树 
	else return query(rt<<1|1,m+1,R,x); //如果在右子树中 
}

int main()
{
	int i,n,m,q,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{ //点的个数和操作次数 
		build(1,1,n);
		while(m--)
		{
			scanf("%d",&q);
			if(q==1)
			{ //询问 
				scanf("%d",&a);
				if(T[1].sum<a) printf("0\n"); //如果整个大区间都不满足则为 0 
				else 
				{
					ans=query(1,1,n,a);
					printf("%d\n",ans);
					update(1,1,n,ans,ans+a-1,1); //将相应区间置为满 
				}				
			}
			else
			{ //更新 
				scanf("%d%d",&a,&b);
				update(1,1,n,a,a+b-1,0); //将区间置空 
			}
		}
	}
	return 0;
}
