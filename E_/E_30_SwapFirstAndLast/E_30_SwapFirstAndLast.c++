/*Practice Problem: Write a C++ program to swap the value of the first element (index 0) with the value of the last element (index size - 1) in an array.
Print the array before and after the swap.*/

#include <iostream>

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int arrSwap[std::size(arr)];

    std::cout << "Array BEFORE sawp : ";
    for(int i = 0; i < std::size(arr); i++){
        std::cout << arr[i] << " ";
        arrSwap[i] = arr[i];
    }
    
    arrSwap[0] = arr[std::size(arr) - 1];
    arrSwap[std::size(arr) - 1] = arr[0];
    std::cout << '\n' << "Array AFTER swap: ";
    for(int i = 0; i < std::size(arr); i++){
        std::cout << arrSwap[i] << " ";
    }
}