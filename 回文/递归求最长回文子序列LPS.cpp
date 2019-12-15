//有很多重复计算，耗时长 
#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int lps(char *s,int i,int j)
{
	if(i==j) return 1; //若只有一个元素，回文长度为1 
	if(i>j) return 0;  //退出 
	if(s[i]==s[j]) return lps(s,i+1,j-1)+2; //若首尾相同 
	return max(lps(s,i,j-1),lps(s,i+1,j));  //若首尾不同 
}

int main()
{
	int i,len,ans;
	char s[1000];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		ans=lps(s,0,len-1);
		printf("%d\n",ans);
	}
	return 0;
}
