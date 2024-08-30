
#include <iostream>
#include <cstring>

using namespace std;


class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    
    Train() : trainNumber(0) {
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

        Train(int number, const char* name, const char* src, const char* dest, const char* time) 
        : trainNumber(number) {
        strncpy(trainName, name, sizeof(trainName) - 1);
        strncpy(source, src, sizeof(source) - 1);
        strncpy(destination, dest, sizeof(destination) - 1);
        strncpy(trainTime, time, sizeof(trainTime) - 1);
        trainName[sizeof(trainName) - 1] = '\0';
        source[sizeof(source) - 1] = '\0';
        destination[sizeof(destination) - 1] = '\0';
        trainTime[sizeof(trainTime) - 1] = '\0';
        trainCount++;
    }

    
    ~Train() {
        trainCount--;
    }

    
    int getTrainNumber() const { return trainNumber; }
    void setTrainNumber(int number) { trainNumber = number; }

    const char* getTrainName() const { return trainName; }
    void setTrainName(const char* name) { strncpy(trainName, name, sizeof(trainName) - 1); }

    const char* getSource() const { return source; }
    void setSource(const char* src) { strncpy(source, src, sizeof(source) - 1); }

    const char* getDestination() const { return destination; }
    void setDestination(const char* dest) { strncpy(destination, dest, sizeof(destination) - 1); }

    const char* getTrainTime() const { return trainTime; }
    void setTrainTime(const char* time) { strncpy(trainTime, time, sizeof(trainTime) - 1); }

    static int getTrainCount() { return trainCount; }

    
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // To ignore newline character from the input buffer
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }
};


int Train::trainCount = 0;


class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() : totalTrains(0) {
        
        trains[0] = Train(101, "Okha Express", "Surat", "Mumbai", "10 AM");
        trains[1] = Train(102, "Gujarat Mail", "Ahmedabad", "Delhi", "12 PM");
        trains[2] = Train(103, "Superfast Express", "Vadodara", "Bhopal", "2 PM");
        totalTrains = 3;
    }

    void addTrain() {
        if (totalTrains < 100) {
            Train newTrain;
            newTrain.inputTrainDetails();
            trains[totalTrains++] = newTrain;
        } else {
            cout << "Cannot add more trains. Registry is full." << endl;
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No trains available." << endl;
            return;
        }
        for (int i = 0; i < totalTrains; ++i) {
            cout << "Train " << (i + 1) << " details:" << endl;
            trains[i].displayTrainDetails();
            cout << "------------------------" << endl;
        }
    }

    void searchTrainByNumber(int number) const {
        for (int i = 0; i < totalTrains; ++i) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train with number " << number << " not found!" << endl;
    }
};

int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3: {
                int number;
                cout << "Enter Train Number to search: ";
                cin >> number;
                system.searchTrainByNumber(number);
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
