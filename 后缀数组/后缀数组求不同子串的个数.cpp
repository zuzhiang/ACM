/*
��ͬ�Ӵ��ĸ���Ϊ�����Ӵ���������ȥ����height���������ֵ��
��Ϊ��Щ����ǰ׺���Ƕ���˵�
*/

#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

#define MAX 100010

int n,k;
int rk[MAX+1]; //�������飬��ʾ�ӵ�i���ַ���ʼ�ĺ�׺�ŵ�j 
int sa[MAX];   //��׺���飬��ʾ�ŵ�j���Ǵӵ�i���ַ���ʼ�ĺ�׺ 
int lcp[MAX];  //�߶����飬��ʾ�������ں�׺�������ǰ׺

int cmp(int i,int j)
{ //�Ƚ�rk[i],rk[i+k] �� rk[j],rk[j+k]
	if(rk[i]!=rk[j]) return rk[i]<rk[j];
	else
	{
		int ri=i+k<=n ? rk[i+k]:-1;
		int rj=j+k<=n ? rk[j+k]:-1;
		return ri<rj;
	}
}

void da(string s)
{ //�����㷨���ַ���s�ĺ�׺������������� 
	int i,tmp[MAX+1]; //tmpΪ��ʱ���� 
	n=s.length();
	for(i=0;i<=n;i++)
	{ //��ʼ����Ϊ1��rkֱ��ȡ�ַ���ASCII��
		sa[i]=i;
		rk[i]=i<n ? s[i]:-1; //rk[n]=-1������=s[i] 
	}	
	for(k=1;k<=n;k*=2) //kΪȫ�ֱ��� 
	{ //���ó���Ϊk���������Գ���Ϊ2k�Ľ������� 
		sort(sa,sa+n+1,cmp);
		tmp[sa[0]]=0; //����tmp����ʱ�洢�¼����rk����ת���rk�� 
		for(i=1;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i]) ? 1:0);			
		for(i=0;i<=n;i++) rk[i]=tmp[i];
	}
}

void LCP(string s)
{ //��߶�����,LCP���������ں�׺�������ǰ׺
	int i;
	int len=s.length();
	for(i=0;i<=n;i++) rk[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	for(i=0;i<n;i++)
	{ //�����ַ����д�λ��i��ʼ�ĺ�׺�����ں�׺�����е�ǰһ����׺��LCP 
		int j=sa[rk[i]-1]; 
		if(h>0) h--;  //��h�ȼ�ȥ����ĸ�� 1���ȣ��ڱ���ǰ׺��ͬ��ǰ���²������� 
		for(;j+h<n && i+h<n;h++)
			if(s[j+h]!=s[i+h]) break;
		lcp[rk[i]-1]=h;
	}
}

int main()
{
	int i,t;
	LL len,ans;
	string s;
	cin>>t; //�ַ������� 
	while(t--)
	{
		cin>>s;
		len=s.length();
		da(s);
		LCP(s);
		ans=len*(len+1)/2;
		for(i=1;i<len;i++) ans-=lcp[i];
		cout<<ans<<endl;
	}
	return 0;
}
