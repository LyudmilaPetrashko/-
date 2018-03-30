#include <iostream>
using namespace std;

struct node{
	double data;
	node *next;
};

struct stack{
 	node *head;
 	
 	stack(){head=NULL;}
 	
 	
 	// вывод стека
 	void show(){
 	    node *p=head;
 	    if(p==NULL){
 	        cout<<"stack empty";
 	    }
 	    else{
 	        while(p!=NULL){
 	            cout<<p->data<<" ";
 	            p=p->next;
 	        }
 	    }
 	    cout<<endl;
 	}
 	
 	
 	//добавление элемента
 	void push(double h){
 	    node *q;
 	    q= new node();
 	    q->data=h;
 	    if(head==NULL){
 	        head=q;
 	    }
 	    else{
 	        q->next=head;
 	        head=q;
 	    }
 	}
 	
 	
 	
 	
 	//проверка на пустоту
 	bool empty(){
 	    if(head==NULL){
 	        return 1;
 	        }
 	        else{
 	            return 0;
 	        }
 	}
 	
};
int main(){
	stack g;
	cout<<"show stack: ";
	g.push(9);
	g.push(0);
	g.show();
	cout<<"stack empty?: "<<g.empty()<<endl;
	return 0;
}

