#include<iostream>
#include<chrono>

void fibonacci_iterative(int n){
    
}
int fibonacci_recursive(int n){
    if (n <= 1){  return n; }
    std::cout << n << "," ;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main(){
    fibonacci_recursive(5);
}