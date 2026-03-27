/*Practice Problem: Create a C++ function named add(int a, int b) that accepts two integers as arguments and returns their sum as an integer. 
Demonstrate its use by adding two numbers and printing the result in main.*/

#include <iostream>

int add(int a, int b){
    int addNumber;
    addNumber = a + b;
    return addNumber;
}

int main()
{
    int num_1, num_2;
    std::cout << "Enter a number: ";
    std::cin >> num_1;
    std::cout << "Enter a second number: ";
    std::cin >> num_2;
    std::cout << "The sum is: " << add(num_1, num_2);
}