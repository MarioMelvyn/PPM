#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a =10;
    int b= 500;
    int *ptr=&b;
    printf ("\nValor de a: %d",a);
    printf ("\nIngrese numero entero: \n");
    scanf ("%d", ptr);
    printf ("\nValor de a: %d",b);


}
