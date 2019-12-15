//HDU 6208 
/*
AC自动机实现多模匹配，及多个单词和一个文本的匹配 
可以减少存储空间，加快匹配速度 
*/ 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;

struct Trie
{ //用数组模拟指针，以减小空间，加快速度 
    int next[500010][26];
	int fail[500010]; //失配指针 
	int sum[500010]; //记录以当前字幕结尾的字符串有几个 
    int root,L;
    
    int newnode()
    { //为新节点分配内存空间 
        for(int i=0;i<26;i++) next[L][i]=-1;
        sum[L++]=0;
        return L-1;
    }
	
    void init()
    { //为root申请内存空间 
        L=0;
        root=newnode();
    }
    
    void insert(char s[])
    { //根据单词建字典树 
        int len=strlen(s);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(next[now][s[i]-'a']==-1)
                next[now][s[i]-'a']=newnode();
            now=next[now][s[i]-'a'];
        }
        sum[now]++;
    }
    
    void build()
    { //建立失配指针
        queue<int>Q;
        fail[root]=root;
        for(int i=0;i<26;i++)
        {
            if(next[root][i]==-1) next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            for(int i=0;i<26;i++)
            {
                if(next[now][i]==-1) next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    
    int query(char s[])
    { //查询所建的字典树中多少个是s的子串 
        int len=strlen(s);
        int now=root;
        int res=0;
        for(int i=0;i<len;i++)
        {
            now=next[now][s[i]-'a'];            
            int temp=now;
            while(temp!=root&&sum[temp]>=0)
            {
                res+=sum[temp];
                sum[temp]=-1;
                temp=fail[temp];
            }
        }
        return res;
    }
    
    void debug()
    { //调试用的 
        for(int i=0;i<L;i++)
        {
            printf("id = %3d,fail = %3d,sum = %3d,chi = [",i,fail[i],sum[i]);
            for(int j=0;j<26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};

char s[100010],t[100010];
Trie ac;

int main()
{
    int T,n,len,max;
    
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        ac.init();
        max=0;        
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            ac.insert(s);
            len=strlen(s);
            if(len>max)
            {
                max=len;
                strcpy(t,s);
            }            
        }
        ac.build();
        if(ac.query(t)==n) printf("%s\n",t);
        else printf("No\n");
    }
    return 0;
}
