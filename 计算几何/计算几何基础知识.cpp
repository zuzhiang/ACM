/*
1.两个向量的叉乘（内积） 
2.判断点是否在线段上 
3.判断点是否在三角形里面（包括边上） 
4.判断点是否在多边形内 
5.判断两线段是否相交
6.求两线段的交点坐标 
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define eps 1e-5

struct point
{ //点 
	double x,y;
};

struct vct
{ //向量 
	point start,end;
};

struct triangle
{ //三角形 
	point A,B,C;	
};

int min(double a,double b)
{
	return a<b? a:b;
}

int max(double a,double b)
{
	return a>b? a:b;
}

double CrossProduct(vct v1,vct v2)
{ //两个向量的叉乘
	double ans=0;
	vct a,b;
	a.start.x=0;
	a.start.y=0;
	a.end.x=v1.end.x-v1.start.x;
	a.end.y=v1.end.y-v1.start.y;
	b.start.x=0;
	b.end.y=0;
	b.end.x=v2.end.x-v2.start.x;
	b.end.y=v2.end.y-v2.start.y;
	ans=a.end.x*b.end.y-b.end.x*a.end.y;
	return ans;
}

//判断点 q 是否在线段 p1p2 上 
int OnSegment(point p1,point p2,point q)
{ //1.(q-p1)x(p2-p1)=0 2.q在以p1、p2为对角线的矩形内 
	if((q.x-p1.x)*(p2.y-p1.y)==(p2.x-p1.x)*(q.y-p1.y)
	&&min(p1.x,p2.x)<q.x&&q.x<=max(p1.x,p2.x)&&
	min(p1.y,p2.y)<q.y&&q.y<=max(p1.y,p2.y)) return 1;		
	return 0;
}

//判断点 p 是否在三角形里面(包括在边上)
int InTriangle(triangle t,point p) 
{ //如果点 p 和三角形三点组成的三角形面积和等于原三角形面积则在三角形内 
	vct AB,AC,PA,PB,PC;
	double Sabc,Spab,Spac,Spbc;
	AB.start=t.A;
	AB.end=t.B;
	AC.start=t.A;
	AC.end=t.C;
	PA.start=p;
	PA.end=t.A;
	PB.start=p;
	PB.end=t.B;
	PC.start=p;
	PC.end=t.C;
	Sabc=fabs(CrossProduct(AB,AC));
	Spab=fabs(CrossProduct(PA,PB));
	Spac=fabs(CrossProduct(PC,PA));
	Spbc=fabs(CrossProduct(PB,PC));
	if(Spab+Spac+Spbc==Sabc) return 1;
	else return 0;
}

/*以下声明及两个函数作用是判断点是否在多边形内*/
int n; //点的个数 
point poly[110]; //保存点 

int online(point p1,point p2,point p3)
{ //判断点 p2 是否在线段 p1p3 上 
	if(p2.x>=min(p1.x,p3.x)&&p2.x<=max(p1.x,p2.x)
	&&p2.y>=min(p1.y,p3.y)&&p2.y<=max(p1.y,p2.y))
	{
		if(fabs((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))<=eps)
			return 1;
	}
	return 0;
}

//判断点 p 是否在多边形内
int InsidePolygon(point p)
{ //做水平射线，如果穿过的点数为奇数则在多边形内 
	int i,cnt=0;
	double x;
	point p1,p2;
	p1=poly[0];
	for(i=1;i<=n;i++)
	{
		p2=poly[i%n];
		if(online(p1,p,p2)) return 1;
		if(p.y>min(p1.y,p2.y)&&p.y<=max(p1.y,p2.y)
		&&p.x<=max(p1.x,p2.x)&&p1.y!=p2.y)
		{
			x=(p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
			if(p1.x==p2.x||p.x<=x) cnt++;
		}
		p1=p2;
	}
	if(cnt%2) return 1;
	else return 0;
}

/*以下两个函数作用为判断两线段是否相交*/
/*一直线端点在另一直线上、两直线部分重合不算相交*/
double Multi(point p0,point p1,point p2)
{ //向量 p0p1 和 p0p2 相乘 
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int Across(vct v1,vct v2)
{ //判断两线段是否相交 
	if(max(v1.start.x,v1.end.x)>=min(v2.start.x,v2.end.x)&&
	max(v2.start.x,v2.end.x)>=min(v1.start.x,v1.end.x)&&
	max(v1.start.y,v1.end.y)>=min(v2.start.y,v2.end.y)&&
	Multi(v1.start,v2.start,v1.end)*Multi(v1.start,v1.end,v2.end)>0&&
	Multi(v2.start,v1.start,v2.end)*Multi(v2.start,v2.end,v1.end)>0)
	return 1;
	return 0;
}

/*以下两个函数作用为判断两线段是否相交*/
/*一直线端点在另一直线上、两直线部分重合也算相交*/
int mlt(vct v1,vct v2)
{
    double a=(v1.start.x-v2.start.x)*(v2.end.y-v2.start.y)
	-(v2.end.x-v2.start.x)*(v1.start.y-v2.start.y);
	double b=(v2.end.x-v2.start.x)*(v1.end.y-v2.start.y)
	-(v1.end.x-v2.start.x)*(v2.end.y-v2.start.y);
	if(a*b<0) return 0;
	return 1;
}

int check(vct v1,vct v2)
{ //判断两直线是否相交 
	if(!mlt(v1,v2)) return 0;
	if(!mlt(v2,v1)) return 0;
	return 1;
}

/*求两线段交点的坐标，会用到Multi和Across函数*/
point* Intersection(vct u,vct v)
{
	point p;
	double dot1,dot2; 
	if(Across(u,v))
	{
		dot1=Multi(u.start,v.end,u.end);
		dot2=Multi(u.start,v.start,u.end);
		p.x=(dot1*v.start.x-dot2*v.end.x)/(dot1-dot2);		
		p.y=(dot1*v.start.y-dot2*v.end.y)/(dot1-dot2);
		return &p;
	}
	return NULL;
}

int main() 
{
	printf("OK\n");
	return 0;
}
