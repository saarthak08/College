#include<iostream>
#include<stdlib.h>
class cm;
class km;
class m;
class inch;
class ft;

class km
{
	private:
	    double y;
	public:
	km(double x)
	{
		this->y=x;
	}
	km operator +(km &b);
	km operator -(km &b);
	km operator *(km &b);
	km operator /(km &b);
	void print();
    double getY()
    {
        return y;
    }
    double setY(double k)
    {
        y=k;
        return y;
    }
};

class cm
{
	private:
	    double y;
	public:
	cm(double x)
	{
		this->y=x;
	}
	cm operator +(cm &b);
	cm operator +(ft &b);
	cm operator +(inch &b);
	cm operator +(km &b);
	cm operator *(cm &b);
	cm operator *(ft &b);
	cm operator *(inch &b);
	cm operator *(km &b);
	cm operator /(cm &b);
	cm operator /(ft &b);
	cm operator /(inch &b);
	cm operator /(km &b);
	cm operator -(cm &b);
	cm operator -(ft &b);
	cm operator -(inch &b);
	cm operator -(km &b);
	void print();
	 double getY()
    {
        return y;
    }
    double setY(double k)
    {
        y=k;
        return y;
    }
};
class m
{
	private:
	    double y;
	public:
	m(double x)
	{
		this->y=x;
	}
	m operator +(cm &b);
	m operator +(km &b);
	m operator +(m &b);
	m operator +(ft &b);
	m operator +(inch &b);
	m operator *(km &b);
	m operator *(inch &b);
	m operator *(cm &b);
	m operator *(m &b);
	m operator *(ft &b);
	m operator -(km &b);
	m operator -(inch &b);
	m operator -(cm &b);
	m operator -(m &b);
	m operator -(ft &b);
	m operator /(km &b);
	m operator /(inch &b);
	m operator /(cm &b);
	m operator /(m &b);
	m operator /(ft &b);
	void print();
	  double getY()
    {
        return y;
    }
    double setY(double k)
    {
        y=k;
        return y;
    }
};
class inch 
{
	private:
	    double y;
	public:
	inch (double x)
	{
		this->y=x;
	}
	inch  operator +(inch  &b);
	inch  operator +(km &b);
	inch  operator +(ft &b);
	inch  operator -(inch  &b);
	inch  operator -(ft &b);
	inch  operator -(km &b);
	inch  operator *(inch  &b);
	inch  operator *(ft &b);
	inch  operator *(km &b);
	inch  operator /(inch  &b);
	inch  operator /(ft &b);
	inch  operator /(km &b);
	void print();
	  double getY()
    {
        return y;
    }
    double setY(double k)
    {
        y=k;
        return y;
    }
};
class ft
{
	private:
	    double y;
	public:
	ft(double x)
	{
		this->y=x;
	}
	ft operator +(ft &b);
	ft operator +(km &b);
	ft operator -(ft &b);
	ft operator -(km &b);
	ft operator *(ft &b);
	ft operator *(km &b);
	ft operator /(ft &b);
	ft operator /(km &b);
	void print();
	double getY()
    {
        return y;
    }
    double setY(double k)
    {
        y=k;
        return y;
    }
};
cm cm::operator +(cm &b)
{
	cm k(0),l(0);
	k.y=(this->y)+(l.y);
	return k;
}
cm cm::operator +(km &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*100000;
	k.y=(this->y)+(l.y);
	return k;
}
cm cm::operator +(ft &b)
{
	cm k(0),l(0);
	l.y=((b.getY())*30.48);
	k.y=(this->y)+(l.y);
	return k;
}
cm cm::operator +(inch &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*2.54;
	k.y=(this->y)+(l.y);
	return k;
}
cm cm::operator *(cm &b)
{
	cm k(0),l(0);
	k.y=(this->y)*(l.y);
	return k;
}
cm cm::operator *(km &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*100000;
	k.y=(this->y)*(l.y);
	return k;
}
cm cm::operator *(ft &b)
{
	cm k(0),l(0);
	l.y=((b.getY())*30.48);
	k.y=(this->y)*(l.y);
	return k;
}
cm cm::operator *(inch &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*2.54;
	k.y=(this->y)*(l.y);
	return k;
}
cm cm::operator /(cm &b)
{
	cm k(0),l(0);
	k.y=(this->y)/(l.y);
	return k;
}
cm cm::operator /(km &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*100000;
	k.y=(this->y)/(l.y);
	return k;
}
cm cm::operator /(ft &b)
{
	cm k(0),l(0);
	l.y=((b.getY())*30.48);
	k.y=(this->y)/(l.y);
	return k;
}
cm cm::operator /(inch &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*2.54;
	k.y=(this->y)/(l.y);
	return k;
}
cm cm::operator -(cm &b)
{
	cm k(0),l(0);
	k.y=(this->y)-(l.y);
	return k;
}
cm cm::operator -(km &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*100000;
	k.y=(this->y)-(l.y);
	return k;
}
cm cm::operator -(ft &b)
{
	cm k(0),l(0);
	l.y=((b.getY())*30.48);
	k.y=(this->y)-(l.y);
	return k;
}
cm cm::operator -(inch &b)
{
	cm k(0),l(0);
	l.y=(b.getY())*2.54;
	k.y=(this->y)-(l.y);
	return k;
}


