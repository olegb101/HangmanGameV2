#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

static const char hangman[9][9] = {

    "   _____",
    "       |",
    "  |    |",
    "  O    |",
    " / \\   |",
    "  |    |",
    " / \\   |",
   
};

static void draw_hangman(int wrong_attempts) {
    for (int i = 0; i < 9; i++) {
       for (int j = 0; j < 8; j++) {
           char c = hangman[i][j];
            if (c != ' ' && wrong_attempts > 0) {
                std::cout << c;
                wrong_attempts--;
            }
            else {
                std::cout << ' ';
            }
       }
        std::cout << std::endl;
    } 
}

static std::string pick_random_word(std::vector<std::string>& words) {
    std::srand((unsigned int)std::time(0)); // the random number according to the current time
    int index = std::rand() % words.size(); // random index in the range of words
    return words[index];
}

static void current_word_state(std::string word, const std::vector<bool>& guessed) {  // to show the word's state 
    
    for (int i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            std::cout << word[i];
        }
        else {
            std::cout << "_";
        } std::cout << " ";
       
    }
    std::cout << std::endl;
}

static bool check_game_state(std::vector<bool>& guessed) { // to check if the player has guessed the word or not
    for (bool b : guessed) {            //iterates each element in "guessed" vector with variable bool b
        if (!b) {                       //if any of letters are not guessed, it will be false
            return false;               
        }
    } return true;
} 

void sepLine() {
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
}
