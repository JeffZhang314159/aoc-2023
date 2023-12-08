#include <fstream>
#include <iostream>
#include <map>
#include <string>

void updateMax(std::string sample, std::map<std::string, int>& colourMax) {
    int index = 0;
    int newIndex = 0;
    do {
        newIndex = sample.find(",", index);
        if (newIndex == std::string::npos) newIndex = sample.length();
        std::string single = sample.substr(index, newIndex - index);

        int spaceIndex = single.find(" ");
        int count = std::stoi(single.substr(0, spaceIndex));
        std::string colour = single.substr(spaceIndex + 1, single.length());
        colourMax[colour] = std::max(colourMax[colour], count);
        
        index = newIndex + 2;
    } while (newIndex < sample.length());
}

int main() {
    std::ifstream input("input.txt");

    int ans = 0;
    std::string line;
    if (input.is_open()) {
        while (std::getline(input, line)) {
            std::map<std::string, int> colourMax
            {
                {"red", 0},
                {"green", 0},
                {"blue", 0}
            };
            
            int colon = line.find(":");
            
            colon += 2;
            int newColon = 0;
            while (newColon < line.length()) {
                newColon = line.find(";", colon);
                if (newColon == std::string::npos) newColon = line.length();
                std::string sample = line.substr(colon, newColon - colon);
                updateMax(sample, colourMax);

                colon = newColon + 2;
            }

            int prod = 1;
            for (auto const& [colour, count] : colourMax) {
                prod *= count;
            }
            ans += prod;
        }
    } else {
        std::cout << "Could not open file";
    }
    
    std::cout << ans;
}