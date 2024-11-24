//线程池学习(只展示了方法一哦)
#include<stdio.h>
#include<pthread.h>



//入队
#define LINK_ADD(item,list) do
{
    item->prev=NULL;
    item->next=list;
    if(list!=NULL)
    {
        list->prev=item;
    }
    list=item;
} while (0)











//结构体实现
struct worker_entry
{
    struct worker_entry *next;
    struct worker_entry *prev;
    pthread_t id;
    int  terminate;
};

struct task_entry
{
    void (*task_callback)(void *arg);
    void *userdata;

#if 1
    struct task_entry *next;
    struct task_entry *prev;
#endif 
    //struct task_entry *next;
};

struct thread_pool
{
    struct worker_entry *workq;
    struct task_entry *taskq;

};

/*struct task_queue
{
    struct task_entry *head;
    struct task_entry **tail;
};*/
int main()
{
    return 0;
}