#pragma once
#include "../utils/helper.h"
#include <string>
#include <limits>

// Node Structure
struct Node {
    string name;
    string phone; //  For Unique identification 
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
bool isAlreadyRegistered(Workshop& ws, string phone);
void addToList(Node*& head, Node*& tail, int& count, string name , string phone);
bool removeFromList(Node*& head, Node*& tail, int& count, string phone);
void registerResident(Workshop& ws, string name, string phone);
void cancelRegistration(Workshop& ws, string phone);
void displayStatus(Workshop& ws);
void clearList(Node*& head);
void workshopMenu();

