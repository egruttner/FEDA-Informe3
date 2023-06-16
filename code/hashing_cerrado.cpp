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
    vector<pair<long, string> > table;
    vector<EntryStatus> status;

public:
    HashTable() {
        table.resize(tableSize);
        status.resize(tableSize, VACIO);
    }

    int hashFunction(long key) {
        return key % tableSize;
    }

    int findEmptySlot(long key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] == OCUPADO && table[hashValue].first != key) {
            i++;
            hashValue = (hashValue + i) % tableSize;
        }

        return hashValue;
    }

    void insertItem(long key, string value) {
        int slot = findEmptySlot(key);
        table[slot] = make_pair(key, value);
        status[slot] = OCUPADO;
    }

    void removeItem(long key) {
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

    string searchItem(long key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] != VACIO) {
            if (status[hashValue] == OCUPADO && table[hashValue].first == key) {
                return table[hashValue].second;
            }

            i++;
            hashValue = (hashValue + i) % tableSize;
        }

        return "Key not found";
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

    hashTable.insertItem(1, "John");
    hashTable.insertItem(11, "Jane");
    hashTable.insertItem(21, "Bob");
    hashTable.insertItem(2, "Alice");
    hashTable.insertItem(12, "Mike");

    cout << "Initial table:" << endl;
    hashTable.displayTable();

    cout << endl;

    hashTable.removeItem(11);
    hashTable.removeItem(2);

    cout << "Table after removing items:" << endl;
    hashTable.displayTable();

    cout << endl;

    cout << "Searching for key 1: " << hashTable.searchItem(1) << endl;
    cout << "Searching for key 11: " << hashTable.searchItem(11) << endl;

    return 0;
}
