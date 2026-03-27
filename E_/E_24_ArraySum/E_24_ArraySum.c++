#include <iostream>

int main(){
    int lengthArray, temp = 0;
    std::cout << "Enter the length of the array(N): ";
    std::cin >> lengthArray;
    int arrayVeryLong[lengthArray];
    std::cout << "Enter " << lengthArray << " integers:" << '\n';
    for(int i = 0; i < lengthArray; i++){
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arrayVeryLong[i];
        temp += arrayVeryLong[i];
    }
    std::cout << "The sum of all elements in the array is: " << temp;
}