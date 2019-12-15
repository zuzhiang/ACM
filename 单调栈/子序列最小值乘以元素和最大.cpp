//给定一序列，寻找某一子序列，使得子序列中的最小值乘以子序列所有元素和最大。
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;

int main()
{
	int i,n,pos1,pos2; //pos1和pos2记录区间的开始和结束位置 
	//tmp为临时变量，记录区间内的和；top指向栈顶元素；ans为结果；sum为前缀和 
	LL tmp,top,ans,a[100010],sum[100010];
	stack<int> st; //单调栈，记录元素位置 
	while(~scanf("%d",&n))
	{
		while(!st.empty()) st.pop(); //清空栈 
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i]; //计算前缀和 
		}			
		a[n+1]=-1; //将最后一个设为最小值，以最后让栈内元素全部出栈 
		ans=0;
		for(i=1;i<=n+1;i++)
		{
			if(st.empty()||a[i]>=a[st.top()])
			{ //如果栈为空或入栈元素大于等于栈顶元素，则入栈 
				st.push(i);
			}
			else 
			{
				while(!st.empty()&&a[i]<a[st.top()])
				{ //如果栈非空并且入栈元素小于栈顶元素，则将栈顶元素出栈 
					top=st.top();
					st.pop();					
					tmp=sum[i-1]-sum[top-1]; //计算区间内元素和 
					tmp*=a[top]; //计算结果 
					if(tmp>=ans) 
					{ //更新最大值并记录位置 
						ans=tmp;
						pos1=top;
						pos2=i;
					}
				}
				st.push(top); //将最后一次出栈的栈顶元素入栈 
				a[top]=a[i]; //将其向左向右延伸并更新对应的值 
			}
		}
		printf("%lld\n",ans);
		printf("%d %d\n",pos1,pos2-1);
	}
	return 0;
}
