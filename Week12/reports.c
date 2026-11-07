#include <stdio.h>
#include "reports.h"
#include "budget.h"

void budgetReport(float revenue, float expenses)
{
    float result = calculateBudget(revenue, expenses);

    printf("Balance: %.2f\n", result);
    if (result > 0) {
        printf("SURPLUS\n");
    } else if (result < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
}

void employeeSearchReport(int id, int position)
{
    if (position == -1) {
        printf("Employee %d not found.\n", id);
    } else {
        printf("Employee %d found at position %d.\n", id, position);
    }
}