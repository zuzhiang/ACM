/*
含有n个元素的集合的非空子集个数为2^n,那么二进制的1~(1<<n)-1
则对应着每个子集的元素下标。
*/
#include<stdio.h>
void subset(int n)  
{  //n为集合元素个数
	int i,j; 
    for(i=1;i<(1<<n);i++)
    { //枚举1~(1<<n)-1的所有二进制数 
        for(j=0;j<n;j++) //输出二进制数位为1的下标，从左到右递增 
            if(i&(1<<j)) printf("%d ",j); //输出的j为子集的下标 
        printf("\n");
    }  
}  
  
int main()  
{  
    int n;  
    while(scanf("%d", &n))  
    {
        subset(n);  
    }  
    return 0;  
}  
