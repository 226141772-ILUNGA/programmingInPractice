#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "project.h"
#include "budget_records.h"
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

    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;

    Asset assets[MAX_ASSETS];
    int assetCount = 0;

    BudgetRecord budgets[MAX_BUDGETS];
    int budgetCount = 0;

    Project projects[MAX_PROJECTS];
    int projectCount = 0;

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
                employeeCount = addEmployee(employees, employeeCount);
                break;

            case 6:
                listEmployees(employees, employeeCount);
                break;

            case 7:
                supplierCount = addSupplier(suppliers, supplierCount);
                break;

            case 8:
                listSuppliers(suppliers, supplierCount);
                break;

            case 9:
                assetCount = addAsset(assets, assetCount);
                break;

            case 10:
                listAssets(assets, assetCount);
                break;

            case 11:
                budgetCount = addBudgetRecord(budgets, budgetCount);
                break;

            case 12:
                listBudgetRecords(budgets, budgetCount);
                break;

            case 13: {
                int e = saveEmployeesText(employees, employeeCount);
                int s = saveSuppliersText(suppliers, supplierCount);
                int a = saveAssetsText(assets, assetCount);
                int b = saveBudgetRecordsText(budgets, budgetCount);
                if (e >= 0) printf("%d employee(s) saved.\n", e);
                if (s >= 0) printf("%d supplier(s) saved.\n", s);
                if (a >= 0) printf("%d asset(s) saved.\n", a);
                if (b >= 0) printf("%d budget(s) saved.\n", b);
                break;
            }

            case 14:
                employeeCount = loadEmployeesText(employees, MAX_EMPLOYEES);
                printf("%d employee(s) loaded.\n", employeeCount);
                supplierCount = loadSuppliersText(suppliers, MAX_SUPPLIERS);
                printf("%d supplier(s) loaded.\n", supplierCount);
                assetCount = loadAssetsText(assets, MAX_ASSETS);
                printf("%d asset(s) loaded.\n", assetCount);
                budgetCount = loadBudgetRecordsText(budgets, MAX_BUDGETS);
                printf("%d budget(s) loaded.\n", budgetCount);
                break;

            case 15: {
                int n = saveEmployeesBinary(employees, employeeCount);
                if (n >= 0) {
                    printf("%d employee(s) saved (binary).\n", n);
                }
                break;
            }

            case 16:
                employeeCount = loadEmployeesBinary(employees, MAX_EMPLOYEES);
                printf("%d employee(s) loaded (binary).\n", employeeCount);
                break;

            case 17:
                projectCount = addProject(projects, projectCount);
                break;

            case 18:
                listProjects(projects, projectCount);
                break;

            case 0:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

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
    printf("1.  Calculate VAT\n");
    printf("2.  Calculate Salary\n");
    printf("3.  Calculate Budget\n");
    printf("4.  Search Employee\n");
    printf("5.  Add Employee\n");
    printf("6.  List Employees\n");
    printf("7.  Add Supplier\n");
    printf("8.  List Suppliers\n");
    printf("9.  Add Asset\n");
    printf("10. List Assets\n");
    printf("11. Add Budget Record\n");
    printf("12. List Budget Records\n");
    printf("13. Save Data\n");
    printf("14. Load Data\n");
    printf("15. Save Employees (binary)\n");
    printf("16. Load Employees (binary)\n");
    printf("17. Add Project\n");
    printf("18. List Projects\n");
    printf("0.  Exit\n");
    printf("Enter choice: ");
}