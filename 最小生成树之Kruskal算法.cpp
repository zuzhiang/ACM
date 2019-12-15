/*
Kruskal����С�������㷨
ԭ���Ա߽��в�����������δ����ı���ѡȨֵ��С�ģ�
������ʹ�ڵ��γɻ�·����룬ֱ������n-1���߽����� 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXN 5000
using namespace std; 

int q,total=0,f[MAXN]; //nΪ�ڵ������totalΪ�ߵ�������fΪ���鼯������

struct node //������ʼ�ڵ�/��ֹ�ڵ��Ȩֵ�Ľṹ��
{
    int u,v,w; //uΪ��ʼ�ڵ㣬vΪ��ֹ�ڵ㣬w��Ȩֵ
} a[MAXN];

int cmp(node x,node y) //���ṹ�����鰴Ȩֵ��������
{
    return x.w<y.w;
}

void init(int n) //���鼯��ʼ��
{
    int i;
    for(i=1;i<=n;i++) f[i]=i;
}

int find(int x) //�ڲ��鼯��Ѱ��ĳ��Ԫ�صĴ���Ԫ��
{
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int Union(int x,int y) //�ϲ�����Ԫ�����ڵļ���
{
	int fx,fy;
    fx= find(x);
    fy= find(y);
    if(fx==fy) return 0;
    f[fx]=fy;
    return 1;
}

int main()
{
	int i,t,n,m,cnt,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(n);
		for(i=0;i<m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		sort(a,a+total,cmp);   //���ṹ�����鰴Ȩֵ��������
		cnt=0;
		ans=0;		
		for(i=0;i<m;i++)
		{
		    if(Union(a[i].u,a[i].v))
		    {
		    	ans+=a[i].w;
		    	cnt++;
			}
			if(cnt>=n-1) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
