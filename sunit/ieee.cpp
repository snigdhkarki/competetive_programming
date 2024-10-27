#include <iostream>

using namespace std;

#include <iostream>
#include <string>
#include <cmath>

double BinaryFractionToDecimal(const string& binaryStr) {
    double decimalValue = 0.0;

    // Iterate through each bit
    for (size_t i = 0; i < binaryStr.length(); ++i) {
        if (binaryStr[i] == '1') {
            // Add the value of 2^-(i+1) if the bit is 1
            decimalValue += pow(2, -(static_cast<int>(i) + 1));
        }
    }

    return decimalValue;
}

int main() {
    string binaryStr = "10010010000111111011011";

    double fractionValue = BinaryFractionToDecimal(binaryStr);

    cout << "Fractional decimal value: " << fractionValue << endl;

    return 0;
}