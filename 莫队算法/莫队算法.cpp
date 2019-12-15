//http://blog.csdn.net/xym_csdn/article/details/50889293
//http://www.cnblogs.com/MashiroSky/p/5914637.html
//bzOJ 2038 //������ nֻ���ӵ���ɫ���ʸ���������ѡ����ֻ��ͬ��ɫ���ӵĸ��� 
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
	int l,r,x; //ѯ�ʵ��������估��� 
	LL a,b;    //�𰸵ķ��Ӻͷ�ĸ 
} ask[MAXN];

int a[MAXN],s[MAXN]; //s��¼ÿ����ɫ�ĳ��ֵĴ��� 
int blk[MAXN]; //��ʾ��i����������һ�ֿ�
LL ans;

int cmp1(node x,node y)
{ //���ѯ�ʵ���˴�����ͬ�����Ҷ����򣬷���������� 
	if(blk[x.l]==blk[y.l]) return x.r<y.r;
	else return x.l<y.l;
}

int cmp2(node x,node y)
{ //���ձ������ 
	return x.x<y.x;
}

void update(int x,int xx)
{ //����Ϊ�±�ͱ䶯����
  //��ĳ����ɫ�����仯ʱ����Ϊ�ȼ�ȥԭ���ĺ�����µ� 
	ans-=s[a[x]]*s[a[x]];
	s[a[x]]+=xx; //ĳ����ɫ���������仯 
	ans+=s[a[x]]*s[a[x]];
}

LL gcd(LL a,LL b)
{ //�����Լ�� 
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int i,n,m,t;
	while(~scanf("%d%d",&n,&m))
	{
		t=sqrt(n); //ÿ��Ĵ�С 
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
		{ //ѯ�� 
			scanf("%d%d",&ask[i].l,&ask[i].r);
			ask[i].x=i; //��¼ѯ��λ�� 
		}
		for(i=1;i<=n;i++) blk[i]=(i-1)/t+1; //�ֿ�
		sort(ask+1,ask+m+1,cmp1); //��ѯ������ 
		int l=1,r=0; //��ʼ��ʱ���䳤��Ϊ��
		ans=0; //��¼ĳ����ɫ������[L,R]�ڳ��ֵĴ��� 
		memset(s,0,sizeof(s));
		for(i=1;i<=m;i++)
		{
			while(r<ask[i].r)
			{ //ÿ�ε� r ����ɫ���� 
				r++;
				update(r,1);
			}
			while(r>ask[i].r)
			{ //ÿ�ε� r ����ɫ����				
				update(r,-1);
				r--;
			}
			while(l<ask[i].l)
			{ //ÿ�ε� l ����ɫ���� 
				update(l,-1);
				l++;
			}
			while(l>ask[i].l)
			{ //ÿ�ε� l ����ɫ���� 
				l--;
				update(l,1);
			}
			//���ݹ�ʽ����Ӻͷ�ĸ
			ask[i].a=ans-(ask[i].r-ask[i].l+1);
			ask[i].b=(LL)(ask[i].r-ask[i].l+1)*(ask[i].r-ask[i].l);
			LL k=gcd(ask[i].a,ask[i].b); //���Լ�������ڻ��� 
			ask[i].a/=k; //����
			ask[i].b/=k; //����
			if(ask[i].a==0) ask[i].b=1;
		}
		sort(ask+1,ask+m+1,cmp2); //��ԭΪԭ����˳�� 
		for(i=1;i<=m;i++) printf("%lld/%lld\n",ask[i].a,ask[i].b);	
	}
	return 0;
}
