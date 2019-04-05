#include<iostream>
#include<stdlib.h>

using namespace std;

struct circularList{
	int data;
	circularList* link;	
};

circularList *start, *ptr, *ptr1;
int number=0;


void addf(){
	ptr=(struct circularList *)malloc(sizeof(struct circularList));
	cout<<endl<<"Enter Data: ";
	cin>>ptr->data;
	start=ptr;
	number++;
}

void addn(){
	ptr1=(struct circularList *)malloc(sizeof(struct circularList));
	ptr->link=ptr1;
	cout<<endl<<"Enter Data: ";
	cin>>ptr1->data;
	ptr=ptr1;
	number++;
}

void display(){
	int count=0;
	ptr=start;
	while(count<number){
		cout<<ptr->data<<"  ";
		ptr=ptr->link;
		count++;
	}
}

void josephus(int pos){
	ptr=start;
	if (pos>number+1) cout<<endl<<"Invalid Entry! ";
	for(int i=0; i<pos-1; i++){
		ptr=ptr->link;
	}
	circularList *newp;
	newp=ptr->link;
	ptr->link=newp->link;
	number--;
	start=newp->link;
	
}

int main(){
	addf();
	char ch='y';
	while(ch=='y'||ch=='Y'){
		addn();
		cout<<endl<<"Enter More(y/n)?: ";
		cin>>ch;
	}
	ptr1->link=start;
	
	display();
	cout<<endl;
	cout<<endl<<"Enter position for josephus: ";
	int n;
	cin>>n;
	n=n-1;
	
	while(number>=n-1){
		josephus(n);
		display();
		cout<<endl;
	}
	
	return 0;
}

