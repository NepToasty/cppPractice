/*Practice Problem: Given an integer array, write a C++ program that only prints the elements that are even numbers.*/

#include <iostream>

int main(){
    int arr[] = {1, 6, 3, 8, 5, 10, 7};

    std::cout << "The even numbers in the array are :";
    for(int i = 0; i < std::size(arr); i++){
        if(arr[i] % 2 == 0) std::cout << arr[i] << " ";
    }
}