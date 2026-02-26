#include <iostream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

vector<string> input_array_format() {
    vector<string> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string c;
    while (ss >> c) {
        // if (isalpha(c)) {
            // string element;
            // ss >> element;
            arr.push_back(c);
        // }
    }
    return arr;
}

vector<string> input_space_separated() {
    vector<string> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string element;
    while (ss >> element) {
        arr.push_back(element);
    }
    return arr;
}

vector<string> input_array_size_not_given() {
    vector<string> arr;
    string input;
    cout << "Enter array elements (press Enter after each element, press Enter twice to stop):" << endl;
    while (getline(cin, input)) {
        
        
        if (input.empty()) {
            break;
        }
        arr.push_back(input);
    }
    return arr;
}



vector<string> input_universal_string_array() {
    vector<string> arr;
    string input;

    // Read a full line of input
    getline(cin, input);

    // Replace commas with spaces, so "a,b,c" -> "a b c"
    replace(input.begin(), input.end(), ',', ' ');

    // Create stringstream to read tokens
    stringstream ss(input);
    string token;
    while (ss >> token) {
        arr.push_back(token);
    }

    return arr;
}


int main() {
 
    //  // Case 1: ['A', 'B', 'C', 'D']
    // cout << "Case 1: ['A', 'B', 'C', 'D']" << endl;
    // vector<string> arr1 = input_array_format();
    // for (const string& element : arr1) {
    //     cout << element << " ";
    // }
    // cout << endl;

    // // Case 2: A B C D
    // cout << "Case 2: A B C D" << endl;
    // vector<string> arr2 = input_space_separated();
    // for (const string& element : arr2) {
    //     cout << element << " ";
    // }
    // cout << endl;

    // Case with size not given
    cout << "Case with size not given" << endl;
    vector<string> arr3 = input_array_size_not_given();
    for (const string& element : arr3) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}