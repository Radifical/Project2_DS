#include "WordGraph.h"
#include <algorithm>
#include <iostream>

using namespace std;

WordGraph::WordGraph() {}

WordGraph::~WordGraph() {}

bool WordGraph::initialize(const string& dictionaryFile, size_t wordLength) {
    if (!dictionary.loadFromFile(dictionaryFile, wordLength)) {
        return false;
    }

    const auto& words = dictionary.getWords();
    for (const auto& word : words) {
        graph[word] = dictionary.getAdjacentWords(word);
    }

    return true;
}

vector<string> WordGraph::findAnyPath(const string& start, const string& target) {
    if (!dictionary.contains(start) || !dictionary.contains(target)) {
        return {};
    }

    stack<string> stack;
    unordered_map<string, string> parent;
    unordered_set<string> visited;

    stack.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!stack.empty()) {
        string current = stack.top();
        stack.pop();

        if (current == target) {
            vector<string> path;
            string word = target;
            while (!word.empty()) {
                path.push_back(word);
                word = parent[word];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                stack.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    return {};
}

vector<string> WordGraph::findOptimalPath(const string& start, const string& target) {
    if (!dictionary.contains(start) || !dictionary.contains(target)) {
        return {};
    }

    queue<string> queue;
    unordered_map<string, string> parent;
    unordered_set<string> visited;

    queue.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!queue.empty()) {
        string current = queue.front();
        queue.pop();

        if (current == target) {
            vector<string> path;
            string word = target;
            while (!word.empty()) {
                path.push_back(word);
                word = parent[word];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    return {};
}

string WordGraph::findChangedChar(const string& word1, const string& word2) {
    for (size_t i = 0; i < word1.length(); ++i) {
        if (word1[i] != word2[i]) {
            return string(1, word1[i]) + "->" + string(1, word2[i]);
        }
    }
    return "";
}

void WordGraph::printPathWithChanges(const vector<string>& path) {
    if (path.empty()) {
        cout << "No path found." << endl;
        return;
    }

    for (size_t i = 0; i < path.size() - 1; ++i) {
        string change = findChangedChar(path[i], path[i + 1]);
        cout << path[i] << " {" << change << "} " << path[i + 1] << endl;
    }
    cout << "Total steps: " << path.size() - 1 << endl;
}
