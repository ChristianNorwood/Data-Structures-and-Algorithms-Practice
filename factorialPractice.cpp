#include <iostream>
template <typename T>
class Recursion {
    public:
        int i;

        T findFactorialRecursive(T num) {
            if (num == 1) {
                return num;
            }
            num = num * findFactorialRecursive(num-1);
            return num;
        }

        T findFactorialIterative(T num) {
            int iterator = num;
            for (int i = iterator-1; i > 0; --i) {
                num = num*i;
            }
            return num;
        }


        T fibonacciIterative(T n) {
            std::vector<int> z = {0,1};
            for (int i = 2; i < n+1; i++) {
                z.push_back(z[i-1] + z[i-2]);
                std::cout << "i " << z[i]<< std::endl;
            }
            return z[n];
        }

        T fibonacciIterativeRecursive(T n) {
            if (n < 2) {
                return n;
            }
            return fibonacciIterativeRecursive(n-1) + fibonacciIterativeRecursive(n-2);
        }
};

int main() {
    Recursion<int> t1;
    int val = t1.findFactorialRecursive(5);
    int val2 = t1.findFactorialIterative(5);

    std::cout << "Recursive Count: " << val << std::endl;
    std::cout << "Iterative Count: " << val2 << std::endl;

    int val3 = t1.fibonacciIterative(5);
    int val4 = t1.fibonacciIterativeRecursive(3);

    std::cout << "Fibonacci Iterative Count: " << val3 << std::endl;
    std::cout << "Fibonacci Iterative Recursive Count: " << val4 << std::endl;
}