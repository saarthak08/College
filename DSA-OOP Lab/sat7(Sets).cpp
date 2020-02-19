#include<iostream>
#include<stdlib.h>
#include<math.h>
#define MAX 30
using namespace std;

class Set
{
	protected:
	char set[MAX];
	int n;
	public:
	int i,j;
	char y;
	void setn(int x)
	{
		n=x;
	}
	int getn()
	{
		return n;
	}
	void setset()
	{
		for(i=0;i<n;i++)
		{
			r:
			cin.ignore();cin>> y;
			for(j=0;j<n;j++)
			{
				if(set[j]==y)
				{
					cout<<"Error! Cannot repeat element\nEnter the element again."<<endl;
					goto r;
				}
			}
			set[i]=y;
		}
	}
	char *getset()
	{
		return set;
	}
	void display()
	{
		cout<<"{ ";
		if(n==0)
		{
			cout<<" }\n";
		}
		else
		{
			for(i=0;i<n;i++)
			{
				cout<<set[i]<<" , ";
			}
			cout<<"\b\b}\n";
		}
	}
	void powerset()
	{ 
	int c,i; 
	int powss=pow(2,getn());
	cout<<"\n\nTotal number of subsets: "<<powss<<"\nPower set:\n{ ";
	for(c=0;c<powss;c++) 
	{ 
      		cout<<"{ ";
      		for(i=0;i<getn();i++) 
		{        
			if(c&(1<<i)) 
			{
            			cout<<*(this->getset()+i)<<" , "; 
            		}
       		}
       		if(c==0)
       		{
       			cout<<" }, ";
       		}
       		else
       			cout<<"\b\b}, ";
       	} 
       	cout <<"}\n";
} 	
};

Set uset;

class Subset:public Set
{
	private:
	int k,flag=0;
	public:
	void setset()
	{
		cout<<"\nEnter the elements of the subset:"<<endl;
		for(i=0;i<n;i++)
		{
			t:
			cin.ignore(); cin>>y;
			for(j=0;j<uset.getn();j++)
			{
				if(*(uset.getset()+j)==y)
				{
					flag=1;
				}
				if(set[j]==y)
				{
					cout<<"Error! Cannot repeat element\nEnter the element again."<<endl;
					goto t;
				}
			}
			if(flag==0)
			{
				cout<<"Error! Given input element is not present in the universal set\nEnter the element again."<<endl;
				goto t;
			}
			flag=0;
			set[i]=y;
		}	
	}
	void unions();
	void intersection();
	void compliment();
	void subtract(Subset *m);
};

Subset a,b,c;

void Subset::unions()
{
	int k=0,o;
	int flag;
	for(i=0;i<a.getn();i++)
	{
	  	*(c.getset()+i)=*(a.getset()+i);
	  	k++;
	}
	for(o=0;o<b.getn();o++)
	{
		flag=1;
		for(j=0;j<a.getn();j++)
		{
			if(*(b.getset()+o)==*(a.getset()+j))
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			*(c.getset()+i)=*(b.getset()+o);
			i++;
			k++;
		}
		
	 }
	 cout<<"\nA U B =";
	 c.setn(k);
}

void Subset::intersection()
{
	int k=0;
	for(i=0;i<a.getn();i++)
	{
		for(j=0;j<b.getn();j++)
		{
			if(*(a.getset()+i)==*(b.getset()+j))
			{
				*(c.getset()+k)=*(a.getset()+i);
				k++;
			}
		}
	}
	c.setn(k);
	cout<<"\nA 🎧 B = ";
}

