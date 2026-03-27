/*Practice Problem: Write a function swap_value(int a, int b) that attempts to swap the values of its parameters (a and b) inside the function body.
Call this function from main and print the original variables before and after the call to demonstrate that the swap does not affect the original variables in main.*/

#include <iostream>

void swap_value(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    std::cout << "The swaped values are: " << x << " and " << y;
}

int main()
{
    int toPassVal_1, toPassVal_2;
    std::cout << "Enter a first number to be swaped: ";
    std::cin >> toPassVal_1;
    std::cout << "Enter a second number to be swaped: ";
    std::cin >> toPassVal_2;
    swap_value(toPassVal_1, toPassVal_2);
}