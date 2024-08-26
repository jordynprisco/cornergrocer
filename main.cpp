#include <iostream>
#include "grocer.h"

using namespace std;

int main() {
    Groceries groceries;

    // Load data from file
    groceries.loadDataFromFile("CS210_Project_Three_Input_File.txt");

    // Save data to frequency.txt file
    groceries.saveDataToFile("frequency.txt");

    int choice = 0;

    while (choice != 4) {
        // Display the menu options
        groceries.displayMenu(); 

        // Validate user input
        while (!(cin >> choice)) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "--------------------------------------------------------" << endl;
            cout << "Invalid input. Please enter a number between 1 and 4: ";
        }

        // Handle the user's choice
        groceries.handleUserChoice(choice); 
    }

    return 0;
}
