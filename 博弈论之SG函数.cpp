//http://blog.csdn.net/luomingjun12315/article/details/45555495
/*
sg保存的是不属于其后继节点 sg值集合的最小非负整数
若sg的函数值为 0 则为必败态，反之为必胜态
如果有 n堆石子按照相同的取法操作，则 n堆石子 sg函数值
的异或结果为 0则为必败态，反之为必胜态。 
*/
#include<stdio.h>
#include<string.h>
#define N 11 //取石子的方案数 
#define MAXN 1005 //最多有多少个石子 

int f[N];   //可以取走的石子个数
int sg[MAXN];  //0~n的SG函数值
int vis[MAXN]; //vis[]:mex{}

void getSG(int n)
{ //SG[n]为 0为必败点，非 0为必胜点 
	int i,j;
	memset(sg,0,sizeof(sg));
	for(i=1;i<=n;i++)
	{ //有 i 个石子时的 SG函数值 
		memset(vis,0,sizeof(vis)); //每一次将上一状态的后继重置 
		for(j=0;f[j]<=i&&j<N;j++)
		{ //将后继状态的SG函数值进行标记
			vis[sg[i-f[j]]]=1; //后继为 i个石子取 f[j]个后剩下的 
		}
		for(j=0;j<= n;j++)
			if(!vis[j])
			{ //求mes{}中未出现的最小的非负整数
				sg[i] = j;
				break;
			}
	}
}

int main()
{
	int i,n;
	for(i=0;i<=10;i++) f[i]=1<<i;	
	getSG(1001);
	while(~scanf("%d",&n))
	{		
		if(sg[n]) printf("Kiki\n");
		else printf("Cici\n");
	}
	return 0;
}
