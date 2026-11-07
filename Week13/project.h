#ifndef PROJECT_H
#define PROJECT_H

#include "records.h"

#define MAX_PROJECTS 100

typedef struct {
    int    id;
    char   title[50];
    double budget;
    Date   startDate;
    Date   endDate;
} Project;

int  addProject(Project list[], int count);
void listProjects(const Project list[], int count);

#endif