#include "helper.h"



void printBenefitScoreRules() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════╗\n";
    std::cout << "║         BENEFIT SCORE RULES  (0 – 100)          ║\n";
    std::cout << "╠══════════════════════════════════════════════════╣\n";
    std::cout << "║  Score Range  │  Importance   │  Description     ║\n";
    std::cout << "║  ───────────  │  ───────────  │  ─────────────── ║\n";
    std::cout << "║   75 – 100   │  ★★★ HIGH     │  Near 100        ║\n";
    std::cout << "║               │               │  Most critical   ║\n";
    std::cout << "║               │               │  for the garden  ║\n";
    std::cout << "║  ───────────  │  ───────────  │  ─────────────── ║\n";
    std::cout << "║   40 –  74   │  ★★  MEDIUM   │  Near 50         ║\n";
    std::cout << "║               │               │  Moderately      ║\n";
    std::cout << "║               │               │  beneficial      ║\n";
    std::cout << "║  ───────────  │  ───────────  │  ─────────────── ║\n";
    std::cout << "║    0 –  39   │  ★   LOW      │  Near 0          ║\n";
    std::cout << "║               │               │                 ║\n";
    std::cout << "║               │               │  least priority  ║\n";
    std::cout << "╚══════════════════════════════════════════════════╝\n";
    std::cout << "\n";
}

bool isValidBenefitScore(int score) {
    return (score >= 0 && score <= 100);
}

void AskBudget(){
    std::cout<<"\nWhat is your budget: ";
}

void AskItems(){//
    std::cout<<"\nHow many items you want to add for the check: ";
}

void AskItemsName(){//
    std::cout<<"\nEnter the item Name: ";
}

void AskItemsCost(){//
    std::cout<<"\nEnter the item Cost: ";
}

void AskItemImpScore(){//
    std::cout<<"\nEnter the Benefit Score (1-100): ";
}

bool isValidName(string name) {
    if (name.empty()) return false;
    bool hasAlphabet = false;
    for (char c : name) {
        if (isalpha(static_cast<unsigned char>(c))) hasAlphabet = true;
        else if (c != ' ') return false;
    }
    return hasAlphabet;
}

bool isValidPhone(string phone) {
    if (phone.empty()) return false;

    for (char c : phone) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    return true;
}

bool isPositive(int x)
{
    return x > 0;
}

