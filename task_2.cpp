#include<iostream>

int factorial_recursive(int n){
    if (n == 0 || n==1 ){return 1;}
    return factorial_recursive(n-1)*n;
}
int factorial_iterative(int n){
    int fact = 1  ;
    for ( ; n>0 ; n--) {
        fact = fact * n;
    }
    return fact;
}
int main() {
    std::cout << "Enter a value to find factorial for:" << std::endl;
    int n;
    std::cin >> n;
    std::cout << factorial_iterative(n) << std::endl;
    std::cout << factorial_recursive(n) << std::endl;
}