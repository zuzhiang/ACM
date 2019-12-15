/*
�������е�Ϊ˳ʱ�������,��Ϊ��ʱ����ȥ��reverse����
��ƽ�潻�㷨��������������Ƿ���ں��Լ�
������п��Է�������Բ������� 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define eps 1e-8
#define PI acos(-1.0)
#define MAXN 1010
using namespace std;

int n;
double r;

int sgn(double x)
{ //���ź���
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point
{ //�� 
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{ //���캯�� 
		x = _x; y = _y;
	}
	Point operator -(const Point &b)const
	{ //������� 
		return Point(x - b.x, y - b.y);
	}
	double operator ^(const Point &b)const
	{ //���
		return x*b.y - y*b.x;
	}
	double operator *(const Point &b)const
	{ //���
		return x*b.x + y*b.y;
	}
};

struct Line
{ //���� 
	Point s,e; //���� 
	double k; //б�� 
	Line(){}
	Line(Point _s,Point _e)
	{ //����
		s = _s; e = _e;
		k = atan2(e.y - s.y,e.x - s.x);
	}
	Point operator &(const Line &b)const
	{ //����ֱ�߽���
		Point res = s;
		double t = ((s - b.s)^(b.s - b.e))/((s - e)^(b.s - b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return res;
	}
};

Line Q[MAXN];
Point p[MAXN]; //��¼������ĵ㼯
Line line[MAXN]; //������ĵ㼯����ֱ�ߵļ���

//��ƽ�潻��ֱ�ߵ���ߴ�����Ч����
bool HPIcmp(Line a,Line b)
{ //ֱ��������
	if(fabs(a.k - b.k) > eps)return a.k < b.k; //б������
	//б����ͬ��Ҳ��֪����ô��
	return ((a.s - b.s)^(b.e - b.s)) < 0;
}

void HPI(Line line[], int n, Point res[], int &resn)
{ //line�ǰ�ƽ�潻��ֱ�ߵļ��� n��ֱ�ߵ����� res�ǽ��
//�ĵ㼯 resn�ǵ�������ĸ���
	int tot = n;
	sort(line,line+n,HPIcmp);
	tot = 1;
	for(int i = 1;i < n;i++)
		if(fabs(line[i].k - line[i-1].k) > eps) //ȥ��б���ظ���
			line[tot++] = line[i];
	int head = 0, tail = 1;
	Q[0] = line[0];
	Q[1] = line[1];
	resn = 0;
	for(int i = 2; i < tot; i++)
	{
		if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s)) < eps ||
		fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
			return;
		while(head < tail && (((Q[tail]&Q[tail-1]) -
		line[i].s)^(line[i].e-line[i].s)) > eps)
			tail--;
		while(head < tail && (((Q[head]&Q[head+1]) -
		line[i].s)^(line[i].e-line[i].s)) > eps)
			head++;
		Q[++tail] = line[i];
	}
	while(head < tail && (((Q[tail]&Q[tail-1]) -
	Q[head].s)^(Q[head].e-Q[head].s)) > eps)
		tail--;
	while(head < tail && (((Q[head]&Q[head-1]) -
	Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
		head++;
	if(tail <= head + 1) return;
	for(int i = head; i < tail; i++)
		res[resn++] = Q[i]&Q[i+1];
	if(head < tail - 1)
		res[resn++] = Q[head]&Q[tail];
}

double dist(Point a,Point b)
{ //��������
    return sqrt((a-b)*(a-b));
}

void change(Point a,Point b,Point &c,Point &d,double p)
{ //���߶�ab�����ƶ�����p,�޸ĵõ��߶�cd
    double len=dist(a,b);
    /*�����������Ƴ����湫ʽ*/
    double dx=(a.y-b.y)*p/len;
    double dy=(b.x-a.x)*p/len;
    c.x=a.x+dx; c.y=a.y+dy;
    d.x=b.x+dx; d.y=b.y+dy;
}
void solve()
{
	int i,j,x,y;
	double dis;
    for(i=0;i < n;i++)
    { //������ε�ÿ���������ƶ� r �ľ��� 
        Point t1,t2;
        change(p[i],p[(i+1)%n],t1,t2,r);
        line[i]=Line(t1,t2);
    }
    int resn;
    HPI(line,n,p,resn); //�����εĺ� 
    x=0;
    y=0;
    dis=0;
    //˫��ѭ��Ѱ�Ҿ������������� 
    for(i=0;i<resn;i++)
    	for(j=i+1;j<resn;j++)
    		if(dist(p[i],p[j])>dis)
    		{
    			x=i;
    			y=j;
    			dis=dist(p[i],p[j]);
			}
	printf("%.4f %.4f %.4f %.4f\n",p[x].x,p[x].y,p[y].x,p[y].y);
}

int main()
{
	while(~scanf("%d%lf",&n,&r))
	{		
		for(int i = 0;i < n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		reverse(p,p+n);
		solve();
	}
	return 0;
}
/*
5 2
-2 0
-5 3
0 8
7 3
5 0

4 3
0 0
0 8
10 8
10 0
*/
