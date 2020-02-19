#include<iostream>
#include<malloc.h>

using namespace std;

int main(int argv, char *argc[])
{
	int **ptr,n,i,j,k,m,l;						//Initializing  a double pointer
	cout << "Enter the number of rows/columns:\n";			//Input of number of rows
	cin >> n;
	if(n==0)						//If the input rows/columns is 0 as given by the user
	{
		cout << "Error! There can be no array with 0 rows/columns." << endl;
		return 0;
	}
	ptr=(int **)malloc(n*(sizeof(int *)));				//Allocating memory for n rows with n pointers
	for(i=0;i<n;i++)
	{
		*(ptr+i)=(int *)malloc(n*sizeof(int));	    		//Allocating memory for n elements in each row
	}
	cout << "\n\nEnter elements of the array:\n";
	for(i=0;i<n;i++)						//Getting input
	{
		for(j=0;j<n;j++)
		{
			cin >> *(*(ptr+j)+i);
		}
	}
	cout << "\n\nEntered elements:\n";
	for(i=0;i<n;i++)						//Printing the array
	{
		for(j=0;j<n;j++)
		{
			cout << *(*(ptr+j)+i) <<"\t";
		}
		cout << endl;
	}
	cout << "\n\nArray according to the pattern:" <<endl;
	for(i=0;i<n;i++)	//Printing the first half array upto the longest diagonal in increasing order of length
	{	
		if(i%2==0)		//Printing the even diagonals
		{
			for(j=i,k=0;j>=0,k<=i;k++,j--)
			{
				cout << *(*(ptr+k)+j) << " ";
			}
		}
		if(i%2!=0)			//Printing the odd diagonals
		{
			for(k=i,j=0;j<=i,k>=0;k--,j++)
			{
				cout << *(*(ptr+k)+j) << " ";
			}
		}
	}
	for(i=(n-1);i>=1;i--)		//Now printing the other half of array in decreasing order of length of diagonals
        { 
		if(i%2!=0)		//Printing the odd diagonals
        	{
               		for(j=(n-1),k=(n-i);k<=(n-1),j>=(n-i);j--,k++)
               		{
               			cout << *(*(ptr+k)+j) << " ";
			}
		}
		if(i%2==0)		//Printing the even diagonals
		{
			for(j=(n-i),k=(n-1);j<=(n-1),k>=(n-i);k--,j++)
                	{
               			cout << *(*(ptr+k)+j) << " ";
			}
		}
        }
	cout << endl;
	free(ptr);			//Setting up free the allocated memory
}
