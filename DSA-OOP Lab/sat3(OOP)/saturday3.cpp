#ifndef IOSTREAM
#define IOSTREAM
#endif

#ifndef STDLIB_H
#define STDLIB_H
#endif

#include"class.h"
using namespace std;

int main()
{
	int l,n,o;
	double i,j;
	x:cout <<"Which operation do you want to perform:\nPress \'1\' for Addition\nPress \'2\' for Subtraction\nPress \'3\' for Multiplication\nPress \'4\' for Division" <<endl;
	cin >>n;
	cout << "\n\nEnter the value of first number:"<<endl;
	cin >> i;
	cout <<"Enter its unit:\nPress \'1\' for km\nPress \'2\' for m\nPress \'3\' for cm\nPress \'4\' for ft\nPress \'5\' for inch" <<endl;
	cin >> l;
	cout << "\n\nEnter the value of second number:"<<endl;
	cin >> j;
	cout <<"Enter its unit:\nPress \'1\' for km\nPress \'2\' for m\nPress \'3\' for cm\nPress \'4\' for ft\nPress \'5\' for inch" <<endl;
	cin >>o;
	if(n==1)
	{
		if(o==1)
		{
			km a(i);
			if(l==1)
			{
				km b(j),c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}

		}
		if(o==2)
		{
			m a(i);
			if(l==1)
			{
				km b(j);
				m c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				m c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				m c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				m c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==3)
		{
			cm a(i);
			if(l==1)
			{
				km b(j);
				cm c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j);
				m c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				cm c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				cm c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==4)
		{
			ft a(i);
			if(l==1)
			{
				km b(j);
				ft c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				ft c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==5)
		{
			inch a(i);
			if(l==1)
			{
				km b(j);
				inch c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b+a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				inch c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=a+b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
	}
	if(n==3)
	{
		if(o==1)
		{
			km a(i);
			if(l==1)
			{
				km b(j),c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}

		}
		if(o==2)
		{
			m a(i);
			if(l==1)
			{
				km b(j);
				m c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				m c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				m c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				m c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==3)
		{
			cm a(i);
			if(l==1)
			{
				km b(j);
				cm c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j);
				m c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				cm c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				cm c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==4)
		{
			ft a(i);
			if(l==1)
			{
				km b(j);
				ft c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				ft c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==5)
		{
			inch a(i);
			if(l==1)
			{
				km b(j);
				inch c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b*a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				inch c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=a*b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
	}
	if(n==4)
	{
		if(o==1)
		{
			km a(i);
			if(l==1)
			{
				km b(j),c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}

		}
		if(o==2)
		{
			m a(i);
			if(l==1)
			{
				km b(j);
				m c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				m c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				m c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				m c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==3)
		{
			cm a(i);
			if(l==1)
			{
				km b(j);
				cm c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j);
				m c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				cm c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				cm c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==4)
		{
			ft a(i);
			if(l==1)
			{
				km b(j);
				ft c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				ft c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==5)
		{
			inch a(i);
			if(l==1)
			{
				km b(j);
				inch c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b/a;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				inch c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=a/b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
	}
	if(n==2)
	{
		if(o==1)
		{
			km a(i);
			if(l==1)
			{
				km b(j),c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j),c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j),c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j),c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}

		}
		if(o==2)
		{
			m a(i);
			if(l==1)
			{
				km b(j);
				m c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				m c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				m c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				m c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==3)
		{
			cm a(i);
			if(l==1)
			{
				km b(j);
				cm c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j);
				m c(0);
				c=b-a;
				cout <<endl <<"Result: -"<<c.getY() <<endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				cm c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				cm c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
		if(o==4)
		{
			ft a(i);
			if(l==1)
			{
				km b(j);
				ft c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b-a;
				cout <<endl<<"Result: -("<< (c.getY())<<")" <<endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b-a;
				cout <<endl<<"Result: -("<< (c.getY())<<")" <<endl;
			}
			else if(l==4)
			{
				ft b(j);
				ft c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=b-a;
				cout <<endl<<"Result: -("<< (c.getY())<<")" <<endl;
			}
		}
		if(o==5)
		{
			inch a(i);
			if(l==1)
			{
				km b(j);
				inch c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==2)
			{
				m b(j),c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}
			else if(l==3)
			{
				cm b(j);
				cm c(0);
				c=b-a;
				cout <<endl<< "Result: -"<<c.getY() << endl;
			}
			else if(l==4)
			{
				ft b(j);
				inch c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
			else if(l==5)
			{
				inch b(j);
				inch c(0);
				c=a-b;
				cout <<endl<< "Result: "<<c.getY() << endl;
			}
		}
	}
}



