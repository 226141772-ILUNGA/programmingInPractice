#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
    int id;
    char name[50];
    double amountOwed;
} Supplier;

int addSupplier(Supplier list[], int count);
void listSuppliers(const Supplier list[], int count);
int saveSuppliersText(const Supplier list[], int count);
int loadSuppliersText(Supplier list[], int max);

#endif