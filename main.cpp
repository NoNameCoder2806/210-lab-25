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

// Enum class
enum class dataStructureType{VECTOR, LIST, SET};

// Constants
const string DATA_PATH = "codes.txt";
const int OPERATIONS = 4;
const int DATA_STRUCTURES = 3;

// Function prototypes
template<typename T>
long long read(T dataStructure, dataStructureType type);

template<typename T>
long long sorting(T dataStructure, dataStructureType type);

template<typename T>
long long insertion(T dataStructure, dataStructureType type);

template<typename T>
long long deletion(T dataStructure, dataStructureType type);

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
long long read(T dataStructure, dataStructureType type)
{
    // Create a file stream
    ifstream fin;
    fin.open(DATA_PATH);

    // Check for file stream error
    if (!fin.is_open())
    {
        // Display an error message
        cerr << "Error: could not open file " << DATA_PATH << endl;
        
        // Exit the function
        return -1;
    }

    // Create a string variable to store the line data
    string line = "";

    // Start timing
    auto start = high_resolution_clock::now();

    // Check for the data structure type
    if (type == VECTOR || type == LIST)
    {
        // Read the data
        while (getline(fin, line))
        {
            // Use push_back() for vectors and lists
            dataStructure.push_back(line);
        }
    }
    else if (type == SET)
    {
        // Read the data
        while (getline(fin, line))
        {
            // Use insert() for sets
            dataStructure.insert(line);
        }
    }
    
    return 0;
}

template<typename T>
long long sorting(T dataStructure, dataStructureType type)
{
    return 0;
}

template<typename T>
long long insertion(T dataStructure, dataStructureType type)
{
    return 0;
}

template<typename T>
long long deletion(T dataStructure, dataStructureType type)
{
    return 0;
}
