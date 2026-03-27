#include <iostream>

int main(){
    int N;
    std::cout << "Enter the legth of the square: ";
    std::cin >> N;
    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            std::cout << "* ";
        }
        std::cout << '\n';
    }
    return 0;
}