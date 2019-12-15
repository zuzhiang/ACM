/*
ʱ�临�Ӷȣ�log(n) 

��״���鲻��ֱ����һ������С�ڵ���0���������е�������,��ʱҪ�����е���������һ����
��Ϊ������

˼�룺��״�����ÿ���ڵ��ʾ������ʾ���±����������ֳ��ֵĴ��� 
������ i ����������������Ϊ i-query(n),��
�Ѳ������ĸ��� - �Ѳ���ıȵ�ǰ��С�����ĸ�����
��ÿ�εĽ����Ӽ��ɡ� 

ע�⣺��״����Ĵ�СΪ�����������ֵ�������ֵ̫��ʱ�������Ƚ�����������ȥ�أ���Ϊ
�����±� 
*/
#include<stdio.h>
#include<string.h>
#define N 500010

int n,t[N*2];

int lowbit(int x)
{ //lowbit(k)���ǰ�k�Ķ����Ƶĸ�λ1ȫ����գ�ֻ�������λ��1
    return x&(-x);
}

void update(int x)
{//����x������ 1 
	for(int i=x;i<=N*2;i+=lowbit(i))
		t[i]++;		    
}

long long query(int x)
{//���ҵ�ǰ��������б� x С�����ĸ��� 
    long long ans=0;
    for(int i=x;i>0;i-=lowbit(i))
    	ans+=t[i];
    return ans;
}

int main()
{
	int i,a;
	long long ans;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		ans=0;
		memset(t,0,sizeof(t));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a); //����� a �൱���±� 
			//�������ĸ��� - �Ѳ���ıȵ�ǰ��С�����ĸ���
			ans+=i-query(a+1); //a=0ʱ������ 
			update(a+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
