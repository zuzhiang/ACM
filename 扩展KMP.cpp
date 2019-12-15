/*
扩展KMP算法求主串前缀和模式串的最长公共前缀的长度，用extend存储 
*/
#include<stdio.h>
#include<string.h>

int ls,lt;
int next[1000],extend[1000];
char s[1000],t[1000];

//求解next的过程就是t和t自己匹配的过程 
void get_next()
{ //next存储的是t的后缀和前缀的最长公共前缀的长度 
    int i,a=0,p=0;
    next[0]=lt;
    for(i=1;i<lt;i++)
    {
		if(i>=p || i+next[i-a]>=p)
		{
			if(i>=p) p=i;
			while(p<lt && t[p]==t[p-i]) p++;			
			next[i]=p-i;
			a=i;
		}
		else next[i]=next[i-a];
	}
}

void ex_kmp()
{
	int i,a=0,p=0; //a为匹配起始位置，p为匹配最远位置 
	get_next();	
	for(i=0;i<ls;i++)
	{
		if(i>=p || i+next[i-a]>=p)//i>=p的作用：举个典型例子，s和t无一字符相同
		{
			if(i>=p) p=i;
			while(p<ls && p-i<lt && s[p]==t[p-i])	p++;			
			extend[i]=p-i;
			a=i;
		}
		else extend[i]=next[i-a];
	}
}

int main()
{
	int i,j;
	while(~scanf("%s%s",s,t))
	{
		ls=strlen(s);
		lt=strlen(t);
		ex_kmp();
		for(i=0;i<ls;i++) printf("%d ",extend[i]);
		printf("\n");
	}
	return 0;
}
/*
aaaaaabbb
aaaaac

abcabac
abc
*/
