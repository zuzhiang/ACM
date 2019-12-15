/*
尺取法：
整个过程分为4步：

　　　　1.初始化左右端点

　　　　2.不断扩大右端点，直到满足条件

　　　　3.如果第二步中无法满足条件，则终止，否则更新结果

　　　　4.将左端点扩大1，然后回到第二步

时间复杂为O(n)

给定一个长度为n的数列以及一个整数S，求总和不小于S的连续子序列的长度的最小值。如果解不存在，输出0.
*/
#include<stdio.h>
int main()
{
    //n为数列的长度，S为题目给定要不小于的总和，sum为当前数列的总和，min为长度的最小值，a为保存数列元素的数组
    int i,s,t,n,S,sum,min,a[1000];//i为循环变量，s为尺取时sum所包含的数组和的开始位置，t为尺取时sum所包含的数组和的结束位置
    scanf("%d %d",&n,&S);   //输入数列元素个数和不小于的总和
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    s=t=sum=0;  //开始位置，结束位置，当前数列总和初始化为0
    min=n+1;    //长度最小值初始化为n+1
    while(1)    //尺取过程
    {
        while(t<n && sum<S)
        {
            sum=sum+a[t];
            t++;
        }
        if(sum<S) break;
        if((t-s)<min) min=t-s;
        sum=sum-a[s];
        s++;
    }
    if(min>n) printf("0\n");
    else printf("%d\n",min);
    return 0;
}
