#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


 // ARRAYEMPLOYEES_H_INCLUDED
int initEmployees(eEmployee* pEmployee, int length);
int addEmployee(eEmployee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector);
int findEmptySlot(eEmployee* pEmployee, int length);

int findEmployeeById(eEmployee* pEmployee, int length,int id);
int removeEmployee(eEmployee* pEmployee, int length, int id);
void sortEmployeeByName(eEmployee* pEmployee, int length, int order);
void printEmployees(eEmployee* pEmployee, int length);
int modifyMenu();
char areYourSure(char* msg, char* errormsg);
void modifyEmployee(eEmployee* pEmployee, int size);
int salaryInformation( eEmployee* pEmployee , int size , float* averagefloatSalary , float* floatSalary , int* counterTotalInt );

#endif

/*
int menuAbm();
void initEmployees(eEmployee* list, int len);
int findEmptySlot(eEmpleado* list, int len);
int getIdEmployee(eEmpleado* list, int len);
int findEmployeeById(eEmpleado* list, int len,int id);
int removeEmployee(eEmpleado* list, int len, int id);
void sortEmployees(eEmpleado list[], int len);
void printEmployee(eEmpleado list);
void printEmployees(eEmpleado list[], int len);
int menuModificar();
void modifyEmployee(eEmpleado* list, int len);
void hardCodearEmpleados(eEmpleado vec[], int tam);
int infoSueldos(eEmpleado* list, int len,float* pFloatProm,float* pFloatTotal, int* pIntCant);
int validateFlag(int* flag, char* msgError);
int listEmpty(eEmpleado* list, int len);

*/
