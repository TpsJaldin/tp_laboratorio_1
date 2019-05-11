#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "utn.h"
#include "ArrayEmployees.h"

#define TRUE 1
#define FALSE 0


/**
 *  \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param pEmployee eEmployee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(eEmployee* pEmployee, int length)
{
    int i;
    int retorno=0;
    if ( pEmployee==NULL || length<=0 )
        retorno=-1;
    else
        for (i=0;i<length;i++)
            pEmployee[i].isEmpty=TRUE;
    return retorno;
}


/**
 * \brief add in a existing list of employees the values recived as parameters
 * \param pEmployee eEmployee*
 * \param length int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */


int addEmployee(eEmployee* pEmployee[],int limite)
{
    char auxName[50];
    char auxLastName[50];

    char auxSector[5];
    char auxSalary;
    int sector;
    int salary;
    int retorno = -2;

    int indice;

    if(limite > 0 && pEmployee != NULL)
    {
        retorno = -1;
       indice=obtenerEspacioLibre(pEmployee,limite);

        if(indice >= 0)
        {

              if(!getStringLetras("Ingrese nombre de persona : ",auxName))
              {
                printf ("ERROR:Ingrese solo letras!! \n");
                return -2;
              }
              if(!getStringLetras("Ingrese apellido de persona : ",auxLastName))
              {
                printf ("ERROR:Ingrese solo letras!! \n");
                return -2;
              }
             if(!getStringNumeros("Ingrese el salario : ",auxSalary))
                {
                    printf ("ERROR:Ingrese numeros!! \n");
                    return -2;
                }
                salary=atoi(auxSalary);
             if(!getStringNumeros("Ingrese el numero de sector: elija entre //1///2//3//4//5// : \n",auxSector))
             {
                    printf ("ERROR:Ingrese numeros!! \n");
                    return -2;
             }

                pEmployee[indice].id = getIdEmployee(pEmployee,len);
                strcpy(pEmployee[indice].name,name);
                strcpy(pEmployee[indice].lastName,lastName);
                pEmployee[indice].salary=salary;
                pEmployee[indice].sector=sector;
                pEmployee[indice].isEmpty=1;
                retorno=0;

        }

    }
    return retorno;
}

int findEmptySlot(eEmployee* pEmployee, int length)
{
    int todoOk=-1;

        for(int i = 0 ; i < length ; i++)
        {
            if(list[i].isEmpty==0)
            {
                todoOk=i;
                break;
            }
        }

    return todoOk;
}


/**
 * \brief find a Employee by Id
 * \param pEmployee eEmployee*
 * \param length int
 * \param id int
 * \return eEmployee* Return a (Employee pointer) if ok or (NULL pointer) if [Invalid length or NULL pointer recived or employeed not found]
 */
int findEmployeeById(eEmployee* pEmployee, int length,int id)
{

    int i;
    eEmployee* retorno=NULL;
    if ( pEmployee!=NULL && length>0 )
        for (i=0 ; i<length;i++)
            if ( pEmployee[i].isEmpty !=TRUE && pEmployee[i].id==id )
            {
                retorno=pEmployee+i;
                break;
            }
    return retorno;
}


/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param pEmployee eEmployee*
 * \param length int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a eEmployee] - (0) if Ok
 */
int removeEmployee(eEmployee* pEmployee, int length, int id)
{
    int i;
    int retorno=-1;
    if ( pEmployee!=NULL && length>0 )
        for (i=0 ; i<length ; i++)
            if ( pEmployee[i].isEmpty!=TRUE && pEmployee[i].id==id )
            {
                pEmployee[i].isEmpty=TRUE;
                retorno=0;
                break;
            }
    return retorno;
}


/**
 * \brief Sort the elements in the array of employees by Name, the argument order indicate UP or DOWN order
 * \param pEmployee eEmployee*
 * \param length int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
void sortEmployeeByName(eEmployee* pEmployee, int length, int order)
{
    int i;
    int flagSwap = 1;
    eEmployee aux;

    int retorno=-1;
    if ( pEmployee!=NULL && length>0 )
    {
        retorno=0;
        while(flagSwap)
        {
            flagSwap = 0;
            for(i = 0; i<length-1 ; i++)
            {
                if( order==1 && strcmp(pEmployee[i].name,pEmployee[i+1].name) > 0 ) /// && pEmployee[i].isEmpty!=TRUE && pEmployee[i].isEmpty!=TRUE )
                {
                    aux = pEmployee[i+1];
                    pEmployee[i+1] = pEmployee[i];
                    pEmployee[i] = aux;
                    flagSwap = 1;
                }
                else if( order==1 &&  strcmp(pEmployee[i].name,pEmployee[i+1].name) < 0 ) /// && pEmployee[i].isEmpty!=TRUE && pEmployee[i].isEmpty!=TRUE )
                {
                    aux = pEmployee[i+1];
                    pEmployee[i+1] = pEmployee[i];
                    pEmployee[i] = aux;
                    flagSwap = 1;
                }
            }
        }
    }
    return retorno;
}



/**
 * \brief
 * \param pEmployee eEmployee*
 * \param length int
 * \return int
 */
