#include<iostream>
#include<cmath>
#include<string>

using namespace std;

struct value{
    double av_val;
    double error;
    string name;
    
    int a;
    double* arr=new double[a];
    
    double cout_er, scal_er, calib_er;
    
    value(int k): a(k) {
        if(a==0){
            name='nope';
            error=0;
            a=0;
            arr=0;
            cout_er=0;
            scal_er=0; 
            calib_er=0;
        }
        else{
            cout<<"vvedite nazvanue velechin: ";
            cin>>name;
            double div, curr=0, cur=0;
            cout<<"vvedite ceny deleniya("<<name<<"): ";
            cin>>div;
            cout_er=div/2;
            cout<<"vvedite pogreshnosti gradyirovki("<<name<<"): ";
            cin>>calib_er;
        
            for(int i=0; i<a; i++){
                cout<<"vvedite rezult "<<i+1<<" experimenta("<<name<<"): ";
                cin>>arr[i];
                cur+=arr[i];
            }
            cout<<endl;
            av_val=cur/a;
        
            for(int i=0; i<a; i++){
                curr=curr+abs(av_val-arr[i]);
            }
            scal_er=curr/a;
        
            error=sqrt(cout_er*cout_er+scal_er*scal_er+calib_er*calib_er);
            }
    }
    
    value(){
        name='nope';
        av_val=0;
        error=0;
        a=0;
        arr=0;
        cout_er=0;
        scal_er=0; 
        calib_er=0;
    }
    
    
    value(double x, double y): av_val(x), error(y){
        cout<<"vvedite nazvanue velechin: ";
        cin>>name;
        a=0;
        arr=0;
        cout_er=0;
        scal_er=0; 
        calib_er=0;
        }
    
    value(const value& v){
        name=v.name;
        av_val=v.av_val;
        error=v.error;
        a=v.a;
        for(int i=0; i<a; i++){
            arr[i]=v.arr[i];
            }
        cout_er=v.cout_er;
        scal_er=v.scal_er;
        calib_er=v.calib_er;
    }
    
    value& operator=(const value& v1){
        name=v1.name;
        av_val=v1.av_val;
        error=v1.error;
        a=v1.a;
        for(int i=0; i<a; i++){
            arr[i]=v1.arr[i];
            }
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
        value mult;
        mult.av_val=av_val*x;
        mult.error=error*x;
        return mult;
    }
    
    
    value operator*(const value& v4){
        value mult;
        mult.av_val=av_val*v4.av_val;
        mult.error=mult.av_val*sqrt(error*error/(av_val*av_val)+v4.error*v4.error/(v4.av_val*v4.av_val));
        return mult;
    }
    
        
    void show(){
        cout<<endl<<av_val<<"+-"<<error<<endl;
    }
};


int main(){
    value fi, g(1), sum;
    g=fi;
    cout<<endl<<"show fi: ";
    fi.show();
    cout<<endl<<"show g: ";
    g.av_val++;
    g.show();
    return 0;
}
