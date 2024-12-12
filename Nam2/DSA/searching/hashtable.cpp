#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    std::vector<std::list<std::pair<int, int>>> table;
    int P; // Kích thước của bảng băm

    int getHash(int key) {
        return key % P;
    }

public:
    HashTable(int size) : P(size) {
        table.resize(P);
    }

    void insert(int key, int value) {
        int hkey = getHash(key);
        for (auto &p : table[hkey]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);
        for (auto &p : table[hkey]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1; // Không tìm thấy
    }

    void remove(int key) {
        int hkey = getHash(key);
        table[hkey].remove_if([key](const std::pair<int, int> &p) { return p.first == key; });
    }
};

int main() {
    HashTable ht(10);
    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(11, 300);

    std::cout << "Value for key 1: " << ht.find(1) << std::endl;
    std::cout << "Value for key 2: " << ht.find(2) << std::endl;
    std::cout << "Value for key 11: " << ht.find(11) << std::endl;

    ht.remove(1);
    std::cout << "Value for key 1 after removal: " << ht.find(1) << std::endl;

    return 0;
}