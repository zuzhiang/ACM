//����һ���У�Ѱ��ĳһ�����У�ʹ���������е���Сֵ���������еĳ������
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;

int main()
{
	int i,n,top; //topָ��ջ�� 
	stack<int> st; //ջ���ڱ�����εı�ţ���λ�� 
	LL tmp,ans,a[100010]; //tmpΪ��ʱ��������¼�����ֵ��ansΪ�������¼������ֵ 
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ans=0;
		a[n]=-1; //���һ��Ԫ����Ϊ��Сֵ����������ջ 
		for(i=0;i<=n;i++)
		{
			if(st.empty()||a[i]>=a[st.top()])
			{ //���ջΪ�ջ���ջԪ�ش��ڵ���ջ��Ԫ�� ������ջ 
				st.push(i);
			}
			else
			{
				while(!st.empty()&&a[i]<a[st.top()])
				{ //���ջ�ǿ�����ջԪ��С��ջ��Ԫ�أ���ջ��Ԫ�س�ջ 
					top=st.top();
					st.pop();
					tmp=(i-top)*a[top]; //�ڳ�ջ�����м������ֵ 
					if(tmp>ans) ans=tmp; //����������ֵ 
				}
				st.push(top); //ֻ���������쵽������˵�λ����ջ
				a[top]=a[i];  //���޸ĸ�λ�õ�ֵ 
			}			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
