#include "modules/PlantModule.h"
#include "modules/WorkshopModule.h"
#include "modules/ResourceModule.h"

int main()
{
    int choice;

    do
    {
        cout << "\n=================================================\n";
        cout << "        SOIL TO STRATEGY MANAGEMENT SYSTEM\n";
        cout << "=================================================\n";

        cout << "1. Plant Management and Growth Tracking\n";
        cout << "2. Workshop Scheduling\n";
        cout << "3. Efficient Resource Procurement\n";
        cout << "0. Exit System\n";

        cout << "\nEnter Your Choice: ";

        // Input Validation
        while (!(cin >> choice))
        {
            cout << "\n[ERROR] Invalid Input! Enter numbers only: ";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');
        }

        switch (choice)
        {
        // MODULE 1
        case 1:
        {
            plantMenu();
            break;
        }

        // MODULE 2
        case 2:
        {
            workshopMenu();
            break;
        }

        // MODULE 3
        case 3:
        {
            resourceMenu();
            break;
        }

        // EXIT
        case 0:
        {
            cout << "\nSystem Closed Successfully.\n";
            break;
        }

        // INVALID
        default:
        {
            cout << "\n[ERROR] Invalid Menu Choice!\n";
        }
        }

    } while (choice != 0);

    return 0;
}
