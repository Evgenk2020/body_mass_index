#ifndef INT_H
#define INT_H

#define MAX_AGE_INDEX 6
#define MAX_GEND_INDEX 38
#define MAX_HUM_GENDER 2
#define MAX_RESULT 7

#define CYAN std::cout << "\033[96;1m"
#define RESET std::cout << "\033[0m"

#include <iostream>
#include <memory>
#include "enums.h"

extern const float MaleBase[MAX_GEND_INDEX][MAX_AGE_INDEX];//base of indexes
extern const float FemaleBase[MAX_GEND_INDEX][MAX_AGE_INDEX];
extern const std::string Human_Ages_Name[MAX_GEND_INDEX];
extern const std::string Human_Gender_Name[MAX_HUM_GENDER];
extern const std::string Human_Results_Name[MAX_RESULT];

#endif // INT_H
