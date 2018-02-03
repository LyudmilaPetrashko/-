/*1-2) Реализовать структуру или класс для работы с комплексными числами и программу с примером работы этой структуры.
В структуре должны быть перегружены арифметика для комплексных и вещественных чисел, сравнения и определены методы для
получения/изменения вещественной и мнимой части, взятия модуля и сопряжения.*/


#include <iostream>
using namespace std;

struct Complex{
    double a;
    double b;
};



class complex{
    Complex comp;
   public: 
complex(double x=0.0, double y=0.0){ //числа вида (а,б) на самом деле выглядят так с=а+ib
    comp.a=x;
    comp.b=y;
}


bool operator==(const complex& val1 ){
	return ((comp.a==val1.comp.a)&&(comp.b==val1.comp.b));
}


bool operator!=(const complex& val2) {
	return !((comp.a==val2.comp.a)&&(comp.b==val2.comp.b));
}


complex operator+(const complex& val3){
	complex sum;
	sum.comp.a=comp.a+val3.comp.a;
	sum.comp.b=comp.b+val3.comp.b;
	return sum;
}


complex operator-(const complex& val4){
	complex dif;
	dif.comp.a=comp.a-val4.comp.a;
	dif.comp.b=comp.b-val4.comp.b;
	return dif;
}


complex operator*( int i){
	complex mult1;
	mult1.comp.a=i*comp.a;
	mult1.comp.b=i*comp.b;
	return mult1;
}

complex operator*(const complex& val5){
	complex mult2;
	mult2.comp.a=comp.a*val5.comp.a-comp.b*val5.comp.b;
	mult2.comp.b=comp.a*val5.comp.b+comp.b*val5.comp.a;
	return mult2;
}
	
	
	
complex operator/(const complex& val6){
	complex quo;
   if((val6.comp.b==0)&&(val6.comp.a==0)){
cout<<"error";
  }
else{
	quo.comp.a=(comp.a*val6.comp.a+comp.b*val6.comp.b)/(val6.comp.a*val6.comp.a+val6.comp.b*val6.comp.b);
	quo.comp.b=(val6.comp.a*comp.b-comp.a*val6.comp.b)/(val6.comp.a*val6.comp.a+val6.comp.b*val6.comp.b);
	return quo;
}}

void display(complex h){
    cout<<"="<<h.comp.a<<"+"<<h.comp.b<<"*"<<"i";
	  }};
	  


int main() {
    double n, m, k, l;
    int a,b, i;
	cin>>n>>m>>k>>l>>i;
	complex p(n,m), q(k,l), c,d,e,f, g, h;
	if(p==q){
		a=1;
	} else{
		a=0;
	}
	if(p!=q){
		b=1;
	} else{
		b=0;
	}
	c=p+q;
	d=p-q;
	e=p*i;
	f=p*q;
	
	
	cout<<"!=: "<<b<<endl;
	cout<<"==: "<<a<<endl;
	cout<<"sum: c";
	c.display(c);
	cout<<endl<<"dif: d";
	d.display(d);
	cout<<endl<<"mult1: e";
	e.display(e);
	cout<<endl<<"mult2: f";
	f.display(f);
cout<<endl<<"quo: ";
    h=p/q;
cout<<endl<<"control: ";
    g=p*q+q*3-p/q;
	return 0;
}
