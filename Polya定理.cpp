/*
直接用Polya定理求解，找出所有的置换，并求出置换的循环节数。然后

根据上边公式求出 M^c(ai) 的总和，再除以置换群个数。


题中有两种置换方式：

1.旋转置换。分别顺时针旋转 i 个珠子，其循环节长度为 LCM(N，i) / i，循环节数为

N / (LCM(N，i) / i)，即 GCD(N，i)。

2.翻转置换。根据 N 的奇偶性分情况讨论。

N为奇数时： 以第 i 个珠子为顶点和中心翻转，翻转后，第 i 个珠子保持不变，其余珠子
两两相互对换，因为有 N 个珠子，所以有 N 种翻转置换，每种翻转循环节数为 (N+1) / 2。

N为偶数时，有两种翻转方式：

      以两边相对的两个珠子为轴和中心翻转，翻转后，这两个珠子保持不变，其余珠子

两两相互对换，共有 N/2 种翻转置换，每种翻转循环节数为 (N+2) / 2。

      以相邻的珠子中间连线为轴和中心翻转，翻转后，所有珠子两两相互对换，共有 N/2

种翻转置换，每种翻转循环节数为 N/2。
*/
#include<stdio.h>
#include<math.h>

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int i,m,n,tmp,ans;
	while(~scanf("%d%d",&m,&n)&&(m||n))
	{
		ans=0;
		for(i=1;i<=n;i++)
		{
			tmp=gcd(n,i);
			ans+=pow(m*1.0,tmp);
		}
		if(n&1) ans+=n*pow(m*1.0,(n+1)>>1);
		else
		{
			ans+=(n>>1)*pow(m*1.0,(n+2)>>1);
			ans+=(n>>1)*pow(m*1.0,n>>1);
		}
		ans=ans/(n<<1);
		printf("%d\n",ans);
	}
	return 0;
}
