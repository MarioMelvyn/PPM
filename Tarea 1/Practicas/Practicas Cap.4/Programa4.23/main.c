#include <stdlib.h>
#include <stdio.h>
void trueque(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int suma(int x)
{
    return (x + x);
}

int main()
{
    int a = 5;
    int b = 10;

    printf("Valores antes del trueque: a = %d, b = %d\n", a, b);

    trueque(&a, &b);

    printf("Valores después del trueque: a = %d, b = %d\n", a, b);

    int resultado = suma(a);

    printf("El resultado de la suma es: %d\n", resultado);

    return 0;
}
