#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

void insert_first();
void insert_pos();
void insert_last();
void del_first();
void del_last();
void del_pos();
void ll_traversal();

void ll_traversal()
{
    struct node *ptr;
    ptr=head;
    do
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

void insert_last()
{
    printf("Insert at last:\n");
    struct node *new,*temp;
    char ch;
    int value;
    printf("Do you want to continue?: ");
    scanf("%s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&value);
        new->data=value;
        if(head==NULL)
        {
            head=new;
            new->next=head;
            new->prev=head;
        }
        else
        {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=new;
            new->next=head;
            new->prev=temp;
            head->prev=new;
            // head=new;
        }
        printf("Do u want to continue? (y/n): ");
        scanf("%s",&ch);
    }
    ll_traversal();
}

void insert_first()
{
    printf("Insert at first:\n ");
    char ch;
    int value;
    struct node *new,*temp;
    printf("Do u want to continue? (y/n): ");
    scanf("%s",&ch);
    while(ch=='y')
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&value);
        new->data=value;
        if(head==NULL)
        {
            head=new;
            new->next = head;
            new->prev=head;    
        }
        else
        {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=new;
            new->next=head;
            new->prev=temp;
            head->prev=new;
            head=new;
        }
        printf("Do u want to continue? (y/n): ");
        scanf("%s",&ch);
    }
    ll_traversal();
}

void insert_pos()
{
    int count=1;
    struct node *new,*ptr;
    int value,pos;
    ptr=head;
    printf("\nInserting at a position: \n");
    printf("\nEnter the postion: ");
    scanf("%d",&pos);
    printf("\nEnter the value: ");
    scanf("%d",&value);
    new=(struct node *)malloc(sizeof(struct node));
    new->data=value;
    do
    {
        ptr=ptr->next;
        count++;
    }while(ptr!=head && count!=pos-1);
    new->next=ptr->next;
    new->next->prev=new;
    new->prev=ptr;
    ptr->next=new;
    ll_traversal();
}

void del_first()
{
    struct node * ptr,*temp;
    // ptr=head;
    if(head==NULL)
    {
        printf("Deletion not possible\n");
        exit(0);
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=head->next;
        head->next->prev=ptr;
        free(head);
        head=ptr->next;
    }
    printf("\nDeleting the data at the first position:\n");
    ll_traversal();
}

void del_last()
{
    struct node * ptr, *temp;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    temp=ptr;
    ptr->prev->next=head;
    head->prev=ptr->prev;
    free(ptr);
    printf("\nDeleting the data at the last position:\n");
    ll_traversal();
}

void del_pos()
{
    int pos,count=1;
    printf("\nEnter the position to delete: ");
    scanf("%d",&pos);
    printf("\nDeleting at position %d\n",pos);
    struct node * ptr,*temp;
    ptr=head;
    do
    {
        ptr=ptr->next;
        count++;
    }while(ptr!=head && count!=pos-1);
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    ll_traversal();
}

int main()
{
    int choice;
    printf("\nDOUBLE CIRCULAR LINKED LIST OPERATIONS:\n");
    printf("\n1:Insert at first\n2:Insert at last\n3:Insert at pos\n4:Delete at first\n5:Delete at last\n6:Delete at position\n");
    int i=0;
    while(i!=1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                insert_first();
                printf("\n");
                break;
            }
            case 2:
            {
                insert_last();
                printf("\n");
                break;
            }
            case 3:
            {
                insert_pos();
                printf("\n");
                break;
            }
            case 4:
            {
                del_first();
                printf("\n");
                break;
            }
            case 5:
            {
                del_last();
                printf("\n");
                break;
            }
            case 6:
            {
                del_pos();
                printf("\n");
                break;
            }
            default:
            {
                i=1;
            }
        }
    }
    return 0;
}

