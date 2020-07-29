#include <iostream>
#include "ufo_functions.hpp"

int main() {

  greet();

  std::string codeword = "interobang";
  std::string answer = "__________";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  while (answer != codeword && misses < 7)
  {
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;

    for (int l = 0; l < codeword.length(); l++)
    {
      if (letter == codeword[l])
      {
        answer[l] = letter;
        guess = true;
      }
    }

    if (guess)
    {
      std::cout << "\nCorrect! You're closer to cracking the codeword.\n";
    }

    else
    {
      std::cout << "\nIncorrect! The tractor beam puls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }
    
  }
  guess = false;
  end_game(answer, codeword);

  
}
