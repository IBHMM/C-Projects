
    srand(static_cast<unsigned>(time(nullptr)));

    find_coordinates();

    std::cout << "Starting at: " << location << std::endl;

    for (int k = 1; k < 200; k++) {
        std::string sum = "";
        while (location != target) {
            int d = rand() % 2;
            location = map[i].possible[d];
            if (location != target) {
                sum += location;
                sum += "->";
            } else {
                sum += location;
            }
            find_coordinates();
        }
        all_possible_moves.push_back(std::string(1, i_location) + "->" + sum);
        location = i_location;
    }

    std::cout << "All Possible Moves:" << std::endl;
    for (const std::string& move : all_possible_moves) {
        std::cout << move << std::endl;
    }

    // Function to remove duplicates from a vector of strings
    std::vector<std::string> unique_moves;
    for (const std::string& move : all_possible_moves) {
        if (std::count(unique_moves.begin(), unique_moves.end(), move) == 0) {
            unique_moves.push_back(move);
        }
    }

    // Function to remove strings longer than 8 characters
    std::vector<std::string> filtered_moves;
    for (const std::string& move : unique_moves) {
        if (move.length() <= 8) {
            filtered_moves.push_back(move);
        }
    }

    std::cout << "Unique and Filtered Moves:" << std::endl;
    for (const std::string& move : filtered_moves) {
        std::cout << move << std::endl;
    }
