#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
using namespace std;

// selfimposed challange to use only 1 byte since everything happens in mod
int main() {
    uint8_t curr = 50;
    uint16_t pass = 0;
    ifstream file("data/AoC_2025_1_1.txt");
    uint8_t val;
    char buffer[5];
    while (file.getline(buffer, sizeof(buffer))){
        uint8_t len = file.gcount()-1;
        char c1 = (len > 2) ? buffer[len-2] : '0';
        char c2 = buffer[len-1];
        val = (c1 - '0') * 10 + (c2 - '0');
        val = (buffer[0] == 'L') ? 100 - val : val;
        curr = (curr + val) % 100;
        if (curr == 0) pass++;
    }
    cout << pass << endl;
    return 0;
}
