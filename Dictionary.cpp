#include "Dictionary.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

Dictionary::Dictionary() : wordLength(0) {}

Dictionary::~Dictionary() {}

bool Dictionary::loadFromFile(const string& filename, size_t length) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open dictionary file: " << filename << endl;
        return false;
    }

    wordLength = length;
    string word;
    int wordCount = 0;
    while (file >> word) {
        if (word.length() == length) {
            words.push_back(word);
            wordSet.insert(word);
            wordCount++;
        }
    }

    // Remove duplicates
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());
    
    cout << "Loaded " << wordCount << " words of length " << length << " from dictionary" << endl;
    cout << "First few words: ";
    for (int i = 0; i < min(5, (int)words.size()); i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    return !words.empty();
}

const vector<string>& Dictionary::getWords() const {
    return words;
}

bool Dictionary::contains(const string& word) const {
    return wordSet.find(word) != wordSet.end();
}

vector<string> Dictionary::getAdjacentWords(const string& word) const {
    vector<string> adjacent;
    for (const auto& dictWord : words) {
        if (isAdjacent(word, dictWord)) {
            adjacent.push_back(dictWord);
        }
    }
    return adjacent;
}

bool Dictionary::isAdjacent(const string& word1, const string& word2) {
    if (word1.length() != word2.length()) {
        return false;
    }

    int diffCount = 0;
    for (size_t i = 0; i < word1.length(); ++i) {
        if (word1[i] != word2[i]) {
            diffCount++;
            if (diffCount > 1) {
                return false;
            }
        }
    }
    return diffCount == 1;
}
