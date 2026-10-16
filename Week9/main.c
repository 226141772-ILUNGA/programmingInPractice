#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

void displayWelcome(void);
void displayMenu(void);

int main(void)
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = 5;

    displayWelcome();

    do {
        displayMenu();
        choice = readInt("");

        switch (choice) {
            case 1: {
                float amount = readFloat("Enter amount: ");
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            }

            case 2: {
                float basic = readFloat("Basic salary: ");
                float housing = readFloat("Housing allowance: ");
                float transport = readFloat("Transport allowance: ");
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;
            }

            case 3: {
                float revenue = readFloat("Enter revenue: ");
                float expenses = readFloat("Enter expenses: ");
                budgetReport(revenue, expenses);
                break;
            }

            case 4: {
                int searchID = readInt("Enter employee ID: ");
                int position = searchEmployee(searchID, employeeIDs, size);
                employeeSearchReport(searchID, position);
                break;
            }

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu(void)
{
    printf("\n==================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}