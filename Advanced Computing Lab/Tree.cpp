#include<iostream>

using namespace std;

typedef struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
}Node;


Node* queue[100];
int front=0;
int rear=-1;
int length=0;
void pushQueue(Node* tempData);
Node* popQueue();
void printQueue();
void printTree(Node* head);



int main() {
    Node *head;
    head=new Node;
    cout << "Enter the root node:" <<endl;
    cin >> head->data;
    pushQueue(head);
    while(length!=0) {
        int tempFlag;
        Node* tempNode=popQueue();
        cout << "\n\nPress \'1\' to enter the left child of "<<tempNode->data<<endl;
        cin >> tempFlag;
        if(tempFlag==1) {
            Node* leftNode;
            leftNode=new Node;
            cout << "\nEnter the left child of "<< tempNode->data << endl;
            cin >> leftNode->data;
            tempNode->leftChild=leftNode;
            pushQueue(leftNode);
        }
        cout << "\n\nPress \'1\' to enter the right child of "<<tempNode->data << endl;
        cin >> tempFlag;
        if(tempFlag==1) {
            Node* rightNode;
            rightNode=new Node;
            cout << "\nEnter the right child of "<< tempNode->data << endl;
            cin >> rightNode->data;
            tempNode->rightChild=rightNode;
            pushQueue(rightNode);
        }      
    }
    cout << "\n\nInitial Tree (Pre-Order Traversal): " <<endl;
    printTree(head);
    return 0;
}

void printQueue() {
    int temp=front;
    while(temp!=rear+1) {
        cout<< queue[temp]->data<<"\t";
        temp++;
    }
}

void pushQueue(Node* tempData) {
    queue[++rear]=tempData;
    length++;
}

Node* popQueue() {
    Node* temp;
    if(length==0) {
        cout << "Queue underflow!";
        exit(0);
    }
    temp=queue[front];
    front++;
    length--;
    return temp;
} 

void printTree(Node* head) {
    if(head!=NULL) {
        cout<<head->data<<endl;
        printTree(head->leftChild);
        printTree(head->rightChild);
    }
}