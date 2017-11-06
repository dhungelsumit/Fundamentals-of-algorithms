//Process the provided input text below and lay it out in lines of a specified maximum length.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/* Split a  sentence into vectors containing different strings. */ 
vector<string> split(string sentence, string delimiter){
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

void greedy(int max_length){
    ifstream inFile;//input text
    inFile.open("input_text.txt");//opening the input text
    if (inFile.fail()) {
		cout << "Problem opening file: " << endl;
		exit(1);
	}
    ofstream outFile;//output text
    outFile.open ("output_text.txt");//opening the output text
    string temp_word = "";
    string temp_sentence ="";
    int word_len = 0;
    int line_len = 0;
    int counter = 0;
    while(!inFile.eof()){
        getline(inFile, temp_sentence);
        counter++;
        // Splitting a line into various words.
        vector <string> word_list = split(temp_sentence, " ");
        for(int i = 0; i < word_list.size(); i++){
            temp_word = word_list[i];
            word_len = temp_word.length();
            line_len += word_len;
             // If the length of word is greater than the maximum length of line.
             if (word_len > max_length){
                cout << "Error: The file contain very long word. Please remove it "<<endl;
                exit(1);
            }
            if (line_len > max_length){
                outFile << "\n";
                line_len = word_len;
                outFile << temp_word;
                line_len++;
                outFile <<" ";                
             }
             else{
                outFile << temp_word;
                line_len += 1;
                outFile <<" ";
             }
    }
    line_len = 0;
    word_len = 0;
        // Change of paragraph.
        if (counter > 1){
            outFile << "\n";
        }
    }

}

int main(){
    int max_length;
    cout << "Enter the maximum length of each line (maximum character possible)" << endl;
    cin >> max_length;
    greedy(max_length);
    return 0;
}