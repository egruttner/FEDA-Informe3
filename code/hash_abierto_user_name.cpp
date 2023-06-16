#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    list<pair<string, long> > table[tableSize];

public:
    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % tableSize;
    }

    void insertItem(const string& key, long value) {
        int hashValue = hashFunction(key);
        table[hashValue].push_back(make_pair(key, value));
    }

    void removeItem(const string& key) {
        int hashValue = hashFunction(key);
        list<pair<string, long> >& bucket = table[hashValue];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                break;
            }
        }
    }

    long searchItem(const string& key) {
        int hashValue = hashFunction(key);
        list<pair<string, long> >& bucket = table[hashValue];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }

        return -1; // Indica que la clave no se encontró
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

    hashTable.insertItem("John", 123456789);
    hashTable.insertItem("Jane", 987654321);
    hashTable.insertItem("Bob", 555555555);
    hashTable.insertItem("Alice", 111111111);
    hashTable.insertItem("Mike", 999999999);

    cout << "Initial table:" << endl;
    hashTable.displayTable();

    cout << endl;

    hashTable.removeItem("Jane");
    hashTable.removeItem("Alice");

    cout << "Table after removing items:" << endl;
    hashTable.displayTable();

    cout << endl;

    cout << "Searching for key 'John': " << hashTable.searchItem("John") << endl;
    cout << "Searching for key 'Jane': " << hashTable.searchItem("Jane") << endl;

    return 0;
}
