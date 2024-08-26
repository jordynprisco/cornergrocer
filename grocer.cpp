#include "grocer.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Default constructor for Groceries class
Groceries::Groceries() {}

// Opens file and loads item data from a file into the vectors
void Groceries::loadDataFromFile(const string& filename) {
    ifstream inputFile(filename); 
    if (!inputFile.is_open()) { 
        cerr << "Error opening file: " << filename << endl; 
        return;
    }

    string item;

    // Clear previous data
    itemNames.clear();
    itemFrequencies.clear();

    // Reads items from the file
    while (getline(inputFile, item)) {
        if (!item.empty()) {
            addItem(item); // Process each item
        }
    }
    inputFile.close(); // Closes the file
}

// Adds an item to the vectors or increments its frequency if it already exists
void Groceries::addItem(const string& item) {
    // Search for the item in the itemNames vector
    for (int i = 0; i < itemNames.size(); ++i) {
        if (itemNames[i] == item) {
            itemFrequencies[i]++;
            return;
        }
    }
    // If item is not found, add it to the vectors
    itemNames.push_back(item);
    itemFrequencies.push_back(1);
}

// Saves item data from the vectors to a file
void Groceries::saveDataToFile(const string& filename) const {
    ofstream outputFile(filename); 
    if (!outputFile.is_open()) { 
        cerr << "Error opening file: " << filename << endl; 
        return;
    }

    // Writes each item and its frequency to the file
    for (int i = 0; i < itemNames.size(); ++i) {
        outputFile << itemNames[i] << " " << itemFrequencies[i] << endl;
    }
    outputFile.close(); // Closes the file
}

// Retrieves the frequency of a specific item
int Groceries::getItemFrequency(const string& item) const {
    // Search for the item in itemNames vector
    for (int i = 0; i < itemNames.size(); ++i) {
        if (itemNames[i] == item) {
            return itemFrequencies[i];
        }
    }
    return 0; // If item is not found, return 0
}

// Prints the frequency of all items
void Groceries::printItemFrequency() const {
    for (int i = 0; i < itemNames.size(); ++i) {
        cout << itemNames[i] << " " << itemFrequencies[i] << endl;
    }
}

// Prints a histogram of item frequencies with asterisks
void Groceries::printHistogram() const {
    for (int i = 0; i < itemNames.size(); ++i) {
        cout << itemNames[i] << " ";
        for (int j = 0; j < itemFrequencies[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

// Displays the menu options to the user
void Groceries::displayMenu() const {
    cout << "--------------------------------------------------------" << endl;
    cout << "Menu Options:\n";
    cout << "1. Search for an item\n";
    cout << "2. Print the frequency of all items\n";
    cout << "3. Print histogram of item frequencies\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Handles user input based on the menu choice
void Groceries::handleUserChoice(int choice) {
    switch (choice) {
        case 1: {
            string item;
            cout << "--------------------------------------------------------" << endl;
            cout << "Enter the item to search for: "; 
            cin >> item; 
            int frequency = getItemFrequency(item); 
            cout << endl;
            cout << "Frequency of " << item << ": " << frequency << endl; 
            break;
        }
        case 2:
            cout << "--------------------------------------------------------" << endl;
            printItemFrequency(); 
            break;
        case 3:
            cout << "--------------------------------------------------------" << endl;
            printHistogram(); 
            break;
        case 4:
            cout << "--------------------------------------------------------" << endl;
            cout << "Exiting program." << endl; 
            break;
        default:
            cout << "--------------------------------------------------------" << endl;
            cout << "Invalid choice. Please try again." << endl; 
    }
}
