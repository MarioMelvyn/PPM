#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x, y;
    }tcoord;

int main()
{
   /* int *a, *b;
    a= (int *)malloc(sizeof(int));
    b= (int *)malloc(sizeof(int));
    *a= 5;
    *b= 10;
    printf("El valor de a es: %d", *a);
    printf("\nEl valor de b es: %d", *b);
    printf("\n El valor de la suma de a y b es: %d", (*a + *b));
    */
   /* tcoord *punto;
    punto = (tcoord *)malloc(sizeof(tcoord));
    printf("ingrese el valor de x: ");scanf("%d", &punto->x);
    printf("ingrese el valor de y: ");scanf("%d", &punto->y);
    printf("El valor de x es: %d, el valor de y es: %d", punto->x, punto->y);

    free(punto); punto = NULL;*/
    int i,n, *lis;
    printf("Ingrese el tamanio de la lista: ");scanf("%d", &n);
    lis= (int *)calloc(n,sizeof(int));

    for (i=0; i<n; i++)
    {


    printf("Ingrese el dato  de %d: ",i);
    scanf("%d", &lis[i]);
    }
    for (i=0; i<n; i++)
    {

    printf("\nEl valor dato %d: %d",i, lis[i]);

    }
    free(lis); lis= NULL;

}
