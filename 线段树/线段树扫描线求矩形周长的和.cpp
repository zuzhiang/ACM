//www.cnblogs.com/scau20110726/archive/2013/04/13/3018687.html
/*
线段树节点表示的区间可以有负值，因为不作为数组下标
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#define N 10010
#define NN 200010
using namespace std;

struct node
{ //用来保存矩形的上下边 
	int l,r,h; //左右横坐标，纵坐标 
	int f; //-1为上边界，1为下边界 
} a[N];

struct tree
{
	int cnt; //该区间被几条线段整段覆盖过，若为0则可能只覆盖过一部分区间 
	int len; //该区间被覆盖的总长度 
	int lp,rp; //取值只有0和1，表示这个节点的两个端点有否被覆盖 
	int num; //这个区间被多少条线段覆盖 
} T[NN*4];

int cmp(node x,node y)
{
	return x.h<y.h;
}

void build(int rt,int L,int R)
{	
	T[rt].cnt=T[rt].len=0;
	T[rt].lp=T[rt].rp=T[rt].num=0;
	if(L==R) return;
	int m=(L+R)>>1;
	build(rt<<1,L,m);
	build(rt<<1|1,m+1,R);
}

void pushup(int rt,int L,int R)
{
	if(T[rt].cnt)
	{ //非0则被整段覆盖
		T[rt].len=R-L+1;
		T[rt].lp=T[rt].rp=1; //左右端点都被覆盖 
		T[rt].num=1; //区间被 1 条线段覆盖 
	}
	else if(L==R)
	{ //已经不是一条线段
		T[rt].len=0;
		T[rt].lp=T[rt].rp=0; //左右端点都没被覆盖 
		T[rt].num=0; //区间被 1 条线段覆盖
	}
	else
	{ //是一条线段但又没被整段覆盖，则其覆盖长度为左右子树之和
		T[rt].len=T[rt<<1].len+T[rt<<1|1].len;
		T[rt].lp=T[rt<<1].lp;   //左端点的覆盖情况和左子树相同 
		T[rt].rp=T[rt<<1|1].rp;	//右端点的覆盖情况和右子树相同 
		//被线段覆盖的条数为左右子树之和 - 左子树的右端和右子树的左端线段合并的线段数 
		T[rt].num=T[rt<<1].num+T[rt<<1|1].num-(T[rt<<1].rp&T[rt<<1|1].lp);
	}
}

void update(int rt,int L,int R,int l,int r,int x)
{
	if(l<=L&&R<=r)
	{
		T[rt].cnt+=x;   //更新区间被覆盖的情况
		pushup(rt,L,R); //更新区间被覆盖的总长度 
		return;
	}
	int m=(L+R)>>1;
	if(l<=m) update(rt<<1,L,m,l,r,x);
	if(r>m) update(rt<<1|1,m+1,R,l,r,x);
	pushup(rt,L,R); //更新区间被覆盖的总长度
}

int main()
{
	int i,n,x1,x2,y1,y2,ans;
	int l,r,pre,minx,maxx;
	while(~scanf("%d",&n))
	{ //矩形的个数 
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		minx=0x3f3f3f3f;
		maxx=-0x3f3f3f3f;
		for(i=0;i<n;i++)
		{ //输入矩形左下方和右上方点的坐标
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			//记录x坐标最大值和最小值 
			if(maxx<x2) maxx=x2;
			if(minx>x1) minx=x1;
			//记录上边界信息
			a[i*2].l=x1;
			a[i*2].r=x2;
			a[i*2].h=y1;
			a[i*2].f=1;
			//记录下边界信息
			a[i*2+1].l=x1;
			a[i*2+1].r=x2;
			a[i*2+1].h=y2;
			a[i*2+1].f=-1;			
		}
		sort(a,a+n*2,cmp); //按纵坐标升序排列 
		build(1,minx,maxx-1);
		ans=0;
		pre=0;
		for(i=0;i<n*2;i++)
		{ //从下往上拿出每条横线并更新
			update(1,minx,maxx-1,a[i].l,a[i].r-1,a[i].f); //用线段更新区间 
			ans+=abs(T[1].len-pre); //计算横线部分
			//竖线有 num*2 条，竖线高度为相邻横线高度之差 
			ans+=(a[i+1].h-a[i].h)*(2*T[1].num); //计算竖线部分
			pre=T[1].len;
		}
		printf("%d\n",ans);
	}
}
