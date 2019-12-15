/*
问题；有 n 种物品，每种物品有重量 w[i] 和价值 v[i]，
从中选出几件 物品，求重量不超过 B 时的最大价值。
注意，物品的重量很大（w[i]<10e9）。 

 dp[i] 的意思变成了当价值为 i 时物品的最小重量。
 然后再找一个满足重量 <=B 的价值的最大值即可。
*/
#include<stdio.h>  
#include<string.h>  
#define inf 0x3f3f3f3f  
  
int min(int a,int b)  
{  
    return a<b? a:b;  
}  
  
int main()  
{  
    int i,j,t,n,b,sum,ans,w[505],v[505],dp[5005];  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&b);  
        sum=0;  
        for(i=0;i<n;i++)  
        {  
            scanf("%d%d",&w[i],&v[i]);  
            sum+=v[i]; //计算价值之和   
        }  
        memset(dp,inf,sizeof(dp));  
        dp[0]=0;  
        for(i=0;i<n;i++)  
        { //DP部分   
            for(j=sum;j>=v[i];j--)  
                dp[j]=min(dp[j],dp[j-v[i]]+w[i]);  
        }  
        ans=0;  
        for(i=sum;i>=0;i--) //求重量 <=b的最大价值   
            if(dp[i]<=b)  
            {  
                ans=i;  
                break;  
            }  
        printf("%d\n",ans);  
    }  
    return 0;  
} 

