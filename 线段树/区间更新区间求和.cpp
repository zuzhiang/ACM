/*
线段树区间更新，求区间和代码
以求区间更新时是某区间都加上一个数演示 
若更新时某区间都更改成一个数，则pushdown和update中的+=应改为= 

注意：
建树时根节点下标为1，区间皆为左闭右闭区间。原数组下标从1开始。
*/
#include<stdio.h>
#define MAXN 100010
typedef long long LL;

LL a[MAXN];

struct node
{ //val为节点为根节点的树的总和，mark为延迟标记
	LL val,mark;
} tree[MAXN*4];

//作用：设置延迟标记 
void pushdown(int root,int len)
{ //参数：线段树当前节点 / 区间长度 
	if(tree[root].mark)	
	{ //如果根节点有延迟标记才能往下传递 
		tree[root<<1].mark+=tree[root].mark;
		tree[root<<1|1].mark+=tree[root].mark;
		//因为之前只把加的总值加到了根节点上，现在要加到左右子树的根节点上 
		tree[root<<1].val+=(LL)(tree[root].mark*(len-len/2));
		tree[root<<1|1].val+=(LL)(tree[root].mark*(len/2)); //此处(len/2)必须加括号 
		tree[root].mark=0;
	}
}

//作用：建树 
void build(int root,int L,int R)
{ //参数：线段树当前节点 / 区间开始位置 / 区间结束位置 
	tree[root].mark=0;    //设置延迟标记 
	if(L==R) tree[root].val=a[L];
	else
	{
		int mid=(L+R)>>1;
		build(root<<1,L,mid);        //递归构造左子树 
		build(root<<1|1,mid+1,R);  //递归构造右子树 
		tree[root].val=tree[root<<1].val+tree[root<<1|1].val; //计算和 
	}	
}

//作用：进行区间更新（区间内每个数都加上add） 
void update(int root,int L,int R,int l,int r,int add)
{ //参数：线段树当前节点 / 大区间 / 所要更新的区间 / 更新的值 
	if(l<=L && R<=r)
	{
		tree[root].val+=(LL)(add*(R-L+1)); //加上的值为区间长度*add 
		tree[root].mark+=add; 
		return;
	}
	pushdown(root,R-L+1);
	int mid=(L+R)>>1;
	if(l<=mid) update(root<<1,L,mid,l,r,add);       //更新左子树 
	if(r>mid) update(root<<1|1,mid+1,R,l,r,add);  //更新右子树 
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val; //更新当前节点代表的树 
}

//作用：查询 
LL query(int root,int L,int R,int l,int r)
{ //参数：线段树当前节点 / 大区间 / 所要查询的区间 
	if(l<=L && R<=r) return tree[root].val;
	pushdown(root,R-L+1); //设置延迟标记 
	int mid=(L+R)>>1;
	LL ans=0;
	if(l<=mid) ans+=query(root<<1,L,mid,l,r);       //计算左子树的和 
	if(r>mid) ans+=query(root<<1|1,mid+1,R,l,r);  //计算右子树的和 
	return ans;
}
