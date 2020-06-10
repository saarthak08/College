#include<iostream>
#include<stdlib.h>

using namespace std;

struct stack
{
	int data;				//Initializing stack via linked lists
	struct stack *next;
};

class tower
{
	private:
		struct stack *top;
		char x;
	public:
		tower()
		{
			top=NULL;				//class tower with basic member functions
		}
		void push(int a);
		int pop();
		void display();
		char getX()
		{
			return x;
		}
		void setX(char m)
		{
			this->x=m;
		}
};
void tower::display()
{
	struct stack* temp;
	temp=top;
	while(temp!=NULL)
	{
		cout << temp->data <<"\t";			//Printing the tower
		temp=temp->next;
	}
	temp=NULL;
	cout << endl;
}
void tower::push(int a)
{
	struct stack *new_node;
	new_node=(struct stack *)malloc(sizeof(struct stack));
	new_node->data=a;				//Pushing an element to the stack
	new_node->next=top;
	top=new_node;
}
int tower::pop()
{
	struct stack *temp;
	if((top)==NULL)
	{
		return 0;
	}							//Popping an element from stack
	int p;
	temp=top;
	(top)=(top)->next;
	p=temp->data;
	free(temp);
	return p;
}
tower A,B,C;
void toh(int o,tower *X,tower *Y,tower *Z);
int main()
{
	int n,i;
	cout << "Enter the number of inputs you want to give in the first tower:"<<endl;
	cin >> n;
	for(i=0;i<n;i++)
	{
		A.push(n-i);				//Getting input
	}
	cout <<"\n\nInitial Towers:\nTower A:\t";
	A.display();
	cout <<"Tower B:\t";			//Initial towers
	B.display();
	cout <<"Tower C:\t";
	C.display();
	cout <<"\n"<<endl;
	A.setX('A');
	B.setX('B');
	C.setX('C');
	toh(n,&A,&B,&C);
	cout<< "\n\n\n\nFinal Towers:"<<endl;
	cout <<"Tower A:\t";
	A.display();
	cout <<"Tower B:\t";			//Final towers
	B.display();
	cout <<"Tower C:\t";
	C.display();
}

void toh(int o,tower *X,tower *Y,tower *Z)
{
	if(o>=1)
	{
		toh((o-1),X,Z,Y);
		int k;
		k=X->pop();			//Tower Of Hanoi algorithm
		Z->push(k);
		cout << "Moved " <<k<<" from "<< X->getX() <<" to " << Z->getX() << endl;
		cout <<"Tower A:\t";
		A.display();
		cout <<"Tower B:\t";
		B.display();
		cout <<"Tower C:\t";		
		C.display();
		cout << endl;
		toh((o-1),Y,X,Z);
	}
}
