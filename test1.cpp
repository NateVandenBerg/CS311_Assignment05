/**
 * This file tests the implementation of BST data structure
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "BST.h"
using namespace std;

/**
 * Test BST class using numbers from standard input
 */
int main() {
    // randomly sample a bunch of integers
    //srand(time(NULL));
    srand(1);
    unordered_set<int> nums;
    while(nums.size() < 100) {
        nums.insert((rand() % 10000) - 5000);
    }

    // create and populate BST
    BST bst;
    unsigned int count = 0;
    for(int num : nums) {
        bst.insert(num);
        //bst.printInorder(bst.getRoot());
        //cout << bst.size() << endl;
        if (bst.size() != ++count) {
            cout << "\n\nIncorrect tree size\n\n" << "inOrder: ";
            bst.printInorder(bst.getRoot());
            return 1;
        }
    }
    cout << "BST size1 = " << bst.size() << endl;

    // clear and repopulate BST
    bst.clear();
    cout << "BST size2 = " << bst.size() << endl;
    count = 0;
    for(int num : nums) {
        bst.insert(num);
        if(bst.size() != ++count) {
            cout << "Incorrect tree size" << endl;
            return 1;
        }
    }
    cout << "BST size3 = " << bst.size() << endl;

    cout << "\ncheck if numbers that should exist\n";
    for(int num : nums) {
        cout << "Checking if " << num << " exists" << endl;
        if(!bst.find(num)) {
            cout << "BST find returned false when element actually existed" << endl;
            return 1;
        } else {
            cout << "  BST find returned true" << endl;
        }
    }

    cout << "\ncheck numbers that shouldn't exist\n";
    for(int i = 0; i < 100; ++i) {
        int num = (rand() % 10000) - 5000;
        while(nums.find(num) != nums.end()) {
            num = (rand() % 10000) - 5000;
        }
        cout << "Checking if " << num << " exists" << endl;
        if(bst.find(num)) {
            cout << "BST find returned true when element didn't actually exist" << endl;
            return 1;
        } else {
            cout << "  BST find returned false" << endl;
        }
    }

    // if it didn't fail yet, success!
    cout << endl << "Success" << endl;
    return 0;
}
