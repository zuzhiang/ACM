/*
���Է����� a%m ����Ԫ��Ҫ�� a��m ������ m Ϊ���� 
inv[i]�б������i����m����Ԫ
*/
#include<stdio.h>
int main()
{
	int i,a,m;
	int inv[1000];
	while(~scanf("%d %d",&a,&m))
	{
		inv[1]=1;
		for(i=2;i<m;i++)
			inv[i]=((m-m/i)%m*inv[m%i])%m;
		printf("%d\n",inv[a]);
	}	
	return 0;
}
