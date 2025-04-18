#include "tests.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool runTest(const string& testName, const string& startWord, const string& targetWord, 
            const string& dictionaryFile, bool expectSuccess) {
    cout << "\n=== Testing: " << testName << " ===" << endl;
    
    // Convert input words to uppercase
    string upperStartWord = startWord;
    string upperTargetWord = targetWord;
    transform(upperStartWord.begin(), upperStartWord.end(), upperStartWord.begin(), ::toupper);
    transform(upperTargetWord.begin(), upperTargetWord.end(), upperTargetWord.begin(), ::toupper);
    
    cout << "Start word: " << upperStartWord << endl;
    cout << "Target word: " << upperTargetWord << endl;

    WordGraph wordGraph;
    if (!wordGraph.initialize(dictionaryFile, upperStartWord.length())) {
        cout << "Error: Could not initialize word graph." << endl;
        return false;
    }

    // Test optimal path only (since it's more important than any path)
    cout << "\nTesting optimal path:" << endl;
    vector<string> optimalPath = wordGraph.findOptimalPath(upperStartWord, upperTargetWord);
    WordGraph::printPathWithChanges(optimalPath);

    // Verify results
    bool pathSuccess = !optimalPath.empty();
    bool testPassed = false;
    
    if (expectSuccess) {
        if (!pathSuccess) {
            cout << "Test failed: Expected to find a path but none was found." << endl;
            testPassed = false;
        } else {
            cout << "Test passed: Found optimal path." << endl;
            testPassed = true;
        }
    } else {
        if (pathSuccess) {
            cout << "Test failed: Expected no path but one was found." << endl;
            testPassed = false;
        } else {
            cout << "Test passed: Correctly found no path." << endl;
            testPassed = true;
        }
    }

    return testPassed;
}

bool runAllTests() {
    cout << "Running essential tests..." << endl;
    cout << "===================" << endl;
    
    const string dictionaryFile = "dictionary345.txt";
    bool allTestsPassed = true;

    // Test case 1: Simple 4-letter transformation
    if (!runTest("4-letter transformation", "lend", "send", dictionaryFile, true)) {
        allTestsPassed = false;
    }

    // Test case 2: Invalid input (different lengths)
    if (!runTest("Different length words", "cat", "dogs", dictionaryFile, false)) {
        allTestsPassed = false;
    }

    // Test case 3: One letter difference
    if (!runTest("One letter difference", "lend", "lent", dictionaryFile, true)) {
        allTestsPassed = false;
    }

    // Test case 4: Non-existent word
    if (!runTest("Non-existent word", "xyzq", "lend", dictionaryFile, false)) {
        allTestsPassed = false;
    }

    cout << "\n===================" << endl;
    if (allTestsPassed) {
        cout << "All essential tests passed!" << endl;
    } else {
        cout << "Some tests failed. Please check the issues above." << endl;
    }
    cout << "===================" << endl;

    return allTestsPassed;
}
