#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "utn.h"
#include "ArrayEmployees.h"


int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max)
{
    int todoOk = -1;
    int buffer;

    if(pEntero!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&buffer) == 0 && buffer >= min && buffer<=max)
            {
                *pEntero= buffer;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max)
{
    int todoOk = -1;
    float auxFloat;

    if(pFloat!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat<=max)
            {
                *pFloat= auxFloat;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int utngetString(char* pAux,int limite)
{
    char auxString[4096];
    int todoOk =-1;
    if (pAux != NULL && limite >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux,auxString,limite);
            todoOk=0;
        }
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(utngetString(auxString,200)==0 && isInt(auxString)==0)
    {
        *pAux=atoi(auxString);
        todoOk=0;
    }
    return todoOk;
}
int isInt(char *pAux)
{
    int todoOk=-1;
    int contador=0;
    do
    {
        if(*(pAux+contador)<48||*(pAux+contador)>57)
        {
            break;
        }
        contador++;
    }while (contador<strlen(pAux));
    if(contador==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

int isFloat(char* pAux)
{
    int todoOk=-1;
    int contador=0;
    int contadorDePuntos=0;
    do
    {
        if(*(pAux+contador)==','||*(pAux+contador)=='.')
        {
            *(pAux+contador)='.';
            contadorDePuntos++;
            if(contadorDePuntos==2)
            {
                break;
            }
        }
        else if(*(pAux+contador)<48||*(pAux+contador)>57)
        {
            break;
        }
        contador++;
    }while (contador<strlen(pAux));
    if(contador==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(utngetString(auxString,200)==0 && isFloat(auxString)==0)
    {
        *pAux=atof(auxString);
        todoOk=0;
    }
    return todoOk;
}

int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError){
    int todoOk=-1;
    char auxString[limite];
    if(pAux!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("%s",msj);
            if(utngetString(auxString,limite)==0 && isLetras(auxString)==0){
                strncpy(pAux,auxString,limite);
                todoOk=0;
                break;
            }else
                printf("%s",msjError);
        }while(reintentos>=0);
    }
    return todoOk;
}

int isLetras(char*pAux){
    int todoOk=-1;
    int i=0;
    if(pAux!=NULL){
        do{
            if((*(pAux+i)<65||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pAux));
        if(i==strlen(pAux)){
            todoOk=0;
        }
    }
    return todoOk;
}

int validateFlag(int* flag, char* msgError)
{
    int todoOk=-1;

    if(*flag==1)
    {
        todoOk=0;
    }
    else
    {
        printf("%s", msgError);
        system("pause");

    }

    return todoOk;
}

int validarMail(char *pAux)
{
  int todoOk=-1;
    int i;
    int flagArroba=0;
    int flagPunto=0;
    int contarroba=0;
    if(pAux!=NULL)
    {
        for(i=0; i<strlen(pAux); i++)
        {
            if(i==0&&(pAux[i]==64||pAux[i]==46)||pAux[i]==32)
            {
                break;
            }

            if(pAux[i]==64)
            {
                flagArroba=1;
                contarroba++;
            }
            if(flagArroba==1 && contarroba==1)
            {
                if(pAux[i]==46)
                {
                    flagPunto=1;
                }
            }
        }
        if(i==strlen(pAux)&&flagArroba==1&&flagPunto==1&&contarroba==1)
        {
            todoOk=0;
        }
    }
    return todoOk;

}



int utn_getEmail(char* pString, int limite, int reintentos, char* msg, char* msgError)
{
    int todoOk=-1;
    char auxChar[limite];
    if(pString!=NULL && limite >0 && reintentos > 0)
    {

        do
        {
            reintentos--;
            printf("%s",msg);

            if(utngetString(auxChar,limite)==0 && validarMail(auxChar)==0)
            {
                strncpy(pString,auxChar,limite);
                todoOk=0;
                break;
            }
            else
            {
                printf("%s", msgError);

            }

        }
        while(reintentos>=0);
    }
    return todoOk;
}
