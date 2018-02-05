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
complex(double x=0.0, double y=0.0){ 
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



complex operator*(const complex& val5){
	complex mult2;
	mult2.comp.a=comp.a*val5.comp.a-comp.b*val5.comp.b;
	mult2.comp.b=comp.a*val5.comp.b+comp.b*val5.comp.a;
	return mult2;
}
	
	
	
complex operator/(const complex& val6){ // re - вещественная часть, im - мнимая часть
	complex quo;
   double r = val6.comp.a * val6.comp.a + val6.comp.b * val6.comp.b;
   quo.comp.a = (comp.a * val6.comp.a + comp.b * val6.comp.b) / r;
   quo.comp.b = (comp.b * val6.comp.a - comp.a * val6.comp.b) / r;
     return quo;
}


complex operator = (complex* val7)
{
	if (val7 == this)
		return *this;
	return complex(this->comp.a = val7->comp.a, this->comp.b = val7->comp.b);
}


void init(double a,double b)
{
    comp.a=a;
    comp.b=b;
}

complex conj()
{
    complex res1;
    double y=-comp.b;
    double x=comp.a;
    res1.init(x,y);
    return res1;
}

complex mod()
{
    complex res2;
    double x=-comp.a;
    double y=-comp.b;
    res2.init(x,y);
    return res2;
}

double output_re(){
    double x=comp.a;
    return x;
}


double output_im{
    double y=comp.b;
    return y;
}


void display(){
    cout<<"=("<<comp.a<<","<<comp.b<<")";
	  }};
	  


int main() {
    double n, m, k, l, i, v, w;
    int a,b;
	cin>>n>>m>>k>>l>>i;
	complex p(n,m), q(k,l), c,d,e,f, g, h, j(7,8), x, y;
	if(p==q){
		a=1;
	} else{
		a=0;
	}
	if(p!=q){
		b=1;
	} else {
		b=0;
	}
	c=p+q;
	d=p-q;
	e=p*i;
	f=p*q;
	j=p;
	h=p/q;
    x=p.conj();
    y=q.mod();
    v=p.output_re();
    w=q.output_im();
	
	cout<<"in complex numbers first number is real part, second number is imaginary part"<<endl<<endl;;
	cout<<"!=: "<<b<<endl;
	cout<<"==: "<<a;
	cout<<endl<<"=: j";
	j.display();
	cout<<"sum: c";
	c.display();
	cout<<endl<<"dif: d";
	d.display();
	cout<<endl<<"mult1: e";
	e.display();
	cout<<endl<<"mult2: f";
	f.display();
	cout<<endl<<"quo: h";
	h.display();
	cout<<endl<<"conj: x(p)";
	x.display();
	cout<<endl<<"mod: y(q)";
	y.display();
    cout<<endl<<"real part: v(p)="<<v<<endl<<"imaginary part: w(q)="<<w;
       
cout<<endl<<"control: g";
    g=p*q+q*3-p/q;
    g.display();
	return 0;
}
