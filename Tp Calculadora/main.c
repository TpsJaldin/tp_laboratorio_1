#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "math.h"
#include <windows.h>

int main()
{
    float numA, numB, resultAddition, resultSubtract, resultMultiplication, resultDivision;
    int flagExit = 1, opcion, flagA = 0, flagB = 0, resultFactorialA, resultFactorialB;
    int controlStep1=0, controlStep2=0, controlStep3=0;
    do
    {
        if (flagA == 1)
        {
            printf("1. Ingresar 1er operando (A=%.2f)\n", numA);
        } else
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }
        if (flagB == 1)
        {
            printf("2. Ingresar 2do operando (B=%.2f)\n", numB);
        } else
        {
            printf("2. Ingresar 2do operando (B=y)\n");
        }
        printf("3. Calcular\n");
        printf("4. Informar\n");
        printf("5. Salir\n");
        printf("\nIngrese una opcion del menu:");
        fflush (stdin);//__fpurge(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            enterNumber(&numA);
            flagA = 1;
            controlStep1++;
            break;
        case 2:
            enterNumber(&numB);
            flagB = 1;
            controlStep2++;
            break;
        case 3:
            if (flagA == 1 && flagB == 1)
            {
                resultAddition = addition (numA,numB);
                resultSubtract = subtract (numA,numB);
                resultMultiplication = multiplication (numA,numB);
                resultDivision = division (numA, numB);
                resultFactorialA = factorialA(numA);
                resultFactorialB = factorialB(numB);
                controlStep3++;
            }
            else
            {
                printf(" Error, Ingrese los numeros!");
            }
            break;

        case 4:
            printf("\n>>>>>>> RESULTADOS <<<<<<<\n");

            if( controlStep1==0 || controlStep2==0 || controlStep3==0 )
            {
                printf("\n ERROR, valor faltante y/o invalido!\n Verifique lo ingresado e intente nuevamente.\n");
            }
            else
            {

                printf("\nEl resultado de la suma es: %.2f ",resultAddition);
                /////////////

                printf("\nEl resultado de la resta es: %.2f ",resultSubtract);

                ///////////////

                if (numB == 0)
                {
                    printf("\nNo se puede dividir por cero, asigne otro valor B en la opcion 2." );

                }else
                {
                    printf("\nEl resultado de A/B es: %.2f", resultDivision);
                    //scanf("%f", &numB);}
                }


                ////////////////////////


                printf("\nEl resultado de A*B es: %.2f", resultMultiplication);

                ////////////////////////////////
                if(numA<0)
                {

                    printf("\nEl factorial de A es: Un numero negativo no tiene factorial");
                }
                else
                {
                    printf("\nEl factorial de A es: %d",resultFactorialA);
                }
                if(numB<0)
                {
                    printf("\nEl factorial de B es: Un numero negativo no tiene factorial\n\n");
                }
                else
                {
                    printf("\nEl factorial de B es: %d \n\n",resultFactorialB);
                }
            }
            break;
        case 5:
            printf("Saliendo...");
            flagExit = 0;
            break;
        default:
            printf("Ingrese una opcion que sea valida por favor.\n");
        }

        fflush(stdin);//__fpurge(stdin);
        printf("\nIngrese ENTER para continuar...");
        getchar();
        system ("cls");//system("clear");
    }
    while(flagExit != 0);

    return 0;
}
