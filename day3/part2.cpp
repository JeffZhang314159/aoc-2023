#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int main() {
    std::ifstream input("input.txt");
    const int n = 140;
    if (input.is_open()) {
        std::string line;
        char engine[n][n];
        int i = 0;
        while (std::getline(input, line)) {
            for (int j = 0; j < line.length(); j++) {
                engine[i][j] = line.at(j);
            }
            i += 1;
        }
        
        int dirs[8][2] = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, 1},
            {1, 1},
            {1, 0},
            {1, -1},
            {0, -1}
        };

        std::map<std::pair<int, int>, std::vector<int>> gearParts;
        for (int i = 0; i < n; i++) {
            int curNum = 0;
            std::set<std::pair<int,int>> gears;
            for (int j = 0; j < n; j++) {
                if ('0' <= engine[i][j] && engine[i][j] <= '9') {
                    curNum = 10 * curNum + engine[i][j] - '0';
                    for (auto& [dr, dc] : dirs) {
                        int newRow = i + dr;
                        int newCol = j + dc;
                        if (0 <= newRow && newRow < n && 0 <= newCol && newCol < n && engine[newRow][newCol] == '*') {
                            gears.insert(std::pair<int,int>(newRow, newCol));
                        }
                    }
                } else {
                    for (auto& pair : gears) {
                        gearParts[pair].push_back(curNum);
                    }
                    curNum = 0;
                    gears.clear();
                }
            }
            for (auto& pair : gears) {
                gearParts[pair].push_back(curNum);
            }
        }
        int ans = 0;
        for (auto& [gear, parts] : gearParts) {
            //std::cout << gear.first << " " << gear.second << " " << parts.size() << "\n";
            if (parts.size() == 2) {
                ans += parts[0] * parts[1];
            }
        }

        std::cout << ans;
    } else {
        std::cout << "Could not open file";
    }

}