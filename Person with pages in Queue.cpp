#include<iostream>
using namespace std;
struct person{
	string p;
	int page;
	person *next;
};

class Queue{
	person *front,*rear;
	
	public:
		Queue(){
			front=NULL;
			rear=NULL;
		}
	
	bool isEmpty(){
		if(front==NULL)
		  return true; else
		   return false; 
	}	
		
	void toEnque(string per,int pa){
		person *temp=new person();
		temp->p=per;
		temp->page=pa;
		temp->next=NULL;
		
		if(isEmpty()){
			front=rear=temp;
		}else{
			rear->next=temp;
			rear=temp;
		}
		
	}
	
	void toDisplay(){
		
		if(isEmpty()){
			cout<<endl<<"Queue is Empty."<<endl;
		}else{
		   person *tmp=front;
		   cout<<"Person"<<"\t"<<"\t"<<"Pages"<<endl;
		   do{
		   	cout<<tmp->p<<"\t"<<"\t"<<tmp->page<<endl;
		    tmp=tmp->next;
		   }while(tmp!=NULL);
		}
		
		
	}	
};



int main(){
	Queue obj;
	
	obj.toEnque("p1",10);
	obj.toEnque("p2",2);
	obj.toEnque("p3",8);
	obj.toEnque("p4",7);
	obj.toEnque("p5",12);
	
	obj.toDisplay();
}
