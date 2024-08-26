# Corner Grocer
Corner Grocer Inventory Tracker

# Scenario
The Corner Grocer needs a program that analyzes the text records they generate throughout the day. These records list items purchased in chronological order from the time the store opens to the time it closes. They are interested in rearranging their produce section and need to know how often items are purchased so they can create the most effective layout for their customers.

## Documentation

## Overview
The CornerGrocer Grocery Tracker is a C++ program designed to read data from an input file, process it to determine the frequency of each item, and provide various functionalities through user selections from a menu. The user can either get the individual frequency of an item, the overall frequency, or a histogram of the overall frequency. 
## Design and Functionality

### main.cpp
The main program initializes the Groceries class, loads data from a file, and handles user interaction through a menu until the user chooses to exit.

Key functions:
  
  ● Load data from file: Reads item names from a text file.
 
  ●	Save data to file: Writes item frequencies to an output file.
 
  ●	Display menu: Presents options to the user.
 
  ●	Handle user choice: Executes the selected option.

### grocer.h
The header file defines the Groceries class, containing functions and data members used to manage the grocery data.

Key components:

●	Public functions: Constructor, data loading/saving, frequency retrieval, frequency printing, histogram printing, menu display, and user choice handling.

●	Private members: Vectors to store item names and frequencies.

### grocer.cpp
The implementation file provides definitions of the functions declared in the header file.

Key functions:

●	loadDataFromFile: Reads item names from the input file and updates item frequencies.

●	addItem: Adds or increments an item's frequency in the vectors.

●	saveDataToFile: Writes item names and frequencies to an output file.

●	getItemFrequency: Retrieves the frequency of a specific item.

●	printItemFrequency: Prints all item names and frequencies.

●	printHistogram: Displays a histogram of item frequencies.

●	displayMenu: Shows menu options.

●	handleUserChoice: Executes actions based on the user's menu choice.