inch inch::operator +(inch &b)
{
	inch k(0),l(0);
	k.y=(this->y)+(l.y);
	return k;
}
inch inch::operator +(ft &b)
{
	inch k(0),l(0);
	l.y=((b.getY())*12);
	k.y=(this->y)+(l.y);
	return k;
}
inch inch::operator +(km &b)
{
	inch k(0),l(0);
	this->y=this->y*39370.079;
	k.y=(this->y)+(l.y);
	return k;
}
inch inch::operator -(inch &b)
{
	inch k(0),l(0);
	k.y=(this->y)-(l.y);
	return k;
}
inch inch::operator -(ft &b)
{
	inch k(0),l(0);
	l.y=((b.getY())*12);
	k.y=(this->y)-(l.y);
	return k;
}
inch inch::operator -(km &b)
{
	inch k(0),l(0);
	this->y=this->y*39370.079;
	k.y=(this->y)-(l.y);
	return k;
}
inch inch::operator *(inch &b)
{
	inch k(0),l(0);
	k.y=(this->y)*(l.y);
	return k;
}
inch inch::operator *(ft &b)
{
	inch k(0),l(0);
	l.y=((b.getY())*12);
	k.y=(this->y)*(l.y);
	return k;
}
inch inch::operator *(km &b)
{
	inch k(0),l(0);
	this->y=this->y*39370.079;
	k.y=(this->y)*(l.y);
	return k;
}
inch inch::operator /(inch &b)
{
	inch k(0),l(0);
	k.y=(this->y)/(l.y);
	return k;
}
inch inch::operator /(ft &b)
{
	   inch k(0),l(0);
	l.y=((b.getY())*12);
	k.y=(this->y)/(l.y);
	return k;
}
inch inch::operator /(km &b)
{
	inch k(0),l(0);
	this->y=this->y*39370.079;
	k.y=(this->y)/(l.y);
	return k;
}	
ft ft::operator +(ft &b)
{
	ft k(0),l(0);
	k.y=(this->y)+(l.y);
	return k;
}
ft ft::operator +(km &b)
{
	ft k(0),l(0);
	this->y=(this->y)*3280.84;
	k.y=(this->y)+(l.y);
	return k;
}
ft ft::operator -(ft &b)
{
	ft k(0),l(0);
	k.y=(this->y)-(l.y);
	return k;
}
ft ft::operator -(km &b)
{
	ft k(0),l(0);
	this->y=(this->y)*3280.84;
	k.y=(this->y)-(l.y);
	return k;
}
ft ft::operator *(ft &b)
{
	ft k(0),l(0);
	k.y=(this->y)*(l.y);
	return k;
}
ft ft::operator *(km &b)
{
	ft k(0),l(0);
	this->y=(this->y)*3280.84;
	k.y=(this->y)*(l.y);
	return k;
}
ft ft::operator /(ft &b)
{
	ft k(0),l(0);
	k.y=(this->y)/(l.y);
	return k;
}
ft ft::operator /(km &b)
{
	ft k(0),l(0);
	this->y=(this->y)*3280.84;
	k.y=(this->y)/(l.y);
	return k;
}


