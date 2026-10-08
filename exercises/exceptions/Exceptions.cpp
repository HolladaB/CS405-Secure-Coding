// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <string>

class CustomException : public std::length_error { // created a custom exceptiom for a length_error
public:
    explicit CustomException(const std::string& msg) : std::length_error(msg) {}
};

bool do_even_more_custom_application_logic()
{
    // Throw any standard exception
    throw std::invalid_argument("Error/Invalid arguement found! ");// always throws invalid_arguement

    std::cout << "Running Even More Custom Application Logic. " << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;


    try { // try block to find if error happenes
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded. " << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Error found in do_even_more_custom_application_logic()! " << e.what() << std::endl; // catches error to and informs user of what function it occured in and gives the error
    }
    // Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw CustomException("Error/Invalid length! ");

    std::cout << "Leaving Custom Application Logic. " << std::endl;

}

float divide(float num, float den)
{
    // Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) {
        throw std::domain_error("Error/Can't divide by zero! "); // throws an exception when dem is 0
    }

    return (num / den); // gives division if den is not 0
}

void do_division() noexcept
{
    //  Create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;
    try { // tries to run the divide function which will not work with 0 denominator
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (std::domain_error& de) {
        std::cerr << "Error found in do_division()! " << de.what() << std::endl; // catches error to and informs user of what function it occured in and gives the error
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try { // tries to run the functions
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException& ce) { // catches CustomException/ invalid length
        std::cerr << "Error found CustomException: " << ce.what() << std::endl;
    }
    catch (const std::exception& e) {  // catches standard exception
        std::cerr << "Error found std::exception: " << e.what() << std::endl;
    }
    catch (...) { // catches uncaught exceptions
        std::cerr << "Error found uncaught exception! " << std::endl;
    }

    std::cout << "Program has reached end of main! " << std::endl; // informs user end of main was reached
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu