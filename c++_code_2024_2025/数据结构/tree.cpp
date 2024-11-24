#include<bits/stdc++.h>
template<typename T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T>* leftChild;
    binaryTreeNode<T>* rightChild;

    binaryTreeNode() {leftChild=rightChild=NULL}
    binaryTreeNode(const T& theElement)
    {
        element(theElement);
        leftChild=rightChild=NULL;
    }
    binaryTreeNode(const T& theElement,binaryTreeNode* theleftChild,binaryTreeNode* therightChild)
    {
        element(theElement);
        leftChild=theleftChild;
        rightChild=therightChild;
    }
};
template<typename T>
void visit(binaryTreeNode<T>* x)
{
    std::cout<<x->element<<"\n";
}

template<typename T>
void preOrder(binaryTreeNode<T>* t)
{
    if(t!=NULL)
    {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template<typename T>
void inOrder(binaryTreeNode<T>* t)
{
    if(t!=NULL)
    {
        preOrder(t->leftChild);
        visit(t);
        preOrder(t->rightChild);
    }
}

template<typename T>
void postOrder(binaryTreeNode<T>* t)
{
    if(t!=NULL)
    {
        preOrder(t->leftChild);
        preOrder(t->rightChild);
        visit(t);
    }
}

template<typename T>
void levelOrder(binaryTreeNode<T>* t)
{
    std::queue<binaryTreeNode<T>*> q;
    while(t!=NULL)
    {
        visit(t);

        if(t->leftChild!=NULL)
            q.push(t->leftChild);
        if(t->rightChild!=NULL)
            q.push(t->rightChild);

        try
        {
            t=q.front();
        }
        catch(std::queueEmpty)
        {
            return;
        }

        q.pop();
    }
}






template<typename T>
class binaryTree
{
public:
    virtual ~binaryTree(){}
    virtual bool empty() const=0;
    virtual int size() const=0;
    virtual void preOrder(void (*)(T*)) const=0;
    virtual void postOrder(void (*)(T*)) const=0;
    virtual void inOrder(void (*)(T*)) const=0;
    virtual void levelOrder(void (*)(T*)) const=0;
};

template<typename E>
class linkedBinaryTree: public binaryTree<binaryTreeNode<E> >
{
private:
    binaryTreeNode<E>* root;
    int treeSize;
    static void (*visit)(binaryTreeNode<E>*);
    static void preOrder(binaryTreeNode<E>* t);
    static void inOrder(binaryTreeNode<E>* t);
    static void postOrder(binaryTreeNode<E>* t);
    static void dispose(binaryTreeNode<E>* t) {delete t;}
    static void output(binaryTreeNode<E>* t) {std::cout<<t->element<<"\n";}
    static int height(binaryTreeNode<E>* t)
public:
    linkedBinaryTree()
    {
        root=NULL;
        treeSize=0;
    }
    ~linkedBinaryTree() {erase();}
    bool empty() const {return treeSize==0;}
    int size() const {return treesize;}
    void preOrder(void (*theVisit)(binaryTreeNode<E>*))
    {
        visit=theVisit;
        preOrder(root);
    }
    void inOrder(void (*theVisit)(binaryTreeNode<E>*))
    {
        visit=theVisit;
        inOrder(root);
    }
    void postOrder(void (*theVisit)(binaryTreeNode<E>*))
    {
        visit=theVisit;
        postOrder(root);
    }
    void erase()
    {
        postOrder(dispose);
        root=NULL;
        treeSize=0;
    }
    void preOrderOutput() {preOrder(output);std::cout<<std::endl;}
    int height() const {return height(root);}
};

template<typename E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E>* t)
{
    if(t!=NULL)
    {
        linkedBinaryTree<E>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template<typename E>
int linkedBinaryTree<E>::height(binaryTreeNode<E>* t)
{
    if(t==NULL)
        return 0;
    int hl=height(t->leftChild);
    int hr=heught(t->rightChild);
    if(hl>hr)
        return ++hl;
    else
        return ++hr;
}