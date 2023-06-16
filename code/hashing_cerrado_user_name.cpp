#include <iostream>
#include <vector>
using namespace std;

enum EntryStatus {
    VACIO,
    OCUPADO,
    BORRADO
};

class HashTable {
private:
    static const int tableSize = 10;
    vector<pair<string, long> > table;
    vector<EntryStatus> status;

public:
    HashTable() {
        table.resize(tableSize);
        status.resize(tableSize, VACIO);
    }

    int hashFunction(const string& key) {
        uint32_t hash = 0;

            const char* str = key.c_str();
            int len = key.length();

            for (int i = 0; i < len; ++i) {
                hash = 31 * hash + static_cast<uint32_t>(str[i]);
    }

    return hash % tableSize;
    }

    int findEmptySlot(const string& key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] == OCUPADO && table[hashValue].first != key) {
            i++;
            hashValue = (hashValue + i) % tableSize;
        }

        return hashValue;
    }

    void insertItem(const string& key, long value) {
        int slot = findEmptySlot(key);
        table[slot] = make_pair(key, value);
        status[slot] = OCUPADO;
    }

    void removeItem(const string& key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] != VACIO) {
            if (status[hashValue] == OCUPADO && table[hashValue].first == key) {
                status[hashValue] = BORRADO;
                break;
            }

            i++;
            hashValue = (hashValue + i) % tableSize;
        }
    }

    long searchItem(const string& key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] != VACIO) {
            if (status[hashValue] == OCUPADO && table[hashValue].first == key) {
                return table[hashValue].second;
            }

            i++;
            hashValue = (hashValue + i) % tableSize;
        }

        return -1;  // Return -1 to indicate value not found
    }

    void displayTable() {
        for (int i = 0; i < tableSize; ++i) {
            cout << "Slot " << i << ": ";
            if (status[i] == OCUPADO) {
                cout << "[" << table[i].first << ", " << table[i].second << "]";
            } else if (status[i] == BORRADO) {
                cout << "<deleted>";
            } else {
                cout << "<empty>";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insertItem("John", 10);
    hashTable.insertItem("Jane", 20);
    hashTable.insertItem("Bob", 30);
    hashTable.insertItem("Alice", 40);
    hashTable.insertItem("Mike", 50);

    cout << "Initial table:" << endl;
    hashTable.displayTable();

    cout << endl;

    hashTable.removeItem("Jane");
    hashTable.removeItem("Alice");

    cout << "Table after removing items:" << endl;
    hashTable.displayTable();

    cout << endl;

    cout << "Searching for key 'John': " << hashTable.searchItem("John") << endl;

    cout << "Searching for key 'Suzy': " << hashTable.searchItem("Suzy") << endl;

    return 0;

};