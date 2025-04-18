#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include "Dictionary.h"

using namespace std;

/**
 * @file WordGraph.h
 * @brief Header file for the WordGraph class that manages word transformations
 */

/**
 * @class WordGraph
 * @brief Manages word transformations and finds paths between words
 */
class WordGraph {
private:
    Dictionary dictionary;
    unordered_map<string, vector<string>> graph;
    
    /**
     * @brief Finds the changed character between two words
     * @param word1 First word
     * @param word2 Second word
     * @return String representation of the character change
     */
    static string findChangedChar(const string& word1, const string& word2);

public:
    /**
     * @brief Default constructor
     */
    WordGraph();
    
    /**
     * @brief Destructor
     */
    ~WordGraph();

    /**
     * @brief Initializes the graph with words from dictionary
     * @param dictionaryFile The name of the dictionary file
     * @param wordLength The length of words to use
     * @return true if initialization was successful, false otherwise
     */
    bool initialize(const string& dictionaryFile, size_t wordLength);
    
    /**
     * @brief Finds any path from start to target (non-optimal)
     * @param start The starting word
     * @param target The target word
     * @return A vector of words representing the path
     */
    vector<string> findAnyPath(const string& start, const string& target);
    
    /**
     * @brief Finds optimal path from start to target
     * @param start The starting word
     * @param target The target word
     * @return A vector of words representing the path
     */
    vector<string> findOptimalPath(const string& start, const string& target);
    
    /**
     * @brief Prints a path with character changes
     * @param path The path to print
     */
    static void printPathWithChanges(const vector<string>& path);
};
