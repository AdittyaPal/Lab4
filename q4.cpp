#include <iostream>
using namespace std;
class QueueArr
{
	public:
	int front;//stores the index of the front of the queue
	int rear;//stores the index of the rear of the queue
	int length;//stores the length of the array
	int a[10];//array declared
	public:
	QueueArr()//default constructor
	{
		front=-1;//to initialize front to -1
		rear=-1;//to initialize rear to -1
		length=10;//and length to 10
	}//end of default constructor
	void enqueue(int num)//function to enqueue an element 
	{
		if(rear==-1)//if the queue is empty
		{
			front++;//front is incermented
			a[++rear]=num;//and rear is incermented and the value is stored
		}
		else if(rear==length-1)//if the array index becomes out of bounds
		cout<<"Queue Overflow\n";//queue overflows
		else
		a[++rear]=num;//an element ia added to the rear of the queue
	}//end of method to enqueue an element
	int dequeue()//method to dequeue an element
	{
		if(front==-1)//if the queue is empty there is othing to delete
		return -9999;
		else if(front==rear)//if only one element is present in the queue
		{
			int b=a[front];//it is stored in some variable
			front=-1;//front is reset to -1 signifying an empty queue
			rear=-1;//rear is set to -1 signifying an empty queue
			return b;//the deleted value is returned
		}
		else
		return a[front++];//else front is incermented
	}//and of method to dequeue an element
	void display()//method to display the elements in the queue
	{
		for(int i=front;i<=rear;i++)//for loop to display elements
		cout<<a[i]<<", ";//from front to rear in the queue
	}//end of method to display the queue elements
	int size()//function to count the number of elements in the queue
	{
		int counter=0;
		for(int i=front;i<=rear;i++)//for loop to
		counter++;//count the number of elements in the queue
		return counter;//and return it
	}//end of function to count the number of elements in the queue
	bool isEmpty()//function to find if a queue is empty or not
	{
		if(front==-1)//if front is not an array index
		return true;//then the queue is empty
		else
		return false;
	}//end of function to find if the queue is empty or not
	int frontValue()//function to return the value at the front of the queue
	{
		return a[front];//value returned
	}//end of function to return the value at the front of the queue
	int rearValue()//function to return the value at the rear of the queue
	{
		return a[rear];//value returned
	}//end of function to return the value at the rear of the queue
};
int main()
{
    cout<<"Stack implemented using an Array.";
    QueueArr queue1;//object of Queue class created
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
