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

// Check if number represented by second string is greater than the first.
bool IsGreat(string first, string second){
  if (first.length() < second.length()){
    return true;
  }
  if (first.length() > second.length()){
    return false;
  }
  for(int i = 0; i < first.length(); i++){
    if (first[i] < second[i])
    { 
        return true; 
    }
    if(first[i] > second[i]){
      return false;
    }
  }
    return false;
}

// Merges the subarrays of the number.
void Merge(string *nth_array, string *temp, int start,int middle, int end)
{
int i = start;
int h = start;
int j = middle + 1;
while((h<=middle)&&(j<=end)) {
        if(!IsGreat(nth_array[j],nth_array[h])){
            temp[i]=nth_array[h];
            h++;
        }
        else{
            temp[i]=nth_array[j];
            j++;
        }
        i++;
    }
    // For remaining elements.
    if(h>middle){
        for(int k=j; k<=end; k++){
            temp[i]=nth_array[k];
            i++;
        }
    }
    else {
        for(int k=h; k<=middle; k++) {
            temp[i]=nth_array[k];
            i++;
        }
    }
    for(int k=start; k<=end; k++) {
      nth_array[k]=temp[k];
    }
}

// Sort the numbers using merge sort
void MergeSort(string *random_array, string *temp, int start, int end)
{
if (start >= end)
{
    return;
}   
int middle = (start + end)/2;
MergeSort(random_array, temp, start, middle);
MergeSort(random_array, temp, middle+1, end);
Merge(random_array, temp, start, middle, end);
}

int main()
{
  string *random_nth = new string[10];
  random_nth = RandomNthArray();
  string *temp = new string[10];
  MergeSort(random_nth, temp, 0, 9);
  cout << "***** Printing the array in sorted order *****" << endl;
  cout << endl;
  cout << "[";
  for(int i=0; i < 10; i++)
  {
      cout << random_nth[i];
      if (i != 9){
        cout << ",";
    }
  }
  cout << "]" << endl;  
  return 0;    
}