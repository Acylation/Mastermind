#include <random>
#include <iostream>

void test() {
    std::random_device rd;
    std::cout << rd() << ", ";
    std::cout << rd() << ", ";
    std::cout << rd() << std::endl;
}

int main() {
    test();
    test();
    test();
    return 0;
}