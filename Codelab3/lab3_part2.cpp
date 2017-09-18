// Program to generate look and say sequence
// https://en.wikipedia.org/wiki/Look-and-say_sequence

#include <iostream>
#include <map>
#include <string>
#include <sstream>


using namespace std;

// Function to find nth element of the look and say sequence.
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

// Return an array containing random numbers.
int *RandomArray(){
  srand(time(NULL)); 
  map <int , int> pushed_numbers;
  int *random_numbers = new int[10];
  int count = 0;
  while (count < 10){
    bool check = true;
    // Add a new random number to the array.
    do {
      int random_number = rand() % 10 + 5;
      if (pushed_numbers.find(random_number) == pushed_numbers.end()){
        random_numbers[count] = random_number;
        pushed_numbers[random_number] = 1;
        break;
      }
      else{
        check = false;
      }
    } while(!check);
  count++;
  }
  return random_numbers;
}

// Return random array with nth value of the series.
string *RandomNthArray(){
  srand(time(NULL)); 
  map <int , int> pushed_numbers;
  string *random_numbers = new string[10];
  int count = 0;
  while (count < 10){
    bool check = true;
    // Add a new random number to the array.
    do {
      int random_number = rand() % 10 + 5;
      if (pushed_numbers.find(random_number) == pushed_numbers.end()){
        random_numbers[count] = LookAndSay(random_number);
        pushed_numbers[random_number] = 1;
        break;
      }
      else{
        check = false;
      }
    } while(!check);
  count++;
  }
  return random_numbers;
}

int main(){
  int *random = new int[10];
  string *random_nth = new string[10];
  random = RandomArray();
  cout << "***** Printing the integer array *****" << endl;
  cout << endl;
  cout << "[ ";
  for (int i=0; i<10; i++){
    cout << random[i];
    if (i != 9){
        cout << ",";
    }
  }
  cout << "]" << endl;
  cout << endl;
  random_nth = RandomNthArray();
  cout << "***** Printing the array of nth numbers *****" << endl;
  cout << endl;
  cout << "[";
  for (int i=0; i<10; i++){
    cout << random_nth[i];
    if (i != 9){
        cout << ",";
    }
  }
  cout << "]" << endl;
  cout << endl;
  return 0;
  }