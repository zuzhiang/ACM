/*
�������򣬹��б�Ŵ�0��9��10��Ͱ
�����ֵ����λ�����λ��ʼ�ŵ���λ��Ӧ��Ͱ��
���ν�Ͱ�е������ռ��������ٰ��ո���/��λ����
ÿ��������󣬾�����˶�ÿһλ������
ȫ����ɺ������������ 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[10000];

int get_digit(int n,int k)
{ //��ȡ����n�ĵ�kλ���֡���λΪ��1λ�� 
	int r[11]={1,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	return (n/r[k])%10;
}

void sort(int n,int k)
{ //�������kλ��n�������л������� 
	int i,j,index,count[10]; //count��¼��i��Ͱ������ĸ��� 
	int *bucket=(int *)malloc(n*sizeof(int)); //��ʼ��Ͱ�Ĵ�С 
	for(j=1;j<=k;j++)
	{ //jΪλ�����Ӹ�λ��ʼ 
		for(i=0;i<10;i++) count[i]=0; //��ʼ�� 
		for(i=0;i<n;i++) count[get_digit(a[i],j)]++; //��ȡÿ��Ͱ������ĸ��� 
		for(i=1;i<10;i++) count[i]+=count[i-1]; //�����0����i��Ͱ������˶��ٸ�������Ϊbucket��һά���顣 
		for(i=n-1;i>=0;i--)
		{
			index=get_digit(a[i],j);
			bucket[count[index]-1]=a[i]; //����������Ӧ��Ͱ�� 
			count[index]--;
		}
		for(i=0;i<n;i++) a[i]=bucket[i]; //��Ͱ���ռ����� 
	}
	free(bucket);
}

int main()
{
	int i,n,k,max;
	while(~scanf("%d",&n))
	{ //��n���� 
		max=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			if(a[i]>max) max=a[i];
		}		 
		k=(int)log10(max)+1; //�������ֵ�ж���λ
		sort(n,k);
		for(i=0;i<n;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
