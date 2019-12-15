#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;

struct point
{
	int x, y;
	point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	point operator - (const point &b)const
	{
		return point(x - b.x, y - b.y);
	}
	int operator ^(const point &b)const
	{
		return x * b.y - y * b.x;
	}
	int operator *(const point &b)const
	{
		return x * b.x + y * b.y;
	}	
} p[MAXN];

//距离的平方
int dis(point a, point b)
{
	return (a - b) * (a - b);
}
//二维凸包
point list[MAXN];
int stk[MAXN],top;

void Swap(int i,int j)
{ //交换点 
    point tmp;
    tmp=list[i];
    list[i]=list[j];
    list[j]=tmp;
}

int cmp(point a,point b) 
{ //排序比较函数 
    int k=(a-list[0])^(b-list[0]);
    if(k==0) return dis(a,list[0])<dis(b,list[0]); //如果平行则比较距离 
    else return k>0; //否则比较极角大小 
}

void Graham(int n)
{ //Graham求凸包，最终stk数组中保存凸包点的下标
    int i,u=0;
    for(i = 1;i< n;i++) //找到最左下的点
        if((list[i].y<list[u].y)||(list[i].y==list[u].y&&list[i].x < list[u].x))
            u=i;
    Swap(0,u); //将最左下的点和 0 处点交换 
    sort(list+1,list+n,cmp); //对剩余点进行极角排序 
    //比单纯求凸包多下面两个判断 
	for(i=0;i<=1;i++) stk[i]=i;
    top=2;
    for (int i = 2; i < n; i++)
	{
		while(top>1&&((list[stk[top-1]]-list[stk[top-2]])^(list[i]-list[stk[top-2]]))<=0)
		{
			top--;
		}
		stk[top++] = i;
	}
}

// 旋转卡壳,求两点间距离平方的最大值
int rotating_calipers(int n)
{
	int ans = 0;
	point v;
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		v = p[i] - p[(i + 1) % n];
		while ((v ^ (p[(cur + 1) % n] - p[cur])) < 0)
			cur = (cur + 1) % n;
		ans = max(ans, max(dis(p[i], p[cur]), dis(p[(i + 1) % n], p[(cur + 1) % n])));
	}
	return ans;
}

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &list[i].x, &list[i].y);
		if(n==2)
		{
			printf("%d\n",dis(list[0],list[1]));
			continue;
		}
		Graham(n);
		for (int i = 0; i < top; i++)
			p[i] = list[stk[i]];
		printf("%d\n", rotating_calipers(top));
	}
	return 0;
}
