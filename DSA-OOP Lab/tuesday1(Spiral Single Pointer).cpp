#include<iostream>

using namespace std;
int main(int argv, char *argc[])
{
	int *ptr,i,j,a,b,n;
	ptr=(int*)malloc(n*n*sizeof(int));
	cout << "Enter the number of rows/columns:\n";
	cin >> n;
	cout << "\n\nEnter the elements:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin >> *(ptr+(i*n)+j);
		}
	}
	cout << "\n\nEntered  elements:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout << *(ptr+(i*n)+j);
			cout << " ";
		}
		cout << "\n";
	}
	free(ptr);
}
			
