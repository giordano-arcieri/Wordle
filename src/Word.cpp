#include "../include/Word.hpp"
#include <iostream>
#include <random>

bool is_in(char c, const std::string& str)
{
    for(char ch: str)
    {
        if(ch == c)
        {
            return true;
        }
    }
    return false;
}
Word::Word()
{
    //set input stream
    Word::fin.open(FILE_PATH);
    if(!fin)
    {
        std::string error_str = "Error: in constructor Word failed to open file: " + std::string(FILE_PATH);
        throw std::runtime_error {error_str};
    }
   
    //set guesses_remaining and word_is_guessed
    Word::guesses_remaining = GUESSES_ALLOWED;
    Word::word_is_guessed = false;

    //set random word
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, NUMBER_OF_WORDS); //there are 2309 lines in the file
    int random_number = distrib(gen);
    Word::fin.seekg((random_number - 1) * (WORD_SIZE + 1), std::ios::beg);
    std::getline(fin, Word::word);
}
Word::~Word()
{
    Word::fin.close();
}
int Word::guesses_left() const
{
    return Word::guesses_remaining;
}
void Word::print()
{
    int i = 0;
    for(char c: Word::currentPrint)
    {
        if(c == Word::word[i])
        {
            //print c in green
            std::cout << "\033[32m" << c << "\033[0m";
        }
        else if(is_in(c, Word::word))//if c is in word
        {
            //print c in yellow
            std::cout << "\033[33m" << c << "\033[0m";
        }   
        else
        {
            //print c in gray
            std::cout << c;
        }
        std::cout << " ";
        i++;
    }
    std::cout << std::endl;
}
bool Word::is_guessed() const
{   
    return Word::word_is_guessed;
}
bool Word::guess(const std::string& guess) 
{
    Word::currentPrint = guess;
    Word::guesses_remaining--;
    if(guess == Word::word){ return (Word::word_is_guessed = true); }
    return false;
}   