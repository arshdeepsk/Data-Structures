#include<iostream>
#include<process.h>

using namespace std;

class dynamicArray{
	private: 
		int len;											//current array length
		int capacity;										//total available capacity of array
		int *arr;											//pointer to first element of array
	
	public:
		dynamicArray();										//constructor to initialise array
		void add();											//function to add element
		void size();										//returns len
		void totalLength();									//returns capacity
		void display();										//displays array
		void removeIndex();									//removes element at index
		void sort();										//sorts array
};

dynamicArray::dynamicArray(){
	len=0;
	capacity=0;
	cout<<endl<<"Enter required capacity of array:";
	cin>>capacity;
	if(capacity<0) cout<<endl<<"Error: Negative Capacity";
	else arr=new int [capacity];							//dynamic memory allocation to array. Returns address hence assigned to a pointer.
}	

void dynamicArray::add(){
	if ((len+1)>capacity) {									//check for invalid input
		if (capacity==0) capacity=1;
		else capacity=capacity*2;							//capacity is being doubled
		int * newArr=new int [capacity];					//new temporary array created
		for(int i=0; i<len; i++) newArr[i]=arr[i];			//elements of old array transferred into new array
		arr=newArr;											//new array assigned to old array
	}
	cout<<endl<<"Enter Element: ";
	int elem;
	cin>>elem;
	arr[len]=elem;
	len++;
	cout<<endl<<"Add more? (y/n): ";						//option to add more elements
	char choice;
	cin>>choice;
	if(choice=='y'||choice=='Y') add();
	else display();
}

void dynamicArray::sort(){									//bubble sort to sort array
	for(int i=0; i<len-1; i++){
		for(int j=0; j<len-i-1; j++){
			if (arr[j]>arr[j+1]) {
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	display();
}

void dynamicArray::removeIndex(){							//fucntion to remove element at given index
	cout<<endl<<"Enter index to be removed: ";
	int index;
	cin>>index;
	if(index>len){											//check for valid index
		cout<<endl<<"Invalid Index!";
		exit(0);
	}
	else{
		int *newArr;										//new array created. All elements except the one to be removed transferred into new array
		newArr=new int [capacity];
		for(int i=0, j=0; i<len; ){
			if(j!=index-1){
				newArr[i]=arr[j];
				i++;
				j++;	
			}
			else{
				j++;
			}
		}
		arr=newArr;											//new array assigned to old array
	}
														
	len--;													//current length reduced by 1 as element removed
	display();
}


void dynamicArray::size(){
	cout<<endl<<"Size of array is: "<<len;
}

void dynamicArray::totalLength(){
	cout<<endl<<"Capacity of array is: "<<capacity;
}

void dynamicArray::display(){
	cout<<endl;
	for(int i=0; i<len; i++) cout<<arr[i]<<" ";
}

int main(){
	dynamicArray arr1;
	arr1.add();
	while(true){											//menu driven input. Menu runs infinitely.
		cout<<endl<<"Press 1 to add another element:";
		cout<<endl<<"Press 2 to delete an element: ";
		cout<<endl<<"Press 3 to sort: ";
		cout<<endl<<"Press 4 to display: ";
		cout<<endl<<"Press 9 to exit: "<<endl;
		
		int choice;
		cin>>choice;
	
		switch(choice){
			case 1: arr1.add();
				break;
			case 2: arr1.removeIndex();
				break;
			case 3: arr1.sort();
				break;
			case 4: arr1.display();
				break;
			case 9: cout<<endl<<"BYE!";
					exit(0);
				break;
			default: cout<<endl<<"Invalid Imput!!";
		}
	}
	
	return 0;
}
