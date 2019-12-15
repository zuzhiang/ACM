//解题思路：直接修改标准KMP函数，当匹配成功不是跳出循环，而是直接按最后一个字符失配的情况去滑动模式串，以获取下一个可能出现的匹配。

#include<stdio.h>
#include<string.h>

int l1,l2,next[1000];
char s[1000],t[1000];

void pnext()
{ //未经优化的求next数组方法
    int i=0,j=-1;
    next[0] = -1;
    while(i<l2)
	{
        if(j==-1||t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

int kmp()
{
    int i=0,j=0,sum=0;	//多了个计数变量sum
    pnext();
    while(i<l1)  //只需要目标串指针小于目标串长度即可，这点和单纯的kmp不一样
	{
        if(s[i]==t[j] || j==-1)
		{
			i++;
			j++;
		}
        else if(j<l2) j = next[j];
/*******************************/
//只是比KMP算法增加了这些内容
        if(j>=l2)
        {
            sum++;
            j=next[l2];////求可重复的子串个数
	    //j=0;  //求不可重复的子串个数
        }
/*******************************/
    }
    return sum;
}

int main()
{
	int v;
	while(1)
	{
		printf("请输入目标串:\n");
		scanf("%s",s);
		l1=strlen(s);
		printf("请输入模式串:\n");
		scanf("%s",t);
		l2=strlen(t);
		v=kmp();
		printf("目标串中模式串的个数为:%d\n",v);
	}	
	return 0;
}
