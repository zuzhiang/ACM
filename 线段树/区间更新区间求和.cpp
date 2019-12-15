/*
�߶���������£�������ʹ���
�����������ʱ��ĳ���䶼����һ������ʾ 
������ʱĳ���䶼���ĳ�һ��������pushdown��update�е�+=Ӧ��Ϊ= 

ע�⣺
����ʱ���ڵ��±�Ϊ1�������Ϊ����ұ����䡣ԭ�����±��1��ʼ��
*/
#include<stdio.h>
#define MAXN 100010
typedef long long LL;

LL a[MAXN];

struct node
{ //valΪ�ڵ�Ϊ���ڵ�������ܺͣ�markΪ�ӳٱ��
	LL val,mark;
} tree[MAXN*4];

//���ã������ӳٱ�� 
void pushdown(int root,int len)
{ //�������߶�����ǰ�ڵ� / ���䳤�� 
	if(tree[root].mark)	
	{ //������ڵ����ӳٱ�ǲ������´��� 
		tree[root<<1].mark+=tree[root].mark;
		tree[root<<1|1].mark+=tree[root].mark;
		//��Ϊ֮ǰֻ�Ѽӵ���ֵ�ӵ��˸��ڵ��ϣ�����Ҫ�ӵ����������ĸ��ڵ��� 
		tree[root<<1].val+=(LL)(tree[root].mark*(len-len/2));
		tree[root<<1|1].val+=(LL)(tree[root].mark*(len/2)); //�˴�(len/2)��������� 
		tree[root].mark=0;
	}
}

//���ã����� 
void build(int root,int L,int R)
{ //�������߶�����ǰ�ڵ� / ���俪ʼλ�� / �������λ�� 
	tree[root].mark=0;    //�����ӳٱ�� 
	if(L==R) tree[root].val=a[L];
	else
	{
		int mid=(L+R)>>1;
		build(root<<1,L,mid);        //�ݹ鹹�������� 
		build(root<<1|1,mid+1,R);  //�ݹ鹹�������� 
		tree[root].val=tree[root<<1].val+tree[root<<1|1].val; //����� 
	}	
}

//���ã�����������£�������ÿ����������add�� 
void update(int root,int L,int R,int l,int r,int add)
{ //�������߶�����ǰ�ڵ� / ������ / ��Ҫ���µ����� / ���µ�ֵ 
	if(l<=L && R<=r)
	{
		tree[root].val+=(LL)(add*(R-L+1)); //���ϵ�ֵΪ���䳤��*add 
		tree[root].mark+=add; 
		return;
	}
	pushdown(root,R-L+1);
	int mid=(L+R)>>1;
	if(l<=mid) update(root<<1,L,mid,l,r,add);       //���������� 
	if(r>mid) update(root<<1|1,mid+1,R,l,r,add);  //���������� 
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val; //���µ�ǰ�ڵ������� 
}

//���ã���ѯ 
LL query(int root,int L,int R,int l,int r)
{ //�������߶�����ǰ�ڵ� / ������ / ��Ҫ��ѯ������ 
	if(l<=L && R<=r) return tree[root].val;
	pushdown(root,R-L+1); //�����ӳٱ�� 
	int mid=(L+R)>>1;
	LL ans=0;
	if(l<=mid) ans+=query(root<<1,L,mid,l,r);       //�����������ĺ� 
	if(r>mid) ans+=query(root<<1|1,mid+1,R,l,r);  //�����������ĺ� 
	return ans;
}
