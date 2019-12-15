//http://www.cnblogs.com/scau20110726/archive/2013/03/21/2972808.html
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

double pos[205];

struct node
{ //����������ε����±� 
	double l,r,h; //���Һ����꣬������ 
	int f; //-1Ϊ�ϱ߽磬1Ϊ�±߽� 
} a[205];

struct tree
{ //�߶����� i ��Ҷ�ӽڵ㱣����ǵ� i ���߶ε���Ϣ�����ǵ����Ϣ��(i��1��ʼ)
	int cnt;    //�����䱻�����߶����θ��ǹ�����Ϊ0�����ֻ���ǹ�һ�������� 
	double len; //�����䱻���ǵ��ܳ��� 
} T[205*4]; 

int cmp(node x,node y)
{
	return x.h<y.h;
}

int find(int l,int r,double val)
{ //���ֲ��� val �� pos �����е�λ�� 
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
{ //���� 
	T[rt].cnt=0;
	T[rt].len=0;
	if(L==R) return;
	int m=(L+R)>>1;
	build(rt<<1,L,m);
	build(rt<<1|1,m+1,R);
}

void get_len(int rt,int L,int R)
{
	if(T[rt].cnt) T[rt].len=pos[R]-pos[L-1]; //��0�����θ���
	else if(L==R) T[rt].len=0; //�Ѿ�����һ���߶�
	//��һ���߶ε���û�����θ��ǣ����串�ǳ���Ϊ��������֮�� 
	else T[rt].len=T[rt<<1].len+T[rt<<1|1].len;
}

void update(int rt,int L,int R,int l,int r,int x)
{
	if(l<=L&&R<=r)
	{
		T[rt].cnt+=x;    //�������䱻���ǵ���� 
		get_len(rt,L,R); //�������䱻���ǵ��ܳ��� 
		return;		
	}
	int m=(L+R)>>1;
	if(l<=m) update(rt<<1,L,m,l,r,x);
	if(r>m) update(rt<<1|1,m+1,R,l,r,x);
	get_len(rt,L,R); //�������䱻���ǵ��ܳ���
}

int main()
{
	int i,n,l,r,num,cas=1;
	double x1,x2,y1,y2;
	while(~scanf("%d",&n)&&n)
	{ //���εĸ��� 
		for(i=0;i<n;i++)
		{ //����������·������Ϸ�������� 
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
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
			//��¼������ 
			pos[i*2]=x1;
			pos[i*2+1]=x2;
		}
		sort(a,a+2*n,cmp); //���������������� 
		sort(pos,pos+2*n); //����������������
		num=unique(pos,pos+2*n)-pos;
		build(1,1,num); //���� 
		double ans=0;
		for(i=0;i<2*n;i++)
		{ //���������ó�ÿ�����߲����� 
			l=find(0,num,a[i].l)+1; //��ɢ����ߵ���˵� 
			r=find(0,num,a[i].r);   //��ɢ����ߵ��Ҷ˵� 
			update(1,1,num,l,r,a[i].f); //�������߶�ȥ���� 
			ans+=(a[i+1].h-a[i].h)*T[1].len; //����߶�*���䳤�� 
		}
		printf("Test case #%d\n",cas++);
		printf("Total explored area: %.2f\n\n",ans);
	}
	return 0;
}
