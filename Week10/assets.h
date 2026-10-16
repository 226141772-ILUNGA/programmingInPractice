#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct {
    int id;
    char name[50];
    double value;
} Asset;

int addAsset(Asset list[], int count);
void listAssets(const Asset list[], int count);
int saveAssetsText(const Asset list[], int count);
int loadAssetsText(Asset list[], int max);

#endif