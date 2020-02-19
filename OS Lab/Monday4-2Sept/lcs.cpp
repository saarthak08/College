#include<iostream>

using namespace std;

int **table;
int string_length(string str);
int lcs(string a, string b, int length_a, int length_b);
int max(int a, int b);
void print_lcs(string a, string b, int length_a, int length_b, int length_lcs);

int main(){
    string a,b;
    int length_lcs;
    cout << "Enter any two strings: "<< endl;
    cin >> a;
    cin >> b;
    int length_a=string_length(a);
    int length_b=string_length(b);
    length_lcs=lcs(a,b,length_a,length_b);
    cout << "Length of Longest Common Subsequence between the given two strings is: " << length_lcs << endl<<endl;     
}


int string_length(string str){
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

int max(int a, int b) 
{ 
    return (a>b)?a:b; 
}


int lcs(string a, string b, int length_a, int length_b){
    int i,j; 
    table=(int **)malloc((length_a+1)*sizeof(int *));
    for(i=0;i<=length_a;i++){
        *(table+i)=(int *)malloc((length_b+1)*sizeof(int));
    }

    for(i=0;i<=length_a;i++) 
    {     
        for(j=0;j<=length_b;j++) 
        { 
            if(i==0||j==0){
                table[i][j] = 0; 
            }
            else if(a[i-1]==b[j-1]){
                table[i][j]=table[i-1][j-1]+1; 
            }
            else{
                table[i][j]=max(table[i-1][j], table[i][j-1]); 
            }
        }
    } 
    print_lcs(a,b,length_a,length_b,table[length_a][length_b]);
    return table[length_a][length_b];
}


void print_lcs(string a, string b, int length_a, int length_b, int length_lcs){
    char lcs[length_lcs+1];
    lcs[length_lcs]='\0';
    int i=length_a, j = length_b; 
    while(i>0 && j>0) 
    { 
        if(a[i-1]==b[j-1]) 
        { 
            lcs[length_lcs-1] = a[i-1];
            i--; j--; length_lcs--;      
        } 
        else if (table[i-1][j] > table[i][j-1]){
            i--; 
        }
        else{
            j--; 
        }
    } 
  
   cout << "\n\nLongest Common Subsequence of \"" << a << "\" and \"" << b << "\" is: \"" << lcs <<"\""<<endl;
}