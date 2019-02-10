#include<iostream>
//#include "LL.cpp"
using namespace std;
//Include lib.
#include<iostream>
using namespace std;

//declare class for making a node
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
		tail=NULL;
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
		else if(head==NULL && tail==NULL){
			Node *temp=new Node;
			temp->data=value;
			head=temp;
			tail=head;
			cout<<"****"<<endl;
		}
		else if(position==1){
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
	



class Queue{
	public:
		linkedlist l1;
		Node * end;
		Node*front;
		Queue(){
			end=NULL;
			//front=l1.tail;
			front=NULL;
		}
	void enqueue(int value){
		l1.insertAt(1,value);
		end=l1.head;
		front=l1.tail;
		//top=new_head;
	}
	void dequeue(){
		if(front==NULL){
			cout<<"The que is empty...pls insert an element and then delete it."<<endl;
		}
		else{
			l1.deelete();
			end=l1.head;
			front=l1.tail;	
		}
		//top=new_head;
	}
	bool isEmpty(){
		if(end==NULL){
		return true;
		}
		else{
		return false;
		}
	}
	int size(){
	return l1.countItems();
	}
	void topDisplay(){
		cout<<end->data<<endl;
	}
	void Display(){
		l1.display();
	}
};


int main(){
	Queue q1;
	cout<<q1.isEmpty()<<endl;
	for(int i=0;i<5;i++){
		q1.enqueue(i);
	}
	q1.Display();
	q1.topDisplay();
	cout<<q1.front->data;
	cout<<"****";
	q1.dequeue();
	cout<<q1.front->data<<endl;
	q1.dequeue();
	cout<<q1.front->data<<endl;
	q1.dequeue();
	cout<<q1.front->data<<endl;
	q1.dequeue();
	cout<<q1.front->data<<endl;
	//q1.dequeue();
	//cout<<q1.front->data;
	//q1.dequeue();
	
	q1.Display();
	cout<<endl;
	q1.topDisplay();
	cout<<q1.size()<<endl;
	cout<<q1.isEmpty()<<endl;
	return 0;
}
