#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
	int info;
	node* link;
};

node *start;
node *ptr, *ptr1;

void create1(){

	ptr=(struct node *)malloc(sizeof(struct node));
	cout<<endl<<"Enter Element: ";
	cin>>ptr->info;
	start=ptr;
}

void createn(){
	ptr1=(struct node *)malloc(sizeof(struct node));
	cout<<endl<<"Enter Element: ";
	cin>>ptr1->info;
	ptr->link=ptr1;
	ptr=ptr1;
}

int searchEle(){
	cout<<endl<<"Enter element to be searched: ";
	int ele;
	cin>>ele;
	ptr=start;
	int loc=1;
	while(ptr!=NULL){
		if(ptr->info==ele){
			cout<<endl<<"Element Found at "<<loc<<".";
			return loc;
			break;
		}
		else{
			ptr=ptr->link;
			loc++;
			if(ptr==NULL)cout<<endl<<"Element not found.";
		}
		
	}
}

void deleteEle(){
	cout<<endl<<"Enter Element to be deleted: ";
	int ele;
	cin>>ele;
	int pass=1;
	ptr=start;
	node *next;
	while(ptr!=NULL){
		if(pass==1){
			if (ptr->info==ele){
				start=ptr->link;
				break;
			}
			pass++;
		}
		next=ptr->link;
		if (next->info==ele){
			ptr->link=next->link;
			free(next);
			break;
		}
		else{
			ptr=ptr->link;
			if(ptr==NULL)cout<<endl<<"Element not found.";
		}
	}
}

void display(){
	ptr=start;
	while(ptr!=NULL){
		cout<<ptr->info<<"  ";
		ptr=ptr->link;
	}
	
}

void addEle(){
	cout<<endl<<"Enter Element after which to add new Element: ";
	int pre;
	cin>>pre;
	cout<<endl<<"Enter Element to be added: ";
	int newEle;
	cin>>newEle;
	node *newptr;
	newptr=(struct node *)malloc(sizeof(struct node));
	newptr->info=newEle;
	ptr=start;
	while(ptr!=NULL){
		if(ptr->info==pre){
			node *saver;
			saver=ptr->link;
			ptr->link=newptr;
			newptr->link=saver;
			break;
		}
		else ptr=ptr->link;
	}
	
	
}

int main(){
	char ch;
	create1();
	ch='y';
	while(ch=='y'){
		createn();
		cout<<endl<<"Add more? (y/n): ";
		cin>>ch;
	}
	ptr1->link=NULL;
	display();
	
	int a=searchEle();
	
	deleteEle();
	display();
	
	addEle();
	display();
	
	
	return 0;
}

