//Given an array of integer type, return all the possible combinations of 2 numbers such that they add up to a specific target. 
//Use Hashmap/ dictionary

#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

// Assuming array of size 5.
int size = 5;

vector<vector<int> > Combination(int Numbers[size] , int target){
    vector<vector<int> > combo;
    map <int, int> numbers;
    for (int i = 0 ; i<size ; i++){
        if (numbers.find(Numbers[i]) == numbers.end()){
            numbers.insert(pair <int, int> (Numbers[i], 1));            
        }
    }
    for (int i = 0 ; i<size ; i++){
        if ((numbers.find(Numbers[i]) != numbers.end()) && (numbers.find(target-Numbers[i]) != numbers.end())){
            vector<int> temp;
            temp.push_back(Numbers[i]);
            temp.push_back(target - Numbers[i]);
            combo.push_back(temp);     
            numbers.erase(Numbers[i]);
            numbers.erase(target - Numbers[i]);
        }
    }
    return combo;
}

int main(){
    int target = 9;
    int numbers[5] = {2,11,7,5,4};
    vector<vector<int> > combination = Combination(numbers , target);
    cout << "Using Hash Map" << endl;
    cout << "Array = [2,11,7,5,4]" << endl;
    for (int i = 0; i<combination.size(); i++){
        cout << combination[i][0] << " , " << combination[i][1] <<endl;

    }

}