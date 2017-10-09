//Given an array of integer type, return all the possible combinations of 2 numbers such that they add up to a specific target. 

#include <iostream>
#include <vector>

using namespace std;

// Assuming array of size 5.
int size = 5;

vector<vector<int> > Combination(int Numbers[size] , int target){
    vector<vector<int> > combo;
    for (int i = 0 ; i<size-1 ; i++){
        for (int j = i+1 ; j<size ; j++){
            if ((Numbers[i]+Numbers[j]) == target){
                vector<int> temp;
                temp.push_back(Numbers[i]);
                temp.push_back(Numbers[j]);
                combo.push_back(temp);
            }
        }
    }
    return combo;
}

int main(){
    int target = 9;
    int numbers[5] = {2,11,7,5,4};
    vector<vector<int> > combination = Combination(numbers , target);
    cout << "Array = [2,11,7,5,4]" << endl;
    for (int i = 0; i<combination.size(); i++){
        cout << combination[i][0] << " , " << combination[i][1] <<endl;
    }
    return 0;
}