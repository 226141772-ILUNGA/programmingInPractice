#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

float calculateSalary(float basic, float housing, float transport);
int searchEmployee(int id, int ids[], int size);

int addEmployee(Employee list[], int count);
void listEmployees(const Employee list[], int count);
int saveEmployeesText(const Employee list[], int count);
int loadEmployeesText(Employee list[], int max);
int saveEmployeesBinary(const Employee list[], int count);
int loadEmployeesBinary(Employee list[], int max);
void      updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int count, int id);

#endif