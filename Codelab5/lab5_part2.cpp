//Given the index of Excel spreadsheet, return the equivalent column number

#include <iostream>
#include <string>

using namespace std;

int ColumnNumber(string index){
    int number = 0;
    for (int i = 0; i < index.size(); i++) {
        number = number * 26 + (index.at(i) - 'A' + 1);
    }
    return number;
}

int main(){
    string index;
    cout << "Enter desired index: ";
    cin >> index;
    cout << "Column Number = " << ColumnNumber(index) << endl;
    return 0;
}