void Subset::compliment()
{
	int flag,k=0;
	for(i=0;i<uset.getn();i++)
	{
		flag=1;
		for(j=0;j<(this->getn());j++)
		{
			if(*(this->getset()+j)==*(uset.getset()+i))
			{
					flag=0;
					break;
			}
		}
		if(flag==1)
		{
			*(c.getset()+k)=*(uset.getset()+i);
			k++;
		}
	}
		c.setn(k);
		cout<<"\nCompliment:"<<endl;
}
void Subset::subtract(Subset *m)
{
	int k=0,flag=0;
	for(i=0;i<this->getn();i++)
	{
		for(j=0;j<m->getn();j++)
		{
			if(*(this->getset()+i)==*(m->getset()+j))
			{
				flag=1;
			}
		}
		if(flag==0)
		{	
			*(c.getset()+k)=*(this->getset()+i);
			k++;
		}
		c.setn(k);
		cout<<"\nSubtraction:"<<endl;
		
	}
}

int main()
{
	int n,flag=1,v;
	cout<<"Enter the number of elements needed in the universal set: "<<endl;
	cin>>n;
	if(n==0)
	{
		cout<<"Given set is empty"<<endl;
		return 0;
	}
	uset.setn(n);
	cout<<"Enter the elements of the set: "<<endl;
	uset.setset();
	cout<<endl<<"Universal Set:"<<endl;
	uset.display();
	q:cout <<"\n\nEnter the number of elements needed in the subset A: ";
	cin.ignore();cin >> n;	
	if(n>uset.getn())
	{
		cout<<"Error! Number of elements in a subset cannot be greater than number of elements in a universal set\nPlease try again\n";
		goto q;
	}
	a.setn(n);
	a.setset();
	cout<<"\n\nSubset A:"<<endl;
	a.display();
	w:cout <<"\n\nEnter the number of elements needed in the subset B: ";
	cin.ignore();cin >> n;
	if(n>uset.getn())
	{
		cout<<"Error! Number of elements in a subset cannot be greater than number of elements in a universal set\nPlease try again\n";
		goto w;
	}	
	b.setn(n);
	b.setset();
	cout<<"\n\nSubset B:"<<endl;
	b.display();
	cout<<"\n\n\nUniversal Set:"<<endl;
	uset.display();
	cout<<"\nSubset A:"<<endl;
	a.display();
	cout<<"\nSubset B:"<<endl;
	b.display();
	while(flag)
	{
		cout<<"\n\n\nEnter the operation needed to be performed: \n1. Union of A & B\n2. Intersection of A & B\n3. Compliment\n4. Subtraction\n5. Power Set\n6. Exit\n\n";
		cin >> n;
		switch(n)
		{
			case 1:
			{
				c.unions();
				c.display();
			}break;
			case 2:
			{
				c.intersection();
				c.display();
			}break;
			case 3:
			{
				e:cout<<"Enter:\n\'1\' for Set A\n\'2\' for Set B\n";
				cin.ignore(); cin>>v;
				if(v==1)
				{ 
					a.compliment();
					c.display();
				}
				else if(v==2)
				{
					b.compliment();
					c.display();
				}
				else
				{
					cout<<"Error! Invalid Input\nPlease try again"<<endl;
					goto e;
				}
			}break;
			case 4:
			{
				u:cout<<"Enter:\n\'1\' for A-B\n\'2\' for B-A\n";
				cin.ignore(); cin>>v;
				if(v==1)
				{ 
					a.subtract(&b);
					c.display();
				}
				else if(v==2)
				{
					b.subtract(&a);
					c.display();
				}
				else
				{
					cout<<"Error! Invalid Input\nPlease try again"<<endl;
					goto u;
				}
			}break;
			case 5:
			{
				p:cout<<"Enter:\n\'1\' for Set A\n\'2\' for Set B\n\'3\' for Universal Set\n";
				cin.ignore(); cin>>v;
				if(v==1)
				{ 
					a.powerset();
				}
				else if(v==2)
				{
					b.powerset();
				}
				else if(v==3)
				{
					uset.powerset();
				}
				else
				{
					cout<<"Error! Invalid Input\nPlease try again"<<endl;
					goto e;
				}
			}break;
			case 6:
				flag=0;
				break;
		}
	}	
}

