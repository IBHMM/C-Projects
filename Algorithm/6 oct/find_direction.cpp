#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Location {
    std::string name;
    std::vector<std::string> possible;
};

std::vector<Location> map = {
    {"A", {"B", "D"}},
    {"B", {"C", "A"}},
    {"C", {"B", "D"}},
    {"D", {"A", "C"}},
};

std::vector<std::string> all_possible_moves;

std::string location = "A";
std::string target = "C";
std::string initial_location = location;

int i;

void find_coordinates() {
    for (int index = 0; index < map.size(); ++index) {
        if (map[index].name == location) {
            i = index;
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generator
    
    find_coordinates();
    
    for (int k = 1; k < 100; ++k) {
        std::string sum = "";
        
        while (location != target) {
            int d = rand() % 2;
            location = map[i].possible[d];
            
            if (location != target) {
                sum += location + "->";
            } else {
                sum += location;
            }
            
            find_coordinates();
        }
        
        all_possible_moves.push_back(initial_location + "->" + sum);
        location = initial_location;
    }
    
    // Function to remove duplicates
    auto removeDuplicates = [](std::vector<std::string>& arr) {
        std::vector<std::string> result;
        for (const std::string& item : arr) {
            if (std::find(result.begin(), result.end(), item) == result.end()) {
                result.push_back(item);
            }
        }
        return result;
    };

    // Function to remove repeated items with length greater than 8
    auto removeRepeated = [](std::vector<std::string>& arr) {
        std::vector<std::string> result;
        for (const std::string& item : arr) {
            if (item.length() <= 8) {
                result.push_back(item);
            }
        }
        return result;
    };

    std::cout << "All possible moves:" << std::endl;
    for (const std::string& move : all_possible_moves) {
        std::cout << move << std::endl;
    }

    all_possible_moves = removeDuplicates(all_possible_moves);
    all_possible_moves = removeRepeated(all_possible_moves);

    std::cout << "\nUnique and non-repeated moves:" << std::endl;
    for (const std::string& move : all_possible_moves) {
        std::cout << move << std::endl;
    }

    return 0;
}



// Define a structure Location with name and possible moves

// Create a list/map called map that contains Location objects

// Create an empty list called all_possible_moves

// Initialize a variable location to the starting location ('A')
// Initialize a variable target to the target location ('C')
// Initialize a variable initial_location to store the initial location

// Define a variable i to store the current index in the map

// Function find_coordinates():
//     Iterate through the map and find the index i where map[i].name equals location

// Seed the random number generator with the current time

// Main program:
//     Call find_coordinates() to initialize i
    
//     Repeat 200 times:
//         Initialize an empty string called sum
        
//         While location is not equal to the target:
//             Generate a random integer d (0 or 1)
//             Update the location to map[i].possible[d]
            
//             If location is not equal to the target:
//                 Append location followed by '->' to the sum
//             Else:
//                 Append location to the sum
            
//             Call find_coordinates() to update i
        
//         Append initial_location followed by '->' and the sum to all_possible_moves
//         Reset location to initial_location

//     Define a function removeDuplicates(arr):
//         Create an empty list called result
//         For each item in arr:
//             If item is not in result, append it to result
//         Return result

//     Define a function removeRepeated(arr):
//         Create an empty list called result
//         For each item in arr:
//             If the length of item is less than or equal to 8, append it to result
//         Return result

//     Print "All possible moves:"
//     For each move in all_possible_moves:
//         Print move
    
//     Remove duplicates from all_possible_moves using removeDuplicates()
//     Remove repeated moves with length greater than 8 using removeRepeated()

//     Print "\nUnique and non-repeated moves:"
//     For each move in all_possible_moves:
//         Print move
