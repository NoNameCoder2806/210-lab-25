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
long long read(T& dataStructure);

void insertElement(vector<string>& v, const string& str);
void insertElement(list<string>& l, const string& str);
void insertElement(set<string>& s, const string& str);

long long sort(vector<string> dataStructure);
long long sort(list<string> dataStructure);
long long sort(set<string> dataStructure);


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
    cout << "Vector: " << read(v) << endl;
    cout << "List:   " << read(l) << endl;
    cout << "Set:    " << read(s) << endl;

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
long long read(T& dataStructure)
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

    // Read the data
    while (getline(fin, line))
    {
        // Use insertElement() to add the element
        insertElement(dataStructure, line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

void insertElement(vector<string>& v, const string& str)
{
    // Use push_back() for vectors
    v.push_back(str);
}

void insertElement(list<string>& l, const string& str)
{
    // Use push_back() for list
    l.push_back(str);
}

void insertElement(set<string>& s, const string& str)
{
    // Use insert() for set
    s.insert(str);
}

long long sort(vector<string> dataStructure)
{
    return 0;
}

long long sort(list<string> dataStructure)
{
    return 0;
}

long long sort(set<string> dataStructure)
{
    // Return -1 for sets
    return -1;
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
