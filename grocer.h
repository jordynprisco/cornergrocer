#ifndef GROCER_H
#define GROCER_H

#include <vector>
#include <string>

using namespace std;

// Declares Groceries Class
class Groceries {
// Can be accessed by any class
public:
    // Default constructor
    Groceries();

    // Function prototypes
    void loadDataFromFile(const string& filename);
    void saveDataToFile(const string& filename) const;
    int getItemFrequency(const string& item) const;
    void printItemFrequency() const;
    void printHistogram() const;
    void displayMenu() const;
    void handleUserChoice(int choice);
    void addItem(const string& item);

// Can only be accessed by the class
private:
    vector<string> itemNames;
    vector<int> itemFrequencies;
};

#endif
