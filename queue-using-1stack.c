#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct queue{
    struct node *stack1;
};
void push(struct node **top,int newdata)
{
    struct node *new_top=(struct node*)malloc(sizeof(struct node));
    if(new_top==NULL){
        printf("stack overflow");
        getchar();
        exit(0);
    }
    new_top->data=newdata;
    new_top->next=*top;
    *top=new_top;
}
int pop(struct node **top)
{
    int x;
    struct node *temp;
     if(*top==NULL){
        printf("underflow");
        getchar();
        exit(0);
    }
    temp=*top;
    x=temp->data;
    *top=temp->next;
    free(temp);
    return x;
}

void enqueue(struct queue *q, int x ){
    push(&q->stack1,x);
}

int dequeue(struct queue *q)
{
    int x,res;
    if(q->stack1==NULL){
        printf("underflow");
        getchar();
        exit(0);
    }
    else if(q->stack1->next==NULL){
        return pop(&q->stack1);
    }
    else{
        x=pop(&q->stack1);
        res=dequeue(q);
        push(&q->stack1,x);
        return res;
    }
}


int main()
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->stack1=NULL;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);

    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
return 0;
}
