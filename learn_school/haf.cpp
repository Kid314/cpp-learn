#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
typedef struct node
{
    char ch;
    int count;
    struct node* left,*right;
}Node,*pNode;

std::vector<pNode> character;
std::vector<char> code;

pNode linktree(Node* tree_a,Node* tree_b)
{
    pNode newNode=(pNode)malloc(sizeof(Node));
    newNode->ch='!';
    newNode->count=tree_a->count+tree_b->count;
    newNode->left=tree_a;
    newNode->right=tree_b;
    return newNode;
}

void read()
{
    int n;
    int count;
    char ch;
    scanf("%d",&n);
    getchar();
    for(n;n>0;n--)
    {
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->left=newNode->right=NULL;
        scanf("%c %d",&ch,&count);
        newNode->ch=ch;
        newNode->count=count;
        getchar();
        character.push_back(newNode);
    }
}

pNode inithaftree()
{
    while(character.size()!=1)
    {
        std::sort(character.begin(),character.end(),[](const pNode& a,const pNode& b)
                                                        {
                                                            return a->count>b->count;
                                                        });
        Node* newNode1=character.back();
        character.pop_back();
        Node* newNode2=character.back();
        character.pop_back();
        pNode newTreeNode=linktree(newNode1,newNode2);
        character.push_back(newTreeNode);
    }
    return character.back();
}

void coding(char ch)
{
    FILE* fp=fopen("codefile","a");
    if (fp==NULL) {
        printf("无法打开文件！");
        return ;
    }
    fprintf(fp,"%c ",ch);
    for(int i=0;i<code.size();i++)
    {
        fprintf(fp,"%c",code[i]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}

void forepost(pNode head)
{
    if(head->ch!='!')
    {
        coding(head->ch);
        return ;
    }
    code.push_back('0');
    forepost(head->left);
    code.pop_back();
    code.push_back('1');
    forepost(head->right);
}

int main()
{
    read();
    pNode mynode=inithaftree();
    forepost(mynode);
    return 0;
}