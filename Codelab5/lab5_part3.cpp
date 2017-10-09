// Given the column number of Excel spreadsheet, return the equivalent index 
#include <iostream>
#include <string>

using namespace std;

string Index(int number){
    string index="";
    while (number>0)
    {
        int remain = number % 26;
        if (remain == 0)
        {
            index += 'Z';
            number = (number/26)-1;
        }
        else 
        {
            index += (remain-1) + 'A';
            number = number/26;
        }
    }
    reverse(index.begin(),index.end());
    return index;
}

int main(){
    int number;
    cout << "Enter Column Number: ";
    cin >> number;
    cout << "Index = " << Index(number) << endl;
    return 0;
}