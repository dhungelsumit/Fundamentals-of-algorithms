// Multiplication of two numbers using the naive approach.
// Time Complexitiy: O(n^2)
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Convert the integer into a vector where each member represent the digits of the number.
vector <int> CreateVector(int number){
  int remainder;
  stack <int> number_stack;
  while (number != 0 ){
    remainder = number % 10;
    number_stack.push(remainder);
    number = number/10;
  }
  vector <int> number_vector;
  while (!number_stack.empty()){
    number_vector.push_back(number_stack.top());
    number_stack.pop();
  }
  return number_vector;
}

// Multiply the vector by a certain number. Since each memeber of the vector represents the digits of a number,
// the result should be same as when a whole number is multiplied by another number.
int multiply(vector <int> first_vector , int number){
  int carry_over = 0;
  int result = 0;
  int product;
  int multiplier = 1;
  for (int i = first_vector.size()-1 ; i >=0 ; i--){
    product = number * first_vector[i];
    product += carry_over;
    int remainder;
    if (product > 9){
      remainder = product % 10;
      carry_over = product / 10;
      product = remainder;
    }
    else{
      carry_over = 0;
    }
    result = (product*multiplier) + result;
    multiplier *= 10;
  }
  if (carry_over != 0){
    result = (carry_over*multiplier)+result;
  }
  return result;
  
}

int main(){
  int first_number , second_number;
  cout << "Enter the first number: ";
  cin >> first_number;
  cout << "Enter the second number: ";
  cin >> second_number;
  vector <int> first_vector = CreateVector(first_number);
  vector <int> second_vector = CreateVector(second_number);
  int result;
  int multiplier = 1;
  for (int i = second_vector.size()-1 ; i >=0 ; i--){
    result = result + (multiply(first_vector , second_vector[i]) * multiplier);
    multiplier *= 10;
  }
  cout << endl;
  cout << "**** Using Naive Approach ****" << endl;
  cout << "The product is " << result;
  return 0;
}

/* Output: 
Enter the first number:  99999
Enter the second number:  99999

**** Using Naive Approach ****
The product is 1409865409 */


