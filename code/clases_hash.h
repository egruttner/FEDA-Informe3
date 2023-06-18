#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum EntryStatus {
    VACIO,
    OCUPADO,
    BORRADO
};

const int tableSizeAbierto = 10000;  
const int tableSizeCerrado = 30000;  


class HashTableCerradoUser_Id {
private:
    vector<pair<long, string> > table;
    vector<EntryStatus> status;

public:
    HashTableCerradoUser_Id() {
        table.resize(tableSizeCerrado);
        status.resize(tableSizeCerrado, VACIO);
    }

    int hashFunction(long key) {
        return key % tableSizeCerrado;
    }

    int findEmptySlot(long key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] == OCUPADO && table[hashValue].first != key) {
            i++;
            hashValue = (hashValue + i) % tableSizeCerrado;
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
            hashValue = (hashValue + i) % tableSizeCerrado;
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
            hashValue = (hashValue + i) % tableSizeCerrado;
        }

        return "No encontrado";
    }

    void displayTable() {
        for (int i = 0; i < tableSizeCerrado; ++i) {
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

class HashTableCerradoUser_Name {
private:
    vector<pair<string, long> > table;
    vector<EntryStatus> status;

public:
    HashTableCerradoUser_Name() {
        table.resize(tableSizeCerrado);
        status.resize(tableSizeCerrado, VACIO);
    }

    int hashFunction(const string& key) {
        uint32_t hash = 0;
        const char* str = key.c_str();
        int len = key.length();

        for (int i = 0; i < len; ++i) 
        {
            hash = 31 * hash + static_cast<uint32_t>(str[i]);
        }
        return hash % tableSizeCerrado;
    }

    int findEmptySlot(const string& key) {
        int hashValue = hashFunction(key);
        int i = 0;

        while (status[hashValue] == OCUPADO && table[hashValue].first != key) {
            i++;
            hashValue = (hashValue + i) % tableSizeCerrado;
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
            hashValue = (hashValue + i) % tableSizeCerrado;
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
            hashValue = (hashValue + i) % tableSizeCerrado;
        }

        return -1;  // -1 -> No encontrado
    }

    void displayTable() {
        for (int i = 0; i < tableSizeCerrado; ++i) {
            cout << "Slot " << i << ": ";
            if (status[i] == OCUPADO) {
                cout << "[" << table[i].first << ", " << table[i].second << "]";
            } else if (status[i] == BORRADO) {
                cout << "<borrado>";
            } else {
                cout << "<vacío>";
            }
            cout << endl;
        }
    }
};

class HashTableAbiertoUser_Id {
private:
    list<pair<long, string> > table[tableSizeAbierto];

public:
    int hashFunction(long key) {
        return key % tableSizeAbierto;
    }

    void insertItem(long key, string value) {
        int hashValue = hashFunction(key);
        table[hashValue].push_back(make_pair(key, value));
    }

    string searchItem(long key) {
        int hashValue = hashFunction(key);
        list<pair<long, string> >& bucket = table[hashValue];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }

        return " NO ENCONTRADO ";
    }

    void displayTable() {
        for (int i = 0; i < tableSizeAbierto; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& item : table[i]) {
                cout << "[" << item.first << ", " << item.second << "] ";
            }
            cout << endl;
        }
    }
};

class HashTableAbiertoUser_Name {
private:
    list<pair<string, long> > table[tableSizeAbierto];

public:
    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % tableSizeAbierto;
    }

    void insertItem(const string& key, long value) {
        int hashValue = hashFunction(key);
        table[hashValue].push_back(make_pair(key, value));
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
        for (int i = 0; i < tableSizeAbierto; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& item : table[i]) {
                cout << "[" << item.first << ", " << item.second << "] ";
            }
            cout << endl;
        }
    }
};