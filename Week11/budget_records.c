#include <stdio.h>
#include "budget_records.h"
#include "utilities.h"

int addBudgetRecord(BudgetRecord list[], int count)
{
    if (count >= MAX_BUDGETS) {
        printf("Budget list is full.\n");
        return count;
    }

    list[count].id = readInt("Budget ID: ");
    printf("Department (no spaces): ");
    scanf("%49s", list[count].department);
    list[count].amount = readFloat("Amount: ");

    return count + 1;
}

void listBudgetRecords(const BudgetRecord list[], int count)
{
    if (count == 0) {
        printf("No budgets.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Department: %s | Amount: %.2f\n",
               list[i].id, list[i].department, list[i].amount);
    }
}

int saveBudgetRecordsText(const BudgetRecord list[], int count)
{
    FILE *fp = fopen("data/budgets.txt", "w");
    if (fp == NULL) {
        perror("data/budgets.txt");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                list[i].id, list[i].department, list[i].amount);
    }

    fclose(fp);
    return count;
}

int loadBudgetRecordsText(BudgetRecord list[], int max)
{
    FILE *fp = fopen("data/budgets.txt", "r");
    int count = 0;

    if (fp == NULL) {
        perror("data/budgets.txt");
        return 0;
    }

    while (count < max &&
           fscanf(fp, "%d|%49[^|]|%lf\n",
                  &list[count].id, list[count].department,
                  &list[count].amount) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}
