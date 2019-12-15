/*
01�ֵ�����Ҫ���ڽ���������ֵ������.
HDU 5536: ��һ���������ҳ� (s[i]+s[j])^s[k] ����ֵ������ i��j��k ������ͬ��
������ѭ�������ͬ�����ĺͣ�Ȼ����ʣ��������� 01�ֵ����������ǵĺ�������Ľ��ֵ��
���ǿ����ڲ�ѯ x �� y �ĺ�֮ǰ���Ȱ� x �� y �� 01�ֵ�����ȥ����
��������һ������ num��������¼ÿ���ڵ㱻���ʵĴ�����ÿ�θı�ڵ�ķ��ʴ������ɡ� 
*/
#include<stdio.h>
#include<iostream>
#define MAXN 1010
typedef long long LL;
using namespace std;

int tol; //�ڵ��� 
LL val[32*MAXN]; //���ֵ 
int num[32*MAXN]; //ÿ���ڵ㱻���ʵĴ���
int ch[32*MAXN][2]; //��ָ��Ľڵ��� 

void init()
{ //��ʼ�� 
    tol=1;
    ch[0][0]=ch[0][1]=0;
}

void insert(LL x)
{ //�� 01�ֵ����в��� x 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        if(!ch[u][v])
        { //�����δ�����ʹ����򴴽� 
            ch[tol][0]=ch[tol][1]=0; //��ֵΪ0��ʾ��ָ���κνڵ�
            val[tol]=0; //��ֵΪ0��ʾ���˲���һ���� 
            num[tol]=0; //ÿ���ڵ㱻���ʵĴ���
            ch[u][v]=tol++; //��ָ��Ľڵ��� 
        }
        u=ch[u][v]; //��һ�ڵ� 
        num[u]++; //ÿ���ڵ㱻���ʵĴ���+1
    }
    val[u]=x; //��ֵ
}

void update(LL x,int add)
{ //���²����ɾ�� x��ÿ���ڵ㱻���ʵĴ��� 
	int u=0;
	for(int i=32;i>=0;i--)
	{
		int v=(x>>i)&1;
		u=ch[u][v];
		num[u]+=add;
	}
}

LL query(LL x)
{ //��ѯ�������к� x����������ֵ 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        //����̰�Ĳ��ԣ�����Ѱ�Һ͵���λ��ͬ�ĵ� 
        if(ch[u][v^1]&&num[ch[u][v^1]]) u=ch[u][v^1];
        else u=ch[u][v];
    }
    return x^val[u]; //���ؽ��
}

int main()
{
	int i,j,t,n;
	LL a[MAXN],ans;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			insert(a[i]);
		}
		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(i==j) continue;
				update(a[i],-1);
				update(a[j],-1);
				ans=max(ans,query(a[i]+a[j]));
				update(a[i],1);
				update(a[j],1);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
