#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct Location {
    char name;
    std::vector<char> possible;
};

std::vector<std::string> all_possible_moves;

string location = "A";
string target = "E";
string i_location = location;

int i;

std::vector<Location> map = {
    {'A', {'B', 'E'}},
    {'B', {'C', 'A'}},
    {'C', {'B', 'D'}},
    {'D', {'E', 'C'}},
    {'E', {'A', 'D'}},
};

int find_coordinates() {
    int i;
    for (int index = 0; index < map.size(); index++) {
        if (map[index].name == location) {
            i = index; 
            break;
        }
    }
    return i;
}


int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    i = find_coordinates();

    std::cout << "Starting at: " << location << std::endl;

    for (int k = 1; k <= 2; k++) {
        while (location != target) {
            int r = rand() % 2;
            location = map[i].possible[r];
            // if (location != target) {
            //     sum += location;
            //     sum += "->";
            // } else {
            //     sum += location;
            // }
            // i = find_coordinates();
            std::cout << location << std::endl;

        }
        // all_possible_moves.push_back(std::string(1, i_location) + "->" + sum);
        location = i_location;
    }

    // std::cout << "All Possible Moves:" << std::endl;
    // for (const std::string& move : all_possible_moves) {
    //     std::cout << move << std::endl;
    // }

    // // Function to remove duplicates from a vector of strings
    // std::vector<std::string> unique_moves;
    // for (const std::string& move : all_possible_moves) {
    //     if (std::count(unique_moves.begin(), unique_moves.end(), move) == 0) {
    //         unique_moves.push_back(move);
    //     }
    // }

    // // Function to remove strings longer than 8 characters
    // std::vector<std::string> filtered_moves;
    // for (const std::string& move : unique_moves) {
    //     if (move.length() <= 8) {
    //         filtered_moves.push_back(move);
    //     }
    // }

    // std::cout << "Unique and Filtered Moves:" << std::endl;
    // for (const std::string& move : filtered_moves) {
    //     std::cout << move << std::endl;
    // }

    return 0;
}
