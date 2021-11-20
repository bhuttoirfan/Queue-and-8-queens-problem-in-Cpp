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
    
    void toSort(){
    	
    	if(isEmpty()){
			cout<<endl<<"Queue is Empty, and there is nothing to sort."<<endl;
		}else{
			person *pre = front;
	person *cur;
	for (pre; pre != NULL; pre = pre->next) {
		for(cur = pre->next; cur != NULL; cur = cur->next) {
			if (pre->page < cur->page) {
				int pages;
				string n;
				pages=pre->page;
				n=pre->p;
				
				pre->page=cur->page;
				pre->p=cur->p;
				
				cur->page=pages;
				cur->p=n;			
			}
		}
	}
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
	
	cout<<endl<<"Before Sorting:"<<endl;
	obj.toDisplay();
	obj.toSort();
	cout<<endl<<"After Sorting with respect to pages:"<<endl;
	obj.toDisplay();
}
