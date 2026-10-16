#include <stdio.h>
#include "employees.h"

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