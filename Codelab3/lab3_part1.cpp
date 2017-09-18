// Program to generate look and say sequence and find nth element..
// https://en.wikipedia.org/wiki/Look-and-say_sequence

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to find nth element of the sequence.
string LookAndSay(int n){
    if (n == 0) {
      return "";
    }
    if (n == 1) {
      return "1";
    }
    string previous = "1";
    int counter = 1;
    while (counter < n) {
        string current = "";
        for (int i = 0; i < previous.length(); i++) {
            int count = 1;
             while ((i + 1 < previous.length()) && (previous[i] == previous[i + 1])){
                i++;
                count++;    
            }
            current += to_string(count) + previous[i];
        }
        previous = current;
        counter++;
    }
    return previous;
}


int main(){
  int number;
  string result;
  cout << "Enter the value of n";
  cin >> number;
  cout << endl;
  result = LookAndSay(number);
  cout << "The "<< number<<" number in the series is "<<result<<endl;
  return 0;
  }
