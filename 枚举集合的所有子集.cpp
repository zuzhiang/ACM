/*
����n��Ԫ�صļ��ϵķǿ��Ӽ�����Ϊ2^n,��ô�����Ƶ�1~(1<<n)-1
���Ӧ��ÿ���Ӽ���Ԫ���±ꡣ
*/
#include<stdio.h>
void subset(int n)  
{  //nΪ����Ԫ�ظ���
	int i,j; 
    for(i=1;i<(1<<n);i++)
    { //ö��1~(1<<n)-1�����ж������� 
        for(j=0;j<n;j++) //�����������λΪ1���±꣬�����ҵ��� 
            if(i&(1<<j)) printf("%d ",j); //�����jΪ�Ӽ����±� 
        printf("\n");
    }  
}  
  
int main()  
{  
    int n;  
    while(scanf("%d", &n))  
    {
        subset(n);  
    }  
    return 0;  
}  
