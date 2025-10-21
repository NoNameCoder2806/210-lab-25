// COMSC-210 | Lab 23 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

// Main function
int main() {
    // Start timing
    auto start = high_resolution_clock::now();

    // Example loop to measure
    vector<int> numbers;
    for(int i = 0; i < 1000000; ++i)
    {
        numbers.push_back(i);
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<milliseconds>(end - start);

    // Output the duration in milliseconds
    std::cout << "Time taken: " << duration.count() << " milliseconds\n";

    return 0;
}
