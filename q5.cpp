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
class Stack
{
    public:
    Node* top;//top is a node type pointer to the first element of the stack
    public:
    Stack()//default constructor
    {
        top=NULL;//initializes top to null
    }
    void push(int value)//function to push an elemnt into the stack
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the stack is empty
        top=ptr;//the first element is added
        else
        {
            ptr->next=top;//ptr to pushed at the top of the list
            top=ptr;//the pointer top points to the new node which is the topmost node now
        }        
    }//end of function to push a value into the stack
    int pop()//function to pop an element into the stack
    {
        int delVal=0;//stores the value that is to be popped from the list
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else 
        {
            Node* temp=top;
            delVal=temp->data;//the value at the topmost node is stored
            top=top->next;//top is moved to the next element in the stack
            temp->next=NULL;//the first element is removed from the stack
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
    }
    bool isEmpty()//function to check if a stack is empty or not
    {
        if(top==NULL)//if top is null
        return true;//then the stack is empty
        else
        return false;
    }//end of function to check if the stack is empty or not
    int size()//function to count the number of elements in the stack
    {
        int counter=0;//variable to store the number of elements in the stack
        Node* temp=top;//pointer to traverse the list
        while(temp!=NULL)//till the bottom of the stack is reached
        {
            temp=temp->next;//pointer moves forward
            counter++;//number of elements incremented
        }
        return counter;//number of elements returned
    }//end of function to find the size of the stack
    void display()//display function
    {
        Node* temp=top;//pointer to traverse through the stack
        while(temp!=NULL)//while the end of the stack is reached
        {
            cout<<temp->data<<", ";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<".\n";
    }//end of display function
    void displayRev()//displays the stack in the reverse order
    {
        displayRev(top);//call to the parameterized function using the data member
    }//end of the function to display the stack in the reverse order
    void displayRev(Node* temp)//method to print the elements of the stack in the reverse order
    {
        if(temp->next==NULL)//when the end of the stack is reached
        cout<<temp->data<<", ";//the element is displayed
        else
        {
            displayRev(temp->next);//the next element in the stack is traversed
            cout<<temp->data<<", ";//the nalue of the element in stack is printed
        }
    }//end of function to print the elements of the stack inreverse order
    int topValue()//function to return the value at the top of the stack
    {
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else
        return top->data;//the first element is returned
    }//end of function to return the topmost value in the stack
};//end of class Stack
class QueueFromStack//class to implement a queue using a stack
{
    public:
    Stack s1;//stack object used to implement a queue
    public:
    void enqueue(int num)//while enqueuing an element into the queue
    {
	s1.push(num);//it is simply popped into the stack
    }
    void dequeue()//while dequeuing an element from the queue
    {
	if(s1.size()==0)//if the queue is empty then there is nothing to dequeue
        cout<<"Stack Underflow.\n";
	else if(s1.size()==1)//else the last element is popped from the stack
	cout<<s1.pop()<<" has been dequened.\n";
        else//else
	{
	    int poppedValue=s1.pop();//each element is popped from the stack and stored
	    dequeue();//the next element is dequeued
            s1.push(poppedValue);//the stored element is later pushed back into the stack
	}
    }
    void display()//to display the queue
    {
        s1.displayRev();//the stack is displayed from bottom to top
    }
};//end of the class implementing a queue using a stack
int main()
{
    cout<<"Quene Object.";
    QueueFromStack queue1;//object of Queue class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enquene an element.\n";
    cout<<"Enter 2 to dequene an element.\n";
    cout<<"Enter 3 to display the elements of the quene.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued.\n";
                    cin>>val;
                    queue1.enqueue(val);
		    cout<<val<<" has been enqueued.\n";
                    break;
            case 2 :queue1.dequeue();
                    break;
            case 3 :queue1.display();
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}
