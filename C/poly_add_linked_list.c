#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int co;
    int ex;
    struct Node *next;
};
void show_poly(struct Node *Head)
{
    struct Node *PTR = Head;
    while (PTR->next != NULL)
    {
        printf("%dx^%d+", PTR->co, PTR->ex);
        PTR = PTR->next;
    }
    printf("%dx^%d", PTR->co, PTR->ex);
    PTR=PTR->next;
}
struct Node *create(struct Node *Head)
{
    struct Node *PTR, *New;
    Head = NULL;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Co-efficient : ");
    scanf("%d", &New->co);
    printf("Exponent : ");
    scanf("%d", &New->ex);
    New->next = NULL;
    Head = New;
    PTR = Head;
    int choice;
    printf("\n0 for Exit & 1 for continue? :");
    scanf("%d", &choice);
    while (choice != 0)
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        printf("Co-efficient: ");
        scanf("%d", &New->co);
        printf("Exponent: ");
        scanf("%d", &New->ex);
        New->next = NULL;
        PTR->next = New;
        PTR = PTR->next;
        printf("\n0 for Exit & 1 for continue? :");
        scanf("%d", &choice);
    }
    show_poly(Head);
    return Head;
}
struct Node *insert(struct Node *HEAD3, int ex, int co)
{
    struct Node *New, *PTR;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->ex = ex;
    New->co = co;
    New->next = NULL;
    if (HEAD3 == NULL)
    {
        HEAD3 = New;
    }
    else
    {
        PTR = HEAD3;
        while (PTR->next != NULL)
        {
            PTR = PTR->next;
        }
        PTR->next = New;
    }
    return (HEAD3);
}
struct Node *add_poly(struct Node *HEAD1, struct Node *HEAD2)
{
    struct Node *HEAD3, *PTR1, *PTR2;
    HEAD3 = NULL;
    PTR1 = HEAD1;
    PTR2 = HEAD2;
    while (PTR1 != NULL && PTR2 != NULL)
    {
        if (PTR1->ex == PTR2->ex)
        {
            HEAD3 = insert(HEAD3, PTR1->ex, PTR1->co + PTR2->co);
            PTR1 = PTR1->next;
            PTR2 = PTR2->next;
        }
        else if (PTR1->ex > PTR2->ex)
        {
            HEAD3 = insert(HEAD3, PTR1->ex, PTR1->co);
            PTR1 = PTR1->next;
        }
        else
        {
            HEAD3 = insert(HEAD3, PTR2->ex, PTR2->co);
            PTR2 = PTR2->next;
        }
    }
    while (PTR1 != NULL || PTR2 != NULL)
    {
        if (PTR1 != NULL)
        {
            HEAD3 = insert(HEAD3, PTR1->ex, PTR1->co);
            PTR1 = PTR1->next;
        }
        if (PTR2 != NULL)
        {
            HEAD3 = insert(HEAD3, PTR2->ex, PTR2->co);
            PTR2 = PTR2->next;
        }
    }
    show_poly(HEAD3);
    return HEAD3;
}

int main()
{
    struct Node *HEAD1, *HEAD2, *HEAD3;
    printf("\n**1st Polynomial**\n\n");
    HEAD1 = create(HEAD1);
    printf(" -> 1st Polynomial\n");

    printf("\n\n**2nd Polynomial**\n\n");
    HEAD2 = create(HEAD2);
    printf(" -> 2nd Polynomial\n");

    printf("\n\nAdded Polynomial: ");
    HEAD3 = add_poly(HEAD1, HEAD2);

    return 0;
}