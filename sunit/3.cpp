#include <iostream>
#include <string>

int ans = 0;

std::string DivideByThree(const std::string& bigInt) {
    std::string result;  // To store the result of division
    int remainder = 0;   // To store the current remainder

    for (char digit : bigInt) {
        // Convert character to integer
        int currentDigit = digit - '0';
        
        // Update the current value by appending the current digit
        remainder = remainder * 10 + currentDigit;
        
        // Calculate the quotient for the current remainder divided by 3
        int quotient = remainder / 3;
        
        // Update the result string
        if (!result.empty() || quotient != 0) { // Avoid leading zeros
            result.push_back(quotient + '0');
        }
        
        // Update the remainder
        remainder %= 3;
    }

		ans = ans + 1;
		if (result == "1") {
			std::cout << ans << std::endl;
			exit(0);
		}
		if (remainder != 0) {
			std::cout << -1 << std::endl;
			exit(0);
		}
    // If result is empty, it means the result is 0
    if (result.empty()) {
        return "0";
    }

    return result;
}

int main() {
    std::string bigInt;
    std::cin >> bigInt;
		std::string result = bigInt;

		if (result == "1"){
			std::cout << 0 << std::endl;
			exit(0);
		}

		while (true) {
    	result = DivideByThree(result);
		}

    return 0;
}
