#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

struct node
{
	int x,y;
} a[1000];

bool operator<(node d,node e)
{
	return d.x>e.x;
}


int main()
{
	node c;
	priority_queue<node> Q;
	a[0].x=1;
	a[0].y=2;
	a[1].x=3;
	a[1].y=2;
	a[2].x=8;
	a[2].y=7;
	a[3].x=5;
	a[3].y=9;
	a[4].x=6;
	a[4].y=6;
	Q.push(a[0]);
	Q.push(a[1]);
	Q.push(a[2]);
	Q.push(a[3]);
	Q.push(a[4]);
	while(!Q.empty())
	{
		c=Q.top();
		printf("%d %d\n",c.x,c.y);
		Q.pop();
	}
	printf("\n");
	return 0;
}