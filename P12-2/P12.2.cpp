#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // Include the header for character functions
using namespace std;

void pressEnterToContinue();
int characterCount(const string& fileName);
int wordCount(const string& fileName);

int main() {
    int charCount, wdCount;
    string datafile;
    cout << "Enter input file: " << endl;
    getline(cin, datafile);
    charCount = characterCount(datafile);
    wdCount = wordCount(datafile);
    cout << "Characters: " << charCount << endl;
    cout << "Words: " << wdCount << endl;
    pressEnterToContinue();
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue...\n";
    cin.clear();
    while (cin.get() != '\n') continue;
}

int characterCount(const string& fileName) {
    ifstream inFile(fileName);
    char characters;
    int charCount = 0;

    if (!inFile.is_open()) {
        cout << "Failed to open file." << endl;
        return -1;
    }

    while (inFile.get(characters)) {
        // Check if the character is an uppercase or lowercase letter
        if (isalpha(characters)) {
            charCount++;
        }
    }

    inFile.close();
    return charCount;
}

int wordCount(const string& fileName) {
    ifstream inFile(fileName);
    string word;
    int wordCount = 0;

    if (!inFile.is_open()) {
        cout << "Failed to open file." << endl;
        return -1;
    }

    while (inFile >> word) {
        // Check if the word contains at least one letter
        bool hasLetter = false;
        for (int i = 0; i < word.length(); ++i) {
            if (isalpha(word[i])) {
                hasLetter = true;
                break;
            }
        }
        if (hasLetter) {
            wordCount++;
        }
    }

    inFile.close();
    return wordCount;
}
