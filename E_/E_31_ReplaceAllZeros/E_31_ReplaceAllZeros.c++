/*Practice Problem: Given an array, write a C++ program to replace all occurrences of the number 0 with the value -1. Print the modified array.*/

#include <iostream>

int main(){
    int numbers[] = {1, 0, 5, 0, 8, 0, 2};
    std::cout << "Original array: ";
    for(int i = 0; i < std::size(numbers); i++){
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n' <<"Modified array: ";
    for(int i = 0; i < std::size(numbers); i++){
        if(numbers[i] == 0) numbers[i] = -1;
        std::cout << numbers[i] << " ";
    }
}