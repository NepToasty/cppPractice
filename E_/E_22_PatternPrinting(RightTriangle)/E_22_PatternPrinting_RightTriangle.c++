#include <iostream>

int main(){
    int numberOfRows;
    std::cout << "Enter the row count of the triangle: ";
    std::cin >> numberOfRows;
    for(int i = 0; i <= numberOfRows; i++){
        for(int k = 0; k < i; k++){
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}