m m::operator +(cm &b)
	{
	m k(0),l(0);
	l.y=(b.getY())/100;
	k.y=(this->y)+(l.y);
	return k;
}
m m::operator +(km &b)
{
    m k(0),l(0);
	l.y=(b.getY())*1000;
	k.y=(this->y)+(l.y);
	return k;
}
m m::operator +(m &b)
{
	m k(0),l(0);
	k.y=(this->y)+(l.y);
	return k;
}
m m::operator +(ft &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.305;
	k.y=(this->y)+(l.y);
	return k;
}
m m::operator +(inch &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.0254;
	k.y=(this->y)+(l.y);
	return k;
}
m m::operator *(km &b)
{
	m k(0),l(0);
	this->y=(this->y*1000);
	k.y=(this->y)*(l.y);
	return k;
}
m m::operator *(inch &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.0254;
	k.y=(this->y)*(l.y);
	return k;
}
m m::operator *(cm &b)
{
	m k(0),l(0);
	l.y=(b.getY())/100;;
	k.y=(this->y)*(l.y);
	return k;
}
m m::operator *(m &b)
{
	m k(0),l(0);
	k.y=(this->y)*(l.y);
	return k;
}
m m::operator *(ft &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.305;
	k.y=(this->y)*(l.y);
	return k;
}
m m::operator -(km &b)
{
	m k(0),l(0);
	this->y=(this->y*1000);
	k.y=(this->y)-(l.y);
	return k;
}
m m::operator -(inch &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.0254;
	k.y=(this->y)-(l.y);
	return k;
}
m m::operator -(cm &b)
{
	m k(0),l(0);
	l.y=(b.getY())/100;;
	k.y=(this->y)-(l.y);
	return k;
}
m m::operator -(m &b)
{
	m k(0),l(0);
	k.y=this->y-(l.y);
	return (*this);
}
m m::operator -(ft &b)
{
    m k(0),l(0);
	l.y=(b.getY())*0.305;
	k.y=(this->y)-(l.y);
	return k;
}
m m::operator /(km &b)
{
	m k(0),l(0);
	this->y=(this->y*1000);
	k.y=(this->y)/(l.y);
	return k;
}
m m::operator /(inch &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.0254;
	k.y=(this->y)/(l.y);
	return k;
}
m m::operator /(cm &b)
{
	m k(0),l(0);
	l.y=(b.getY())/100;;
	k.y=(this->y)/(l.y);
	return k;
}
m m::operator /(m &b)
{
	m k(0),l(0);
	k.y=(this->y)/(l.y);
	return k;
}
m m::operator /(ft &b)
{
	m k(0),l(0);
	l.y=(b.getY())*0.305;
	k.y=(this->y)/(l.y);
	return k;
}
km km::operator +(km &b)
{
	km k(0);
	k.y=(this->y)+(b.y);
	return k;
}
km km::operator -(km &b)
{
	km k(0);
	k.y=(this->y)-(b.y);
	return k;
}
km km::operator *(km &b)
{
	km k(0);
	k.y=(this->y)*(b.y);
	return k;
}
km km::operator /(km &b)
{
    km k(0);
	k.y=(this->y)/(b.y);
	return k;
}
