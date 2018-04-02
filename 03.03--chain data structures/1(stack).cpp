//реализовать структуру для работы со стеками вещественных чисел и программу с примером работы этой структуры.
//стек должен удовлетворять правилу трех, содержать методы push, pop, front, empty.
#include <iostream>
#include<cassert>
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
 	
 	

//конструктор копирования
stack (const stack &other) {
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
}
        


stack& operator = (const stack &st){
    if(this!=&st){
    node *p, *q;
    while(head!=NULL){  
    p=head;
    head=head->next ;
    delete p;
}
    size=st.size;
    p=new node();
    head=new node();
    head->data=st.head->data;
    head->next=p;
    q=st.head->next;
    p->data=q->data;
    for(int i=2; i<size; i++){
        p->next=new node();
        p=p->next;
        q=q->next;
        p->data=q->data;
    }
    }
    else{
        return *this;
        }
        
    return *this;
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
 	
 
 //добавление элемента с консоли
 void push(){
     node *p;
     double s;
     p= new node();
     cout<<"enter a number: ";
     cin>>s;
     p->data=s;
     if(head==NULL){
         head=p;
     }
     else{
         p->next=head;
         head=p;
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
	 cout<<"stack empty";   
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
    p=head->next ;
    delete head;
    head=p;
}
}

};
    

int main(){
	stack g, y;
	g.push(9.8);
	g.push(0.7);
	g.push(7.65749);
	g.push(67.1);
	cout<<"pop: "<<g.pop()<<endl;
	cout<<"front: "<<g.front()<<endl;
	cout<<"the stack is empty?: "<<g.empty()<<endl;
	cout<<endl<<"check operator ="<<endl<<"show stack g(left-back, right-front): ";
	y=g;
	g.head->data++;
	g.show();
	cout<<"show stack y(left-back, right-front): ";
	y.show();
	return 0;
}

}
}

};
    

int main(){
	stack g, y;
	g.push(9.8);
	g.push(0.7);
	g.push(7.65749);
	g.push(67.1);
	cout<<"pop: "<<g.pop()<<endl;
	cout<<"front: "<<g.front()<<endl;
	cout<<"the stack is empty?: "<<g.empty()<<endl;
	cout<<endl<<"check operator ="<<endl<<"show stack g(left-back, right-front): ";
	y=g;
	g.head->data++;
	g.show();
	cout<<"show stack y(left-back, right-front): ";
	y.show();
	return 0;
}
