#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;

namespace fs = filesystem;

// Function to search for a string in a file
void searchInFile(const string& filePath, const string& searchStr) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;
        if (line.find(searchStr) != string::npos) {
            cout << "Found at line " << lineNumber << " in file " << filePath << endl;
            break;  // Remove this line if you want to find all occurrences in the file
        }
    }

    file.close();
}

// Function to search for a string in a directory and its subdirectories
void searchInDirectory(const string directoryPath, const string searchString) {
    for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            searchInFile(entry.path().string(), searchString);
        }
    }
}

int main() {
    string searchDirectory = ""; // Replace with your directory path
    string searchString = ""; // Replace with your search string

    searchInDirectory(searchDirectory, searchString);

    return 0;
}

// 1. Define a function "searchInFile" to search for a string in a given file.
// 2. Open the file.
// 3. If the file cannot be opened, display an error message and return.
// 4. Read each line in the file.
// 5. For each line, check if it contains the search string.
// 6. If found, display the line number and file path and exit (or continue searching).
// 7. Close the file.

// 8. Define a function "searchInDirectory" to search for a string in a directory and its subdirectories.
// 9. Iterate through all entries (files and directories) in the specified directory.
// 10. For each file entry with a ".txt" extension, call "searchInFile" to search for the string.

// 11. In the "main" function:
// 12. Specify the directory to search ("searchDirectory") and the search string ("searchString").
// 13. Call "searchInDirectory" to perform the search in the specified directory.

// 14. End the program.



