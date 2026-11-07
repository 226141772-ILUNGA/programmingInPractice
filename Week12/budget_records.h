#ifndef BUDGET_RECORDS_H
#define BUDGET_RECORDS_H

#define MAX_BUDGETS 100

typedef struct {
    int id;
    char department[50];
    double amount;
} BudgetRecord;

int addBudgetRecord(BudgetRecord list[], int count);
void listBudgetRecords(const BudgetRecord list[], int count);
int saveBudgetRecordsText(const BudgetRecord list[], int count);
int loadBudgetRecordsText(BudgetRecord list[], int max);

#endif