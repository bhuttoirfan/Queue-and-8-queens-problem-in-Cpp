#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct process {
	process *next;
	int page;
	int slot;
	string p;
};

class Queue {
	process *front, *rear;
	int num;
public:
	Queue() {
		front = rear = NULL;
		num = 3;
	}

	bool isEmpty() {
		if (front == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void toInsert(string x,int num) {
		process *tmp = new process;

		tmp->p = x;
		tmp->page = num;
		tmp->next = NULL;
		if (isEmpty()) {
			front = rear = tmp;
		}
		else {
			rear->next = tmp;
			rear = tmp;
		}
	}
	
	void sorting(){
		if(isEmpty()){
			cout<<endl<<"Queue is Empty, and there is nothing to sort."<<endl;
		}else{
			process *pre = front;
	process *cur;
	for (pre; pre != NULL; pre = pre->next) {
		for(cur = pre->next; cur != NULL; cur = cur->next) {
			if (pre->slot > cur->slot) {
				
				int pages;
				string n;
				int slots;
				
				pages=pre->slot;
				n=pre->p;
				slots=pre->slot;
				
				pre->page=cur->page;
				pre->p=cur->p;
				pre->slot=cur->slot;
				
				cur->page=pages;
				cur->p=n;
				cur->slot=slots;			
			}
		}
	}
		}
	}

	void processing() {
		if (isEmpty()) {
			cout << endl << "Empty" << endl;
		}
		else {
			process *tmp = front;
			do {
				tmp->slot = tmp->page / num;
				tmp = tmp->next;
			} while (tmp != NULL);
		}
		
		sorting();//just to show greater value of slot at the end.
	}
   
   void display(){
   	process *t=front;
   	cout<<"Person"<<"\t"<<"Pages"<<"\t"<<"Slots Required"<<endl;
   	do{
   		cout<<t->p<<" "<<t->page<<"\t"<<t->slot<<endl;
   		t=t->next;
	   }while(t!=NULL);
   }

};

int main() {
	Queue pq;

	pq.toInsert("person1",15);
	pq.toInsert("person2",4);
	pq.toInsert("person3",9);
	pq.toInsert("person4",2);
	pq.toInsert("person5",63);

	pq.processing();
    pq.display();
    cout<<endl;
	system("pause");
}
