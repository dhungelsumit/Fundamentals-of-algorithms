/** Implement a dynamic programming solution that provides the optimal "pretty printing" text layout that optimizes the provided cost function. 
 * References:
 * http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/
 * https://www.youtube.com/watch?v=RORuwHiblPc&t=822s
 */

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/* Split a  sentence into vectors containing different strings. */ 
vector<string> Split(string sentence, string delimiter){
    vector<string> list;
    size_t pos = 0;
    string token;
    while ((pos = sentence.find(delimiter)) != string::npos) {
        token = sentence.substr(0, pos);
        list.push_back(token);
        sentence.erase(0, pos + delimiter.length());
    }
    // If some element is still remaining in sentence.
    if (sentence.length() >0){
        list.push_back(sentence);
    }
    return list;
}

// Separate out all the words from the text file
vector<string> AllWords(int max_length){
    ifstream inFile;//input text
    inFile.open("input_text.txt");//opening the input text
    if (inFile.fail()) {
		cout << "Problem opening file: " << endl;
		exit(1);
	}
    string temp_word = "";
    string temp_sentence ="";
    int word_len = 0;
    int line_len = 0;
    int counter = 0;
    vector <string> all_words;
    while(!inFile.eof()){
        getline(inFile, temp_sentence);
        counter++;
        // Splitting a line into various words.
        vector <string> word_list = Split(temp_sentence, " ");
        for(int i = 0; i < word_list.size(); i++){
            temp_word = word_list[i];
            word_len = temp_word.length();
             // If the length of word is greater than the maximum length of line.
             if (word_len > max_length){
                cout << "Error: The file contain very long word. Please remove it "<<endl;
                exit(1);
            }
            all_words.push_back(temp_word);
    }
    }
    return all_words;
}

void WordWrap(int max_length){
    vector <string> words = AllWords(max_length);
    // (M - l​1​)​^2​ + (M - l​2​)​^2​ + ... + (M - l​(k-1​))​^2​ . 
    int cost[words.size()][words.size()];
    // Calculating cost
    for(int i=0 ; i < words.size(); i++){
        // Max Length minus length of the word ( M - l(n))
        cost[i][i] = max_length - words[i].length();
        for(int j=i+1; j < words.size(); j++){
            cost[i][j] = cost[i][j-1] - words[j].length() - 1; 
        }
    }
    for(int i=0; i < words.size(); i++){
        for(int j=i; j < words.size(); j++){
            if(cost[i][j] < 0){
                // If word doesn't fit one line, add maximum integer value
                cost[i][j] = INT_MAX;
            }else{
                cost[i][j] = pow(cost[i][j], 2);
            }
        }
    }
    int minimum_cost[words.size()];
    int result[words.size()];
    // Finding minimum cost
    for(int i = words.size()-1; i >= 0 ; i--){
        minimum_cost[i] = cost[i][words.size()-1];
        result[i] = words.size();
        for(int j=words.size()-1; j > i; j--){
            if(cost[i][j-1] == INT_MAX){
                continue;
            }
            if(minimum_cost[i] > minimum_cost[j] + cost[i][j-1]){
                minimum_cost[i] = minimum_cost[j] + cost[i][j-1];
                result[i] = j;
            }
        }
    }
    int i = 0;
    int j;
    ofstream outFile;//output text
    outFile.open ("output_text.txt");//opening the output text
    do{
        j = result[i];
        for(int k=i; k < j; k++){
            outFile << words[k];
            outFile <<  " ";
        }
        outFile << "\n";
        i = j;
    }while(j < words.size());
}

int main(){
    int max_length;
    cout << "Enter the maximum length of each line (maximum character possible)" << endl;
    cin >> max_length;
    WordWrap(max_length);
    return 0;
}