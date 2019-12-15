//http://blog.csdn.net/xym_csdn/article/details/50889293
//http://www.cnblogs.com/MashiroSky/p/5914637.html
//bzOJ 2038 //告诉你 n只袜子的颜色，问给定区间内选出两只相同颜色袜子的概率 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define MAXN 50010
using namespace std;
typedef long long LL;

struct node
{
	int l,r,x; //询问的左右区间及编号 
	LL a,b;    //答案的分子和分母 
} ask[MAXN];

int a[MAXN],s[MAXN]; //s记录每种颜色的出现的次数 
int blk[MAXN]; //表示第i个数属于哪一分块
LL ans;

int cmp1(node x,node y)
{ //如果询问的左端处于相同块则按右端排序，否则按左端排序 
	if(blk[x.l]==blk[y.l]) return x.r<y.r;
	else return x.l<y.l;
}

int cmp2(node x,node y)
{ //按照编号排序 
	return x.x<y.x;
}

void update(int x,int xx)
{ //参数为下标和变动个数
  //当某种颜色数量变化时，答案为先减去原来的后加上新的 
	ans-=s[a[x]]*s[a[x]];
	s[a[x]]+=xx; //某种颜色的袜子数变化 
	ans+=s[a[x]]*s[a[x]];
}

LL gcd(LL a,LL b)
{ //求最大公约数 
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int i,n,m,t;
	while(~scanf("%d%d",&n,&m))
	{
		t=sqrt(n); //每块的大小 
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
		{ //询问 
			scanf("%d%d",&ask[i].l,&ask[i].r);
			ask[i].x=i; //记录询问位置 
		}
		for(i=1;i<=n;i++) blk[i]=(i-1)/t+1; //分块
		sort(ask+1,ask+m+1,cmp1); //将询问排序 
		int l=1,r=0; //初始化时区间长度为负
		ans=0; //记录某种颜色在区间[L,R]内出现的次数 
		memset(s,0,sizeof(s));
		for(i=1;i<=m;i++)
		{
			while(r<ask[i].r)
			{ //每次第 r 种颜色增加 
				r++;
				update(r,1);
			}
			while(r>ask[i].r)
			{ //每次第 r 种颜色减少				
				update(r,-1);
				r--;
			}
			while(l<ask[i].l)
			{ //每次第 l 种颜色减少 
				update(l,-1);
				l++;
			}
			while(l>ask[i].l)
			{ //每次第 l 种颜色增加 
				l--;
				update(l,1);
			}
			//根据公式求分子和分母
			ask[i].a=ans-(ask[i].r-ask[i].l+1);
			ask[i].b=(LL)(ask[i].r-ask[i].l+1)*(ask[i].r-ask[i].l);
			LL k=gcd(ask[i].a,ask[i].b); //最大公约数，用于化简 
			ask[i].a/=k; //化简
			ask[i].b/=k; //化简
			if(ask[i].a==0) ask[i].b=1;
		}
		sort(ask+1,ask+m+1,cmp2); //还原为原来的顺序 
		for(i=1;i<=m;i++) printf("%lld/%lld\n",ask[i].a,ask[i].b);	
	}
	return 0;
}
