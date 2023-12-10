#include <fstream>
#include <iostream>
#include <string>
#include <set>

const int start = 10;

int main(int argc, char *argv[]) {
    std::ifstream input(argv[1]);

    if (input.is_open()) {
        std::string line;
        int answer = 0;
        while (std::getline(input, line)) {
            int divide = line.find("|");
            std::set<int> winning;
            for (int i = start; i < divide; i += 3) {
                int num = std::stoi(line.substr(i, 2));
                winning.insert(num);
            }
            
            int count = 0;
            for (int i = divide + 2; i < line.length(); i += 3) {
                int num = std::stoi(line.substr(i, 2));
                if (winning.contains(num)) count++;
            }
            answer += 1 << (count - 1);
        }
        std::cout << answer;
    } else {
        std::cout << "Failed to open file";
    }
}