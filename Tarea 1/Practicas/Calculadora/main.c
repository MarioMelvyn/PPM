#include <stdio.h>
#include <stdlib.h>
double Suma(double a,double b);
double Div(double numerador, double denominador);
double Multiplicacion(double multiplicando, double multiplicador)


int main()
{
    int menu = 0;
    int errores = 0;
    double res2;
    double num1, num2,res;



    do
    {
        printf("\n0- Salir \n1- Suma\n2- Division\n");
        scanf("%d",&menu);



        if(menu == 1)
        {
            errores = 0;
            printf("\nInsertr el numero 1:");
            scanf("%lf",&num1);
            printf("\nInsertr el numero 2:");
            scanf("%lf",&num2);
            res = Suma(num1,num2);
            printf("\n Suma de %lf + %lf = %lf\n\n",num1,num2,res);
        }
        else if(menu == 2)
        {
            errores = 0;
            printf("\nInsertr el numerador  :");
            scanf("%lf",&num1);
            printf("\nInsertr el denominador:");
            scanf("%lf",&num2);
            Div2(num1,num2,&res2);
            printf("\n Divicion de %lf / %lf = %lf\n\n",num1,num2,res2);
        }else
        {
            errores++;
            if(errores >= 3)
            {
                printf("\nPero mardito insertar numero del 0 al 2\n");
            }else
            {
                printf("\nFavor insertar numero del 0 al 2\n");
            }



        }



    }
    while(menu != 0);




    return 0;
}



double Suma(double a,double b)
{
    return a+b;
}



double Div(double numerador, double denominador)
{
    if(denominador == 0)
    {
        return 0;
    }
    else
    {
        return numerador/denominador;
    }



}



void Div2(double numerador, double denominador,double *result)
{
    if(denominador == 0)
    {
        return 0;
    }
    else
    {
        *result = numerador/denominador;
    }
}

