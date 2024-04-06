#include <iostream>
#include <string>

// Function to perform bit stuffing
std::string bitStuffing(const std::string& data) {
    std::string stuffedData;
    int count = 0;
    for (char bit : data) {
        stuffedData += bit;
        if (bit == '1') {
            count++;
            if (count == 5) {
                stuffedData += '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return stuffedData;
}

// Function to perform bit destuffing
std::string bitDestuffing(const std::string& stuffedData) {
    std::string destuffedData;
    int count = 0;
    for (char bit : stuffedData) {
        destuffedData += bit;
        if (bit == '1') {
            count++;
            if (count == 5) {
                // Skip the next bit
                destuffedData.pop_back();
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return destuffedData;
}

int main() {
    std::string data = "01111110"; // Example data with flag sequence
    std::string stuffedData = bitStuffing(data);
    std::string destuffedData = bitDestuffing(stuffedData);

    std::cout << "Original Data: " << data << std::endl;
    std::cout << "Stuffed Data: " << stuffedData << std::endl;
    std::cout << "Destuffed Data: " << destuffedData << std::endl;

    return 0;
}
