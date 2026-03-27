#include <iostream>
#include <algorithm>

int main(){
    int A, B, GCD, minNumber;
    std::cout << "Enter a val for A: ";
    std::cin >> A;
    std::cout << "Enter a val for B: ";
    std::cin >> B;
    minNumber = std::min(A, B);
    for(int i = 1; i <= minNumber; i++){
        if((A % i == 0) && (B % i == 0)) GCD = i;
    }
    std::cout << "The GCD of " << A << " and " << B << " is: " << GCD;
}