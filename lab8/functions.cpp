#include "func.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <map>

// Функция для нахождения N самых длинных слов, начинающихся с заданной буквы
void findLongestWords(const std::string& filename, char letter, int N, const std::string& outputFilename) {
    std::ifstream inputFile(filename);
    std::ofstream outputFile(outputFilename);
    std::string word;
    std::set<std::string> uniqueWords;

    // Чтение файла и извлечение слов
    while (inputFile >> word) {
        // Приводим слово к нижнему регистру
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        // Проверка, начинается ли слово с нужной буквы
        if (word[0] == letter) {
            uniqueWords.insert(word);
        }
    }

    // Создаем вектор из слов и сортируем по длине
    std::vector<std::string> sortedWords(uniqueWords.begin(), uniqueWords.end());
    std::sort(sortedWords.begin(), sortedWords.end(), [](const std::string& a, const std::string& b) {
        return a.size() > b.size(); // Сортировка по убыванию длины
    });


    for (int i = 0; i < std::min(N, (int)sortedWords.size()); ++i) {
        outputFile << sortedWords[i] << "\n";
    }
}


bool isPalindrome(const std::string& word) {
    int left = 0;
    int right = word.size() - 1;
    while (left < right) {
        if (word[left] != word[right]) return false;
        ++left;
        --right;
    }
    return true;
}

void processTextWithPalindromes(const std::string& text) {
    std::istringstream stream(text);
    std::string word;
    std::vector<std::string> words;
    std::map<char, int> vowelCount;


    for (char c : text) {
        if (std::isalpha(c)) {
            char lowerChar = std::tolower(c);
            if (lowerChar == 'a'  lowerChar == 'e'  lowerChar == 'i'  lowerChar == 'o'  lowerChar == 'u') {
                vowelCount[lowerChar]++;
            }
        }
    }


    while (stream >> word) {
        if (word.size() > 2 && isPalindrome(word)) {
            words.push_back(word);
        }
    }

    if (!words.empty()) {
        for (const std::string& w : words) {
            std::cout << w << "\n";
        }
    } else {
        std::cout << "No palindromes found.\n";
    }
}


void findWordsWithUniqueLetters(const std::string& filename, const std::string& outputFilename) {
    std::ifstream inputFile(filename);
    std::ofstream outputFile(outputFilename);
    std::string word;

    while (inputFile >> word) {
        std::set<char> uniqueLetters;
        for (char c : word) {
            if (std::isalpha(c)) {
                uniqueLetters.insert(std::tolower(c));
            }
        }

        if (uniqueLetters.size() > 7) {
            outputFile << word << " (";
            for (const char& c : uniqueLetters) {
                outputFile << c;
            }
            outputFile << ")\n";
        }
    }
}