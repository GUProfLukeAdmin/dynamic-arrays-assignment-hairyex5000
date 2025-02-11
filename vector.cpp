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
    std::vector<char> vecs1 = std::vector<char>(10000);
    std::vector<bool> vecs2 = std::vector<bool>(10000);
    std::cout << "Memory usage of std::vector<bool>: " << (vecs2.capacity() / 8) << " bytes" << std::endl;
    std::cout << "Memory usage of std::vector<char>: " << (vecs1.size() * sizeof('a')) << " bytes" << std::endl;
}

int main() {
    part1();
    part2();
    return 0;
}