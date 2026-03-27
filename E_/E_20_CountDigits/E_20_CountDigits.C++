#include <iostream>

int main(){
    long long N, count = 0;
    std::cout << "Enter a number:" << '\n';
    std::cin >> N;
    std::cout << '\n' << "The number of digits in " << N << " is: ";
    while(N > 0){
        N = (int)N / 10;
        count++;
    }
    std::cout << count;
}