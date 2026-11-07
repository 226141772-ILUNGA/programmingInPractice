#include <stdio.h>
#include "employees.h"
#include "utilities.h"

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}

int addEmployee(Employee list[], int count)
{
    list[count].id = readInt("Employee ID: ");
    printf("Name (no spaces): ");
    scanf("%49s", list[count].name);
    list[count].salary = readFloat("Salary: ");

    return count + 1;
}

void listEmployees(const Employee list[], int count)
{
    if (count == 0) {
        printf("No employees.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               list[i].id, list[i].name, list[i].salary);
    }
}

int saveEmployeesText(const Employee list[], int count)
{
    FILE *fp = fopen("data/employees.txt", "w");
    if (fp == NULL) {
        perror("data/employees.txt");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                list[i].id, list[i].name, list[i].salary);
    }

    fclose(fp);
    return count;
}

int loadEmployeesText(Employee list[], int max)
{
    FILE *fp = fopen("data/employees.txt", "r");
    int count = 0;

    if (fp == NULL) {
        perror("data/employees.txt");
        return 0;
    }

    while (count < max &&
           fscanf(fp, "%d|%49[^|]|%lf\n",
                  &list[count].id, list[count].name,
                  &list[count].salary) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

int saveEmployeesBinary(const Employee list[], int count)
{
    FILE *fp = fopen("data/employees.dat", "wb");
    if (fp == NULL) {
        perror("data/employees.dat");
        return -1;
    }

    size_t written = fwrite(list, sizeof list[0], (size_t)count, fp);
    if (written != (size_t)count) {
        perror("Error writing employees");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return count;
}

int loadEmployeesBinary(Employee list[], int max)
{
    FILE *fp = fopen("data/employees.dat", "rb");
    if (fp == NULL) {
        perror("data/employees.dat");
        return 0;
    }

    size_t read = fread(list, sizeof list[0], (size_t)max, fp);

    fclose(fp);
    return (int)read;
}
void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int count, int id)
{
    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }
    return NULL;
}