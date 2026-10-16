#include <stdio.h>
#include "budget.h"

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}