//http://blog.163.com/zhaohai_1988/blog/static/2095100852012716105847112/
#include<stdio.h>
#include<string.h>

const int MAXN=110010;
int Ma[MAXN*2];
int Mp[MAXN*2];

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

void Manacher(int s[],int len)
{
	int l=0;
	Ma[l++]=-1;
	Ma[l++]=-2;
	for(int i=0;i<len;i++)
	{
		Ma[l++]=s[i];
		Ma[l++]=-2;
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0;i<l;i++)
	{
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		//和朴素的Manacher算法只增加了一个判断条件 
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]] /***/ && Ma[i-Mp[i]]<=Ma[i-Mp[i]+2]/***/) Mp[i]++;
		if(i+Mp[i]>mx)
		{
			mx=i+Mp[i];
			id=i;
		}
	}
}

int main()
{
	int i,j,t,n,ans,h[100010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&h[i]);
		Manacher(h,n);
		ans=0;
		for(i=0;i<n*2+2;i++)
			if(Mp[i]-1>ans) ans=Mp[i]-1;
		printf("%d\n",ans);
	}
	return 0;
}
