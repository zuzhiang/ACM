//http://blog.163.com/zhaohai_1988/blog/static/2095100852012716105847112/
#include<stdio.h>
#include<string.h>

#define MAXN 110010
char Ma[MAXN*2];
int Mp[MAXN*2];

/*
Mp[id]-1就是该回文子串在原串中的长度（包括‘#’）
需要增加两个变量id和mx，其中id表示最大回文子串中心的位置，mx则为id+Mp[id] ,也就是最大回文子串的边界
然后可以得到一个非常神奇的结论，这个算法的关键点就在这里了：如果mx > i，那么
Mp[i]=MIN(P[2*id-i],mx-i)。

记j = 2 * id - i，也就是说 j 是 i 关于 id 的对称点。
if (mx - i > P[j]) 
    P[i] = P[j];
else //P[j] >= mx - i 
    P[i] = mx - i; // P[i] >= mx - i，取最小值，之后再匹配更新。

*/

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

void Manacher(char s[],int len)
{
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0;i<len;i++)
	{
		Ma[l++]=s[i];
		Ma[l++]='#';
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0;i<l;i++)
	{
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
		if(i+Mp[i]>mx)
		{
			mx=i+Mp[i];
			id=i;
		}
	}
}

int main()
{
	int i,ans,len;
	char s[110010];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		Manacher(s,len);
		for(i=0;i<2*len+2;i++)
			printf("%c ",Ma[i]);
		printf("\n");
		for(i=0;i<2*len+2;i++)
			printf("%d ",Mp[i]);
		printf("\n");
		i=0;
		ans=0;
		for(i=0;i<2*len+2;i++)
			if(Mp[i]-1>ans) ans=Mp[i]-1;
		printf("%d\n",ans);
	}
	return 0;
}
