#include "std_lib_facilities.h"
using namespace std;

// class for holding name-and-value pairs
class Pair {

    public:
        // attributes
        string name;
        int value;

        // constructor
        Pair(string basicString, int i) {
        this->name = basicString;
        this->value = i;
        }

};

int main() {

    string str;
    int val;
    vector<Pair> pairs;

    cout << "Enter names followed by integer values. Press enter to enter more names and values, and enter NoName and 0 to end.\n";

    // continue collecting input while we do not hit the value to stop at
    while (cin >> str >> val) {
        if (str == "NoName" && val == 0)
            break;

        // when each name is entered, traverse the vector for duplicate names
        for (int i = 0; i < pairs.size(); i++) {
            if (str == pairs[i].name) {
                cout << "The name entered is a duplicate.";
                return 0; // terminate the program when a duplicate name is entered
            }
        }

        // add it to the vector if it is not a duplicate
        pairs.push_back(Pair(str, val));
    }


    cout << "\nYou entered:\n";

    // print the elements in the vector
    for (Pair p : pairs)
        cout << "(" << p.name << ", " << p.value << ")\n";

    return 0;
}