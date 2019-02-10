#include<iostream>
using namespace std;

//#include "ll.cpp"
class Node{
    public:
    //data
    int data;
//pointer that will store the address of next node
    Node *next;
//constructor which by default makes the pointer point to null
    Node(){
        next=NULL;
    }
};

//declare class.....................................
class linkedlist{
    public:
    //this class contains the head and the nodes linked to each other
    //head-stores the address of a node hence datatype will be Node
    Node *head;
    //tail-stores the address of a node hence datatype will be Node
    Node *tail;
    //constructor to make head point to null by default
    linkedlist(){
        head=NULL;
    }
//insert
    void insert(int value){
        //create a new node in heap
        //declare a pointer in stack which will store address of the created node
        Node *temp=new Node;
        //fill in the data
        temp->data=value;
        //if 1st node is added
        if(head==NULL){
            
        //1st node should have head as its pointer
            head=temp;
        }
        else{
        //for any other node
            
            tail->next=temp;
        }
        //updating the position of tail        
            tail=temp;
    }
//insertAt
    void insertAt(int position, int value)
    {
        if(position !=1){
            //reach the place of insertion
            Node *current=head;
            for(int i=1;i<position-1;i++){
                current=current->next;
            }
            /*int i =1;
            while(i < position-1)
            {
                i++;
                current = current->next;
            }*/
            //create a node
            Node *temp=new Node;
            //fill in the data
            temp->data=value;
            //point to the next node
            temp->next=current->next;
            current->next=temp;
            
        }
        else{
            //insert at 1st position
            Node *temp=new Node;
            temp->data=value;
            temp->next=head;
            head=temp;

            
        }
        
    }
        
        
            
//delete
    void deelete(){
        //declare pointer that points to the address store in tail
        Node *temp=tail;

        //declare a pointer that points to the address stored in head
        Node *current=head;

        //make current point to the previous node of the node which has to be deleted
        while(current->next!=tail){
            current=current->next;
        }

        //let the tail point to the previous node of the node which has to be deleted
        tail=current;

        //break the link b/w the last two nodes
        tail->next=NULL;

        //delete the node permanently    
        delete temp;
    
    }
//deleteAt
    void deleteAt(int position){
        if(position !=1){
            //point current at the 1st node
            Node *current=head;
            //reach the position
            int i=1;
            while(i<position){
                i++;
                current=current->next;
            }
            //point ptr to position node's next node
            Node *ptr=current->next;
            //temp points to the position node
            Node*temp=current;
        
            //reach the previous node
            Node *present=head;
            int j=1;
            while(j<position-1){
                j++;
                present=present->next;
            }
        
            //make a link b/w the previous node and the node after the position node
            present->next=ptr;
        
            //break the link b/w position node and the next node
            temp->next=NULL;

            //delete temp
            delete temp;
        }
        else{
            //point temp to 1st node
            Node*temp=head;
            //assign head to 2nd node
            head=temp->next;
            //delete the 1st node
            delete temp;
        }
            
        
    }
        
//countItems
    int countItems(){
        Node*current=head;
        int i=1;
        while(current->next!=NULL){
            i++;
            current=current->next;
        }
        //cout<<"No. of items in linked list are "<<i<<endl;
        return i;
    }    

//display
    void display(){
        //declare a pointer to store the value of head
        Node *current=head;
        /*for(Node *current=head;current !=NULL;current->next){
            cout<<current->data<<"=>"<<endl;
        }*/
        while(current != NULL){
            cout << current->data << "=>";
            current = current->next;
        }
        cout<<endl;
    }
};
    



//Stack class

class Stack{
//make the class public
    public:
    //declare pointer for 1st element
        Node*top;
        linkedlist l1;
        Stack(){
            top=NULL;
        }
        
        //push
        void push(int value){
            l1.insertAt(1,value);
            top=l1.head;
        }
        
        //pop
        void pop(){
            if(top==NULL){
                    cout<<"Stack does not contain any elements. Pls insert and then delete"<<endl;
            }
            else{
                l1.deleteAt(1);
                top=l1.head;
            }
        }
        
        //Is stack empty?
        bool isEmpty(){
        if(top == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    //Size of Stack
    int size(){
        return l1.countItems();
    }
    
    //display 1st 
    void topDisplay(){
        cout<<top->data<<endl;
    }
    
    //display stack
    void Display(){
        if(top==NULL){
            cout<<"Stack is Empty."<<endl;
        }
        else{
            l1.display();
        }
    }
};
    
        
//int main
int main(){
    Stack s1;
    //call isEmpty
    cout<<s1.isEmpty()<<endl;
    for(int i = 1; i < 4 ; i++){
      s1.push(i);
  }
  
  //call Display function
  s1.Display();
  cout<<"Data of 1st element of stack is ";
  s1.topDisplay();
  cout<<endl;
  //call size function
  cout<<"* No. of elements in stack = "<<s1.size()<<endl;
  cout<<s1.isEmpty()<<endl;
  
  //call pop
  
        s1.pop();
        s1.Display();
  
  
  //call pop
  
        s1.pop();
        s1.Display();
  
  cout<<"* No. of elements in stack = "<<s1.size();
  
  //call pop
  
        s1.pop();
        cout<<"****"<<endl;
        s1.Display();
  
  
  //call pop
      cout<<"////"<<endl;
        s1.pop();
        s1.Display();
  
  
  
  return 0;
  
}


