#include <vector>
#include <iostream>
#include <climits>
#include <cstdint>

void part1() {
    std::vector<int> vecs = std::vector<int>();
    for (int i = 0; i < 50000; i++)
    {
        vecs.push_back(rand());
    }
    int sizeFirst = size(vecs);
    int capFirst = vecs.capacity();
    vecs.resize(size(vecs) / 2);
    int sizeSecond = size(vecs);
    int capSecond = vecs.capacity();
    vecs.shrink_to_fit();
    int sizeThird = size(vecs);
    int capThird = vecs.capacity();

    std::cout << "After adding elements: Size = " << sizeFirst << ", Capacity = " << capFirst << std::endl;
    std::cout << "After resizing: Size = " << sizeSecond << ", Capacity = " << capSecond << std::endl;
    std::cout << "After shrink_to_fit(): Size = " << sizeThird<< ", Capacity = " << capThird << std::endl;
}

void part2() {
    std::vector<char> vecs1 = std::vector<char>();
    std::vector<bool> vecs2 = std::vector<bool>();
    for (int i = 0; i < 10000; i++)
    {
        vecs1.push_back((char)('a' + (int)(rand()/(INT32_MAX / 24))));
        vecs2.push_back((bool)(rand()/(INT32_MAX / 2)));
    }

    std::cout << "Memory usage of std::vector<bool>: " << sizeof(vecs2) + (((int) sizeof(bool)) * vecs2.capacity()) << " bytes" << std::endl;
    std::cout << "Memory usage of std::vector<char>: " << sizeof(vecs1) + (((int) sizeof('a')) * vecs1.capacity()) << " bytes" << std::endl;
}

int main() {
    part1();
    part2();
    return 0;
}