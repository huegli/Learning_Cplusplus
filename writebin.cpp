#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX_PATH 255

int get_int(int default_value);

int main () {
    char filename[MAX_PATH + 1];
    int n = 0;
    char name[20];
    int age = 0;
    int recsize = sizeof(name) + sizeof(int);

    cout << "Enter file name: ";
    cin.getline(filename, MAX_PATH);

    // Open file for binary write.
    fstream fbin(filename, ios::binary | ios::out);
    if (!fbin) {
        cout << "could not open " << filename << endl;
        return -1;
    }

    // Get record number to write to.
    cout << "Enter file record number: ";
    n = get_int(0);

    // Get data from end user

    cout << "Enter name: ";
    cin.getline(name, sizeof(name) - 1);
    cout << "Enter age: ";
    age = get_int(0);

    // Write data to the file.

    fbin.seekp(n * recsize);
    fbin.write(name, sizeof(name) - 1);
    fbin.write((char *)(&age), sizeof(int));
    fbin.close();
    return 0;
}

#define COL_WIDTH 80    // 80 is typical column width

// Get integer function
// Get an integer from keyboard; return default
// value if user enters 0-length string.
//
int get_int(int default_value) {
    char s[COL_WIDTH + 1];

    cin.getline(s, COL_WIDTH);
    if (strlen(s)==0)
        return default_value;
    return atoi(s);
}