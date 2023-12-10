#include <fstream>
#include <iostream>
#include <string>
#include <set>

const int start = 10;
const int n = 216;

int main(int argc, char *argv[]) {
    std::ifstream input(argv[1]);

    if (input.is_open()) {
        std::string line;
        int matching[n];
        int lineNum = 0;
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
            matching[lineNum] = count;
            lineNum += 1;
        }
        
        int total[n] = {};
        for (int i = n - 1; i >= 0; i--) {
            total[i] = 1;
            for (int j = 1; j <= matching[i] && i + j < n; j++) {
                total[i] += total[i + j];
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer += total[i];
        }
        std::cout << answer;
    } else {
        std::cout << "Failed to open file";
    }
}