/*
��a,b,c�ǿռ��������������� (axb)*c ��Ϊ��������a,b,c�Ļ�ϻ�
|(axb)*c|�ļ��������ʾ��a,b,cΪ���ƽ������������
��|(axb)*c|=0����˵��������������
*/

struct point
{
	double x,y,z;
};

double dot_product(point a,const point b)
{ //�������,(x1,y1,z1)*(x2,y2,z2)=x1*x2+y1*y2+z1*z2
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

//����(axb)*c��ֵ��ans=dot_product(a,cross_product(b,c)); 
