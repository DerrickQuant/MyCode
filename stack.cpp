#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int top = -1; // points to the most recent element in stack
    int arr[5];   // size of the stack

public:
    Stack(/* args */) // constructor
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0; // setting all indices of the stack to zero
        }
    };
    /*implementing standard functions associated with the stack*/
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int value)
    {
        if (isFull())
            cout << "stack is full" << endl; // stack overflow
        else
        {
            top++;            // we increase the top value to 0
            arr[top] = value; // we assing the value to index location 0
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty " << endl; // stack underflow
            return 0;
        }
        else
        {
            int popValue = arr[top]; // assing top value to pop value
            arr[top] = 0;            // make the index at top value =0
            top--;                   // decrease the top value by one so that it point to an index with a value
            return popValue;
        }
    }
    int count()
    {
        return top + 1; // the top is always going to be one less than number of stack elements
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "stack is empty " << endl;
            return 0;
        }
        else
            return arr[pos];
    }
    void change(int value, int pos)
    {
        arr[pos] = value;
        cout << "value changed at position " << pos << endl;
    }
    void display()
    {
        cout << "the elements in the stack are " << endl;
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << " " << endl;
        }
    }
};

int main()
{
    Stack s1;
    int option, position, value;
    do
    {
        cout << "what operation do you want to perform. Enter operation number. Enter 0 to exit " << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. is Empty()" << endl;
        cout << "4. is Full()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. clear screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;

        case 1 /* constant-expression */:
            cout << "enter an item to push in the stack" << endl;
            cin >> value;
            s1.push(value);
            /* code */
            break;
        case 2:

            cout << "your pop value is " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "stack is empty " << endl;
            else
                cout << "stack is not empty" << endl;
            break;
        case 4:
            if (s1.isFull())
                cout << "stack is full" << endl;
            cout << "stack is not full" << endl;
            break;
        case 5:
            cout << "enter the position of the item you want to peek" << endl;
            cin >> position;
            cout << "peak function called for index " << position << "value at peek position is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Number of values in the stack is " << s1.count() << endl;
            break;
        case 7:
            cout << "enter index of change and enter value to be inserted " << endl;
            cin >> position;
            cin >> value;
            s1.change(value, position);
            cout << "value at index " << position << " changed to " << value << endl;
            break;
        case 8:
            cout << "display function called" << endl;
            s1.display();
            break;

        default:
            cout << "enter proper option number" << endl;
            break;
        }

        /* code */
    } while (option != 0);
    return 0;
}