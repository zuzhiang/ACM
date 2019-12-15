/*
设a,b,c是空间中三个向量，则 (axb)*c 称为三个向量a,b,c的混合积
|(axb)*c|的几何意义表示以a,b,c为棱的平行六面体的体积
若|(axb)*c|=0，则说明三个向量共面
*/

struct point
{
	double x,y,z;
};

double dot_product(point a,const point b)
{ //向量点积,(x1,y1,z1)*(x2,y2,z2)=x1*x2+y1*y2+z1*z2
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

point cross_product(point a,const point b)
{ //a=(xa,ya,za),b=(xb,yb,zb),axb=(yazb-zayz)i+(xazb-zaxb)j+(xayb-yaxb)k
	point ans;
	ans.x=a.y*b.z-a.z*b.y;
	ans.y=a.z*b.x-a.x*b.z;
	ans.z=a.x*b.y-a.y*b.x;
	return ans;
}

//计算(axb)*c的值：ans=dot_product(a,cross_product(b,c)); 
