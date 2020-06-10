#include<iostream>
#include<stdlib.h>

using namespace std;

struct node					//Structure of the node
{
	int data;
	struct node *next;
};

struct node* sort(struct node *k,int b);			//Prototype for the sorting function
struct node* ll_insert(struct node *l,int a);		//Prototype for inserting elements function
void ll_print(struct node *ptr);


int main(int argv,char *argc[])
{
	int n;
	struct node *head,*start,*ptr;	
	cout << "Enter the required number of elements in the linked list:" << endl;
	cin >> n;					   //Entering the desired number of elements in the linked list
	head=(struct node *)malloc(sizeof(struct node));	//Allocating memory for first node		
	head=ll_insert(head,n);
	cout << "\n\n\nEntered elements in the linked list:" << endl;
	ll_print(head);
	head=sort(head,n);
	cout << "\n\nRequired Output:" <<endl;
	ll_print(head);
}


struct node* sort(struct node *k,int b)
{
	int i,j;
	struct node *ptr=k,*m,*pptr=NULL,*head,*temp,*l;
	for(i=0;i<b-1;i++)
	{
		pptr=NULL;
		ptr=k;
		for(j=0;j<b-i-1;j++)
		{
			if((ptr->next)->data<(ptr->data))
			{
				if(ptr==k)
				{
					head=ptr->next;
					ptr->next=head->next;
					head->next=ptr;
					k=head;
					temp=head;
					head=ptr;
					ptr=temp;
					cout <<"\nLinked List after swapping: ";
					ll_print(k);
				}
				else
				{
					m=ptr->next;
					ptr->next=m->next;
					m->next=ptr;
					pptr->next=m;
					l=m;
					m=ptr;
					ptr=l;
					cout <<"\nLinked List after swapping: ";
					ll_print(k);
				}
			}
			pptr=ptr;
			ptr=ptr->next;
		}
	}		
	return k;
}


struct node* ll_insert(struct node *l,int a)
{
	int i;
	struct node *ptr,*new_node=l;
	cout << "\n\nEnter the elements of the linked list:" << endl;
	cin >> new_node->data;					
	for(i=1;i<a;i++)
	{
		ptr=new_node;					
		new_node=(struct node *)malloc(sizeof(struct node));	//Allocating memory for the next desired nodes
		cin >> new_node->data;					//Entering values for for the next nodes
		ptr->next=new_node;					//Linking the nodes
		new_node->next=NULL;		
	}
	return l;
}

void ll_print(struct node *ptr)
{
	struct node* k=ptr;
	while(k!=NULL)
	{
		cout << k->data <<"\t";			//Printing the linked list
		k=k->next;			
	}
	cout << endl;
}

