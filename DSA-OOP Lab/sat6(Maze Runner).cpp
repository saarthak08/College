#include<iostream>
#include<stdlib.h>
#include<time.h>
#define MAX 30
using namespace std;

struct q
{
	int x;
	int y;
	int dist;
};

struct q queue[MAX];
int FRONT=0;
int REAR=MAX-1;
int size=0;
int n;
bool visited[100][100];

void enqueue(struct q data)
{
    REAR=(REAR+1)%MAX;
    size++;
    queue[REAR]=data;
}

struct q dequeue()
{
    struct q data;
    data=queue[FRONT];
    FRONT=(FRONT+1)%MAX;
    size--;
    return data;
}

int isempty()
{
    if(size==0)
    	return 0;
    else
    	return 1;
}


bool check(int **p,int x,int y)
{
	if((x<0)||(x>(n-1))||(y<0)||(y>(n-1))||(visited[x][y]==true)||(p[x][y]==-1))
	{
		return false;
	}
	else 
		return true;
}

bool check2(int x,int y)
{
	if((x<0)||(x>(n-1))||(y<0)||(y>(n-1)))
	{
		return false;
	}
	else 
		return true;
}
	
int main()
{
	int i,j,starti,startj,endi,endj,x,y,obs,b,c,count=0,distance,flag=0;
	struct q k;
	cout << "Enter the size of the matrix:" <<endl;
	cin >> n;
	int** a = new int*[n];
	int back[n][n];
	for(i=0;i<n;++i)
	{
	    a[i] = new int[n];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=-2;
			visited[i][j]=false;
		}
	}	
	cout << "Enter the index of starting point:"<<endl;
	cin >> starti >>startj;
	b=starti; 
	c=startj;
	a[starti][startj]=0;
	enqueue({starti,startj,count});
	visited[starti][startj]=true;
	cout <<"Enter the index of ending point:"<<endl; 
	cin >>endi>>endj;
	a[endi][endj]=1;
	srand(time(0));
	obs=rand()%(((n*n)-2)/2);
	cout<< "\n\nNumber of obstacles: "<<obs<<endl;
	for(i=0;i<obs;i++)
	{
		x=rand()%n;
		y=rand()%n;
		while((x==starti&&y==startj)||(x==endi&&y==endj)||(a[x][y]==-1))
		{
			x=rand()%n;
			y=rand()%n;
		}
		a[x][y]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			back[i][j]=a[i][j];
			cout<< a[i][j]<<"\t";
		}
		cout <<endl;
	}				
	while(isempty())
	{
		k=dequeue();
		b=k.x;
		c=k.y;
		count=k.dist;
		if((b==endi)&&(c==endj))
		{
			distance=k.dist;
			flag=1;
			break;
		}
		if(check(a,b+1,c))
		{
			count=count+1;
			a[b+1][c]=count;
			visited[b+1][c]=true;
			enqueue({b+1,c,count});
			count=count-1;
		}
		if(check(a,b-1,c))
		{
			count=count+1;
			a[b-1][c]=count;
			visited[b-1][c]=true;
			enqueue({b-1,c,count});
			count=count-1;
		}	
		if(check(a,b,c+1))
		{
			count=count+1;
			a[b][c+1]=count;
			visited[b][c+1]=true;
			enqueue({b,c+1,count});
			count=count-1;
		}
		if(check(a,b,c-1))
		{
			count=count+1;
			a[b][c-1]=count;
			visited[b][c-1]=true;
			enqueue({b,c-1,count});
			count=count-1;
		}	
	}		
	if(flag==1)
	{
		cout << "\n\nDestination is found"<<endl;
		cout<< "Shortest path distance:"<<distance<<endl;
	}
	else
	{
		cout << "\n\nDestination is not found"<<endl;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<< a[i][j]<<"\t";
		}
		cout <<endl;
	}

	if(flag==1)
	{
		back[b][c]=distance;
	while(distance>0)
	{
		if(check2(b+1,c))
		{
			if(a[b+1][c]==(distance-1))
			{
				flag=1;
			}
		}
		if(check2(b-1,c))
		{
			if(a[b-1][c]==(distance-1))
			{
				flag=2;
			}
		}
		if(check2(b,c-1))
		{
			if(a[b][c-1]==(distance-1))
			{
				flag=3;
			}
		}
		if(check2(b,c+1))
		{
			if(a[b][c+1]==(distance-1))
			{
				flag=4;
			}
		}
		if(flag==1)
		{
			b=b+1;
			back[b][c]=distance-1;
		}
		if(flag==2)
		{
			b=b-1;
			back[b][c]=distance-1;
		}
		if(flag==3)
		{
			c=c-1;
			back[b][c]=distance-1;
		}
		if(flag==4)
		{
			c=c+1;
			back[b][c]=distance-1;
		}
		distance--;		
	}
	
		cout <<endl<<endl<<"Path:"<<endl;
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<< back[i][j]<<"\t";
			}
		cout <<endl;
		}		
	}
}
