#include<iostream>
using namespace std;
class Queue{
    int *a;
    int n;
    int cs;
    int f;
    int e;
    public:
    Queue(int s){
        n=s;
        a=new int[s];
        cs=0;
        f=0;
        e=n-1;
    }
    void push(int d){
        if(cs<n){
            e=(e+1)%n;
            a[e]=d;
            cs++;
        }
        else{
            cout<<"Overflow\n";
        }
    }
    void pop(){
        if(cs>0){
            f=(f+1)%n;
            cs--;
        }
        else{
            cout<<"Underflow\n";
        }
    }
    int front(){
        return a[f];
    }

    int rear(){
        return a[e];
    }

    bool isEmpty(){
        return cs==0;

    }
};

int main() {
    int choice;
    Queue myQueue(5); // Creating a queue with a capacity of 5

    while (true) {
        cout << "Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Get Front" << endl;
        cout << "4. Get Rear" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int item;
                cout << "Enter the element to push into Queue: ";
                cin >> item;
                myQueue.push(item);
                break;
            case 2:
                myQueue.pop();
                break;
            case 3:
                cout << "Front element: " << myQueue.front() << endl;
                break;
            case 4:
                cout << "Rear element: " << myQueue.rear() << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

//     Queue q(5);
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     while(! q.isEmpty()){
//         cout<<q.front()<<endl;
//     }
// return 0;
// }