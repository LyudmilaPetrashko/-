#include<iostream>
#include<cmath>
#include<string>

using namespace std;

struct value{
    double av_val;
    double error;
    string name;

    int a;


    double cout_er, scal_er, calib_er;

    value(int k, string n):  name(n) {
            a=k;
            double* arr=new double[a];
            double divv, curr=0, cur=0;
            cout<<"vvedite ceny deleniya("<<name<<"): ";
            cin>>divv;
            cout_er=divv/2;
            cout<<"vvedite pogreshnosti gradyirovki("<<name<<"): ";
            cin>>calib_er;

            for(int i=0; i<a; i++){
                cout<<"vvedite rezult "<<i+1<<" experimenta("<<name<<"): ";
                cin>>arr[i];
            }

            for(int i=0; i<a; i++){
                cur=cur+arr[i];
            }
            cout<<endl;
            av_val=cur;

            for(int i=0; i<a; i++){
                curr=curr+abs(av_val-arr[i]);
            }
            scal_er=curr/a;

            error=sqrt(cout_er*cout_er+scal_er*scal_er+calib_er*calib_er);

    }

    value(){
        name='0';
        av_val=0;
        error=0;
        a=0;
        cout_er=0;
        scal_er=0;
        calib_er=0;
    }


    value(double x, double y, string h): av_val(x), error(y), name(h){
        a=0;
        cout_er=0;
        scal_er=0;
        calib_er=0;
        }

    value(const value& v){
        av_val=v.av_val;
        error=v.error;
        a=v.a;
        cout_er=v.cout_er;
        scal_er=v.scal_er;
        calib_er=v.calib_er;
    }

    value& operator=(const value& v1){
        av_val=v1.av_val;
        error=v1.error;
        a=v1.a;
        cout_er=v1.cout_er;
        scal_er=v1.scal_er;
        calib_er=v1.calib_er;
        return *this;
    }


    value operator+(const value& v2){
        value sum;
        sum.av_val=av_val+v2.av_val;
        sum.error=sqrt(error*error+v2.error*v2.error);
        return sum;
    }


    value operator-(const value& v3){
        value div;
        div.av_val=av_val-v3.av_val;
        div.error=sqrt(error*error+v3.error*v3.error);
        return div;
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


    void show(){
        cout<<endl<<av_val<<"+-"<<error<<endl;
    }

};


int main(){
    string e, c;
    getline(cin, e);
    getline(cin, c);
    value fi, g(3, e), summ, divi, su(2,c), mul_v, mul_n;
    cout<<endl<<"show fi: ";
    fi=g;
    g.av_val++;
    fi.show();
    cout<<endl<<"show g: ";
    g.show();
    cout<<endl<<"show su: ";
    su.show();
    summ=fi+g-su;
    cout<<endl<<"show summ: ";
    summ.show();
    divi=fi-g;
    cout<<endl<<"show divi: ";
    divi.show();
    mul_v=fi*g;
    cout<<endl<<"show mul_v: ";
    mul_v.show();
    mul_n=fi*2;
    cout<<endl<<"show mul_n: ";
    mul_n.show();
    return 0;
}
