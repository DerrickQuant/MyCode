#include <iostream>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int arr[5];
    /* data */
public:
    Queue(/* args */)
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    };
    bool isEmpty() // isn't it obvious what this does
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull() // this is self explanatory
    {
        if (rear == 4)
            return true;
        else
            return false;
    }
    void enqueue(int val) // values enter the queue via the rear variable
    {
        if (isFull())
            cout << "Queue cannot accept any more elements" << endl;
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
            rear++;
        arr[rear] = val;
    }

    int dequeue() // values leave the queue via the front variable
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            int x = arr[front];
            arr[front] = 0;
            front = -1;
            rear = -1;
            return x;
        }

        else
        {
            int x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }

        //
        // front = rear = -1;
    }
    int count()
    {
        return (rear - front + 1);
    }
    void display()
    {
        cout << "the elements in the queue are " << endl;
        for (int i = 5; i >= 0; i--)
        {
            cout << arr[i] << " " << endl;
        }
    }
};
int main()

{
    Queue q1;
    int option, value;
    do
    {
        cout << "what operation do you want to perform. Enter operation number. Enter 0 to exit " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. is Empty()" << endl;
        cout << "4. is Full()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            break;

        case 1 /* constant-expression */:
            cout << "enter a value to enque" << endl;
            cin >> value;
            q1.enqueue(value);
            /* code */
            break;
        case 2:

            cout << "your  Dequeued value is " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "queue is empty " << endl;
            else
                cout << "queue is not empty" << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << "queue is full" << endl;
            cout << "queue is not full" << endl;
            break;
        case 5:
            cout << "Number of items in the queue is " << q1.count() << endl;
            break;

        case 6:
            cout << "display function called" << endl;
            q1.display();
            break;

        default:
            cout << "enter proper option number" << endl;
            break;
        }

        /* code */
    } while (option != 0);
    return 0;
}