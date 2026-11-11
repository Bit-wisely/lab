#include<stdio.h>

int power(int a,int b)
{
    int res = 1;
    for(int i=0;i<b;i++)
    {
        res = res*a;
    }
    return res;
}

void main()
{
    int p,g,a,b,computedKeyA,computedKeyB,sharedKeyA,sharedKeyB;

    printf("Enter the value of p and g: ");
    scanf("%d %d",&p,&g);

    printf("Enter the private key of A and B: ");
    scanf("%d %d",&a,&b);

    computedKeyA = power(g,a)%p;
    computedKeyB = power(g,b)%p;

    sharedKeyA = power(computedKeyB,a)%p;
    sharedKeyB = power(computedKeyA,b)%p;

    printf("The shared key of A is: %d\n",sharedKeyA);
    printf("The shared key of B is: %d\n",sharedKeyB);
}
