//给定一序列，寻找某一子序列，使得子序列中的最小值乘以子序列的长度最大
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;

int main()
{
	int i,n,top; //top指向栈顶 
	stack<int> st; //栈用于保存矩形的编号，即位置 
	LL tmp,ans,a[100010]; //tmp为临时变量，记录面积的值，ans为结果，记录最大面积值 
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ans=0;
		a[n]=-1; //最后一个元素设为最小值，以最后清空栈 
		for(i=0;i<=n;i++)
		{
			if(st.empty()||a[i]>=a[st.top()])
			{ //如果栈为空或入栈元素大于等于栈顶元素 ，则入栈 
				st.push(i);
			}
			else
			{
				while(!st.empty()&&a[i]<a[st.top()])
				{ //如果栈非空且入栈元素小于栈顶元素，则将栈顶元素出栈 
					top=st.top();
					st.pop();
					tmp=(i-top)*a[top]; //在出栈过程中计算面积值 
					if(tmp>ans) ans=tmp; //更新面积最大值 
				}
				st.push(top); //只将可以延伸到的最左端的位置入栈
				a[top]=a[i];  //并修改该位置的值 
			}			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
