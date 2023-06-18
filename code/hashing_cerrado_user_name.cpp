#include <iostream>
#include <vector>
using namespace std;

enum EntryStatus {
    VACIO,
    OCUPADO,
    BORRADO
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