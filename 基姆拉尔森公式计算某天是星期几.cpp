#include<stdio.h>

int solve(int y,int m,int d)
{ //基姆拉尔森公式计算某天是星期几 
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
	scanf("%d%d%d",&y,&m,&d); //输入年月日 
	printf("%d\n",solve(y,m,d)); //输出周几 
}
