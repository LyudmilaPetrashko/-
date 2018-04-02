//реализовать класс для работы с очередью символов и программу с примером работы этого классаю
//очередь должна удовлетворять правилу трех, содержать методы push, pop, front, empty.

#include <iostream>
#include<cassert>
using namespace std;


//структура одного узла
struct node{
	char data;
	node *next;
};


//структура для очереди
class queue{
 	
 	int size;


public:

node *head, *tail;

//конструктор
queue(){head=NULL; tail=NULL; size=0;}
 	
 	

//конструктор копирования
queue (const queue &other) {
    size=other.size;
    node *s, *c=other.head;
    head=new node();
    s=new node();	
    head->data=other.head->data;
    head->next=s;	
    while(c!=NULL){
        c=c->next;
        s->data=c->data;
        s=s->next;
	    s=new node();    
        }
        tail=s;
}
        


queue& operator = (const queue &que){
    if(this!=&que){
    node *p, *q;
    while(head!=NULL){  
    p=head->next ;
    delete head;
    head=p;
}
    size=que.size;
    p=new node();
    head=new node();
    head->data=que.head->data;
    head->next=p;
    q=que.head->next;
    p->data=q->data;
    for(int i=2; i<size; i++){
        p->next=new node();
        p=p->next;
        q=q->next;
        p->data=q->data;
    }
    tail=p;
    }
    else{
        return *this;
        }
        
    return *this;
}
        
 
 	
 //добавление элемента
 void push(char h){
     node *q;
     q = new node();
     q->data=h;
     if(head==NULL){
         head=tail=q;
     }
     else{
         tail->next=q;
         tail=q;
     }
     size++;
 }
 
 
    
 // вывод очереди
 void show(){
     node *p=head;
     if(p==NULL){
         cout<<"queue empty";
     }
     else{
         while(p!=NULL){
             cout<<p->data<<" ";
             p=p->next;
         }
     }
     cout<<endl;
 }
 	
 
 //добавление элемента с консоли
 void push(){
     node *p;
     char g;
     cout<<"enter a number: ";
     cin>>g;
     p = new node();
     p->data=g;
     if(head==NULL){
         head=tail=p;
     }
     else{
         tail->next=p;
         tail=p;
     }
     size++;
 }
 	

//удаление элемента 	
char pop(){
    char i=head->data;
    if(head==NULL){
        cout<<"queue empty"<<endl;
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
char front(){
    if(head!=NULL){
        return head->data;
    }
    else{
	 cout<<"queue empty";   
        return '0';
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
~queue(){
    node *p=head;
    while(head!=NULL){  
    p=head->next ;
    delete head;
    head=p;
}
}

};
    

int main(){
	queue g, y;
	g.push('+');
	g.push('c');
	g.push('+');
	g.push('+');
	cout<<"pop: "<<g.pop()<<endl;
	cout<<"front: "<<g.front()<<endl;
	cout<<"the queue is empty?: "<<g.empty()<<endl;
	cout<<endl<<"check operator ="<<endl<<"show queue g(left-head, right-tail): ";
	y=g;
	g.show();
	y.head->data='s';
	cout<<"show queue y(left-head, right-tail): ";
	y.show();
	return 0;
}
