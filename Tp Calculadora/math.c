
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>


void enterNumber(float* pNumber)
{
    printf("Ingrese un numero: ");
    fflush(stdin); // __fpurge(stdin);
    scanf("%f", pNumber);
}

float addition (float numA,float numB)
{
    float result;
    result = numA+numB;
    return result;
}

float subtract (float numA,float numB)
{
    float result;
    result = numA - numB;
    return result;
}
/*
int division(float numA, float numB)
{
    float result;
    result = numA/numB;
    return result;
}
*/

float division(float numA, float numB)
{
    float result;
    result = (numA/numB);
    return result;

}

float multiplication (float numA, float numB)
{

    float result;
    result = numA*numB;
    return result;
}
/*
float factorial (int number)
{
    if (number==1 || number ==0)
    {
        return 1;
    }
    else
    {
        return (number* factorial (number - 1 ));
    }
}
*/

int factorialA (int numA)
{
    if (numA==1 || numA ==0)
    {
        return 1;
    }
    else
    {
        return (numA* factorialA (numA - 1 ));
    }
}


int factorialB (int numB)
{
    if (numB==1|| numB ==0)
    {
        return 1;
    }
    else
    {
        return (numB* factorialB (numB - 1 ));
    }
}



