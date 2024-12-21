#include <iostream>
#include <cstring>

int main() {
    int num;
    std::cout << "Введите целое число: ";
    std::cin >> num;

    unsigned char* ptr = reinterpret_cast<unsigned char*>(&num);

    size_t size = sizeof(num);
    std::cout << "Содержимое байтов числа " << num << ":" << std::endl;

    for (size_t i = 0; i < size; ++i) {
        std::cout << "Байт " << i << ": " << static_cast<int>(ptr[i])
        << " (0x" << std::hex << static_cast<int>(ptr[i]) << std::dec << ")" << std::endl;
    }

    unsigned char bytes[sizeof(num)];
    memcpy(bytes, &num, sizeof(num));
    std::cout << "Содержимое байтов числа " << num << " (memcpy):" << std::endl;
    for (size_t i = 0; i < sizeof(num); ++i) {
        std::cout << "Байт " << i << ": " << static_cast<int>(bytes[i])
        << " (0x" << std::hex << static_cast<int>(bytes[i]) << std::dec << ")" << std::endl;
    }

    return 0;
}