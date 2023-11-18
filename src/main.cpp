#include "../include/Word.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{

    //set up some variables
    bool user_wants_to_play_again = true;
    std::string user_input;

 
    while(user_wants_to_play_again)//while user wants to play again
    {
        //pick word randomly
        Word word {};

        //print initali empty word
        word.print();

        while(!word.is_guessed() || word.guesses_left() > 0)//while word had not been guessed or all guesses have not been used
        {
            //ask for a guess
            std::cout << "Make a guess! Five letter word: ";
            std::cin >> user_input;
            while(user_input.size() != 5)
            {
                std::cout << "Word has to be of lenght 5! Make a guess! Five letter word: ";
                std::cin >> user_input;   
            }
            word.guess(user_input);
            //print word
            word.print();
        }
        if(word.is_guessed())//if word was guessed 
        {
            //complement user
            std::cout << "Congrats! You have guessed the word correctly!\n";
            //ask to play again
            std::cout << "Would you like to play again? Enter (yes) or (no): ";
            std::cin >> user_input;
            if(user_input != "Yes" || user_input != "yes" || user_input != "y" || user_input != "Y")
            {
                user_wants_to_play_again = false;
            }

        }
        else if(word.guesses_left() <= 0)//if guesses ran out //strong condition
        {
            //apologize for the user losing 
            std::cout << "Sorry, you have lost the game. You ran out of guesses.\n";

            //ask to play agian
            std::cout << "Would you like to play again? Enter (yes) or (no): ";
            std::cin >> user_input;
            if(user_input != "Yes" || user_input != "yes" || user_input != "y" || user_input != "Y")
            {
                user_wants_to_play_again = false;
            }
        }
        else
        {
            throw "Oh oh";
        }

    }


    return 0;
}

