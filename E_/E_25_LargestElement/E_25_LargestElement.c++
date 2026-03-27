#include <iostream>

int main(){
    int maxNum = 0;
    int arr[] = {10, 30, 40, 60, 20};
    for(int i = 0; i < std::size(arr); i++){
        if(maxNum < arr[i]) maxNum = arr[i];
    }
    std::cout << "The largest element in the array is: " << maxNum;
}