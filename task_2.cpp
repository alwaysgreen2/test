#include<iostream>
#include<time.h>  

//multiply current value and go one depth below
double factorial_recursive(double n){
    if (n == 0 || n==1 ){return 1;}
    return factorial_recursive(n-1)*n;
}
//multiply current with previous product
double factorial_iterative(double n){
    int fact = 1;
    for ( ; n>0 ; n--) {
        fact = fact * n;
    }
    return fact;
}

int main() {
    std::cout << "Enter a value to find factorial for:" << std::endl;
    double n;
    std::cin >> n;
    
    // Timing for iterative version
    clock_t start_iterative = clock();
    int result_iterative = factorial_iterative(n);
    clock_t end_iterative = clock();
    double time_iterative = (double)(end_iterative - start_iterative) / CLOCKS_PER_SEC;
    
    // Timing for recursive version
    clock_t start_recursive = clock();
    int result_recursive = factorial_recursive(n);
    clock_t end_recursive = clock();
    double time_recursive = (double)(end_recursive - start_recursive) / CLOCKS_PER_SEC;
    
    std::cout << "Iterative factorial: " << result_iterative << std::endl;
    std::cout << "Time taken (iterative): " << time_iterative << " seconds" << std::endl;
    
    std::cout << "Recursive factorial: " << result_recursive << std::endl;
    std::cout << "Time taken (recursive): " << time_recursive << " seconds" << std::endl;
    
    return 0;
}