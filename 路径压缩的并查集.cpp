#include<stdio.h>
#include<string.h>

int f[500];

void init(int n) //���鼯��ʼ��
{
    int i;
    for(i=1;i<=n;i++) f[i]=i;
}

int find(int x) //�ڲ��鼯��Ѱ��ĳ��Ԫ�صĴ���Ԫ��
{ //·��ѹ���Ĳ��鼯 
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int Union(int x,int y) //�ϲ�����Ԫ�����ڵļ���
{
	int fx,fy;
    fx= find(x);
    fy= find(y);
    if(fx==fy) return 0;
    f[fy]=fx;
    return 1;
}

int main()
{
	int i,n,a,b;
	while(~scanf("%d",&n))
	{
		init(n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		for(i=1;i<=n;i++) printf("%d ",find(i));
		printf("\n");
	}
	return 0;
}
