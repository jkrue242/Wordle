// Written by Joseph Krueger
#pragma once

#include <string>
#include <vector>
//===============================================================

class Wordle {
public:
    Wordle(std::string filename="");

    void setWordListFilename(std::string filename){this->wordListFilename = filename;}
    std::string getWordListFilename(){return this->wordListFilename;}

    void loadWordList();

    void setSecretWord(std::string word);
    std::string getSecretWord(){return this->secretWord;}
    void setRandomSecretWord();

    int getGuessNum(){return guessNum;}
    bool makeGuess(std::string word);

    void printWordList();
    void print();
    void printAvailableLetters();

    // const alphabet array of english letters
    const char ALPHABET[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                               'h', 'i', 'j', 'k', 'l', 'm', 'n',
                               'o', 'p', 'q', 'r', 's', 't', 'u',
                               'v', 'w', 'x', 'y', 'z'};

    std::vector<std::string> wordList;
private:
    std::string wordListFilename;

    std::string secretWord;

    int guessNum = 0;

    // const max number of guesses to be used in the game
    const int MAX_GUESS_NUM = 6;
    std::vector<std::string> guess;
    std::vector<std::string> feedback;

    bool availableLetters[26];
};
