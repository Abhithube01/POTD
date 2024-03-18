#include <iostream>
using namespace std;

int findPivot(int n) {
    int totalSum = n * (n + 1) / 2; // Sum of all elements from 1 to n
    int leftSum = 0;

    for (int x = 1; x <= n; ++x) {
        int rightSum = totalSum - leftSum - x; // Exclude x from the right sum
        if (leftSum == rightSum) {
            return x; // Found the pivot integer
        }
        leftSum += x;
    }

    // No pivot integer fndd
    return -1;
}

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    int pivot = findPivot(n);

    if (pivot != -1) {
        std::cout << "Pivot integer found: " << pivot << std::endl;
    } else {
        std::cout << "No pivot integer found." << std::endl;
    }

    return 0;
}
