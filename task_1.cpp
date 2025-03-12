#include <iostream>
#include <ctime>
//function to get the nth fibonacci number
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
//calling recursive fib function and printing
void fibonacci_recursive(int n) {
    std::cout << "fib series calculated recursively up to " << n << ": ";
    
    int i = 0;
    int current = fib(i);
    while (current <= n) {
        std::cout << current << " ";
        i++;
        current = fib(i);
    }
    std::cout << std::endl;
}
//function to get fibonacci series iteratively and printing the result
void fibonacci_iterative(int n) {
    std::cout << "fib series calculated iteratively up to " << n << ": ";
    
    if (n < 0) {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    
    std::cout << "0 ";
    if (n >= 1)
        std::cout << "1 ";
    
    int a = 0, b = 1;
    while (true) {
        int c = a + b;
        if (c > n)
            break;
        std::cout << c << " ";
        a = b;
        b = c;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the value of n to calculate fibonacci series upto: ";
    std::cin >> n;
    
    clock_t start_recursive = clock();
    fibonacci_recursive(n);
    clock_t end_recursive = clock();
    double time_recursive = double(end_recursive - start_recursive) / CLOCKS_PER_SEC;
    
    clock_t start_iterative = clock();
    fibonacci_iterative(n);
    clock_t end_iterative = clock();
    double time_iterative = double(end_iterative - start_iterative) / CLOCKS_PER_SEC;
    
    std::cout << "\nExecution Time for recursive fib: " << time_recursive << " seconds" << std::endl;
    std::cout << "Execution Time for iterative fib: " << time_iterative << " seconds" << std::endl;
    
    return 0;
}