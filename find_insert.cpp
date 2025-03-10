#include <iostream>
#include <unordered_set>
#include <string>
using namespace std; 

int main() {
    unordered_set<string> database;
    
    // Read the keys and insert them into the database
    string key;
    while (cin >> key && key != "*") {
        database.insert(key);
    }
    
    // Process the actions
    string command, target;
    while (cin >> command >> target && command != "*") {
        if (command == "find") {
            if (database.count(target)) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (command == "insert") {
            if (database.count(target)) {
                cout << "0" << endl;
            } else {
                database.insert(target);
                cout << "1" << endl;
            }
        }
    }
    
    return 0;}
