#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;


struct value{
    double av_val;//среднее значение
    double error;//абсолютная погрешность
    string name;//название переменной(если нужен ввод данных)

    int a;//кол-во экспериментов


    double dig_er, disp_er, calib_er;//погрешности отсчитывания, по разбросу, градуировки

    value(string n):  name(n) { //конструктор
            cout<<endl<<"enter the number of experiments("<<name<<"): ";
            cin>>a;
            double* arr=new double[a];
            double curr=0, cur=0;
            cout<<endl<<"enter the digitizing error("<<name<<"): ";
            cin>>dig_er;
            cout<<"enter the calibration error("<<name<<"): ";
            cin>>calib_er;
            cout<<endl;

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
                curr=curr+pow((av_val-arr[i]),2);// вычисление среднего квадратического отклонения
            }
            if(a==1){
                disp_er=0;
            }
            else{
            disp_er=2*sqrt(curr/(a-1));// c 90% точности
            }
            error=sqrt(pow(dig_er,2)+pow(disp_er,2)+pow(calib_er,2));

            delete[] arr;
    }

    value(){ //конструктор по умолчанию
        av_val=0;
        error=0;
    }


    value(double x, double y): av_val(x), error(y){ //конструктор для переменной, где все уже посчитано
        }

    value(const value& v){ //конструктор копирования
        av_val=v.av_val;
        error=v.error;
    }

    value& operator=(const value& v1){
        av_val=v1.av_val;
        error=v1.error;
        return *this;
    }


     value& operator=(double vv1){
        av_val=vv1;
        error=0;
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
        mult1.error=error;
        return mult1;
    }


    value operator*(const value& v4){
        value mult2;
        mult2.av_val=av_val*v4.av_val;
        mult2.error=sqrt(error*error*v4.av_val*v4.av_val+v4.error*v4.error*av_val*av_val);
        return mult2;
    }


    value operator/(double y){
        value qu1;
        qu1.av_val=av_val/y;
        qu1.error=error;
        return qu1;
    }


    value operator/(const value& v5){
        value qu2;
        qu2.av_val=av_val/v5.av_val;
        qu2.error=sqrt(error*error*v5.av_val*v5.av_val+v5.error*v5.error*av_val*av_val)/(v5.av_val*v5.av_val);
        return qu2;
    }

    value operator-(){
        value y;
        y.av_val=-av_val;
        y.error=error;
        cout<<y.av_val<<" "<<y.error;
        return y;
    }

    bool operator==(const value& v6){
        if(av_val==v6.av_val&&error==v6.error){
            return 1;
        }
        else{
            return 0;
        }
    }

};

 void show(value& va){ //вывод значения(окруление среднего значения и погрешности)

        if(abs(va.av_val)>abs(va.error)){
            if(abs(va.error)>1){
                    va.error=int(va.error*10)/10;
                    va.av_val=round(va.av_val*10)/10;
            }
            else{
                int n=0;
                double f=va.error;
                while(abs(f)<1){
                   f*=10;
                   n++;
                }
                if(int(abs(va.error)*pow(10,n+1)>=15)){
                        va.error=round(va.error*pow(10,n))/pow(10,n);
                        va.av_val=round(va.av_val*pow(10,n))/pow(10,n);
                    }
                else{
                    va.error=round(va.error*pow(10,n+1))/pow(10,n+1);
                    va.av_val=round(va.av_val*pow(10,n+1))/pow(10,n+1);
                    }
            }
            cout<<"("<<va.av_val<<"+-"<<va.error<<")";
        }


    else{
        if(abs(va.av_val)>1){
            va.error=int(va.error*10)/10;
            va.av_val=round(va.av_val*10)/10;
            }
        else{
            int n=0;
            double f=va.av_val;
            while(abs(f)<1){
                f*=10;
                n++;
            }
        if (int(abs(va.av_val)*pow(10,n+1)>=15)){
            va.error=round(va.error*pow(10,n))/pow(10,n);
            va.av_val=round(va.av_val*pow(10,n))/pow(10,n);
            }
        else{
            va.error=round(va.error*pow(10,n+1))/pow(10,n+1);
            va.av_val=round(va.av_val*pow(10,n+1))/pow(10,n+1);
            }
        }
        cout<<"("<<va.av_val<<"+-"<<va.error<<")";
    }

}

    value pow(const value& v5, double n){
            value p;
            p.av_val=pow(v5.av_val, n);
            p.error=p.av_val*n*(v5.error/v5.av_val);
            return p;
        }

    value operator+(double x1, value& va1){
        value k1=va1+x1;
        return k1;
    }

    value operator-(double x2, value& va2){
        value k2;
        k2.av_val=x2-va2.av_val;
        k2.error=va2.error;
        return k2;
    }

    value operator*(double x3, value& va3){
        value k3=va3*x3;
        return k3;
    }

    value operator/(double x4, value& va4){
        value k4;
        k4.av_val=x4/va4.av_val;
        k4.error=va4.error;
        return k4;
    }


int main(){
    value t("time"), s("distance"), u;
    u=s/t;
    cout<<"u=";
    show(u);
    return 0;
}
