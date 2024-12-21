#include <iostream>
#include "func.hpp"

int main() {
    findLongestWords("input.txt", 'a', 2000, "output1.txt");

    std::string text = "madam racecar apple level";
    processTextWithPalindromes(text);

    findWordsWithUniqueLetters("input.txt", "output2.txt");

    return 0;
}