#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <cmath>
using namespace std;

int main() {
    uint8_t curr = 50;
    uint16_t pass = 0;
    ifstream file("data/AoC_2025_1_1.txt");
    int16_t val;
    string line;
    int16_t rot;
    while (getline(file, line)){
        val = stoi(line.substr(1));
        if (line[0] == 'L') val = -val;
        rot = curr + val;
        pass -= (val < 0) && (curr == 0);
        pass += abs(rot)/100 + signbit(rot);
        curr = (rot + 1100) % 100; // positive mod
        pass += (rot == 0);
    }
    cout << pass << endl;
    return 0;
}
