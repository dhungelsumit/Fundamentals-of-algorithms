// Implementation of Bubble Sort to sort input strings.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> BubbleSort(vector<string> unsorted_names){
  int vector_size = unsorted_names.size();
  for (int i = 1 ; i <= vector_size-1 ; i++){
    for (int j = 0 ; j<=vector_size-i-1 ; j++){
      if (unsorted_names[j] > unsorted_names[j+1]){
        swap(unsorted_names[j] , unsorted_names[j+1]);
      }
    }
  }
  return unsorted_names;
}

int main()
{
  int names_size;
  cout << "How many names would you like to sort? : ";
  cin >> names_size;
  vector <string> names;
  string single_name;
  for (int i=0 ; i<names_size ; i++){
    cout << "Enter the name: ";
    cin >> single_name;
    names.push_back(single_name);
  }
  cout << "\n\n****Printing Unsorted Names****\n";
  for (int i=0 ; i<names.size() ; i++){
    cout << names[i] <<" ";
  }
  vector <string> sorted_names = BubbleSort(names);
  cout << "\n\n****Printing Sorted Names****\n";
  for (int i=0 ; i<sorted_names.size() ; i++){
    cout << sorted_names[i] <<" ";
  }
  return 0;
}


