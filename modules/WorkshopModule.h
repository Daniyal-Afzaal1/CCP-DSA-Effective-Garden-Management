#pragma once
#include "../utils/helper.h"
#include <string>
#include <limits>

// Node Structure
struct Node {
    string name;
    Node* next;
};

// Workshop Structure
struct Workshop {
    string title;
    int maxSeats;
    int confirmedCount;
    int waitingCount;
    Node* confirmedHead;
    Node* confirmedTail;
    Node* waitingHead;
    Node* waitingTail;

    Workshop(); // Constructor declaration
};

// Functions Declarations
bool isValidName(string name);
bool isAlreadyRegistered(Workshop& ws, string name);
void addToList(Node*& head, Node*& tail, int& count, string name);
bool removeFromList(Node*& head, Node*& tail, int& count, string name);
void registerResident(Workshop& ws, string name);
void cancelRegistration(Workshop& ws, string name);
void displayStatus(Workshop& ws);
void clearList(Node*& head);
void workshopMenu();

