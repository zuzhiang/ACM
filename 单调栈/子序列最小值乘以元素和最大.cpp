//����һ���У�Ѱ��ĳһ�����У�ʹ���������е���Сֵ��������������Ԫ�غ����
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;

int main()
{
	int i,n,pos1,pos2; //pos1��pos2��¼����Ŀ�ʼ�ͽ���λ�� 
	//tmpΪ��ʱ��������¼�����ڵĺͣ�topָ��ջ��Ԫ�أ�ansΪ�����sumΪǰ׺�� 
	LL tmp,top,ans,a[100010],sum[100010];
	stack<int> st; //����ջ����¼Ԫ��λ�� 
	while(~scanf("%d",&n))
	{
		while(!st.empty()) st.pop(); //���ջ 
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i]; //����ǰ׺�� 
		}			
		a[n+1]=-1; //�����һ����Ϊ��Сֵ���������ջ��Ԫ��ȫ����ջ 
		ans=0;
		for(i=1;i<=n+1;i++)
		{
			if(st.empty()||a[i]>=a[st.top()])
			{ //���ջΪ�ջ���ջԪ�ش��ڵ���ջ��Ԫ�أ�����ջ 
				st.push(i);
			}
			else 
			{
				while(!st.empty()&&a[i]<a[st.top()])
				{ //���ջ�ǿղ�����ջԪ��С��ջ��Ԫ�أ���ջ��Ԫ�س�ջ 
					top=st.top();
					st.pop();					
					tmp=sum[i-1]-sum[top-1]; //����������Ԫ�غ� 
					tmp*=a[top]; //������ 
					if(tmp>=ans) 
					{ //�������ֵ����¼λ�� 
						ans=tmp;
						pos1=top;
						pos2=i;
					}
				}
				st.push(top); //�����һ�γ�ջ��ջ��Ԫ����ջ 
				a[top]=a[i]; //���������������첢���¶�Ӧ��ֵ 
			}
		}
		printf("%lld\n",ans);
		printf("%d %d\n",pos1,pos2-1);
	}
	return 0;
}
