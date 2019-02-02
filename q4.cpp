#include <iostream>
using namespace std;
class QueueArr
{
	public:
	int front;
	int rear;
	int length;
	int a[10];
	public:
	QueueArr()
	{
		front=-1;
		rear=-1;
		length=10;
	}
	void enqueue(int num)
	{
		if(rear==-1)
		{
			front++;
			a[++rear]=num;
		}
		else if(rear==length-1)
		cout<<"Queue Overflow\n";
		else
		a[++rear]=num;
	}
	int dequeue()
	{
		if(front==-1)
		return -9999;
		else if(front==rear)
		{
			int b=a[front];
			front=-1;
			rear=-1;
			return b;
		}
		else
		return a[front++];
	}
	void display()
	{
		for(int i=front;i<=rear;i++)
		cout<<a[i]<<", ";
	}
	int size()//function to count the number of elements in the stack
	{
		int counter=0;
		for(int i=front;i<=rear;i++)//for loop to
		counter++;//count the number of elements in the stack
		return counter;//and return it
	}//end of function to count the number of elements in the stack
	bool isEmpty()//function to find if a siack is empty or not
	{
		if(front==-1)//if top is not an array index
		return true;//then the stack is empty
		else
		return false;
	}//end of function to find if the stack is empty or not
	int frontValue()//function to return the value at the top of the stack
	{
		return a[front];//value returned
	}//end of function to return the value at the top of the stack
	int rearValue()//function to return the value at the top of the stack
	{
		return a[rear];//value returned
	}//end of function to return the value at the top of the stack
};
int main()
{
    cout<<"Stack implemented using an Array.";
    QueueArr queue1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enqueue an element.\n";
    cout<<"Enter 2 to dequeue an element.\n";
    cout<<"Enter 3 to show the size of the queue.\n";
    cout<<"Enter 4 to display the elements of the queue.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued.\n";
                    cin>>val;
                    queue1.enqueue(val);
                    break;
            case 2 :val=queue1.dequeue();
		    if(val!=-9999)
                    cout<<val<<" has been dequeued.\n";
		    else
		    cout<<"Queue Underflow.\n";
                    break;
            case 3 :val=queue1.size();
                    cout<<"The number of elements in the queue is "<<val<<endl;
                    break;
            case 4 :queue1.display();
                    break;
            case 5 :val=queue1.frontValue();
                    cout<<val<<" is the value at the front of the queue.\n";
                    break;
	    case 6 :val=queue1.rearValue();
		    cout<<val<<" is the value at the end of the queue.\n";
		    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}	