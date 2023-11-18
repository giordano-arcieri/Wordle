#ifndef WORD_HPP
#define WORD_HPP

#include <string>
#include <fstream>

#define WORD_SIZE 5
#define GUESSES_ALLOWED 6
#define FILE_PATH "five_letter_words.txt"
#define NUMBER_OF_WORDS 2309

class Word 
{
private:
    std::string word {5};
    std::string currentPrint {"....."};
    int guesses_remaining;
    bool word_is_guessed;
    std::ifstream fin;
public:
    Word();
    ~Word();
    int guesses_left() const;
    void print();
    bool is_guessed() const;
    bool guess(const std::string& guess);
};

#endif