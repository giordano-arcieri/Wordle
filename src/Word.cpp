#include "../include/Word.hpp"
#include <iostream>
#include <random>

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
    Word::fin.seekg((random_number - 1) * WORD_SIZE, std::ios::beg);
    std::getline(fin, Word::word);
}
Word::~Word()
{
    std::cout << "Destroyed!\n";
}
int Word::guesses_left() const
{
    return Word::guesses_remaining;
}
void Word::print()
{
    std::cout << Word::currentPrint;
}
bool Word::is_guessed() const
{   
    return Word::word_is_guessed;
}
bool Word::guess(const std::string& guess) 
{
    std::cout << "made guess: " << guess << std::endl;
    return true;
}