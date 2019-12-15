/*
Graham�㷨�������ĵ�����γɵ����͹����
�����Լ���͹����������ܳ� 
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#define MAXN 100015
using namespace std;

int top,stk[MAXN]; //stk����ջ���������±�

struct point
{ //�� 
    double x,y;
} pnt[MAXN];

void Swap(int i,int j)
{ //������ 
    point tmp;
    tmp=pnt[i];
    pnt[i]=pnt[j];
    pnt[j]=tmp;
}

double multi(point p0,point p1,point p2)
{ //��� 
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));
}

double dis(point p1,point p2) 
{ //��p1,p2�ľ���
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


int cmp(point a,point b) 
{ //����ȽϺ��� 
    double k=multi(pnt[0],a,b);
    if(k==0) return dis(a,pnt[0])<dis(b,pnt[0]); //���ƽ����ȽϾ��� 
    else return k>0; //����Ƚϼ��Ǵ�С 
}

int Graham(int n)
{ //Graham��͹��������stk�����б���͹������±�
    int i,u=0;
    for(i = 1;i< n;i++) //�ҵ������µĵ�
        if((pnt[i].y<pnt[u].y)||(pnt[i].y==pnt[u].y&&pnt[i].x < pnt[u].x))
            u=i;
    Swap(0,u); //�������µĵ�� 0 ���㽻�� 
    sort(pnt+1,pnt+n,cmp); //��ʣ�����м������� 
    for(i = 0;i <= 2;i++) stk[i] = i; //p0,p1,p2��ջ
    top=2;
    i=3;
    while(i<n) //����͹���ĸ�����ı�����δ���stk[]�С�
    {
    	if(multi(pnt[stk[top]],pnt[stk[top-1]],pnt[i])<=0) 
			stk[++top]=i++;
    	else top--;
    }
    return top;
}

double Area(int n)
{ //��͹�����������͹���ָ�ɶ����������������� 
    double area;
    int i;
    area=0;
    for(i=1;i<n;i++)
        area+=fabs(multi(pnt[stk[0]],pnt[stk[i]],pnt[stk[i+1]]));
    return area/2;
}

double Length(int n)
{ //��͹�����ܳ�������߳��ĺ� 
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
    num=Graham(n); //numΪջ��λ�ã���ջ��Ԫ�صĸ���С 1 
   	printf("%lf\n",Area(num));
    printf("%lf\n",Length(num));
}
