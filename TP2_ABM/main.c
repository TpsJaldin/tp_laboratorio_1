#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "utn.h"
#include "ArrayEmployees.h"

#define TAM 1000


int main()
{

   int auxInt;
   int flag=0;
   float auxFloat;
   float auxFloat2;
   char auxNombre[51];
   char auxApellido[51];
   char seguir='s';
   eEmployee employee[TAM];

   initEmployees(employee,TAM);
   //hardCodearEmpleados(employee,12);

   do{

        if(listEmpty(employee,TAM)==0)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }

       switch(menuAbm())
       {

            case 1:
               alta= addEmployee(persona,TAM);
               if(alta==-1)
               {
                   printf("No quedan mas espacios\n");
               }
               //else if(alta==-2)
               else{
                printf("Persona ingresada\n");
               }
                break;
                addEmployee(employee,TAM);
                system("pause");
                break;

            case 2:
                if(validateFlag(&flag,"\nPara poder dar de baja employee primero hay que ingresarlos.\n")==0)
                {
                    printEmployees(employee,TAM);
                    utn_getEntero(&auxInt,3,"Ingresar ID del empleado que desea Eliminar: ", "Error ingresar ID valido",0,TAM);
                    removeEmployee(employee,TAM,auxInt);
                    system("pause");
                }
                break;

            case 3:
                if(validateFlag(&flag,"\nPara poder modificar employee primero hay que ingresarlos.\n")==0)
                {
                    modifyEmployee(employee,TAM);
                    system("pause");
                }
                break;

            case 4:
                if(validateFlag(&flag,"\nPara poder mostrar employee primero hay que ingresarlos.\n")==0)
                {
                    sortEmployees(employee,TAM);
                    printEmployees(employee,TAM);
                    salaryInformation(employee,TAM,&auxFloat,&auxFloat2,&auxInt);
                    //int salaryInformation( eEmpleado* list , int size , float* averagefloatSalary , float* floatSalary , int* counterTotalInt )

                    printf("\n\nSuma de todos los sueldos : %.2f \nPromedio de todos los sueldos : %.2f \n Cantidad de Empleados que superan el promedio : %d \n", auxFloat2,auxFloat,auxInt);
                    system("pause");
                }
                break;

            case 5:
                seguir='n';
                break;

            default:
                printf("Ingresar opcion valida\n");
                system("pause");
                break;

       }

    }while(seguir=='s');

}


