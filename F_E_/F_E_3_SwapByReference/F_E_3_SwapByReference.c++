/*Practice Problem: Write a function swap_reference(int &a, int &b) that successfully swaps the values of the two variables passed to it by using pass by reference.
Print the original variables in main before and after the call to show the effect.*/

#include <iostream>

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    std::cout << "Inside of the function after swap: 1 = " << a << ", 2 = " << b << '\n';
}

int main()
{
    int toPass_1, toPass_2;
    std::cout << "Enter a value to be swaped: ";
    std::cin >> toPass_1;
    std::cout << "Enter a second value to be swaped with the first: ";
    std::cin >> toPass_2;
    std::cout << "Before the call: " << toPass_1 << ", " << toPass_2 << '\n';
    swap(toPass_1, toPass_2);
    std::cout << "After the Function call: 1 = " << toPass_1 << ", 2 = " << toPass_2;
    return 0;
}