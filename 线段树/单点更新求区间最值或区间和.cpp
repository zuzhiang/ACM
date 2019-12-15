/*
线段树单点更新，求区间最值或区间和代码
以求区间最大值为演示，若求区间最小值则将max函数处全改为min函数即可
若求区间和则将相应部分改为注视掉的部分 

注意：
建树时根节点下标为1，区间皆为左闭右闭区间。原数组下标从1开始。 
*/
#include<stdio.h>

//a为原数组，tree为线段树数组，其大小为原数组的4倍 
int a[200100],tree[200100*4];

int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}

//作用：递归构造线段树;
void build(int root,int L,int R)
{//参数：线段树当前节点 / 区间开始位置 / 区间结束位置 
	if(L==R) tree[root]=a[L]; //若只有一个节点，记录该元素
	else 
	{
		int mid=(L+R)>>1;
		//递归构造左子树
		build(root<<1,L,mid);
		//递归构造右子树
		build((root<<1)+1,mid+1,R);
		//回溯时得到当前节点的信息
		tree[root]=max(tree[root<<1],tree[(root<<1)+1]);
		/*求区间和时代码
		tree[root]=tree[root<<1]+tree[(root<<1)+1];
		求区间和时代码*/
	}
}

//作用：查询区间最值或区间和 
int query(int root,int L,int R,int l,int r)
{//参数：当前查询节点 / 大区间 / 所要查询的区间
	int p1=0,p2=0;
	if (L >= l && R <= r) return tree[root]; //若查询区间包括当前区间，则返回tree[root]	
	int mid=(L+R)>>1;
	if(l<=mid) p1=query(root<<1,L,mid,l,r);        //计算左子树的最值或区间和 
	if(r>mid) p2=query((root<<1)+1,mid+1,R,l,r);   //计算右子树的最值或区间和	
	return max(p1,p2);       //返回结果
	/*求区间和时代码
	int ans=0; 
	if(l<=mid) ans+=query(root<<1,L,mid,l,r);        //计算左子树的最值或区间和 
	if(r>mid) ans+=query((root<<1)+1,mid+1,R,l,r);   //计算右子树的最值或区间和	
	return ans;       //返回结果
	求区间和时代码*/
}

//作用：单点更新 
void update(int root,int L,int R,int ind,int add)
{//参数：线段树根节点 / 大区间 / 待更新节点在数组a中的下标 / 更新的值
	//当前区间只有一个元素，即找到了要更新的节点
	if(L==R)
	{
		tree[root]+=add; //此处为该节点值加上add，若为=add则为直接更改节点值
		return ;
	}
	int mid=(L+R)>>1;
	if(ind<=mid) update(root<<1,L,mid,ind,add); //更新左子树
	else update((root<<1)+1,mid+1,R,ind,add);   //更新右子树
	//回溯更新父亲节点
	tree[root]=max(tree[root<<1],tree[(root<<1)+1]);
	/*求区间和时代码
	tree[root]=tree[root<<1]+tree[(root<<1)+1];
	求区间和时代码*/
}
