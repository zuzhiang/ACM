//http://blog.csdn.net/xiaofei_it/article/details/17042651
/*
例题：HDU 1082 //整数拆分数 
普通型母函数主要是来求组合的方案数，而指数型母函数是求多重排列数
普通型母函数的计算过程就是模拟手算多项式乘法的过程
*/
#define MAXN 55
int a[MAXN],b[MAXN];
int s[MAXN],e[MAXN],v[MAXN];

void mu(int n)
{ //n为因子个数 
	int i,j,k;
	memset(a,0,sizeof(a));
	a[0]=1;
	for(i=1;i<=n;i++)
	{ //前i项相乘 
		memset(b,0,sizeof(b));
		//j为第i种物品可能的数量，j*v[i]即第i个括号中第j项的系数
		for(j=s[i];j<=e[i]&&j*v[i]<=MAXN;j++)
			for(k=0;k+j*v[i]<=MAXN;k++) //计算对前i-1项相乘的结果的第k项的系数产生的影响 
				b[k+j*v[i]]+=a[k];
		memcpy(a,b,sizeof(b)); //将b数组存回a数组 
	}	
}

/*
a数组存储最终结果，b数组存储中间结果 
s[i]为第i个变量的最小个数，e[i]为第i个变量的最大个数 
v[i]表示第i个未知量的取值，即x^v[i] 
a[i]存储的是未知量 x^i 前面的系数 

也就是a存储前i-1项的相乘结果，然后遍历第i项中的每一个变量，让其与a中的每一项相乘，
将结果临时存储到b数组中，最后存回a数组。 

例如：求不同个数的不同质量的砝码可以组成的质量为 i 的种类数
v[i]存第i种砝码质量，s[i]存第i种砝码最小的个数，e[i]存第i种砝码最大的个数
a[i]存可以组成的质量为i的种类数 
*/
