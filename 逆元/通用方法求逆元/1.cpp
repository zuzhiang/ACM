#include<stdio.h>
int main()
{
	int i,a,m;
	int inv[1000];
	scanf("%d %d",&a,&m);
	inv[1]=1;
	for(i=2;i<1000;i++)
		inv[i]=((m-m/i)%m*inv[m%i])%m;
	printf("%d\n",inv[a]);
	return 0;
}
//inv[i]�б������i����m����Ԫ��Ҫ��i<p,����Ҫp������
