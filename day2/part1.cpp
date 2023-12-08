#include <fstream>
#include <iostream>
#include <map>
#include <string>

const std::map<std::string, int> COLOUR_MAX
{
    {"red", 12},
    {"green", 13},
    {"blue", 14}
};

bool checkSample(std::string sample) {
    int index = 0;
    int newIndex = 0;
    do {
        newIndex = sample.find(",", index);
        if (newIndex == std::string::npos) newIndex = sample.length();
        std::string single = sample.substr(index, newIndex - index);

        int spaceIndex = single.find(" ");
        int count = std::stoi(single.substr(0, spaceIndex));
        std::string colour = single.substr(spaceIndex + 1, single.length());
        if (count > COLOUR_MAX.at(colour)) return false;
        
        index = newIndex + 2;
    } while (newIndex < sample.length());
    return true;
}

int main() {
    std::ifstream input("test.txt");

    int ans = 0;
    std::string line;
    if (input.is_open()) {
        while (std::getline(input, line)) {
            int colon = line.find(":");
            int id = std::stoi(line.substr(5, colon - 5));
            
            colon += 2;
            int newColon = 0;
            bool pass = true;
            while (newColon < line.length()) {
                newColon = line.find(";", colon);
                if (newColon == std::string::npos) newColon = line.length();
                std::string sample = line.substr(colon, newColon - colon);
                if (!checkSample(sample)) {
                    pass = false;
                    break;
                }
                
                colon = newColon + 2;
            }

            if (pass) ans += id;
        }
    } else {
        std::cout << "Could not open file";
    }
    
    std::cout << ans;
}