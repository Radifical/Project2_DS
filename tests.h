#pragma once
#include <string>
#include "WordGraph.h"

/**
 * @brief Runs a single test case for word transformation
 * @param testName Name of the test case
 * @param startWord Starting word for transformation
 * @param targetWord Target word for transformation
 * @param dictionaryFile Path to the dictionary file
 * @param expectSuccess Whether the test is expected to succeed
 * @return true if test passed, false otherwise
 */
bool runTest(const std::string& testName, const std::string& startWord, 
            const std::string& targetWord, const std::string& dictionaryFile, 
            bool expectSuccess);

/**
 * @brief Runs all test cases for the word transformation program
 * @return true if all tests passed, false otherwise
 */
bool runAllTests(); 