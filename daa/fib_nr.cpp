#include <iostream>
using namespace std;

void printFibonacci(int n) {
    if (n <= 0) {
        return;
    }

    long long first = 0, second = 1;
    cout << first << " ";

    for (int i = 1; i < n; ++i) {
        cout << second << " ";
        long long next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci numbers to print: ";
    cin >> n;

    printFibonacci(n);

    return 0;
}