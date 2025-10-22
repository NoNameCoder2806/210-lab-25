// COMSC-210 | Lab 23 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <algorithm>
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
const string INSERT_ELEMENT = "TESTCODE";

// Function prototypes
long long read(vector<string>& v);
long long read(list<string>& l);
long long read(set<string>& s);

long long sort(vector<string>& v);
long long sort(list<string>& l);
long long sort(set<string>& s);

long long insert(vector<string>& v);
long long insert(list<string>& l);
long long insert(set<string>& s);

long long deletion(vector<string>& v);
long long deletion(list<string>& l);
long long deletion(set<string>& s);

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
    vectorTimes[0] = read(v);
    listTimes[0] = read(l);
    setTimes[0] = read(s);

    // Sort the data
    vectorTimes[1] = sort(v);
    listTimes[1] = sort(l);
    setTimes[1] = sort(s);

    // Insert the element into the middle
    vectorTimes[2] = insert(v);
    listTimes[2] = insert(l);
    setTimes[2] = insert(s);

    // Delete the middle element
    vectorTimes[3] = deletion(v);
    listTimes[3] = deletion(l);
    setTimes[3] = deletion(s);

    // Display the race results
    for (int i = 0; i < OPERATIONS; i++)
    {
        
    }

    return 0;
}

// Function implementations
long long read(vector<string>& v)
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
        // Use push_back() to add element
        v.push_back(line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long read(list<string>& l)
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
        // Use push_back() to add element
        l.push_back(line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long read(set<string>& s)
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
        // Use insert() to add element
        s.insert(line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long sort(vector<string>& v)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use sort() from <algorithm> to sort vectors
    sort(v.begin(), v.end());

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long sort(list<string>& l)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use sort() member function for lists
    l.sort();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long sort(set<string>& s)
{
    // Return -1 for sets because sets are sorted
    return -1;
}

long long insert(vector<string>& v)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use insert() member function for vector and pass in the middle position
    v.insert(v.begin() + v.size() / 2, INSERT_ELEMENT);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long insert(list<string>& l)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create an iterator
    auto it = l.begin();

    // Advance the iterator to the middle position
    advance(it, l.size() / 2);

    // Use insert() member function for sets
    l.insert(it, INSERT_ELEMENT);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long insert(set<string>& s)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use insert() member function for sets
    s.insert(INSERT_ELEMENT);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long deletion(vector<string>& v)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use erase() member function for vector and pass in the middle position
    v.erase(v.begin() + v.size() / 2);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long deletion(list<string>& l)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create an iterator
    auto it = l.begin();

    // Advance the iterator to the middle position
    advance(it, l.size() / 2);

    // Use erase() member function for sets
    l.erase(it);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

long long deletion(set<string>& s)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create an iterator
    auto it = s.begin();

    // Advance the iterator to the middle position
    advance(it, s.size() / 2);

    // Use erase() member function for sets
    s.erase(it);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}
