//输入一个大数，求其模100001所得的结果
#include<stdio.h>
#include<string.h>
int main()
{
    int  i,len,remain;
    char str[10000];
    printf("Please enter a number:\n");
    remain=0;
    while(~scanf("%s",str))
    {
        for(i=0;i<strlen(str);i++)
        {
            remain=(remain*10+str[i]-'0')%100001;
        }
        printf("The mod is : %d\n",remain);
        printf("Please enter a number:\n");
        remain=0;
    }
    return 0;
}
