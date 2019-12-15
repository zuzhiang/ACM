/*
�߶���������£���������ֵ������ʹ���
�����������ֵΪ��ʾ������������Сֵ��max������ȫ��Ϊmin��������
�������������Ӧ���ָ�Ϊע�ӵ��Ĳ��� 

ע�⣺
����ʱ���ڵ��±�Ϊ1�������Ϊ����ұ����䡣ԭ�����±��1��ʼ�� 
*/
#include<stdio.h>

//aΪԭ���飬treeΪ�߶������飬���СΪԭ�����4�� 
int a[200100],tree[200100*4];

int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}

//���ã��ݹ鹹���߶���;
void build(int root,int L,int R)
{//�������߶�����ǰ�ڵ� / ���俪ʼλ�� / �������λ�� 
	if(L==R) tree[root]=a[L]; //��ֻ��һ���ڵ㣬��¼��Ԫ��
	else 
	{
		int mid=(L+R)>>1;
		//�ݹ鹹��������
		build(root<<1,L,mid);
		//�ݹ鹹��������
		build((root<<1)+1,mid+1,R);
		//����ʱ�õ���ǰ�ڵ����Ϣ
		tree[root]=max(tree[root<<1],tree[(root<<1)+1]);
		/*�������ʱ����
		tree[root]=tree[root<<1]+tree[(root<<1)+1];
		�������ʱ����*/
	}
}

//���ã���ѯ������ֵ������� 
int query(int root,int L,int R,int l,int r)
{//��������ǰ��ѯ�ڵ� / ������ / ��Ҫ��ѯ������
	int p1=0,p2=0;
	if (L >= l && R <= r) return tree[root]; //����ѯ���������ǰ���䣬�򷵻�tree[root]	
	int mid=(L+R)>>1;
	if(l<=mid) p1=query(root<<1,L,mid,l,r);        //��������������ֵ������� 
	if(r>mid) p2=query((root<<1)+1,mid+1,R,l,r);   //��������������ֵ�������	
	return max(p1,p2);       //���ؽ��
	/*�������ʱ����
	int ans=0; 
	if(l<=mid) ans+=query(root<<1,L,mid,l,r);        //��������������ֵ������� 
	if(r>mid) ans+=query((root<<1)+1,mid+1,R,l,r);   //��������������ֵ�������	
	return ans;       //���ؽ��
	�������ʱ����*/
}

//���ã�������� 
void update(int root,int L,int R,int ind,int add)
{//�������߶������ڵ� / ������ / �����½ڵ�������a�е��±� / ���µ�ֵ
	//��ǰ����ֻ��һ��Ԫ�أ����ҵ���Ҫ���µĽڵ�
	if(L==R)
	{
		tree[root]+=add; //�˴�Ϊ�ýڵ�ֵ����add����Ϊ=add��Ϊֱ�Ӹ��Ľڵ�ֵ
		return ;
	}
	int mid=(L+R)>>1;
	if(ind<=mid) update(root<<1,L,mid,ind,add); //����������
	else update((root<<1)+1,mid+1,R,ind,add);   //����������
	//���ݸ��¸��׽ڵ�
	tree[root]=max(tree[root<<1],tree[(root<<1)+1]);
	/*�������ʱ����
	tree[root]=tree[root<<1]+tree[(root<<1)+1];
	�������ʱ����*/
}
