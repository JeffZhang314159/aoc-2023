#include <fstream>
#include <iostream>
#include <string>

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
        bool valid[n][n] = {}; // Initialize to all 0's.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (engine[i][j] >= '0' && engine[i][j] <= '9' || engine[i][j] == '.') continue;
                for (auto& [dr, dc] : dirs) {
                    int newRow = i + dr;
                    int newCol = j + dc;
                    if (0 <= newRow && newRow < n && 0 <= newCol && newCol < n) {
                        valid[newRow][newCol] = true;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curNum = 0;
            bool adj = false;
            for (int j = 0; j < n; j++) {
                if ('0' <= engine[i][j] && engine[i][j] <= '9') {
                    curNum = 10 * curNum + engine[i][j] - '0';
                    if (!adj && valid[i][j]) {
                        adj = true;
                    }
                } else {
                    if (adj) ans += curNum;
                    curNum = 0;
                    adj = false;
                }
            }
            if (adj) ans += curNum;
        }
        std::cout << ans;
    } else {
        std::cout << "Could not open file";
    }

}