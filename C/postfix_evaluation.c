//Postfix_evaluation

#include<stdio.h>
#include<ctype.h>

int stack[10];
int top = -1;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[10];
    char *e;
    int n1,n2,n3,n;
    printf("Enter the expression: ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            n=*e-48;
            push(n);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(*e)
            {
                case '+':
                {
                    n3=n2+n1;
                    break;
                }
                case '-':
                {
                    n3=n2-n1;
                    break;
                }
                case '*':
                {
                    n3=n2*n;
                    break;
                }
                case '/':
                {
                    n3=n2/n1;
                    break;
                }
                case '^':
                {
                    n3=n2^n1;
                    break;
                }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}