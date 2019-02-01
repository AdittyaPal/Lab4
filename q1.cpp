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
        cout<<value<<" has been pushed into the stack.\n";
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
            top=temp->next;//top is moved to the next element in the stack
            temp->next=NULL;//the first element is removed from the stack
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
        return delVal;//the value deleted is returned
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
    int topValue()//function to return the value at the top of the stack
    {
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else
        return top->data;//the first element is returned
    }
};//end of class Stack
int main()
{
    cout<<"Stack Object.";
    Stack stack1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to push an element into the stack.\n";
    cout<<"Enter 2 to pop an element from the stack.\n";
    cout<<"Enter 3 to show the size of the stack.\n";
    cout<<"Enter 4 to display the elements of the stack.\n";
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
                    break;
            case 2 :val=stack1.pop();
                    cout<<val<<" has been popped from the stack.\n";
                    break;
            case 3 :val=stack1.size();
                    cout<<"The number of elements in the stack is "<<val<<endl;
                    break;
            case 4 :stack1.display();
                    break;
            case 5 :val=stack1.topValue();
                    cout<<val<<" is the value at the top of the stack.\n";
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}
