//http://www.cnblogs.com/scau20110726/archive/2013/03/21/2972808.html
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

double pos[205];

struct node
{ //用来保存矩形的上下边 
	double l,r,h; //左右横坐标，纵坐标 
	int f; //-1为上边界，1为下边界 
} a[205];

struct tree
{ //线段树第 i 个叶子节点保存的是第 i 条线段的信息（不是点的信息）(i从1开始)
	int cnt;    //该区间被几条线段整段覆盖过，若为0则可能只覆盖过一部分区间 
	double len; //该区间被覆盖的总长度 
} T[205*4]; 

int cmp(node x,node y)
{
	return x.h<y.h;
}

int find(int l,int r,double val)
{ //二分查找 val 在 pos 数组中的位置 
	int m;
	while(l<r)
	{
		m=(l+r)>>1;
		if(pos[m]==val) return m;
		else if(pos[m]>val) r=m;
		else l=m+1;
	}
	return -1;
}

void build(int rt,int L,int R)
{ //建树 
	T[rt].cnt=0;
	T[rt].len=0;
	if(L==R) return;
	int m=(L+R)>>1;
	build(rt<<1,L,m);
	build(rt<<1|1,m+1,R);
}

void get_len(int rt,int L,int R)
{
	if(T[rt].cnt) T[rt].len=pos[R]-pos[L-1]; //非0则被整段覆盖
	else if(L==R) T[rt].len=0; //已经不是一条线段
	//是一条线段但又没被整段覆盖，则其覆盖长度为左右子树之和 
	else T[rt].len=T[rt<<1].len+T[rt<<1|1].len;
}

void update(int rt,int L,int R,int l,int r,int x)
{
	if(l<=L&&R<=r)
	{
		T[rt].cnt+=x;    //更新区间被覆盖的情况 
		get_len(rt,L,R); //更新区间被覆盖的总长度 
		return;		
	}
	int m=(L+R)>>1;
	if(l<=m) update(rt<<1,L,m,l,r,x);
	if(r>m) update(rt<<1|1,m+1,R,l,r,x);
	get_len(rt,L,R); //更新区间被覆盖的总长度
}

int main()
{
	int i,n,l,r,num,cas=1;
	double x1,x2,y1,y2;
	while(~scanf("%d",&n)&&n)
	{ //矩形的个数 
		for(i=0;i<n;i++)
		{ //输入矩形左下方和右上方点的坐标 
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
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
			//记录横坐标 
			pos[i*2]=x1;
			pos[i*2+1]=x2;
		}
		sort(a,a+2*n,cmp); //按纵坐标升序排列 
		sort(pos,pos+2*n); //按横坐标升序排列
		num=unique(pos,pos+2*n)-pos;
		build(1,1,num); //建树 
		double ans=0;
		for(i=0;i<2*n;i++)
		{ //从下往上拿出每条横线并更新 
			l=find(0,num,a[i].l)+1; //离散化后边的左端点 
			r=find(0,num,a[i].r);   //离散化后边的右端点 
			update(1,1,num,l,r,a[i].f); //用这条线段去更新 
			ans+=(a[i+1].h-a[i].h)*T[1].len; //区间高度*区间长度 
		}
		printf("Test case #%d\n",cas++);
		printf("Total explored area: %.2f\n\n",ans);
	}
	return 0;
}
