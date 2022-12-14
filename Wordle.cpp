
#include "Wordle.h"
#include <iostream>
#include <fstream>

//===============================================================
Wordle::Wordle(std::string filename) {
    setWordListFilename(filename);
    srand(time(nullptr));
    // initially setting availability for all letters to true
    for(int i = 0; i < 26; i++)
    {
        availableLetters[i] = true;
    }
}

//===============================================================
void Wordle::loadWordList() {

    // Make sure file was opened
    std::string filename = getWordListFilename();
    std::ifstream fin(filename);
    if (fin.fail()){
        std::cout << "Error: could not open "<<getWordListFilename()<<std::endl;
    }
    else
    {
        // Read how many words in file
        std::string data;
        int count = 0;
        while (!fin.eof()){
            getline(fin, data);
            if(data == ""){break;}
            count++;
        }
        fin.clear();

        // Resize wordList based on how many words were found
        wordList.resize(count);
        fin.seekg(0, fin.beg);
        count = 0;

        // Populate wordList vector
        while(!fin.eof()){
            getline(fin, wordList[count]);
            count++;
        }

        // Close file
        fin.close();
    }
}

//===============================================================
void Wordle::printWordList() {
    // Check if wordList is empty
    if(wordList.size() == 0)
    {
        std::cout<<"Error: Word list empty."<<std::endl;
    }

    // Print each word in wordList if not empty
    else
    {
        for(int i = 0; i < wordList.size(); i++)
        {
            std::cout<<wordList[i]<<std::endl;
        }
    }
}

//===============================================================
void Wordle::setSecretWord(std::string word) {
    // Check if word is in word list
    if (find(wordList.begin(),wordList.end(),word) == wordList.end()){
        std::cout<<"Error: Not a valid secret word."<<std::endl;
    } else {
        secretWord = word;
    }
}

//===============================================================
void Wordle::setRandomSecretWord() {
    // get random number for index
    int range = wordList.size();
    int randomIndex = rand() % range;
    setSecretWord(wordList[randomIndex]);
}

//===============================================================
bool Wordle::makeGuess(std::string word) {
    bool correct = false;
    // filter out invalid guesses
    if (find(wordList.begin(), wordList.end(), word) == wordList.end() && word.size() == 5) {
        std::cout << "Error: " << word << " is not in word list. Try again." << std::endl;
        return false;
    } else if (word.size() != 5) {
        std::cout << "Error: " << word << " is not 5 characters. Try again." << std::endl;
        return false;
    }
        // if guess was valid
    else {
        guessNum++;
        if (guessNum <= MAX_GUESS_NUM) {
            // adding guess to list of guesses
            guess.push_back(word);
            if (word == secretWord) {
                std::cout << "Congratulations!! You guessed the secret word."<<std::endl;
                correct = true;
            }

            // determining feedback by comparing each letter in word and secretWord
            std::string feed = "";
            std::string secretCopy = secretWord;
            for(int i = 0; i < 5; i++)
            {
                // if letter at index i matches
                if(secretCopy[i] == word[i])
                {
                    feed.push_back('!');
                    // making sure this letter does not get copied again
                    secretCopy[i] = '-';
                }
                // if letter at index i does not match, but exists elsewhere in secretWord
                else if(secretCopy.find(word[i]) != std::string::npos)
                {
                    feed.push_back('+');
                }
                // if letter at index i does not match and is not in secretWord anywhere
                else
                {
                    // loop through ALPHABET array to set letter availability to false
                    for(int j = 0; j < 26; j++)
                    {
                        // setting availability to false
                        if(ALPHABET[j] == word[i])
                        {
                            // note: availableLetters and ALPHABET are same size array
                            availableLetters[j] = false;
                        }
                    }
                    feed.push_back('.');
                }
            }
            // appending the created feedback to feedback vector
            feedback.push_back(feed);
        } else {
            std::cout << "You did not guess the word. The word was: " << secretWord << ". Game Over." << std::endl;
        }
        return correct;
    }
}

//===============================================================
void Wordle::print() {
    for(int i = 0; i < guessNum; i++)
    {
        std::cout<<i+1<<": "<<guess[i]<<" "<<feedback[i]<<std::endl;
    }
}

//===============================================================
void Wordle::printAvailableLetters() {
    std::cout<<"Available letters to guess: ";
    for(int i = 0; i < 26; i++)
    {
        if(availableLetters[i])
        {
            // no comma on last letter
            if(i == 25)
            {
                std::cout<<ALPHABET[i]<<std::endl;
            }
            else
            {
                std::cout<<ALPHABET[i]<<", ";
            }
        }
    }
}