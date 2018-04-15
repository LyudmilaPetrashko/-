#include<iostream>
#include<cmath>
#include<string>

using namespace std;

struct value{     
    double av_val;//среднее значение
    double error;//абсолютная погрешность
    string name;//название переменной(если нужен ввод данных)

    int a;//кол-во экспериментов


    double read_er, scal_er, calib_er;//погрешности отсчитывания, по разбросу, градуировки

    value(string n):  name(n) { //конструктор
            cout<<"enter the number of experiments("<<name<<"): ";
            cin>>a;
            double* arr=new double[a];
            double divv, curr=0, cur=0;
            cout<<"enter the reading error("<<name<<"): ";
            cin>>read_er;
            cout<<"enter the calibration error("<<name<<"): ";
            cin>>calib_er;

            for(int i=0; i<a; i++){
                cout<<"enter the result of the "<<i+1<<" experiment("<<name<<"): ";
                cin>>arr[i];
            }

            for(int i=0; i<a; i++){
                cur=cur+arr[i];
            }
            cout<<endl;
            av_val=cur/a;

            for(int i=0; i<a; i++){
                curr=curr+pow((av_val-arr[i]),2.0);// вычисление среднего квадратического отклонения
            }
            if(a==1){
                scal_er=0;
            }
            else{
            scal_er=3*sqrt(curr/(a-1));// c 95% точности
            }
            error=sqrt(pow(read_er,2)+pow(scal_er,2)+pow(calib_er,2));
            
            delete[] arr;
    }

    value(){ //конструктор по умолчанию 
        name='0';
        av_val=0;
        error=0;
        a=0;
        read_er=0;
        scal_er=0;
        calib_er=0;
    }


    value(double x, double y, string h): av_val(x), error(y), name(h){ //конструктор для переменной, где все уже посчитано
        a=0;
        read_er=0;
        scal_er=0;
        calib_er=0;
        }

    value(const value& v){ //конструктор копирования
        av_val=v.av_val;
        error=v.error;
        a=v.a;
        read_er=v.read_er;
        scal_er=v.scal_er;
        calib_er=v.calib_er;
    }

    value& operator=(const value& v1){
        av_val=v1.av_val;
        error=v1.error;
        a=v1.a;
        read_er=v1.read_er;
        scal_er=v1.scal_er;
        calib_er=v1.calib_er;
        return *this;
    }


    value operator+(const value& v2){
        value sum1;
        sum1.av_val=av_val+v2.av_val;
        sum1.error=sqrt(error*error+v2.error*v2.error);
        return sum1;
    }

    value operator+(double a){
        value sum2;
        sum2.av_val=av_val+a;
        sum2.error=error;
        return sum2;
    }


    value operator-(const value& v3){
        value div1;
        div1.av_val=av_val-v3.av_val;
        div1.error=sqrt(error*error+v3.error*v3.error);
        return div1;
    }

    value operator-(double b){
        value div2;
        div2.av_val=av_val-b;
        div2.error=error;
        return div2;
    }


    value operator*(double x){
        value mult1;
        mult1.av_val=av_val*x;
        mult1.error=error*x;
        return mult1;
    }


    value operator*(const value& v4){
        value mult2;
        mult2.av_val=av_val*v4.av_val;
        mult2.error=mult2.av_val*sqrt(error*error/(av_val*av_val)+v4.error*v4.error/(v4.av_val*v4.av_val));
        return mult2;
    }


    value operator/(double y){
        value qu1;
        qu1.av_val=av_val/y;
        qu1.error=error/y;
        return qu1;
    }


    value operator/(const value& v5){
        value qu2;
        qu2.av_val=av_val/v5.av_val;
        qu2.error=qu2.av_val*sqrt(pow(error, 2.0)/pow(av_val, 2.0)+pow(v5.error, 2.0)/pow(v5.av_val, 2.0));
        return qu2;
    }

    void show(){ //вывод значения
        cout<<endl<<av_val<<"+-"<<error<<endl;
    }

};

    value pow(const value& v5, double n){
            value p;
            p.av_val=pow(v5.av_val, n);
            p.error=p.av_val*n*(v5.error/v5.av_val);
            return p;
        }



int main(){
    string name1, name2;
    getline(cin, name1);
    getline(cin, name2);

    value v1, v2(name1), sum, dif, v3(name2), mult_v, mult_n, po, quo_v, quo_n, example;

    cout<<endl<<"show v1: ";
    v1=v2;
    v1.show();

    cout<<endl<<"show v2: ";
    v2.show();

    cout<<endl<<"show v3: ";
    v3.show();

    sum=v1+v2;
    cout<<endl<<"show sum: ";
    sum.show();

    dif=v1-v3;
    cout<<endl<<"show difference: ";
    dif.show();

    mult_v=v1*v2;
    cout<<endl<<"show product_v: ";
    mult_v.show();

    mult_n=v1*2;
    cout<<endl<<"show product_n: ";
    mult_n.show();

    quo_v=v1/v3;
    cout<<endl<<"show quotient_v: ";
    quo_v.show();

    quo_n=v1/2;
    cout<<endl<<"show quotient_n: ";
    quo_n.show();

    po=pow(v2,2.0);
    cout<<endl<<"show pow: ";
    po.show();

    example=v2*v3*(v1+v2)/v3*7;
    cout<<endl<<"show example: ";
    example.show();

    return 0;
}
