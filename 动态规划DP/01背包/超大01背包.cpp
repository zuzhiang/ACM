/*
���⣻�� n ����Ʒ��ÿ����Ʒ������ w[i] �ͼ�ֵ v[i]��
����ѡ������ ��Ʒ�������������� B ʱ������ֵ��
ע�⣬��Ʒ�������ܴ�w[i]<10e9���� 

 dp[i] ����˼����˵���ֵΪ i ʱ��Ʒ����С������
 Ȼ������һ���������� <=B �ļ�ֵ�����ֵ���ɡ�
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
            sum+=v[i]; //�����ֵ֮��   
        }  
        memset(dp,inf,sizeof(dp));  
        dp[0]=0;  
        for(i=0;i<n;i++)  
        { //DP����   
            for(j=sum;j>=v[i];j--)  
                dp[j]=min(dp[j],dp[j-v[i]]+w[i]);  
        }  
        ans=0;  
        for(i=sum;i>=0;i--) //������ <=b������ֵ   
            if(dp[i]<=b)  
            {  
                ans=i;  
                break;  
            }  
        printf("%d\n",ans);  
    }  
    return 0;  
} 

