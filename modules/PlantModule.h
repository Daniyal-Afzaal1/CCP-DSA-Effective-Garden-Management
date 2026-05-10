#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm> // for remove function
#include "../utils/helper.h"



struct Plant {
    string name;
    int growth;
    string sunlight;
    int water;
};

// Functions
void plantMenu();
void addPlant();
void displayPlants();
void searchPlant();