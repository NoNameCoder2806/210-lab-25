// COMSC-210 | Lab 23 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
using namespace std;
using namespace std::chrono;

// Constants
const string DATA_PATH = "codes.txt";
const int OPERATIONS = 4;
const int DATA_STRUCTURES = 3;

// Function prototypes
template<typename T>
long long read(T dataStructure);

template<typename T>
long long sorting(T dataStructure);

template<typename T>
long long insertion(T dataStructure);

template<typename T>
long long deletion(T dataStructure);

// Main function
int main()
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create data structures to race
    vector<string> v;
    list<string> l;
    set<string> s;

    // Create arrays to store the time
    long long vectorTimes[OPERATIONS];
    long long listTimes[OPERATIONS];
    long long setTimes[OPERATIONS];

    // Example loop to measure
    for(int i = 0; i < 1000000; ++i)
    {
        //numbers.push_back(i);
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<milliseconds>(end - start);

    // Output the duration in milliseconds
    std::cout << "Time taken: " << duration.count() << " milliseconds\n";

    return 0;
}

// Function implementations
template<typename T>
long long read(T dataStructure)
{
    // Create a file stream
    ifstream fin;
    fin.open(DATA_PATH);

       
    return 0;
}

template<typename T>
long long sorting(T dataStructure)
{
    return 0;
}

template<typename T>
long long insertion(T dataStructure)
{
    return 0;
}

template<typename T>
long long deletion(T dataStructure)
{
    return 0;
}
