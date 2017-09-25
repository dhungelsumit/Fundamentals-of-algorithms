#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Implement a Last In First Out (LIFO) data structure
class ArrayStack
{
private:
    int top;
    int size;
    vector <char> stack;
public:
    ArrayStack(){
        top = -1;
    }

    // Adds element x at the top of the stack
    void Push(char element){
        stack.push_back(element);
        top++;
        size++;

    }

    // Removes and returns element at top of the stack
    char Pop(){
        char temp = stack[top];
        stack.erase(stack.begin()+top);
        top--;
        size--;
        return temp;
    }

    // Returns (but doesn't remove) element at top of stack
    char Top(){
        return stack[top];
    }

    //  Returns True if the stack is empty
    bool IsEmpty(){
        return (top == -1);
    }
    
    //  Returns the number of items in the stack
    int len(){
        return size;
    }
};

// Implement a First In First Out (FIFO) data structure
class ArrayQueue
{
private:
    int back;
    int size;
    vector <char> queue;
public:
    ArrayQueue(){
        back = -1;
    }

    // Adds element x at the back of the queue
    void Enqueue(char element){
        queue.push_back(element);
        back++;
        size++;

    }

    // Removes and returns element at front of the queue
    char Dequeue(){
        char temp = queue[0];
        queue.erase(queue.begin());
        back--;
        size--;
        return temp;
    }

    // Returns (but doesn't remove) element at front of queue
    char First(){
        return queue[0];
    }

    // Returns True if the queue is empty
    bool IsEmpty(){
        return (back == -1);
    }
    
    //  Returns the number of items in the queue
    int len(){
        return size;
    }
};

// Check if the entered string is palindrome
bool isPalindrome(string input){
    int string_length;    
    string_length = input.length();
    ArrayStack  stack;
    ArrayQueue queue;
    for (int i=0; i<string_length; i++){
        char temp = tolower(input[i]);
        int ascii = int(temp);
        if ((ascii >= 97) && (ascii <= 122)){
            stack.Push(temp);
            queue.Enqueue(temp);
        }
    }
    while (!queue.IsEmpty() || !stack.IsEmpty()){
        if (queue.Dequeue() != stack.Pop()){
            return false;
        }
    }
return true;
}

int main(){
    string input;
    cout << "Enter a word : ";
    cin >> input;
    bool result = isPalindrome (input);
    if (result){
        cout << "It is palindrome" << endl;
    } else {
        cout << "It is not palindrome" << endl;
    }
    return 0;
}