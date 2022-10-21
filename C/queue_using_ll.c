#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * next;
}*front=NULL,*rear=NULL;

void traversal();

void enqueue(int val)
{
    struct node * new;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=val;
    new->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
}

void dequeue()
{
    int val;
    struct node * temp;
    if(front==NULL && rear==NULL)
    {
        printf("UNDERFLOW");
        return;
    }
    if(front==rear)
    {
        temp=front;
        val=front->info;
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        val=front->info;
        front=front->next;
        free(temp);
    }
}

void peek()
{
    int val;
    if(front==NULL && rear==NULL)
    {
        printf("Empty Queue\n");
        return ;
    }
    else
    {
        val=front->info;
        printf("The Peeked value is: %d\n",val);
    }
}

void traversal()
{
    struct node * ptr=front;
    while(ptr!=rear)
    {
        printf("%d\n",ptr->info);
        ptr=ptr->next;    
    }
    printf("%d\n",ptr->info);
}

int main()
{

    int val;
    char ch;
    printf("Do you want to enqueue: (y/n) ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        printf("Enter the value: ");
        scanf("%d",&val);
        enqueue(val);
        printf("Do you want to enqueue: (y/n) ");
        scanf(" %s",&ch);
    }
    traversal();

    printf("Calling Dequeue: \n");
    dequeue();
    printf("Calling Dequeue: \n");
    dequeue();

    traversal();

    peek();

    printf("Calling Dequeue: \n");
    dequeue();

    peek();

    traversal();
    return 0;
}