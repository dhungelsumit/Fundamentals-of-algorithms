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

// Check if  a character is an operator
bool IsOperator(char check){
    if (check == '/' || check == '+' || check == '*' || check == '-'|| check == '^'){
        return true;
    }
    return false;
}

// Perform operation on operands
int PerformOperation(char operation, int operand1, int operand2) 
{
	switch(operation){
        case '+':return operand1 + operand2;
        case '-':return operand1 - operand2;
	    case '*':return operand1 * operand2;
	    case '/':return operand1 / operand2;
        default:cout << "Unexpected Error \n";return -1;
    }
}

// Calculate the value of the expression
int CalculatPostfix(string postfix)
{
	ArrayStack stack;
	for (int i = 0; i< postfix.length(); i++) 
	{
		if (postfix[i]== ' ' || postfix[i] == ',')
		{
			continue;
		}
		else if (IsOperator(postfix[i])) 
		{
			int second_operand = stack.Pop();
			int first_operand = stack.Pop();
			int value = PerformOperation(postfix[i], first_operand, second_operand);
			stack.Push(value);
		}
		else if (isdigit(postfix[i])) 
		{
			int operand = 0;
			while (i<postfix.length() && isdigit(postfix[i])) 
			{
				operand = (operand * 10) + (postfix[i] - '0');
				i++;
			}
			i--;
			stack.Push(operand);
		}
	}
	return stack.Top();
}

// Convert infix expression to postifix expression
string PostFix(string infix){
    string postfix="";
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
    string input1 ="" , input2="", input3="";
    cout << "\n****** Postfix Notation ******\n";
    cout << "\nTEST 1\n";    
    input1 = "1+2";
    cout << endl;
    cout << "Input : " << input1 << endl;
    cout << "Expected : " <<  "1 2+" << endl;
    cout << "Output : " << PostFix(input1) << " , " << CalculatPostfix(PostFix(input1)) << endl;
    cout << "\nTEST 2\n";    
    input2 = "a+b*(c^d-e)^(f+g*h)-i";
    cout << endl;
    cout << "Input : " << input2 << endl;
    cout << "Expected : " <<  "abcd^e-fgh*+^*+i-" << endl;
    cout << "Output : " << PostFix(input2) << endl;
    cout << "\nTEST 2\n";    
    input3 = "5+((1+2)*4)-3";
    cout << endl;
    cout << "Input : " << input3 << endl;    
    cout << "Expected : " <<  "5 1 2 + 4 * + 3 -" << endl;
    cout << "Output : " << PostFix(input3) << " , " << CalculatPostfix(PostFix(input3)) <<endl;

}

int main(){
    PostFixTests();    
    return 0;
}