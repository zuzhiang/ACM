//���ÿ������Ѱ���������ұߵ�һ�����������֮���ж��ٸ���
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int main()
{
	int i,n,top,a[80010]; //topָ��ջ��Ԫ�� 
	LL ans; //�洢���ս�� 
	stack<int> st; //stΪջ��ÿ����ջ����ÿͷţ��λ�� 
	while(~scanf("%d",&n))
	{
		while(!st.empty()) st.pop(); //���ջ 
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[n]=inf; //�����һ��Ԫ����Ϊ���ֵ 
		ans=0;
		for(i=0;i<=n;i++)
		{
			if(st.empty()||a[i]<a[st.top()])
			{ //���ջΪ�ջ���ջԪ��С��ջ��Ԫ�أ�����ջ 
				st.push(i);
			}
			else 
			{
				while(!st.empty()&&a[i]>=a[st.top()])
				{ //���ջ��Ϊ�ղ���ջ��Ԫ�ز�������ջԪ�أ���ջ��Ԫ�س�ջ 
					top=st.top(); //��ȡջ��Ԫ�� 
					st.pop();     //ջ��Ԫ�س�ջ 
					//��ʱ��Ҳ���ҵ��˵�һ����ջ��Ԫ�ش��Ԫ�� 
					//������֮��ţ�ĸ�����Ϊ�±�֮��-1 
					ans+=(i-top-1);	
				}
				st.push(i); //�������ƻ�ջ�ĵ����Ե�Ԫ�ض���ջ�󣬽���ǰԪ����ջ 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
