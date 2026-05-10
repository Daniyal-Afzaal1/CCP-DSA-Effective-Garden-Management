#include "WorkshopModule.h" // 


// Constructor Logic
Workshop::Workshop() {
    confirmedCount = 0;
    waitingCount = 0;
    confirmedHead = nullptr;
    confirmedTail = nullptr;
    waitingHead = nullptr;
    waitingTail = nullptr;
}


// Logic: Check Duplicate Registration
bool isAlreadyRegistered(Workshop& ws, string name) {
    Node* temp = ws.confirmedHead;
    while (temp != nullptr) {
        if (temp->name == name) return true;
        temp = temp->next;
    }
    temp = ws.waitingHead;
    while (temp != nullptr) {
        if (temp->name == name) return true;
        temp = temp->next;
    }
    return false;
}

// Logic: Add Resident to List
void addToList(Node*& head, Node*& tail, int& count, string name) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

// Logic: Remove Resident from List
bool removeFromList(Node*& head, Node*& tail, int& count, string name) {
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->name != name) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) return false;
    if (previous == nullptr) {
        head = head->next;
        if (head == nullptr) tail = nullptr;
    } else {
        previous->next = current->next;
        if (current == tail) tail = previous;
    }
    delete current;
    count--;
    return true;
}

// Logic: Register Resident
void registerResident(Workshop& ws, string name) {
    if (!isValidName(name)) {
        cout << "\n[ERROR] Invalid name.\n";
        return;
    }
    if (isAlreadyRegistered(ws, name)) {
        cout << "\n[ERROR] Resident is already registered.\n";
        return;
    }
    if (ws.confirmedCount < ws.maxSeats) {
        addToList(ws.confirmedHead, ws.confirmedTail, ws.confirmedCount, name);
        cout << "\n[SUCCESS] Registered successfully.\n";
    } else {
        addToList(ws.waitingHead, ws.waitingTail, ws.waitingCount, name);
        cout << "\n[WAITLIST] Added to waiting list.\n";
    }
}

// Logic: Cancel Registration
void cancelRegistration(Workshop& ws, string name) {
    if (removeFromList(ws.confirmedHead, ws.confirmedTail, ws.confirmedCount, name)) {
        cout << "\n[CANCELLED] Registration removed.\n";
        if (ws.waitingHead != nullptr) {
            string nextResident = ws.waitingHead->name;
            removeFromList(ws.waitingHead, ws.waitingTail, ws.waitingCount, nextResident);
            addToList(ws.confirmedHead, ws.confirmedTail, ws.confirmedCount, nextResident);
            cout << "[PROMOTED] " << nextResident << " moved to confirmed list.\n";
        }
    } else if (removeFromList(ws.waitingHead, ws.waitingTail, ws.waitingCount, name)) {
        cout << "\n[REMOVED] Removed from waiting list.\n";
    } else {
        cout << "\n[ERROR] No matching record found.\n";
    }
}

// Logic: Display Workshop Status
void displayStatus(Workshop& ws) {
    cout << "\nWorkshop : " << ws.title << endl;
    cout << "Confirmed Seats : " << ws.confirmedCount << " / " << ws.maxSeats << endl;
    cout << "Waiting List : " << ws.waitingCount << endl;
    cout << "\nConfirmed Residents:\n";
    Node* temp = ws.confirmedHead;
    if (!temp) cout << "None\n";
    while (temp) {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
}

// Logic: Clear Memory
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

void workshopMenu() {

    const int totalWorkshops = 3;
    Workshop workshops[totalWorkshops];

    // Workshop Initialization
    workshops[0].title = "Organic Gardening";
    workshops[0].maxSeats = 5;

    workshops[1].title = "Urban Composting";
    workshops[1].maxSeats = 3;

    workshops[2].title = "Pest Control 101";
    workshops[2].maxSeats = 2;

    int workshopChoice;
    int actionChoice;
    string residentName;

    while (true) {

        cout << "\n=========== COMMUNITY GARDEN ===========\n";
        cout << "        WORKSHOP SCHEDULING SYSTEM\n";
        cout << "========================================\n";

        // Display Workshops
        for (int i = 0; i < totalWorkshops; i++) {

            int remainingSeats =
                workshops[i].maxSeats -
                workshops[i].confirmedCount;

            cout << i + 1 << ". "
                 << workshops[i].title;

            if (remainingSeats == 0) {
                cout << " [FULL]";
            }
            else if (remainingSeats == 1) {
                cout << " [!!! LIMITED SEATS !!!]";
            }

            cout << endl;
        }

        cout << "4. Exit System\n";
        cout << "\nSelect Workshop (1-4): ";

        // Validation
        if (!(cin >> workshopChoice)) {

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\n[ERROR] Invalid input.\n";

            continue;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        // Exit
        if (workshopChoice == 4) {
            break;
        }

        // Invalid Range
        if (
            workshopChoice < 1 ||
            workshopChoice > totalWorkshops
        ) {

            cout << "\n[ERROR] Invalid workshop selection.\n";

            continue;
        }

        Workshop& currentWorkshop =
            workshops[workshopChoice - 1];

        // Workshop Menu
        while (true) {

            cout << "\n========================================\n";

            cout << "Workshop : "
                 << currentWorkshop.title
                 << endl;

            cout << "========================================\n";

            cout << "1. Register Resident\n";
            cout << "2. Cancel Registration\n";
            cout << "3. View Workshop Status\n";
            cout << "4. Return to Main Menu\n";

            cout << "\nEnter Choice: ";

            // Validation
            if (!(cin >> actionChoice)) {

                cin.clear();

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                cout << "\n[ERROR] Invalid input.\n";

                continue;
            }

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            // Register
            if (actionChoice == 1) {

                cout << "\nEnter Resident Name: ";

                getline(cin, residentName);

                registerResident(
                    currentWorkshop,
                    residentName
                );
            }

            // Cancel
            else if (actionChoice == 2) {

                cout << "\nEnter Resident Name to Cancel: ";

                getline(cin, residentName);

                cancelRegistration(
                    currentWorkshop,
                    residentName
                );
            }

            // Status
            else if (actionChoice == 3) {

                displayStatus(currentWorkshop);
            }

            // Back
            else if (actionChoice == 4) {

                break;
            }

            else {

                cout << "\n[ERROR] Invalid menu choice.\n";
            }
        }
    }

    // Cleanup
    for (int i = 0; i < totalWorkshops; i++) {

        clearList(workshops[i].confirmedHead);

        clearList(workshops[i].waitingHead);
    }

    cout << "\nWorkshop System Closed Successfully.\n";
}