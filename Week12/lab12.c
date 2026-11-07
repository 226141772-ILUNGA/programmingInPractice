#include <stdio.h>

#define MAX_STAFF 5

typedef struct {
    int    id;
    char   name[50];
    double salary;
} Employee;


/* ---------- Part A ---------- */
void pointerBasics(void)
{
    int  age = 25;
    int *ptr = &age;

    printf("PART A - a pointer holds an address\n");
    printf("  age          = %d\n",  age);
    printf("  &age         = %p\n",  (void *)&age);
    printf("  ptr          = %p\n",  (void *)ptr);
    printf("  *ptr         = %d\n",  *ptr);

    *ptr = 30;
    printf("  after *ptr = 30, age = %d\n\n", age);
}


/* ---------- Part B ---------- */
void swapWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}


/* ---------- Part C ---------- */
void displaySalaries(const double pay[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("    [%d] %.2f\n", i, pay[i]);
    }
}

double findHighest(const double pay[], int n)
{
    double top = pay[0];
    int i;
    for (i = 1; i < n; i++) {
        if (pay[i] > top) {
            top = pay[i];
        }
    }
    return top;
}

double calculateAverage(const double pay[], int n)
{
    double sum = 0;
    int i;
    if (n == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        sum += pay[i];
    }
    return sum / n;
}

void giveRaise(double pay[], int n, double percent)
{
    int i;
    for (i = 0; i < n; i++) {
        pay[i] += pay[i] * percent / 100.0;
    }
}


/* ---------- Part D ---------- */
void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id)
{
    int i;
    for (i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }
    return NULL;
}


int main(void)
{
    double pay[3] = { 12000.00, 19500.50, 23750.25 };
    double x = 12000.00, y = 23750.25;

    Employee staff[MAX_STAFF] = {
        {201, "Kavita",  19500.50},
        {202, "Thomas",  16800.00},
        {203, "Nangula", 23750.25}
    };
    int n = 3;
    Employee *hit;

    pointerBasics();

    printf("PART B - swapping\n");
    printf("  start        : x = %.2f  y = %.2f\n", x, y);
    swapWrong(x, y);
    printf("  swapWrong    : x = %.2f  y = %.2f   <- unchanged\n", x, y);
    swapSalaries(&x, &y);
    printf("  swapSalaries : x = %.2f  y = %.2f   <- swapped\n\n", x, y);

    printf("PART C - arrays in functions\n");
    printf("  original array:\n");
    displaySalaries(pay, 3);
    printf("  highest = %.2f\n", findHighest(pay, 3));
    printf("  average = %.2f\n", calculateAverage(pay, 3));
    giveRaise(pay, 3, 10.0);
    printf("  after a 10%% raise the ORIGINAL array changed:\n");
    displaySalaries(pay, 3);
    printf("\n");

    printf("PART D - pointer to a structure\n");

    hit = findEmployee(staff, n, 202);
    if (hit != NULL) {
        printf("  %s earns %.2f\n", hit->name, hit->salary);
        updateSalary(hit, 18200.00);
        printf("  %s now earns %.2f\n", hit->name, hit->salary);
    }

    hit = findEmployee(staff, n, 777);
    if (hit == NULL) {
        printf("  ID 777 not found - findEmployee returned NULL\n");
    }

    return 0;
}