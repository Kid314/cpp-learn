#include<stdio.h>
#include<stdlib.h>
typedef struct tree_node
{
    int data;
    struct tree_node* left;
    struct tree_node* right;
}Node,*pNode;

pNode init(int _data)
{
    pNode head=(pNode)malloc(sizeof(Node));
    head->data=_data;
    head->left=NULL;
    head->right=NULL;
    return head;
}

void addData(pNode head,int _data)
{
    if(head==NULL)
    {
        printf("还没初始化\n");
        return ;
    }

    pNode help=head;
    pNode help_fa=help;
    pNode temp=(pNode)malloc(sizeof(Node));
    temp->data=_data;
    temp->left=NULL;
    temp->right=NULL;

    while(help!=NULL)
    {
        if(_data>help->data)
        {
            help_fa=help;
            help=help->right;
        }
        else
        {
            help_fa=help;
            help=help->left;
        }
    }
    if(_data>help_fa->data)
    {
        help_fa->right=temp;
    }
    else
    {
        help_fa->left=temp;
    }
}

void search(pNode head,int _data)
{
    pNode help=head;
    pNode help_pre=help;
    while(help)
    {
        if(help->data==_data)
        {
            break;
        }
        if(_data>help->data)
        {
            help_pre=help;
            help=help->right;
        }
        else
        {
            help_pre=help;
            help=help->left;
        }
    }
    if(help==NULL)
    {
        printf("没有找到要查找的数字\n");
        return ;
    }
    if(help->left==NULL&&help_pre->right==NULL)
    {
        if(_data>help_pre->data)
        {
            help_pre->right==NULL;
            free(help);
            return ;
        }
        else
        {
            help_pre->left==NULL;
            free(help);
            return ;
        }
    }
    if(help->left==NULL||help->right==NULL)
    {
        if(help->left==NULL)
        {
            if(_data>help_pre->data)
            {
                help_pre->right=help->right;
                free(help);
            }
            else
            {
                help_pre->left=help->right;
                free(help);
            }
        }
        else
        {
            if(_data>help_pre->data)
            {
                help_pre->right=help->left;
                free(help);
            }
            else
            {
                help_pre->left=help->left;
                free(help);
            }
        }
        return ;
    }
    pNode help_next=help->right;
    help_pre=help_next;
    while(help_next->left!=NULL)
    {
        help_pre=help_next;
        help_next=help_next->left;
    }
    if(help_pre==help_next)
    {
        help->data=help_next->data;
        help->right=help_next->right;
        free(help_next);
        return ;
    }
    help->data=help_next->data;
    help_pre->left=help_next->right;
    free(help_next);
}

void show(pNode head)
{
    if(head!=NULL)
    {
        show(head->left);
        printf("%d ",head->data);
        show(head->right);
    }
}

int main()
{
    //17,12,19,10,15,18,25,8,11,13,16,22
    int nums[]={12,19,10,15,18,25,8,11,13,16,22};
    pNode head=init(17);
    for(int i=0;i<11;i++)
    {
        addData(head,nums[i]);
    }
    show(head);
    search(head,1);
    search(head,10);
    show(head);
    return 0;
}