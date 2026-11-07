#include <stdio.h>
#include "project.h"
#include "utilities.h"

int addProject(Project list[], int count)
{
    if (count >= MAX_PROJECTS) {
        printf("Project list is full.\n");
        return count;
    }

    list[count].id = readInt("Project ID: ");
    printf("Title (no spaces): ");
    scanf("%49s", list[count].title);
    list[count].budget = readFloat("Budget: ");

    list[count].startDate.day   = readInt("Start day (1-31): ");
    list[count].startDate.month = readInt("Start month (1-12): ");
    list[count].startDate.year  = readInt("Start year: ");

    list[count].endDate.day   = readInt("End day (1-31): ");
    list[count].endDate.month = readInt("End month (1-12): ");
    list[count].endDate.year  = readInt("End year: ");

    return count + 1;
}

void listProjects(const Project list[], int count)
{
    if (count == 0) {
        printf("No projects.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Budget: %.2f | Start: %02d/%02d/%d | End: %02d/%02d/%d\n",
               list[i].id,
               list[i].title,
               list[i].budget,
               list[i].startDate.day,
               list[i].startDate.month,
               list[i].startDate.year,
               list[i].endDate.day,
               list[i].endDate.month,
               list[i].endDate.year);
    }
}