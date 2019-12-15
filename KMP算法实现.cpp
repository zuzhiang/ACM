//next[i]就是前面长度为i的字符串前缀和后缀相等的最大长度，也即索引为i的字符失配时的前缀函数。
#include<stdio.h>
#include<string.h>
 
//目标串即主串，模式串即子串

int l1,l2,next[1000],nextval[1000]; //l1、l2分别为目标串和模式串的长度
char s[1000],t[1000];	//s数组储存目标串内容，t数组储存模式串内容

//next[i]的意思是在第i个字符之前的字符与该模式串从第一个位置开始的最大匹配长度
//也可以理解为从第0~i-1个字符的字符串中前缀和后缀最长的匹配长度 

void GetNext()	//用next数组做，效率比用nextval数组做稍慢一点
{
	int i=0,j=-1;	//用模式串匹配模式串（目标串），j指向目标串的下标，k指向模式串的下标
	next[0]=-1;		//next数组第0个位置规定为-1
	while(i<l2)		//直到目标串匹配完毕
	{
		if(j==-1 || t[i]==t[j]) //如果模式串下标为第一个字符，或者模式串和目标串当前字符相同时
		{
			i++; //模式串和目标串的指针都加1，匹配下一个字符
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}

/* nextval[i]的值在next[i]值上稍微有所调整。第一个字符对应的值仍为-1，其他的如果nextval[i]的值对应的字符与当前字符相同，则当前位置nextval值取相对应的nextal值(不是next的值)，如果不同，则维持当前位置next的值。*/

void GetNextval()
{
	int i=0,j=-1;
	nextval[0]=-1;
	while(i<l2)
	{
		if(j==-1 || t[i]==t[j])
		{
			i++;
			j++;
			if(t[i]!=t[j])
				nextval[i]=j;
			else nextval[i]=nextval[j];
		}
		else j=nextval[j];
	}
}

int kmp()
{
	int i=0,j=0; //i指向目标串的下标，j指向模式串的下标
	//GetNext();
	GetNextval();
	while(i<l1 && j<l2) //当模式串和目标串都未匹配完毕时
	{
		if(j==-1 || s[i]==t[j]) //如果模式串下标为第一个字符，或者模式串和目标串当前字符相同时
		{
			i++; //模式串和目标串的指针都加1，匹配下一个字符
			j++;
		}
		//else j=next[j];
		else j=nextval[j]; //否则跳到模式串当前指针对应的nextval的值指向的位置
	}
	if(j>=l2) return (i-l2); //如果模式串匹配完毕，返回匹配的首位置
	else return -1; //如果模式串未匹配完毕，目标串匹配完毕，则返回匹配失败
}

int main()
{	
	int value;
	printf("请输入目标串:\n");
	scanf("%s",s);
	l1=strlen(s);
	printf("请输入模式串:\n");
	scanf("%s",t);
	l2=strlen(t);
	value=kmp();
	printf("模式串在目标串中首次出现的位置为：%d\n",value);
	return 0;
}

/*
aaabaaaab 
aaaab
*/
