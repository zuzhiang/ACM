/*
��չKMP�㷨������ǰ׺��ģʽ���������ǰ׺�ĳ��ȣ���extend�洢 
*/
#include<stdio.h>
#include<string.h>

int ls,lt;
int next[1000],extend[1000];
char s[1000],t[1000];

//���next�Ĺ��̾���t��t�Լ�ƥ��Ĺ��� 
void get_next()
{ //next�洢����t�ĺ�׺��ǰ׺�������ǰ׺�ĳ��� 
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
	int i,a=0,p=0; //aΪƥ����ʼλ�ã�pΪƥ����Զλ�� 
	get_next();	
	for(i=0;i<ls;i++)
	{
		if(i>=p || i+next[i-a]>=p)//i>=p�����ã��ٸ��������ӣ�s��t��һ�ַ���ͬ
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
