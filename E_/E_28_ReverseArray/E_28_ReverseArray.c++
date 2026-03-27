/*Practice Problem: Write a program to reverse the order of the elements in the array and then
print the reversed array. (e.g., [1, 2, 3, 4] becomes [4, 3, 2, 1]).*/

#include <iostream>

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int arrRev[std::size(arr)];
    std::cout << "Original Array: ";
    for(int i = 0; i < std::size(arr) - 1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[std::size(arr) - 1] << '\n';
    std::cout << "Reversed Array: ";
    for(int i = 0; i < std::size(arr); i++){
        arrRev[std::size(arr) - i - 1] = arr[i];
    }
        for(int i = 0; i < std::size(arr) - 1; i++){
        std::cout << arrRev[i] << ", ";
    }
    std::cout << arrRev[std::size(arr) - 1];
}