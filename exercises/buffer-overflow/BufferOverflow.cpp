// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";
  std::cin.get(user_input, 20);

  if (std::cin.peek() != '\n') { // searches for new line character(end of user input)
      std::cout << "Input was too long, limited to 19!\n"; // error message to inform user 
      std::cin.clear(); // clears fail bit but not buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears entire buffer size or until new line character(end of user input)
  }

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
