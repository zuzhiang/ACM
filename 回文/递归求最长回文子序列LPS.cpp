//�кܶ��ظ����㣬��ʱ�� 
#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int lps(char *s,int i,int j)
{
	if(i==j) return 1; //��ֻ��һ��Ԫ�أ����ĳ���Ϊ1 
	if(i>j) return 0;  //�˳� 
	if(s[i]==s[j]) return lps(s,i+1,j-1)+2; //����β��ͬ 
	return max(lps(s,i,j-1),lps(s,i+1,j));  //����β��ͬ 
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
