#include<stdio.h>
#include<stdlib.h>
typedef struct AVLNode
{
    int data;
    struct AVLNode* l;
    struct AVLNode* r;
    int h;
}AVLNode,*AVLTree;
int max(int a,int b)
{
    return a>b?a:b;
}
int get_h(AVLNode* x)
{
    if(x==NULL) return 0;
    else return x->h;
}
AVLTree LLrotation(AVLTree x)
{
    AVLNode* y=x->l;
    x->l=y->r;
    y->r=x;
    x->h=max(get_h(x->l),get_h(x->r))+1;
    y->h=max(get_h(y->l),get_h(y->r))+1;
    return y;
}
AVLTree RRrotation(AVLTree x)
{
    AVLNode* y=x->r;
    x->r=y->l;
    y->l=x;
    x->h=max(get_h(x->l),get_h(x->r))+1;
    y->h=max(get_h(y->l),get_h(y->r))+1;
    return y;
}
AVLTree LRrotation(AVLTree x)
{
    x->l=RRrotation(x->l);
    x=LLrotation(x);
}
AVLTree RLrotation(AVLTree x)
{
    x->l=LLrotation(x->l);
    x=RRrotation(x);
}
AVLNode* CreateNode(int x)
{
    AVLNode* s=(AVLNode*)malloc(sizeof(AVLNode));
    s->data=x;
    s->l=NULL;
    s->r=NULL;
    s->h=1;
    return s;
}
AVLTree InsertAVL(AVLTree root,int x)
{
    if(root==NULL)
    {
        root=CreateNode(x);
        return root;
    }
    if(x<root->data)
    {
        root->l=InsertAVL(root->l,x);
        if(get_h(root->l)-get_h(root->r)>1)
        {
            AVLNode* left=root->l;
            if(x<left->data)
            {
                root=LLrotation(root);
            }
            else
            {
                root=LRrotation(root);
            }
        }
    }
    else if(x>root->data)
    {
        root->r=InsertAVL(root->r,x);
        if(get_h(root->r)-get_h(root->l)>1)
        {
            AVLNode* right=root->r;
            if(x>right->data)
            {
                root=RRrotation(root);
            }
            else
            {
                root=RLrotation(root);
            }
        }
    }
    root->h=max(get_h(root->l),get_h(root->r))+1;
    return root;
}

void Inorder(AVLTree root)
{
    if(root==NULL)
    {
        return ;
    }
    Inorder(root->l);
    int p=get_h(root->r)-get_h(root->l);
    printf("%d %d %d\n",root->data,root->h,p);
    Inorder(root->l);
}

int main()
{
    int n,x,k;
    AVLTree root=NULL;
    return 0;
}