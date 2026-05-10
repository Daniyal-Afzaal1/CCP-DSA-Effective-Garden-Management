#pragma once

#include <iostream>
#include <cctype>
using namespace std;

void printBenefitScoreRules();

// Validates that a benefit score is within [0, 100]
bool isValidBenefitScore(int score);

//prints statement asking user's budget
void AskBudget(); 

void AskItemImpScore();

void AskItemsCost();

void AskItemsName();

void AskItems();

bool isValidName(string name); //workshop
bool isValidPhone(string phone);  //workshop

bool isPositive(int x); //Plant

