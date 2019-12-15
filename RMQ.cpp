//http://blog.csdn.net/niushuai666/article/details/6624672
/*
RMQָ������������ֵ���⡣ 
*/
#include<stdio.h>
#include<math.h>

int a[50005],mi[50005][22],mx[50005][22];
//mi�����Ϊ��i��ʼ����Ϊ2^j���������Сֵ�� mx�����Ϊ��i��ʼ����Ϊ2^j����������ֵ
//��ʼ����mi[i][0] =a[i],mx[i][0]=a[i]
//״̬ת�Ʒ���:mi[i][j]=min(mi[i][j-1],mi[i+2^(j-1)][j-1])
//             mx[i][j]=max(mx[i][j-1],mx[i+2^(j-1)][j-1])

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

void RMQ(int n)
{ //����Ԥ����dp˼�� 
	int i,j;
	for(i=1;i<=n;i++)
	{
		mi[i][0]=a[i];
		mx[i][0]=a[i];
	}
	//ע��ѭ��˳��,���Ϊj,�ڲ�Ϊi 
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			if(i+(1<<j)-1<=n)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
				mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
			}
}

int main()
{
	int i,j,k,n,q,l,r,ans;
	scanf("%d%d",&n,&q);//���ĸ�����ѯ�ʵĸ��� 
	for(i=1;i<=n;i++) scanf("%d",&a[i]); //n���� 
	RMQ(n);
	while(q--)
	{
		scanf("%d%d",&l,&r); //��ѯ���������� 
		k=(int)(log(r-l+1.0)/log(2.0)); //r-l+1Ϊ���䳤�� 
		//������(l,r)���ֵ
		//ans=max(mx[l][k],mx[r-(1<<k)+1][k]);
		//������(l,r)��Сֵ
		//ans=min(mx[l][k],mx[r-(1<<k)+1][k]);
		//������(l,r)���ֵ-��Сֵ 		
		ans=max(mx[l][k],mx[r-(1<<k)+1][k])-min(mi[l][k],mi[r-(1<<k)+1][k]);
		printf("%d\n",ans);
	}	
	return 0;
}
