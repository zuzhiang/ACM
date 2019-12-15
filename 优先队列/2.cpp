#include<queue>
#include<stdio.h>
#include<iostream>
#include<functional>
using namespace std;

int main()
{
	priority_queue<float,vector<float>,greater<float> > Q;
	Q.push(1.1);
	Q.push(5.5);
	Q.push(4.4);
	Q.push(4.3);
	Q.push(8.5);
	Q.push(2.1);
	Q.push(6.6);
	Q.push(7.4);
	Q.push(9.5);
	while(!Q.empty())
	{
		printf("%f ",Q.top());
		Q.pop();
	}
	printf("\n");
	return 0;
}