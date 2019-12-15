/*
1������
  ��������ַ���str��Trie���ĸ����Ϊroot��i=0��p=root��
  1)ȡstr[i]���ж�p->next[str[i]-97]�Ƿ�Ϊ�գ���Ϊ�գ��������temp������p->next[str[i]-97]ָ��temp��Ȼ��pָ��temp��
   ����Ϊ�գ���p=p->next[str[i]-97]��
  2)i++������ȡstr[i]��ѭ��1)�еĲ�����ֱ������������'\0'����ʱ����ǰ���p�е� exist��Ϊtrue��

2������
  ����Ҫ���ҵ��ַ���Ϊstr��Trie���ĸ����Ϊroot��i=0��p=root
  1)ȡstr[i]���ж��ж�p->next[str[i]-97]�Ƿ�Ϊ�գ���Ϊ�գ��򷵻�false������Ϊ�գ���p=p->next[str[i]-97]������ȡ�ַ���
  2)�ظ�1)�еĲ���ֱ������������'\0'������ǰ���p��Ϊ�ղ��� exist Ϊtrue���򷵻�true�����򷵻�false��

3��ɾ��
  ɾ�������Եݹ����ʽ����ɾ����
ǰ׺��ѯ�ĵ���Ӧ�ã�
*/
#include<iostream>  
#include<cstring>  
using namespace std;  
  
typedef struct Trie_node  
{  
    int count;                    // ͳ�Ƶ���ǰ׺���ֵĴ���  
    struct Trie_node* next[26];   // ָ�����������ָ��  
    bool exist;                   // ��Ǹý�㴦�Ƿ񹹳ɵ���    
}TrieNode , *Trie;  
  
TrieNode* createTrieNode()  
{  
    TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));  
    node->count = 0;  
    node->exist = false;  
    memset(node->next , 0 , sizeof(node->next));    // ��ʼ��Ϊ��ָ��  
    return node;  
}  
  
void Trie_insert(Trie root, char* word)  
{  
    Trie node = root;  
    char *p = word;  
    int id;  
    while( *p )  
    {  
        id = *p - 'a';  
        if(node->next[id] == NULL)  
        {  
            node->next[id] = createTrieNode();  
        }  
        node = node->next[id];  // ÿ����һ�����൱����һ���´�������ָ�������ƶ�  
        ++p;  
        node->count += 1;      // ���д�������ͳ��ÿ������ǰ׺���ֵĴ�����Ҳ����ͳ��ÿ�����ʳ��ֵĴ�����  
    }  
    node->exist = true;        // ���ʽ����ĵط���Ǵ˴����Թ���һ������  
}  
  
int Trie_search(Trie root, char* word)  
{  
    Trie node = root;  
    char *p = word;  
    int id;  
    while( *p )  
    {  
        id = *p - 'a';  
        node = node->next[id];  
        ++p;  
        if(node == NULL)  
            return 0;  
    }  
    return node->count;  
}  
  
int main()  
{  
    Trie root = createTrieNode();     // ��ʼ���ֵ����ĸ��ڵ�  
    char str[12] ;  
    bool flag = false;  
    while(gets(str))  
    {  
        if(flag) printf("%d\n",Trie_search(root , str));  
        else  
        {  
            if(strlen(str) != 0)
            {  
                Trie_insert(root , str);  
            }  
            else flag = true;  
        }  
    }  
    return 0;  
}  
