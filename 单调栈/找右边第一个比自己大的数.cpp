//针对每个数，寻找它和它右边第一个比它大的数之间有多少个数
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int main()
{
	int i,n,top,a[80010]; //top指向栈顶元素 
	LL ans; //存储最终结果 
	stack<int> st; //st为栈，每次入栈的是每头牛的位置 
	while(~scanf("%d",&n))
	{
		while(!st.empty()) st.pop(); //清空栈 
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[n]=inf; //将最后一个元素设为最大值 
		ans=0;
		for(i=0;i<=n;i++)
		{
			if(st.empty()||a[i]<a[st.top()])
			{ //如果栈为空或入栈元素小于栈顶元素，则入栈 
				st.push(i);
			}
			else 
			{
				while(!st.empty()&&a[i]>=a[st.top()])
				{ //如果栈不为空并且栈顶元素不大于入栈元素，则将栈顶元素出栈 
					top=st.top(); //获取栈顶元素 
					st.pop();     //栈顶元素出栈 
					//这时候也就找到了第一个比栈顶元素大的元素 
					//计算这之间牛的个数，为下标之差-1 
					ans+=(i-top-1);	
				}
				st.push(i); //当所有破坏栈的单调性的元素都出栈后，将当前元素入栈 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
