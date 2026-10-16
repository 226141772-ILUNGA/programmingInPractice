#include <stdio.h>
#include "assets.h"
#include "utilities.h"

int addAsset(Asset list[], int count)
{
    if (count >= MAX_ASSETS) {
        printf("Asset list is full.\n");
        return count;
    }

    list[count].id = readInt("Asset ID: ");
    printf("Name (no spaces): ");
    scanf("%49s", list[count].name);
    list[count].value = readFloat("Value: ");

    return count + 1;
}

void listAssets(const Asset list[], int count)
{
    if (count == 0) {
        printf("No assets.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Value: %.2f\n",
               list[i].id, list[i].name, list[i].value);
    }
}

int saveAssetsText(const Asset list[], int count)
{
    FILE *fp = fopen("data/assets.txt", "w");
    if (fp == NULL) {
        perror("data/assets.txt");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                list[i].id, list[i].name, list[i].value);
    }

    fclose(fp);
    return count;
}

int loadAssetsText(Asset list[], int max)
{
    FILE *fp = fopen("data/assets.txt", "r");
    int count = 0;

    if (fp == NULL) {
        perror("data/assets.txt");
        return 0;
    }

    while (count < max &&
           fscanf(fp, "%d|%49[^|]|%lf\n",
                  &list[count].id, list[count].name,
                  &list[count].value) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}