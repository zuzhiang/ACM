/*
Graham算法求解给出的点可以形成的最大凸包，
并可以计算凸包的面积和周长 
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#define MAXN 100015
using namespace std;

int top,stk[MAXN]; //stk用作栈，保存点的下标

struct point
{ //点 
    double x,y;
} pnt[MAXN];

void Swap(int i,int j)
{ //交换点 
    point tmp;
    tmp=pnt[i];
    pnt[i]=pnt[j];
    pnt[j]=tmp;
}

double multi(point p0,point p1,point p2)
{ //叉积 
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));
}

double dis(point p1,point p2) 
{ //求p1,p2的距离
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


int cmp(point a,point b) 
{ //排序比较函数 
    double k=multi(pnt[0],a,b);
    if(k==0) return dis(a,pnt[0])<dis(b,pnt[0]); //如果平行则比较距离 
    else return k>0; //否则比较极角大小 
}

int Graham(int n)
{ //Graham求凸包，最终stk数组中保存凸包点的下标
    int i,u=0;
    for(i = 1;i< n;i++) //找到最左下的点
        if((pnt[i].y<pnt[u].y)||(pnt[i].y==pnt[u].y&&pnt[i].x < pnt[u].x))
            u=i;
    Swap(0,u); //将最左下的点和 0 处点交换 
    sort(pnt+1,pnt+n,cmp); //对剩余点进行极角排序 
    for(i = 0;i <= 2;i++) stk[i] = i; //p0,p1,p2入栈
    top=2;
    i=3;
    while(i<n) //最终凸包的各顶点的编号依次存在stk[]中。
    {
    	if(multi(pnt[stk[top]],pnt[stk[top-1]],pnt[i])<=0) 
			stk[++top]=i++;
    	else top--;
    }
    return top;
}

double Area(int n)
{ //求凸包的面积，将凸包分割成多个三角形求其面积和 
    double area;
    int i;
    area=0;
    for(i=1;i<n;i++)
        area+=fabs(multi(pnt[stk[0]],pnt[stk[i]],pnt[stk[i+1]]));
    return area/2;
}

double Length(int n)
{ //求凸包的周长，即求边长的和 
	int i;
	double ans=dis(pnt[stk[0]],pnt[stk[n]]);
	for(i=0;i<n;i++)
		ans+=dis(pnt[stk[i]],pnt[stk[i+1]]);
	return ans;
}

int main()
{
    int i,n,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
    num=Graham(n); //num为栈顶位置，比栈内元素的个数小 1 
   	printf("%lf\n",Area(num));
    printf("%lf\n",Length(num));
}