void printEmployees(eEmployee* pEmployee, int length)
{
    int i;
    printf("\n  Id   -       Name       -     Last Name    - Salary  - Sector");
    for(i=0; i< length; i++)
    {
        if(!pEmployee[i].isEmpty)
            printf("\n%6i - %-16s - %-16s - %4.2f - %6d",pEmployee[i].id, pEmployee[i].name, pEmployee[i].lastName, pEmployee[i].salary, pEmployee[i].sector );
    }
    return 0;
}

//////////////////////////////////////////////////
////////////////////////////////////////////////////
/////////////////////////////////////
int modifyMenu()
{
    int opcion;

    system("cls");
    fflush(stdin);
    printf("1- Modificar nombre.\n2- Modificar apellido. \n3- Modificar sueldo. \n4- Modificar sector.\n5-Volver al menu principal\n\n Ingresar opcion :  ");
    scanf("%d", &opcion);

    return opcion;

}


char areYourSure(char* msg, char* errormsg)
{
    char confirm;

    printf("%s", msg);
    fflush(stdin);
    confirm = tolower(getche());

    while(confirm!='s' && confirm!='n')
    {
        printf("%s", errormsg);
        fflush(stdin);
        confirm = tolower(getche());
    }

    return confirm;
}

void modifyEmployee(eEmployee* pEmployee, int size)
{

    int id;
    int search;
    int auxInt;
    float auxFloat;
    char auxChar[51];
    char continuee='s';


    printEmployees(pEmployee,size);

    printf("\n\nIngrese el ID del empleado que desea modificar:\n ");
    scanf("%d", &id);

    search = findEmployeeById(pEmployee, size, id);

    if( search == -1)
    {

        printf("\nEl legajo %d no se encuentre registrado en el sistema\n", id);
    }
    else
    {
        do
        {
            switch(modifyMenu())
        {
        case 1 :
            if(areYourSure("Desea cambiar el nombre del empleado? s/n : ", "Error al ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo nombre : \n", "\nError al ingresar, nombre invalido : \n");
                strcpy(pEmployee[search].name,auxChar);
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }

            break;
        case 2 :
            if(areYourSure("Desea cambiar el apellido del empleado s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo apellido : \n", "\nError ingresar, apellido invalido : \n");
                strcpy(pEmployee[search].lastName,auxChar);
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }
            break;
        case 3 :
            if(areYourSure("Desea cambiar el sueldo del empleado s/n : ", "Error ingresar s/n \n")=='s')
            {
                utn_getFlotante(&auxFloat,3,"\nIngresar nuevo sueldo : \n", "\nError ingresar, sueldo invalido : \n", 0,150000);
                pEmployee[search].salary=auxFloat;
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }

            break;
        case 4 :
            if(areYourSure("Desea cambiar el sector del empleado s/n : " , "Error ingresar s/n : ")=='s')
            {
                 utn_getEntero(&auxInt,3,"\nIngresar nuevo sector : \n", "Error ingresar sector valido : \n",0,5);
                pEmployee[search].sector=auxInt;
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }


            break;
        case 5:
            continuee='n';
            break;


        default:
            printf("Ingresar opcion valida\n");
            system("pause");
            break;


        }

        }while(continuee=='s');
    }


}

int salaryInformation( eEmployee* pEmployee , int size , float* averagefloatSalary , float* floatSalary , int* counterTotalInt )
{
    float acumulador=0;
    int averageCounter=0;
    int counter=0;
    int retorno=-1;

    for(int i=0;i<size;i++)
    {
        if(pEmployee[i].isEmpty==1)
        {
            acumulador+=pEmployee[i].salary;
            averageCounter++;
        }

    }

    *floatSalary=acumulador;
    *averagefloatSalary=acumulador/averageCounter;

    for(int i=0;i<size;i++)
    {
        if(pEmployee[i].isEmpty==1 && pEmployee[i].salary>*averagefloatSalary)
        {
            counter++;
        }
    }

    *counterTotalInt = counter;


    if(averagefloatSalary!=NULL && averagefloatSalary!=NULL && counterTotalInt!=NULL)
    {
        retorno=0;
    }

    return retorno;
}

//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
