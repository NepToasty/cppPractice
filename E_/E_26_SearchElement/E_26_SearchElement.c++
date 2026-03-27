/*Practice Problem: Write a C++ program to search a target value in a given array.
If it exists, print the index (position) where it was first found; otherwise, indicate that the element was not found*/

#include <iostream>

int main()
{
    int arr[] = {10, 30, 40, 60, 20, 10};
    int target, coutTarget = 0, atIndex = 0;

    std::cout << "Array elements are: ";
    for (int i = 0; i < std::size(arr) - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << arr[std::size(arr) - 1] << '\n';
    std::cout << "Enter the element to search for: ";
    std::cin >> target;

    for(int i = 0; i < std::size(arr); i++){
        if(target == arr[i]){
            if(atIndex == 0) atIndex = i + 1;
            coutTarget++;
        }
    }
    if(atIndex > 0){
        std::cout << "Element " << target << " found first at index: " << atIndex << " with " << coutTarget << " element that matches the target inside of that array";
    }else{
        std::cout << "There was no element that matched the target";
    }
}