/*
不同子串的个数为所有子串的数量减去所有height数组里的数值和
因为这些公共前缀都是多加了的
*/

#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

#define MAX 100010

int n,k;
int rk[MAX+1]; //名次数组，表示从第i个字符开始的后缀排第j 
int sa[MAX];   //后缀数组，表示排第j的是从第i个字符开始的后缀 
int lcp[MAX];  //高度数组，表示排名相邻后缀的最长公共前缀

int cmp(int i,int j)
{ //比较rk[i],rk[i+k] 和 rk[j],rk[j+k]
	if(rk[i]!=rk[j]) return rk[i]<rk[j];
	else
	{
		int ri=i+k<=n ? rk[i+k]:-1;
		int rj=j+k<=n ? rk[j+k]:-1;
		return ri<rj;
	}
}

void da(string s)
{ //倍增算法求字符串s的后缀数组和名次数组 
	int i,tmp[MAX+1]; //tmp为临时数组 
	n=s.length();
	for(i=0;i<=n;i++)
	{ //初始长度为1，rk直接取字符的ASCII码
		sa[i]=i;
		rk[i]=i<n ? s[i]:-1; //rk[n]=-1，其他=s[i] 
	}	
	for(k=1;k<=n;k*=2) //k为全局变量 
	{ //利用长度为k的排序结果对长度为2k的进行排序 
		sort(sa,sa+n+1,cmp);
		tmp[sa[0]]=0; //先在tmp中临时存储新计算的rk，再转存回rk中 
		for(i=1;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i]) ? 1:0);			
		for(i=0;i<=n;i++) rk[i]=tmp[i];
	}
}

void LCP(string s)
{ //求高度数组,LCP：排名相邻后缀的最长公共前缀
	int i;
	int len=s.length();
	for(i=0;i<=n;i++) rk[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	for(i=0;i<n;i++)
	{ //计算字符串中从位置i开始的后缀及其在后缀数组中的前一个后缀的LCP 
		int j=sa[rk[i]-1]; 
		if(h>0) h--;  //将h先减去首字母的 1长度，在保持前缀相同的前提下不断增加 
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
	cin>>t; //字符串个数 
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
