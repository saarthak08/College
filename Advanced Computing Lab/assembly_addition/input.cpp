
// Subroutine call  from input.cpp to sum.asm file

// This project is built in MacOS. Used nasm assembler.

/* 

g++ -c input.cpp

nasm -f macho64 sum.asm

g++ -o output sum.o input.o

./output

*/

#include <iostream>
using namespace std;
extern "C" void add(int[], int, int *);

int main()
{
	int array[4], length = 4, result=0, i=0;
	cout << "Enter the four numbers a, b, c and d respectively: " << endl;
	for (i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	add(array, length, &result);
	cout << "\n\nEntered inputs : \na => " << array[0] << "\nb => " << array[1] << "\nc => " << array[2] << "\nd => " << array[3] << endl;  
	cout << "\nThe result of a + b + c - d is : " << result << endl;
	return 0;
}
