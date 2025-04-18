#pragma once
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @file Dictionary.h
 * @brief Header file for the Dictionary class that manages word storage and operations
 */

/**
 * @class Dictionary
 * @brief Manages a collection of words and provides operations for word transformations
 */
class Dictionary {
private:
    vector<string> words;
    unordered_set<string> wordSet;
    size_t wordLength;

public:
    /**
     * @brief Default constructor
     */
    Dictionary();
    
    /**
     * @brief Destructor
     */
    ~Dictionary();

    /**
     * @brief Loads words from a file into the dictionary
     * @param filename The name of the file containing words
     * @param length The length of words to load
     * @return true if loading was successful, false otherwise
     */
    bool loadFromFile(const string& filename, size_t length);
    
    /**
     * @brief Gets all words in the dictionary
     * @return A constant reference to the vector of words
     */
    const vector<string>& getWords() const;
    
    /**
     * @brief Checks if a word exists in the dictionary
     * @param word The word to check
     * @return true if the word exists, false otherwise
     */
    bool contains(const string& word) const;
    
    /**
     * @brief Gets all words that differ by one letter from the given word
     * @param word The word to find adjacent words for
     * @return A vector of adjacent words
     */
    vector<string> getAdjacentWords(const string& word) const;
    
    /**
     * @brief Checks if two words differ by exactly one letter
     * @param word1 First word to compare
     * @param word2 Second word to compare
     * @return true if words differ by exactly one letter, false otherwise
     */
    static bool isAdjacent(const string& word1, const string& word2);
};
