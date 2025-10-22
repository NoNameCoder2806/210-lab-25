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
enum class type{VECTOR, LIST, SET};

// Constants
const string DATA_PATH = "codes.txt";
const int OPERATIONS = 4;
const int DATA_STRUCTURES = 3;

// Function prototypes
template<typename T>
long long read(T& dataStructure, type t);

template<typename T>
long long sort(T dataStructure, type t);

template<typename T>
long long insertion(T dataStructure, type t);

template<typename T>
long long deletion(T dataStructure, type t);

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

    // Reading the data
    cout << "Vector: " << read(v, type::VECTOR) << endl;
    cout << "List:   " << read(l, type::LIST) << endl;
    cout << "Set:    " << read(s, type::SET) << endl;

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
long long read(T& dataStructure, type t)
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
    if (t == type::VECTOR || t == type::LIST)
    {
        // Read the data
        while (getline(fin, line))
        {
            // Use push_back() for vectors and lists
            dataStructure.push_back(line);
        }
    }
    else if (t == type::SET)
    {
        // Read the data
        while (getline(fin, line))
        {
            // Use insert() for sets
            dataStructure.insert(line);
        }
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<milliseconds>(end - start);
}

template<typename T>
long long sort(T dataStructure, type t)
{
    return 0;
}

template<typename T>
long long insertion(T dataStructure, type t)
{
    return 0;
}

template<typename T>
long long deletion(T dataStructure, type t)
{
    return 0;
}
