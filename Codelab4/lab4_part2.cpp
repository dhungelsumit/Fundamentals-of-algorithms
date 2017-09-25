// Postfix Notation
// Reference : http://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
// We are assuming that the numbers involved are all single digit numbers
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

// Return precedence of an operator
int Precedence(char op){
    switch(op){
        case '^': return 3;
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default : return -1;
    }
}

// Convert infix expression to postifix expression
string PostFix(string infix){
    string postfix;
    ArrayStack stack;
    for (int i=0; i<infix.length(); i++){
        // If ( , push it to stack
        if(infix[i] == '('){
            stack.Push('(');
        }
        // If ), pop and add to new string until next (
        else if(infix[i] == ')'){
            while(!stack.IsEmpty() && stack.Top() != '(')
            {
                char temp = stack.Top();
                stack.Pop();
                postfix = postfix + temp + " ";
            }
            if(stack.Top() == '(')
            {
                char temp = stack.Top();
                stack.Pop();
            }
        }
        // Operand
        else if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') ){
            postfix = postfix + infix[i] + " ";
        }
        // Operator
        else{
            while(!stack.IsEmpty() && (Precedence(infix[i]) <= Precedence(stack.Top())))
            {
                char temp = stack.Top();
                stack.Pop();
                postfix = postfix + temp + " ";
            }
            stack.Push(infix[i]);
        }
 
    }
    //Remaining Elements
    while (!stack.IsEmpty()){
        char temp = stack.Top();
        stack.Pop();
        postfix = postfix + temp + " ";
    }
    return postfix;
}

void PostFixTests(){
    string input;
    cout << "\n****** Postfix Notation ******\n";
    cout << "\nTEST 1\n";    
    input = "1+2";
    cout << endl;
    cout << "Input : " << input << endl;
    cout << "Expected : " <<  "1 2+" << endl;
    cout << "Output : " << PostFix(input) << endl;
    cout << "\nTEST 2\n";    
    input = "a+b*(c^d-e)^(f+g*h)-i";
    cout << endl;
    cout << "Input : " << input << endl;
    cout << "Expected : " <<  "abcd^e-fgh*+^*+i-" << endl;
    cout << "Output : " << PostFix(input) << endl;
    cout << "\nTEST 2\n";    
    input = "5+((1+2)*4)-3";
    cout << endl;
    cout << "Input : " << input << endl;    
    cout << "Expected : " <<  "5 1 2 + 4 * + 3 -" << endl;
    cout << "Output : " << PostFix(input) << endl;

}

int main(){
    PostFixTests();
    return 0;
}