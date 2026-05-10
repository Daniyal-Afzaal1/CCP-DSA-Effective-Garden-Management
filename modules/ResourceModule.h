#pragma once

#include "../utils/helper.h"
#include <string>
#include <limits>
#include <vector>

struct Supply
{
    std::string name;
    int cost;
    int benefit;
};

void TakeAllInput();
void FindSelectedSupplies();
void FillDpTable();
void resourceMenu();