typedef char itemType;//camelcase nota
#define stack_capacity 100


#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;

class stack
{
private:
    itemType myArray[stack_capacity];
    int myTop;
    int stacksize;
    int *stackArray;
public:
    stack();
    stack(int size);
    bool isempty();
    bool isfull();
    void push(itemType value);
    int top();
    itemType pop();
    void displaystack();
};

stack::stack(int size){
    stackArray = new int[size];
    stacksize = size;
    myTop = -1;
}
stack::stack(){
    myTop = -1;
}
bool stack::isfull(){
    if (myTop > stack_capacity - 1)
    {
        return true;
    }
    else return false;
}
itemType stack::pop(){
    if (myTop >= 0)
        return myArray[myTop--];
    else {
        cout << "Stack is empty";
        return -1;
    }
}
int stack::top(){
    if (myTop >= 0)
        return (myArray[myTop]);
    else
    {
        cout << "Stack is empty";
        return myArray[stack_capacity - 1];
    }
}
void stack::push(itemType value)
{
    if (myTop < stack_capacity - 1)
    {
        ++myTop;
        myArray[myTop] = value;
    }
    else
        cout << "stack is full" << endl;
}
bool stack::isempty(){
    if (myTop == -1)
        return true;
    else
        return false;
}
void stack::displaystack(){
    if (myTop >= 0) {
        cout << "Stack elements are:";
        for (int i = myTop; i >= 0; i--)
            cout << myArray[i] << " ";
    }
    else cout << "Stack is empty";
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


int main()
{
    stack s1;

    s1.push('N');
    string str= "2+3*6";
    int count = 0;
    string output;

    int op = 0, cp = 0;

    for (int i = 0; i < str.length(); i++)
    {
        /*

        */
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '0' && str[i] <= '9')
        {
            output += str[i];
        }
        else if (str[i] == '(')
        {
            s1.push('(');
        }
        else if (str[i] == ')')
        {
            while (s1.top() != 'N' && s1.top() != '(')
            {
                char y = s1.top();
                s1.pop();
                output += y;
            }
            if (s1.top() == '(')
            {
                char y = s1.top();
                s1.pop();
            }
        }
        else{
            while (s1.top() != 'N' && prec(str[i]) <= prec(s1.top()))
            {
                char y = s1.top();
                s1.pop();
                output += y;
            }
            s1.push(str[i]);
        }
    }
    while (s1.top() != 'N')
    {
        char y = s1.top();
        s1.pop();
        output += y;
    }
    cout << output << endl;


    _getch();
}

