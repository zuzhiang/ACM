#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;

struct point
{
	int x, y;
	point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	point operator - (const point &b)const
	{
		return point(x - b.x, y - b.y);
	}
	int operator ^(const point &b)const
	{
		return x * b.y - y * b.x;
	}
	int operator *(const point &b)const
	{
		return x * b.x + y * b.y;
	}	
} p[MAXN];

//�����ƽ��
int dis(point a, point b)
{
	return (a - b) * (a - b);
}
//��ά͹��
point list[MAXN];
int stk[MAXN],top;

void Swap(int i,int j)
{ //������ 
    point tmp;
    tmp=list[i];
    list[i]=list[j];
    list[j]=tmp;
}

int cmp(point a,point b) 
{ //����ȽϺ��� 
    int k=(a-list[0])^(b-list[0]);
    if(k==0) return dis(a,list[0])<dis(b,list[0]); //���ƽ����ȽϾ��� 
    else return k>0; //����Ƚϼ��Ǵ�С 
}

void Graham(int n)
{ //Graham��͹��������stk�����б���͹������±�
    int i,u=0;
    for(i = 1;i< n;i++) //�ҵ������µĵ�
        if((list[i].y<list[u].y)||(list[i].y==list[u].y&&list[i].x < list[u].x))
            u=i;
    Swap(0,u); //�������µĵ�� 0 ���㽻�� 
    sort(list+1,list+n,cmp); //��ʣ�����м������� 
    //�ȵ�����͹�������������ж� 
	for(i=0;i<=1;i++) stk[i]=i;
    top=2;
    for (int i = 2; i < n; i++)
	{
		while(top>1&&((list[stk[top-1]]-list[stk[top-2]])^(list[i]-list[stk[top-2]]))<=0)
		{
			top--;
		}
		stk[top++] = i;
	}
}

// ��ת����,����������ƽ�������ֵ
int rotating_calipers(int n)
{
	int ans = 0;
	point v;
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		v = p[i] - p[(i + 1) % n];
		while ((v ^ (p[(cur + 1) % n] - p[cur])) < 0)
			cur = (cur + 1) % n;
		ans = max(ans, max(dis(p[i], p[cur]), dis(p[(i + 1) % n], p[(cur + 1) % n])));
	}
	return ans;
}

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &list[i].x, &list[i].y);
		if(n==2)
		{
			printf("%d\n",dis(list[0],list[1]));
			continue;
		}
		Graham(n);
		for (int i = 0; i < top; i++)
			p[i] = list[stk[i]];
		printf("%d\n", rotating_calipers(top));
	}
	return 0;
}
