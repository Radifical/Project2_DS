/**
 * @file main.cpp
 * @brief Main program file for the word transformation project
 * This file contains the main program that runs tests and allows user interaction
 * for word transformations. It first runs all tests to ensure the program is working
 * correctly, then allows users to input their own words for transformation.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "WordGraph.h"
#include "tests.h"

using namespace std;

void runWordTransformation() {
    cout << "\nStarting word transformation program..." << endl;
    cout << "=============================================" << endl;

    string startWord, targetWord;
    cout << "Enter starting word: ";
    cin >> startWord;
    cout << "Enter target word: ";
    cin >> targetWord;

    // Convert input words to uppercase
    transform(startWord.begin(), startWord.end(), startWord.begin(), ::toupper);
    transform(targetWord.begin(), targetWord.end(), targetWord.begin(), ::toupper);

    if (startWord.length() != targetWord.length()) {
        cout << "Error: Words must be the same length." << endl;
        return;
    }

    WordGraph wordGraph;
    if (!wordGraph.initialize("dictionary345.txt", startWord.length())) {
        cout << "Error: Could not initialize word graph." << endl;
        return;
    }

    cout << "\nFinding any path:" << endl;
    vector<string> anyPath = wordGraph.findAnyPath(startWord, targetWord);
    WordGraph::printPathWithChanges(anyPath);

    cout << "\nFinding optimal path:" << endl;
    vector<string> optimalPath = wordGraph.findOptimalPath(startWord, targetWord);
    WordGraph::printPathWithChanges(optimalPath);
}

int main() {
    char choice;
    cout << "Welcome to Word Transformation Program!" << endl;
    cout << "======================================" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Run word transformation program" << endl;
    cout << "2. Run test cases" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case '1':
            runWordTransformation();
            break;
        case '2':
            if (!runAllTests()) {
                cout << "\nTests failed. Please check the issues above." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please run the program again and select 1 or 2." << endl;
            break;
    }

    return 0;
}
