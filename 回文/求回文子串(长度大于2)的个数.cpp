#include<stdio.h>
#include<string.h>

const int MAXN=110010;
char Ma[MAXN*2];
int Mp[MAXN*2];

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

void Manacher(char s[],int len)
{
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0;i<len;i++)
	{
		Ma[l++]=s[i];
		Ma[l++]='#';
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0;i<l;i++)
	{
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
		if(i+Mp[i]>mx)
		{
			mx=i+Mp[i];
			id=i;
		}
	}
}

int main()
{
	int i,len,ans;
	char s[100010];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		Manacher(s,len);
		/*for(i=0;i<2*len+2;i++)
			printf("%c ",Ma[i]);
		printf("\n");
		for(i=0;i<2*len+2;i++)
			printf("%d ",Mp[i]);
		printf("\n");*/
		ans=0;
		for(i=0;i<2*len+2;i++)
			if(Mp[i]>2) ans+=(Mp[i]-1)/2;
		printf("%d\n",ans);
	}
	return 0;
}
