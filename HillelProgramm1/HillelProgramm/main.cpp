#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include "regulationFunctions.h"

// + make a vector with words 
// + make a function to pick a random word from vector
// + make a function to show the current state of the word ()
// + make a function to check if the game is won
// + make neccesery parameters
// + check user's input if it's not a letter 
// + add a separation line after each loop



int main() {

    int attempts = 18;
    int wrong_attempts = 0;
    char letter = 'L';
    
    std::vector<std::string> words = {"circumlocution", "disillusioned", "conviviality",
                                        "consanguineous", "cynosure", "aquiver",
                                        "accountability", "independence", "transformation",
                                        "phenomenon", "modernization", "methodology"};

    std::string word = pick_random_word(words);
    std::vector<bool> guessed(word.length(), false);

    std::cout << "Welcome to Hangman Game! This would be your word. Try to guess it! " << std::endl;
    std::cout << "\n" << std::endl;

    while (attempts > 0) {
        bool correctGuess = false;
        current_word_state(word, guessed);
        std::cout << "Make a guess in this field: ";
        std::cin >> letter;
        
        if (!isalpha(letter)) {
            std::cout << "You should enter a letter! " << std::endl;
            continue;
        }
        
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter) {
                guessed[i] = true;
                correctGuess = true;
                std::cout << "Nice guess! The letter " << "'" << letter << "'" << " was correct! " <<std::endl;
                std::cout << "\n" << std::endl;
                sepLine();

        }

            }


        if (!correctGuess) {
            attempts--;
            wrong_attempts++;
            
            std::cout << "Your guess was wrong!" << std::endl;
            std::cout << "\n" << std::endl;
            draw_hangman(wrong_attempts);
            std::cout << "Attempts left: " << attempts << std::endl;
            std::cout << "\n" << std::endl;
            sepLine();
        }

    
    if (check_game_state(guessed)) {
        std::cout << "Congratulations, you've guessed the word: " << word << std::endl;
        break;
    }
}
    if (attempts == 0) {
        std::cout << "Game over! The word was: " << word << std::endl;
    }

    return 0;
}
