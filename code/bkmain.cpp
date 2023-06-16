#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    list<pair<int, string> > table[tableSize];

public:
    int hashFunction(int key) {
        return key % tableSize;
    }

    void insertItem(int key, string value) {
        int hashValue = hashFunction(key);
        table[hashValue].push_back(make_pair(key, value));
    }

    void removeItem(int key) {
        int hashValue = hashFunction(key);
        list<pair<int, string> >& bucket = table[hashValue];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                break;
            }
        }
    }

    string searchItem(int key) {
        int hashValue = hashFunction(key);
        list<pair<int, string> >& bucket = table[hashValue];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }

        return "Key not found";
    }

    void displayTable() {
        for (int i = 0; i < tableSize; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& item : table[i]) {
                cout << "[" << item.first << ", " << item.second << "] ";
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
    hashTable.insertItem(21, "Alice");
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
