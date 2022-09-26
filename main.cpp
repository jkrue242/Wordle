// Written by Joseph Krueger

#include <iostream>
#include "Wordle.h"

//===============================================================
int main() {
    
    std::cout<<"=================================================================================="<<std::endl;
    std::cout<<"Guess the WORDLE in 6 tries."<<std::endl<<std::endl<<
          "Each guess must be a valid 5-letter word. Hit the enter button to submit."<<std::endl<<std::endl<<
          "After each guess, you will get feedback to how close your guess was to the word."<<std::endl<<
          "! is the correct letter in the correct spot"<<std::endl<<
          "+ is the correct letter in the wrong spot"<<std::endl<<
          ". is a letter that does not appear in the word."<<std::endl<<
          "=================================================================================="<<std::endl<<std::endl;

    // Loading the new Wordle object
    Wordle WordleGame("wordList.txt");
    WordleGame.loadWordList();
    WordleGame.setSecretWord("styre");
    std::cout<<"Secret word is "<<WordleGame.getSecretWord()<<std::endl;

    std::string guess;
    bool win = false;

    // Game driver code
    while(WordleGame.getGuessNum() < 6)
    {
        std::cout<<std::endl;
        WordleGame.printAvailableLetters();
        std::cout<<"Enter guess: "<<std::endl;
        std::cin >> guess;
        // if the secret word is guessed, break out of the loop
        if(WordleGame.makeGuess(guess))
        {
            win = true;
            WordleGame.print();
            break;
        }
        //print out guesses and feedback
        WordleGame.print();
    }
    // if the secret word was not guessed
    if (!win)
    {
        std::cout<<"You did not guess the word. The secret word was: "<<WordleGame.getSecretWord()<<std::endl
        <<"Game over.";
    }
    return 0;
}
