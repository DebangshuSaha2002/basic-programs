#include<stdio.h>

void printing(int A[],int d1)
{
    for(int i=d1;i>=0;i--)
    {
        if(i>0)
        {
            printf("%d x^%d + ",A[i],i);
        }
        else if(i==0)
        {
            printf("%d x^%d",A[i],i);
        }
    }
}

void polynomial_product(int d1,int d2,int a[],int b[])
{
    int product[d1+d2];
    for(int i=(d1+d2);i>=0;i--)
    {
        product[i]=0;
    }
    for(int i=d1;i>=0;i--)
    {
        for(int j=d2;j>=0;j--)
        {
            product[i+j]+=a[i]*b[j];
        }
    }
    printing(product,d1+d2);
}

int main()

{
    int degree1,degree2;
    printf("Enter the degree of polynomial A: ");
    scanf("%d",&degree1);
    int A[degree1+1];
    printf("Enter the degree of polynomial B: ");
    scanf("%d",&degree2);
    int B[degree2+1];
    // int m=maxdegree(degree1,degree2);
    // for(int i=m;i>=0;i--)
    // {
    //     A[i]=0;
    //     B[i]=0;
    // }
    for(int i=degree1;i>=0;i--)
    {
        printf("Enter the coefficient of x^%d\n",i);
        scanf("%d",&A[i]);
    }
    for(int i=degree2;i>=0;i--)
    {
        printf("Enter the coefficient of x^%d\n",i);
        scanf("%d",&B[i]);
    }
    printf("\nPolynomial A is: ");
    printing(A,degree1);

    printf("\nThe Polynomial B is: ");
    printing(B,degree2);

    printf("\nMultiplying the 2 polynomials\n");
    polynomial_product(degree1,degree2,A,B);

    return 0;
}