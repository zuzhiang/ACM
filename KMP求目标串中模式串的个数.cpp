//����˼·��ֱ���޸ı�׼KMP��������ƥ��ɹ���������ѭ��������ֱ�Ӱ����һ���ַ�ʧ������ȥ����ģʽ�����Ի�ȡ��һ�����ܳ��ֵ�ƥ�䡣

#include<stdio.h>
#include<string.h>

int l1,l2,next[1000];
char s[1000],t[1000];

void pnext()
{ //δ���Ż�����next���鷽��
    int i=0,j=-1;
    next[0] = -1;
    while(i<l2)
	{
        if(j==-1||t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

int kmp()
{
    int i=0,j=0,sum=0;	//���˸���������sum
    pnext();
    while(i<l1)  //ֻ��ҪĿ�괮ָ��С��Ŀ�괮���ȼ��ɣ����͵�����kmp��һ��
	{
        if(s[i]==t[j] || j==-1)
		{
			i++;
			j++;
		}
        else if(j<l2) j = next[j];
/*******************************/
//ֻ�Ǳ�KMP�㷨��������Щ����
        if(j>=l2)
        {
            sum++;
            j=next[l2];////����ظ����Ӵ�����
	    //j=0;  //�󲻿��ظ����Ӵ�����
        }
/*******************************/
    }
    return sum;
}

int main()
{
	int v;
	while(1)
	{
		printf("������Ŀ�괮:\n");
		scanf("%s",s);
		l1=strlen(s);
		printf("������ģʽ��:\n");
		scanf("%s",t);
		l2=strlen(t);
		v=kmp();
		printf("Ŀ�괮��ģʽ���ĸ���Ϊ:%d\n",v);
	}	
	return 0;
}
