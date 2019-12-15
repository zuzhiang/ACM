#include<stdio.h>
#include<string.h>
#define MAX 500

int n,m,dgr[MAX],map[MAX][MAX]; //drg记录节点入度 
int queue[MAX];

/*
返回值：
-1：有环
0： 结果不唯一
1： 有唯一解 
*/
int tuopu()
{
	int i,j,f,pos,cnt,tol,tmp[MAX];	
	for(i=1;i<=n;i++) tmp[i]=dgr[i]; //因节点的入度值会改变，故用tmp数组存储 
	tol=0;
	f=1;
	for(i=0;i<n;i++)
	{
		cnt=0;  //入度为0的节点数 
		for(j=1;j<=n;j++)
			if(tmp[j]==0)
			{
				pos=j;
				cnt++;
			}
		if(cnt==0) return -1; //无入度为0的节点，则一定有环 
		else if(cnt>1) f=0;   //拓扑排序结果不唯一，注意必须是令f=0,直接返回可能会影响之后点的判断 
		queue[tol++]=pos;
		tmp[pos]=-1;          //相当于删除该节点
		for(j=1;j<=n;j++)     //把与该节点相邻的边删除
			if(map[pos][j])
				tmp[j]--;
	}
	return f;
}

int main()
{
	int i,j,f,val;
	int u,v;
	while(~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map));
		memset(dgr,0,sizeof(dgr));
		f=0;
		//边输入边判断， 
		for(i=1;i<=m;i++) 
		{ //输入A<B
			scanf("%d%d",&u,&v);
			if(f) continue;
			map[u][v]=1;
			dgr[v]++;
			val=tuopu();
			if(val==-1)
			{
				printf("有环！\n");
				f=1;
			}
			else if(val==1)
			{
				for(i=0;i<n;i++) printf("%d ",queue[i]);
				printf("\n");
			}
		}
		if(f==0) printf("无唯一解!\n");
	}
	return 0;
}
