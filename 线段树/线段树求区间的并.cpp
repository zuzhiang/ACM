//http://www.cnblogs.com/scau20110726/archive/2013/05/07/3065418.html 
#include<stdio.h>
#include<string.h>
#define N 50010

struct node
{ //�߶����ڵ��ʾ���� 
	//lsum��ʾ�����������˿�ʼ�ж�������Ϊ��
	//lsum��ʾ����������Ҷ˿�ʼ�ж�������Ϊ��
	//sum��ʾ�������������Ϊ�յĳ���
	//markΪ�ӳٱ�ǣ�Ϊ0��1��ʾ����Ϊ�ջ�ǿգ�-1��ʾ��ȷ�� 
	int lsum,rsum,sum,mark;
} T[N*4];

int max(int a,int b)
{
	return a>b?a:b;
}

void pushup(int rt,int L,int R)
{ //��������Ϣ���ݸ�����
	//���׽ڵ����������ռ�Ϊ���������������ռ�Ϳ�Խ���������������ռ�����ֵ 
	T[rt].sum=max(max(T[rt<<1].sum,T[rt<<1|1].sum),T[rt<<1].rsum+T[rt<<1|1].lsum);	
	int m=(L+R)>>1;
	//������ӵ� sumΪ�������䣬���׵�lsumΪ���ӵ�lsum + �Һ��ӵ� lsum
	if(T[rt<<1].sum==m-L+1) T[rt].lsum=T[rt<<1].lsum+T[rt<<1|1].lsum;
	else T[rt].lsum=T[rt<<1].lsum;
	//����Һ��ӵ� sumΪ�������䣬���׵�rsumΪ���ӵ�rsum + �Һ��ӵ� rsum
	if(T[rt<<1|1].sum==R-m) T[rt].rsum=T[rt<<1].rsum+T[rt<<1|1].rsum;
	else T[rt].rsum=T[rt<<1|1].rsum;
}

void pushdown(int rt,int L,int R)
{ //��������Ϣ���ݸ����� 
	if(T[rt].mark!=-1)
	{ //����ӳٱ�ǲ�Ϊ-1����
		//�����׽ڵ���ӳٱ�Ǵ������� 
		T[rt<<1].mark=T[rt<<1|1].mark=T[rt].mark;
		T[rt].mark=-1;
		int m=(L+R)>>1;
		//�����Լ����ӳٱ��ȷ�� lsum��rsum��sum ��ֵ 
		if(T[rt<<1].mark) T[rt<<1].lsum=T[rt<<1].rsum=T[rt<<1].sum=0;
		else T[rt<<1].lsum=T[rt<<1].rsum=T[rt<<1].sum=m-L+1;
		if(T[rt<<1|1].mark) T[rt<<1|1].lsum=T[rt<<1|1].rsum=T[rt<<1|1].sum=0;
		else T[rt<<1|1].lsum=T[rt<<1|1].rsum=T[rt<<1|1].sum=R-m;			
	}
}

void build(int rt,int L,int R)
{ //���� 
	T[rt].lsum=T[rt].rsum=T[rt].sum=R-L+1;
	T[rt].mark=0;
	if(L==R) return;
	int m=(L+R)>>1;
	build(rt<<1,L,m);
	build(rt<<1|1,m+1,R);
}

void update(int rt,int L,int R,int l,int r,int x)
{ //���� 
	if(l<=L&&R<=r)
	{
		T[rt].mark=x;
		//�����Լ����ӳٱ��ȷ�� lsum��rsum��sum ��ֵ
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
{ //��ѯ 
	if(T[rt].lsum==x) return L; //�����ǰ����� lsum�� x ���򷵻���˵� 
	pushdown(rt,L,R);
	int m=(L+R)>>1;
	if(T[rt<<1].sum>=x) return query(rt<<1,L,m,x); //������������� 
	else if(T[rt<<1].rsum+T[rt<<1|1].lsum>=x) return m-T[rt<<1].rsum+1; //�������������� 
	else return query(rt<<1|1,m+1,R,x); //������������� 
}

int main()
{
	int i,n,m,q,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{ //��ĸ����Ͳ������� 
		build(1,1,n);
		while(m--)
		{
			scanf("%d",&q);
			if(q==1)
			{ //ѯ�� 
				scanf("%d",&a);
				if(T[1].sum<a) printf("0\n"); //������������䶼��������Ϊ 0 
				else 
				{
					ans=query(1,1,n,a);
					printf("%d\n",ans);
					update(1,1,n,ans,ans+a-1,1); //����Ӧ������Ϊ�� 
				}				
			}
			else
			{ //���� 
				scanf("%d%d",&a,&b);
				update(1,1,n,a,a+b-1,0); //�������ÿ� 
			}
		}
	}
	return 0;
}
