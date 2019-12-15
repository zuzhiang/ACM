/*
当只能交换相邻两数时，最少交换次数为该序列的逆序数。
当可以交换任意两数时，最少交换次数为该序列长度 - 循环节个数 
*/
/*
该代码适合于当序列为 1~n 时，如果不是可以用 map容器解决 
*/
#include<stdio.h> 
#include<string.h>
#define maxn 100010

int a[maxn],vis[maxn];

int main()
{
	int i,n,x,num,ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		num=0; //循环节个数 
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		{ //遍历每一个位置 
			if(!vis[i])
			{ //如果未访问过 
				x=i;
				while(!vis[x])
				{ //寻找该数所属的循环节 
					vis[x]=1;
					x=a[x];
				}
				num++; //循环节个数+1 
			}
		}
		ans=n-num;
		printf("%d\n",ans);
	}
	return 0;
}
