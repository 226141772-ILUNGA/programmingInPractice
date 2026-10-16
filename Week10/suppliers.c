#include <stdio.h>
#include "suppliers.h"
#include "utilities.h"

int addSupplier(Supplier list[], int count)
{
    if (count >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return count;
    }

    list[count].id = readInt("Supplier ID: ");
    printf("Name (no spaces): ");
    scanf("%49s", list[count].name);
    list[count].amountOwed = readFloat("Amount owed: ");

    return count + 1;
}

void listSuppliers(const Supplier list[], int count)
{
    if (count == 0) {
        printf("No suppliers.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Owed: %.2f\n",
               list[i].id, list[i].name, list[i].amountOwed);
    }
}

int saveSuppliersText(const Supplier list[], int count)
{
    FILE *fp = fopen("data/suppliers.txt", "w");
    if (fp == NULL) {
        perror("data/suppliers.txt");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                list[i].id, list[i].name, list[i].amountOwed);
    }

    fclose(fp);
    return count;
}

int loadSuppliersText(Supplier list[], int max)
{
    FILE *fp = fopen("data/suppliers.txt", "r");
    int count = 0;

    if (fp == NULL) {
        perror("data/suppliers.txt");
        return 0;
    }

    while (count < max &&
           fscanf(fp, "%d|%49[^|]|%lf\n",
                  &list[count].id, list[count].name,
                  &list[count].amountOwed) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}