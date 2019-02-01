#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class Queue
{
    public:
    Node* front;//front is a node type pointer to the first element of the queue
    Node* end;//end is a node type pointer to the last element of the queue
    public:
    Queue()//default constructor
    {
        front=NULL;//initializes front to null
        end=NULL;//initialized end to null
    }
    void enquene(int value)//function to enqueue an element
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the queue is empty
        {
            front=ptr;//the first element is added
            end=ptr;
        }
        else
        {
            end->next=ptr;//ptr to enqueued at the end of the queue
            end=ptr;//the pointer end points to the new node which is the last node now
        }
        cout<<value<<" has been inserted in the Queue.\n";
    }//end of function to dequeue an element
    int dequene()//function to dequeue an element
    {
        int delVal=0;//stores the value that is to be dequeued
        if(isEmpty()==true)//if the queue is empty
        return -9999;
        else 
        {
            Node* temp=front;//temporary pointer to the first element of the queue
            delVal=temp->data;//the value at the first node is stored
            front=temp->next;//front is moved to the next element in the queue
            temp->next=NULL;//the first element is removed from the queue
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
        return delVal;//the value deleted is returned
    }
    bool isEmpty()//function to check if a queue is empty or not
    {
        if(front==NULL&&end==NULL)//if the front and the end of the queue is null
        return true;//the queue is empty
        else
        return false;
    }//end of function to check if a queue is empty or not
    int size()//function to count the number of elements in the queue
    {
        if(isEmpty()==true)
        return 0;
        else
        {
            int counter=1;//variable to store the number of elements in the queue
            Node* temp=front;//pointer to traverse the list
            do//till the end of the queue is reached
            {
                temp=temp->next;//pointer moves forward
                counter++;//number of elements incremented
            }while(temp!=end);
            return counter;//number of elements returned
        }
    }//end of function to count the number of elements of the queue
    void display()//display function
    {
        if(isEmpty()==false)
        {
            Node* temp=front;//pointer to traverse through the queue
            do//while the end of the queue is reached
            {
                cout<<temp->data<<", ";//the data is printed
                temp=temp->next;//the pointer is moved forward
            }while(temp!=end);
            cout<<end->data<<", ";//the last element is printed
            cout<<".\n";
        }
    }//end of display function
    int frontValue()//function to display the value at the front of the queue
    {
        if(isEmpty()==true)
        return -9999;
        else
        return front->data;
    }//end of the function to display the element at the front of the queue
    int endValue()//function to display the value at the end of the queue
    {
        if(isEmpty()==true)
        return -9999;
        else
        return end->data;
    }//end of the function to display the element at the end of the queue
};//end of class Queue
int main()
{
    cout<<"Quene Object.";
    Queue queue1;//object of Queue class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enquene an element.\n";
    cout<<"Enter 2 to dequene an element.\n";
    cout<<"Enter 3 to show the size of the quene.\n";
    cout<<"Enter 4 to display the elements of the quene.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued.\n";
                    cin>>val;
                    queue1.enquene(val);
                    break;
            case 2 :val=queue1.dequene();
                    cout<<val<<" has been dequeued.\n";
                    break;
            case 3 :val=queue1.size();
                    cout<<"The number of elements in the queue is "<<val<<endl;
                    break;
            case 4 :queue1.display();
                    break;
            case 5 :val=queue1.frontValue();
                    cout<<val<<" is the value at the top of the stack.\n";
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}
