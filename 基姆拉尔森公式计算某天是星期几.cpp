#include<stdio.h>

int solve(int y,int m,int d)
{ //��ķ����ɭ��ʽ����ĳ�������ڼ� 
	if(m<3) 
	{
		m+=12;
		y--;
	}
	return (d+m*2+3*(m+1)/5+y+y/4-y/100+y/400)%7+1;
}

int main()
{
	int y,m,d;
	scanf("%d%d%d",&y,&m,&d); //���������� 
	printf("%d\n",solve(y,m,d)); //����ܼ� 
}
