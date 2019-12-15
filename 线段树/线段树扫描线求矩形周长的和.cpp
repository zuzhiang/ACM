//www.cnblogs.com/scau20110726/archive/2013/04/13/3018687.html
/*
�߶����ڵ��ʾ����������и�ֵ����Ϊ����Ϊ�����±�
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#define N 10010
#define NN 200010
using namespace std;

struct node
{ //����������ε����±� 
	int l,r,h; //���Һ����꣬������ 
	int f; //-1Ϊ�ϱ߽磬1Ϊ�±߽� 
} a[N];

struct tree
{
	int cnt; //�����䱻�����߶����θ��ǹ�����Ϊ0�����ֻ���ǹ�һ�������� 
	int len; //�����䱻���ǵ��ܳ��� 
	int lp,rp; //ȡֵֻ��0��1����ʾ����ڵ�������˵��з񱻸��� 
	int num; //������䱻�������߶θ��� 
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
	{ //��0�����θ���
		T[rt].len=R-L+1;
		T[rt].lp=T[rt].rp=1; //���Ҷ˵㶼������ 
		T[rt].num=1; //���䱻 1 ���߶θ��� 
	}
	else if(L==R)
	{ //�Ѿ�����һ���߶�
		T[rt].len=0;
		T[rt].lp=T[rt].rp=0; //���Ҷ˵㶼û������ 
		T[rt].num=0; //���䱻 1 ���߶θ���
	}
	else
	{ //��һ���߶ε���û�����θ��ǣ����串�ǳ���Ϊ��������֮��
		T[rt].len=T[rt<<1].len+T[rt<<1|1].len;
		T[rt].lp=T[rt<<1].lp;   //��˵�ĸ����������������ͬ 
		T[rt].rp=T[rt<<1|1].rp;	//�Ҷ˵�ĸ����������������ͬ 
		//���߶θ��ǵ�����Ϊ��������֮�� - ���������Ҷ˺�������������߶κϲ����߶��� 
		T[rt].num=T[rt<<1].num+T[rt<<1|1].num-(T[rt<<1].rp&T[rt<<1|1].lp);
	}
}

void update(int rt,int L,int R,int l,int r,int x)
{
	if(l<=L&&R<=r)
	{
		T[rt].cnt+=x;   //�������䱻���ǵ����
		pushup(rt,L,R); //�������䱻���ǵ��ܳ��� 
		return;
	}
	int m=(L+R)>>1;
	if(l<=m) update(rt<<1,L,m,l,r,x);
	if(r>m) update(rt<<1|1,m+1,R,l,r,x);
	pushup(rt,L,R); //�������䱻���ǵ��ܳ���
}

int main()
{
	int i,n,x1,x2,y1,y2,ans;
	int l,r,pre,minx,maxx;
	while(~scanf("%d",&n))
	{ //���εĸ��� 
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		minx=0x3f3f3f3f;
		maxx=-0x3f3f3f3f;
		for(i=0;i<n;i++)
		{ //����������·������Ϸ��������
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			//��¼x�������ֵ����Сֵ 
			if(maxx<x2) maxx=x2;
			if(minx>x1) minx=x1;
			//��¼�ϱ߽���Ϣ
			a[i*2].l=x1;
			a[i*2].r=x2;
			a[i*2].h=y1;
			a[i*2].f=1;
			//��¼�±߽���Ϣ
			a[i*2+1].l=x1;
			a[i*2+1].r=x2;
			a[i*2+1].h=y2;
			a[i*2+1].f=-1;			
		}
		sort(a,a+n*2,cmp); //���������������� 
		build(1,minx,maxx-1);
		ans=0;
		pre=0;
		for(i=0;i<n*2;i++)
		{ //���������ó�ÿ�����߲�����
			update(1,minx,maxx-1,a[i].l,a[i].r-1,a[i].f); //���߶θ������� 
			ans+=abs(T[1].len-pre); //������߲���
			//������ num*2 �������߸߶�Ϊ���ں��߸߶�֮�� 
			ans+=(a[i+1].h-a[i].h)*(2*T[1].num); //�������߲���
			pre=T[1].len;
		}
		printf("%d\n",ans);
	}
}
