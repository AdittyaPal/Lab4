#include <iostream>
using namespace std;
class StackArr
{
	public:
	int top;//stores index of the top of the stack
	int length;//stores the length of the array
	int a[10];//array declared
	public:
	StackArr()//default constructor
	{
		top=-1;//to initialize top to -1
		length=10;//and length to 10
	}//end of default constructor
	void push(int num)//function to push an element into the stack
	{
		if(top<length)//of array index is not out of bounds
		a[++top]=num;//the value is pushed into the next element
		else
		cout<<"Stack Overflow\n";//else stack overflows
	}//end of function to pish an element into stack
	int pop()//function to pop an element from the stack
	{
		if(top>-1)//if the stack is not empty
		return a[top--];//the element is returned and top is decremented
		else
		cout<<"Stack Underflow\n";//else stack underflows
		return -9999;
	}//end of function to pop an element from the stack
	void display()//function to display the elements of the stack
	{
		for(int i=top;i>-1;i--)
		cout<<a[i]<<", ";//elements printed
	}//end of function to display the elements of the stack
	int size()//function to count the number of elements in the stack
	{
		int counter=0;
		for(int i=top;i>-1;i--)//for loop to
		counter++;//count the number of elements in the stack
		return counter;//and return it
	}//end of function to count the number of elements in the stack
	bool isEmpty()//function to find if a siack is empty or not
	{
		if(top==-1)//if top is not an array index
		return true;//then the stack is empty
		else
		return false;
	}//end of function to find if the stack is empty or not
	int topValue()//function to return the value at the top of the stack
	{
		return a[top];//value returned
	}//end of function to return the value at the top of the stack
};
int main()
{
    cout<<"Stack implemented using an Array.";
    StackArr stack1;//object of Stack class created
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
		    if(val!=-9999)
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