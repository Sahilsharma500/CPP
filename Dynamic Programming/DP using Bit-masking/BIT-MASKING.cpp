#include<iostream>  // Includes the input-output stream library
using namespace std;

/*
    Bitmasking Basics:
    ------------------
    In bitmasking, we use bits of an integer to represent the presence or absence of elements in a set.
    For example, a 10-bit integer can represent a subset of {1, 2, 3, ..., 10}.
    
    Each bit position corresponds to one element:
        - 0th bit → element 1
        - 1st bit → element 2
        - ...
        - 9th bit → element 10

    If a bit is set (i.e., 1), that means the element is present in the set.
    If a bit is not set (i.e., 0), the element is absent.
*/


// Function to remove an element from the set
void remove(int &set, int ele) {
    /*
        set:  current set represented by an integer
        ele:  element to be removed from the set

        We use bitwise XOR here with (1 << (ele - 1)):

        (1 << (ele - 1)) gives a mask where only the bit at position (ele - 1) is set.
        XORing with this mask will flip that specific bit.
        
        ⚠️ Important: This toggle operation removes an element if it's already present.
        If it was absent, XOR will add it (i.e., it toggles the presence).
    */
    set = set ^ (1 << (ele - 1));
}


// Function to display elements present in the set
void display(int &set) {
    /*
        This function checks each bit position from 0 to 9.
        If the bit is set, it means the corresponding element is in the set.
    */
    cout << "Elements present in the set: ";
    for (int i = 0; i <= 9; i++) {
        if (set & (1 << i)) {
            // If the ith bit is set, output the corresponding element (i + 1)
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}


int main() {
    /*
        Let's initialize the set with the number 15.
        Binary of 15 → 0000001111
        This means elements {1, 2, 3, 4} are present (bits 0 to 3 are set).
    */
    int set = 15;

    // Removing element 2
    // Since 2 is currently present, it will be removed (bit toggled from 1 → 0)
    remove(set, 2);

    // Removing element 8
    // Since 8 is NOT present initially, it will be added (bit toggled from 0 → 1)
    remove(set, 8);

    // Display the resulting set
    display(set);

    return 0;
}
