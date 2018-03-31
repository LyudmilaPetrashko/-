#include <iostream>
using namespace std;


//структура одного узла
struct node{
	double data;
	node *next;
};


//структура для стека
struct stack{
 	node *head;
 	int size;
	
	//конструктор
 	stack(){head=NULL; size=0;}
 	
 	
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
     size++;
 }
 	

//удаление элемента 	
double pop(){
    double i=head->data;
    if(head==NULL){
        cout<<"stack empty"<<endl;
        return 0;
    }
    else{
        node *k;
        k=head->next;
        delete head;
        head=k;
	size--;
    }
    return i;
}
	

	
//взятие значения первого элемента	
double front(){
    node *c=head;
    if(head!=NULL){
        for(int i=1; i<size; i++){
        c=c->next;
        }
        return c->data;
    }
    else{
        return 0;
    
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

	
	
//деструктор
~stack(){
    node *p=head;
    while(head!=NULL){  
    p=head;
    head=head->next ;
    delete p;
}
}

};



int main(){
	stack g;
	g.push(9.8);
	g.push(0.7);
	g.push(7.65749);
	g.push(67.1);
	cout<<"pop: "<<g.pop()<<endl;
	cout<<"front(if stack empty, write '0'): "<<g.front()<<endl;
	cout<<"stack empty?: "<<g.empty()<<endl;
	cout<<"show stack(left-back, right-front): ";
	g.show();
	return 0;
}
