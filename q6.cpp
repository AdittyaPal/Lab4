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
    void enqueue(int value)//function to enqueue an element
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
    }//end of function to dequeue an element
    int dequeue()//function to dequeue an element
    {
        int delVal=0;//stores the value that is to be dequeued
        if(isEmpty()==true)//if the queue is empty
        return -9999;
        else 
        {
            Node* temp=front;//temporary pointer to the first element of the queue
            delVal=temp->data;//the value at the first node is stored
            front=front->next;//front is moved to the next element in the queue
            temp->next=NULL;//the first element is removed from the queue
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
        return delVal;//the value deleted is returned
    }
    bool isEmpty()//function to check if a queue is empty or not
    {
        if(front==NULL||end==NULL)//if the front and the end of the queue is null
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
class StackFromQueue//class to implement a stack using a queue
{
    public:
    Queue q1;//queue object used to implement a stack
    void push(int num)//while pushing an element into the stack
    {
	q1.enqueue(num);//it is enqueued at the end of the queue
	while(q1.frontValue()!=num)//all other element in front of it 
	q1.enqueue(q1.dequeue());//and dequeued and enqueued after it, bringing the inserted element to the top
    }
    int pop()//while popping an element from the stack
    {
	return q1.dequeue();//it is dequeued from the front of the queue
    }
    void display()//to display the stack
    {
	q1.display();//the queue is displayed
    }
};//end of the class implementing a stack using a queue
int main()
{
    cout<<"Stack Object.";
    StackFromQueue stack1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to push an element into the stack.\n";
    cout<<"Enter 2 to pop an element from the stack.\n";
    cout<<"Enter 3 to display the elements of the stack.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be pushed into the stack.\n";
                    cin>>val;
                    stack1.push(val);
		    cout<<val<<" has been inserted in the Queue.\n";
                    break;
            case 2 :val=stack1.pop();
		    if(val!=-9999)
                    cout<<val<<" has been popped from the stack.\n";
		    else
                    cout<<"Stack underflow.\n";
                    break;
            case 3 :stack1.display();
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}
