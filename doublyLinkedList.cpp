#include<iostream>
#include<stdlib.h>

using namespace std;

class doublyLinkedList{
	private:
		struct node{
			int data;
			node *prev;
			node *next;
		};
		node *head=NULL, *ptr, *ptr1;
	
	public:
		void addf();
		void addn();
		void remove();
		void display();

};

void doublyLinkedList::addf(){
	ptr=(struct node*)malloc(sizeof(struct node));
	cout<<endl<<"Enter Data: ";
	cin>>ptr->data;
	ptr->prev=NULL;
	ptr->next=NULL;
	head=ptr;
}

void doublyLinkedList::addn(){
	ptr1=(struct node*)malloc(sizeof(struct node));
	cout<<endl<<"Enter Data: ";
	cin>>ptr1->data;
	ptr1->prev=ptr;
	ptr1->next=NULL;
	ptr->next=ptr1;
	ptr=ptr1;
}

void doublyLinkedList::display(){
	ptr=head;
	cout<<endl;
	while(ptr->next!=NULL){
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	cout<<ptr->data;
}

int main(){
	doublyLinkedList o1;
	char choice='y';
	o1.addf();
	while (choice=='y'||choice=='Y'){
		o1.addn();
		cout<<endl<<"Add More?(y/n): ";
		cin>>choice;
	}
	o1.display();
	return 0;
}
