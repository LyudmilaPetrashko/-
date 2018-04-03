// Реализовать структуру или класс для работы с деком long long-чисел и программу с примером работы этой структуры. Дек должен 
//удовлетворять правилу Трёх 
//содержать методы push_back,push_front, pop_back,pop_front,back, front, empty.

#include<iostream>

using namespace std;

//структура одного узла
struct node{
    long long data;
    node *next;
};

//структура для дека
struct deque{
    int size;
    node *front, *back;
    
    //конструктор
    deque(){front=NULL; back=NULL; size=0;}
    
    //конструктор копирования
    deque(const deque& other){
        size=other.size;
        if(size==0){
            front=back=NULL;
        }
        else{
            node *s, *c=other.front;
            front=new node();
            s=new node();
            front->data=other.front->data;
            front->next=s;
            if(size==1){
                        back=front;
            }
            else{
            while(c!=NULL){
                           c=c->next;
                           s->data=c->data;
                           back=s;
                           s->next=new node();
                           s=s->next;
                           }
                }
                back->next=NULL;
            }
    }
    
    
    //оператор =
    deque& operator=(const deque& deq){
       if(this!=&deq){
    node *p, *q;
    while(front!=NULL){  
    p=front->next ;
    delete front;
    front=p;
}
    size=deq.size;
    p=new node();
    front=new node();
    front->data=deq.front->data;
    front->next=p;
    q=deq.front->next;
    p->data=q->data;
    for(int i=2; i<size; i++){
        p->next=new node();
        p=p->next;
        q=q->next;
        p->data=q->data;
    }
    back=p;
    }
    else{
        return *this;
        }
        
    return *this;
    }
    
    
    
    //добавление элемента в начало
    void push_front(long long h){
        node *p;
        p=new node();
        p->data=h;
        if(front==NULL){
            back=front=p;
        }
        else{
        p->next=front;
        front=p;
        }
        back->next=NULL;
        size++;
    }
    
    //добавление элемента в конец
    void push_back(long long t){
        node *x;
        x=new node();
        x->data=t;
        if(back==NULL){
            front=back=x;
        }
        else{
            back->next=x;
            back=x;
        }
        back->next=NULL;
        size++;
    }
    
    //удаление элемента из начала
    long long pop_front(){
        if(size==0){
            cout<<"deque is empty->";
            return 0;
        }
        else{
            long long i=front->data;
            if(size==1){
                delete front;
                back=front=NULL;
                size--;
                return i;
            }           
            else{
            node *y;
            y=front->next;
            delete front;
            front=y;
            size--;
            return i;
            }
        }
    }
    
    //удаление элемента из конца
    long long pop_back(){
        node *prev;
        if(front==NULL){
            cout<<"deque is empty->";
            return 0;
        }
        else{
            long long j=back->data;
            if(size==1){
                delete back;
                front=back=NULL;
                size--;
                return j;
            }
            else{
                prev=front;
                while(prev->next!=back){
                    prev=prev->next;
                }
                delete back;
                back=prev;
                back->next=NULL;
                size--;
                return j;
            }
        }
    }
    
    
    //взятие значение 1 элемента
    long long front1(){
        if(front==NULL){
            cout<<"deque is empty->";
            return 0;
        }
        else{
        return front->data;
        }
    }
    
    
    //взятие значения последнего элемента
    long long back1(){
        if(back==NULL){
            cout<<"deque is empty->";
            return 0;
        }
        else{
            return back->data;
        }
    }
    
    
    //проверка на пустоту
    bool empty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    //вывод дека
    void show(){
        node *r=front;
        if(front==NULL){
            cout<<"deque is empty ";
        }
        else{
            while(r!=NULL){
                cout<<r->data<<" ";
                r=r->next;
            }
        }
        cout<<endl;
    }
    
    
    //деструктор
    ~deque(){
            node *e=front;
            while(front!=NULL){  
                               e=front->next ;
                               delete front;
                               front=e; 
                               }
            }
            
};

int main(){
    deque g, f;
    g.push_front(98);
    g.push_front(54);
    g.push_back(8);
    cout<<"show deque g(left-front, right-back): ";
    g.show();
    f=g;
    cout<<"front: "<<g.front1()<<endl;
    cout<<"back: "<<g.back1()<<endl;
    cout<<"pop_back: "<<g.pop_back()<<endl;
    cout<<"pop_front: "<<g.pop_front()<<endl;
    cout<<"show deque g(left-front, right-back): ";
    g.show();
    cout<<"show deque f(left-front, right-back): ";
    f.show();
    cout<<"the deque is empty?: "<<g.empty()<<endl;
    cout<<"pop_back: "<<g.pop_back()<<endl;
    cout<<"the deque is empty?: "<<g.empty()<<endl;
    cout<<"show deque g(left-front, right-back): ";
    g.show();
    cout<<"pop_back: "<<g.pop_back()<<endl;
    
    return 0;
}
