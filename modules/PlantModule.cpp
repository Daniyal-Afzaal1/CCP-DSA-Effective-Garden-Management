#include "PlantModule.h"

// Ragged Array and Hashmap
vector<Plant *> raggedArray[3];
unordered_map<string, Plant *> plantMap;

int getCategoryIndex(int growth)
{
    if (growth >= 80)
        return 0;
    if (growth >= 50)
        return 1;
    return 2;
}

void addPlant()
{
    Plant *newPlant = new Plant;

    cout << "\nEnter Plant Name: ";
    cin >> newPlant->name;

    // Duplicate check
    if (plantMap.count(newPlant->name))
    {
        cout << "\n[ERROR] Plant already exists!\n";
        delete newPlant;
        return;
    }

    int g;
    do
    {
        cout << "Enter Growth (0-100): ";
        cin >> g;

        if (g < 0 || g > 100)
        {
            cout << "Invalid! Please enter between 0-100.\n";
        }

    } while (g < 0 || g > 100);

    newPlant->growth = g;

    cout << "Enter Sunlight: ";
    cin >> newPlant->sunlight;

    cout << "Enter Water: ";
    cin >> newPlant->water;

    int row = getCategoryIndex(newPlant->growth);

    raggedArray[row].push_back(newPlant);

    plantMap[newPlant->name] = newPlant;

    cout << "\nPlant Added Successfully!\n";
}

void updatePlantHealth()
{

    string pName;

    cout << "\nEnter Plant Name to Update: ";
    cin >> pName;

    if (plantMap.count(pName))
    {

        Plant *p = plantMap[pName];

        int oldRow = getCategoryIndex(p->growth);

        cout << "Current Growth: " << p->growth << "%\n";

        int newGrowth;

        do
        {
            cout << "Enter New Growth (0-100): ";
            cin >> newGrowth;

            if (newGrowth < 0 || newGrowth > 100)
            {
                cout << "Invalid! Please enter between 0-100.\n";
            }

        } while (newGrowth < 0 || newGrowth > 100);

        int newRow = getCategoryIndex(newGrowth);

        // Shift category if needed
        if (oldRow != newRow)
        {

            auto &rowVec = raggedArray[oldRow];

            rowVec.erase(
                remove(rowVec.begin(), rowVec.end(), p),
                rowVec.end());

            raggedArray[newRow].push_back(p);

            cout << "Plant moved to new health category!\n";
        }

        p->growth = newGrowth;

        cout << "Growth Updated Successfully!\n";
    }
    else
    {

        cout << "Plant not found!\n";
    }
}


void searchPlant()
{
    if (plantMap.empty())
    {
        cout << "\n[!] No plants in the record.\n";
        return;
    }
    string sName;
    cout << "\nEnter Plant Name to Search: ";
    cin >> sName;

    if (plantMap.count(sName))
    {
        Plant *p = plantMap[sName];
        cout << "\n[Found] Name: " << p->name << " | Growth: " << p->growth << "% | Water: " << p->water << "L\n";
    }
    else
    {
        cout << "\nPlant Not Found!\n";
    }
}

void cleanupMemory()
{
    for (int i = 0; i < 3; i++)
    {
        for (Plant *p : raggedArray[i])
        {
            delete p;
        }
        raggedArray[i].clear();
    }
    plantMap.clear();
    cout << "\nMemory cleaned up successfully. No leaks!\n";
}

void displayPlants()
{
    string titles[] = {"GOOD", "AVERAGE", "POOR"};
    bool gardenEmpty = true;

    for (int i = 0; i < 3; i++)
    {
        if (!raggedArray[i].empty())
        {
            gardenEmpty = false;
            break;
        }
    }

    if (gardenEmpty)
    {
        cout << "\n[!] Garden is currently empty.\n";
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "\n--- " << titles[i] << " HEALTH ---";
        if (raggedArray[i].empty())
        {
            cout << "\n(No plants in this category)";
        }
        else
        {
            for (Plant *p : raggedArray[i])
            {
                cout << "\nName: " << p->name << " | Growth: " << p->growth << "%";
            }
        }
        cout << endl;
    }
}

void plantMenu()
{
    int choice;
    do
    {
        cout << "\n===== Garden Management System =====\n";
        cout << "1. Add Plant\n2. Display Plants\n3. Update Health (Track Status)\n4. Search\n0. Exit\n";
        cout << "Enter Choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid Input! Please enter a number.\n";
            cin.clear();
            cin.ignore(123, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            addPlant();
            break;
        case 2:
            displayPlants();
            break;
        case 3:
            updatePlantHealth();
            break;
        case 4:
            searchPlant();
            break;
        case 0:
            cleanupMemory();
            break;
        default:
            cout << "Wrong Choice!\n";
        }
    } while (choice != 0);
}