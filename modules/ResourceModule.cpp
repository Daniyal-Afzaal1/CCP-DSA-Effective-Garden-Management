#include "ResourceModule.h"


long budget;
int totalSupplies;
vector<vector<long>> dp;
vector<Supply> supplies;

void TakeAllInput()
{
    // Budget Input
    while (true)
    {
        AskBudget();

        if (!(cin >> budget))
        {
            cout << "\n[ERROR] Enter numbers only!\n";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        if (budget <= 0)
        {
            cout << "\n[ERROR] Budget must be greater than 0!\n";
            continue;
        }

        break;
    }

    // Total Supplies Input
    while (true)
    {
        AskItems();

        if (!(cin >> totalSupplies))
        {
            cout << "\n[ERROR] Enter numbers only!\n";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        if (totalSupplies <= 0)
        {
            cout << "\n[ERROR] Supplies must be greater than 0!\n";
            continue;
        }

        break;
    }

    cin.ignore();

    // DP Table Setup
    dp.resize(
        totalSupplies + 1,
        vector<long>(budget + 1, 0)
    );

    supplies.resize(totalSupplies);

    cout << "\nNow Enter Supplies Details:\n";

    printBenefitScoreRules();

    // Supply Details Input
    for (int i = 0; i < totalSupplies; i++)
    {
        cout << "\n=====================================\n";
        cout << "Supply #" << i + 1 << endl;
        cout << "=====================================\n";

        // Name Input
        while (true)
        {
            AskItemsName();

            getline(cin, supplies[i].name);

            if (supplies[i].name.empty())
            {
                cout << "\n[ERROR] Name cannot be empty!\n";
            }
            else
            {
                break;
            }
        }

        // Cost Input
        while (true)
        {
            AskItemsCost();

            if (!(cin >> supplies[i].cost))
            {
                cout << "\n[ERROR] Enter numbers only!\n";

                cin.clear();

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                continue;
            }

            if (supplies[i].cost <= 0)
            {
                cout << "\n[ERROR] Cost must be greater than 0!\n";
                continue;
            }

            break;
        }

        // Benefit Input
        while (true)
        {
            AskItemImpScore();

            if (!(cin >> supplies[i].benefit))
            {
                cout << "\n[ERROR] Enter numbers only!\n";

                cin.clear();

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                continue;
            }

            if (!isValidBenefitScore(supplies[i].benefit))
            {
                cout << "\n[ERROR] Benefit score must be between 1-100!\n";
                continue;
            }

            break;
        }

        cin.ignore();

        cout << "\nSupply Added Successfully!\n";
    }
}


void FillDpTable()
{    
    // Fill dp table
    for (int i = 1; i <= totalSupplies; i++)
    {

        for (int currentBudget = 1;
             currentBudget <= budget;
             currentBudget++)
        {

            // If supply can fit in budget
            if (supplies[i - 1].cost <= currentBudget)
            {

                int takeSupply =
                    supplies[i - 1].benefit +
                    dp[i - 1][currentBudget - supplies[i - 1].cost];

                int skipSupply =
                    dp[i - 1][currentBudget];

                dp[i][currentBudget] =
                    max(takeSupply, skipSupply);
            }

            // If supply cannot fit
            else
            {

                dp[i][currentBudget] =
                    dp[i - 1][currentBudget];
            }
        }
    }
}


void FindSelectedSupplies()
{
    cout<<"Selected supplies for the maximum Benefit are: \n";
    // Find Selected Supplies
    int remainingBudget = budget;

    for (int i = totalSupplies; i > 0; i--)
    {
        // Supply was selected
        if (dp[i][remainingBudget] !=
            dp[i - 1][remainingBudget])
        {

            cout << supplies[i - 1].name
                 << " selected "
                 << "(Cost = "
                 << supplies[i - 1].cost
                 << ", Benefit = "
                 << supplies[i - 1].benefit
                 << ")\n";

            // Reduce remaining budget
            remainingBudget =
                remainingBudget - supplies[i - 1].cost;
        }
    }
}


void resourceMenu()
{
    cout << "\n=========================================\n";
    cout << "     EFFECTIVE RESOURCE PROCUREMENT\n";
    cout << "=========================================\n";

    TakeAllInput();

    FillDpTable();

    cout << "\n=========================================\n";
    cout << "Maximum Benefit Achieved: "
         << dp[totalSupplies][budget]
         << endl;

    cout << "=========================================\n";

    FindSelectedSupplies();

    cout << "\nResource Optimization Completed!\n";
}