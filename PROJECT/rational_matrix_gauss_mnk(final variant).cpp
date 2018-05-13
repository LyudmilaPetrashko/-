#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;


long int gcd(long int a1, long int b1) { //НОД по алгоритму Евклида
    if (b1 == 0) return a1;
    return gcd(b1, a1 % b1);
}


struct ration{ // класс дробей

    long int a,b;// а-числитель b- знаменатель


    ration(){a=0;b=1;}


    ration(int x, int y){
        long int z=gcd(x,y);
        a=x/z;
        b=y/z;
    }


    ration(int h): a(h), b(1){}


    ration(long double w){
        int d=0;
        while(abs(w-round(w))>1.0e-9){
            w*=10;
            d++;
        }
        long int k=pow(10.0,d);
        long int z=gcd(round(w),k);
        a=round(w)/z;
        b=k/z;
    }


    /*ration(double w){
        int d=0;
        w*=10000000;
        int z=gcd((int)w,10000000);
        a=(int)w/z;
        b=10000000/z;
    }*/


    ration(const ration& rat){
        a=rat.a;
        b=rat.b;
    }


    ration operator=(const ration& r){
        a=r.a;
        b=r.b;
        return *this;
    }


    ration operator=(long double rr){
        ration c(rr);
        a=c.a;
        b=c.b;
        return *this;
    }


    bool operator==(const ration& ra){
        if(a==ra.a&&b==ra.b){
            return 1;
        }
        else{
            return 0;
        }
    }


    bool operator==(long double rra){
        ration rraa(rra);
        if(a==rraa.a&&b==rraa.b){
            return 1;
        }
        else{
            return 0;
        }
    }


    ration operator+(const ration& r1){
        ration s1;
        s1.a=a*r1.b+r1.a*b;
        s1.b=b*r1.b;
        int k1=gcd(s1.a,s1.b);
        s1.a/=abs(k1);
        s1.b/=abs(k1);
        return s1;
    }


    ration operator+(long double j1){
        ration ss1, jj1(j1);
        ss1.a=a*jj1.b+jj1.a*b;
        ss1.b=b*jj1.b;
        int kk1=gcd(ss1.a,ss1.b);
        ss1.a/=abs(kk1);
        ss1.b/=abs(kk1);
        return ss1;
    }


    ration operator-(const ration& r2){
        ration s2;
        s2.a=a*r2.b-r2.a*b;
        s2.b=b*r2.b;
        int k2=gcd(s2.a,s2.b);
        s2.a/=abs(k2);
        s2.b/=abs(k2);
        return s2;
    }


    ration operator-(long double j2){
        ration ss2, jj2(j2);
        ss2.a=a*jj2.b-jj2.a*b;
        ss2.b=b*jj2.b;
        int kk2=gcd(ss2.a,ss2.b);
        ss2.a/=abs(kk2);
        ss2.b/=abs(kk2);
        return ss2;
    }


    ration operator*(const ration& r3){
        ration m1;
        m1.a=a*r3.a;
        m1.b=b*r3.b;
        int k3=gcd(m1.a,m1.b);
        m1.a/=abs(k3);
        m1.b/=abs(k3);
        return m1;
    }


    ration operator*(long double j3){
        ration mm1, jj3(j3);
        mm1.a=a*jj3.a;
        mm1.b=b*jj3.b;
        int kk3=gcd(mm1.a,mm1.b);
        mm1.a/=abs(kk3);
        mm1.b/=abs(kk3);
        return mm1;
    }


    ration operator/(const ration& r4){
        ration m2;
        m2.a=a*r4.b;
        m2.b=b*r4.a;
        int k4=gcd(m2.a,m2.b);
        m2.a/=abs(k4);
        m2.b/=abs(k4);
        return m2;
    }


    ration operator/(long double j4){
        ration mm2, jj4(j4);
        mm2.a=a*jj4.b;
        mm2.b=b*jj4.a;
        int kk4=gcd(mm2.a,mm2.b);
        mm2.a/=abs(kk4);
        mm2.b/=abs(kk4);
        return mm2;
    }


    ration operator-(){
        ration u;
        u.a=-a;
        u.b=b;
        return u;
    }


    void show(){
        long int k=gcd(a,b);
        a/=abs(k);
        b/=abs(k);
        if((a<=0&&b<=0)||(a>=0&&b>=0)){
            if(abs(b)==1){
                cout<<abs(a);
            }
            else{
                cout<<abs(a)<<"/"<<abs(b);
            }
        }
        else{
            if(abs(b)==1){
                cout<<-abs(a);
            }
            else{
                cout<<-abs(a)<<"/"<<abs(b);
        }
    }
    }
};


ration operator+(double c1, ration& ra1){
        ration k1=ra1+c1;
        return k1;
}


ration operator-(double c2, ration& ra2){
        ration k2=-ra2+c2;
        return k2;
}


ration operator*(double c3, ration& ra3){
        ration k3=ra3*c3;
        return k3;
}


ration operator/(double c4, ration& ra4){
        ration k4;
        k4.a=c4*ra4.b;
        k4.b=ra4.a;
        return k4;
}


ration pow(ration m, int n){
        m.a=pow(m.a,n);
        m.b=pow(m.b,n);
        return m;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class matrix{ //класс матриц

public:
int n,m;  //n-кол-во строк,m-кол-во столбцов
ration** arr;



matrix(int a, int b): n(a), m(b){  //конструктор
    arr = new ration*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new ration[m];
    }
    for(int e=0; e<a; e++){
        for(int o=0; o<b; o++){
            arr[e][o]=0;
        }
    }
}


matrix(int k): n(k), m(k){ //конструктор для создания единичной матрицы
    arr=new ration*[k];
    for (int i=0; i<k; i++){
        arr[i]=new ration[k];
    }
    for(int j=0; j<k; j++){
        for(int s=0; s<k; s++){
            if(j==s){
                arr[j][s]=1;
            }
            else{
                arr[j][s]=0;
           }
        }
    }
}



matrix(){n=0; m=0; arr=0;} //конструктор по умолчанию



void get(){  //заполнение матрицы
    long double e;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cout << "enter element " << "[" << i << "][" << j << "]:  ";
            cin >> e;
            arr[i][j]=e;
        }
    }
}



matrix(const matrix& matr){  //конструктор копирования
        n=matr.n;
        m=matr.m;
        arr = new ration*[matr.n];
    for (int i = 0; i < matr.n; i++)
        arr[i] = new ration[matr.m];

    for (int a = 0; a < matr.n; a++){
        for (int b = 0; b < matr.m; b++)
        {
         arr[a][b]=matr.arr[a][b];
        }
    }
}



matrix& operator=(const matrix& matx){
    for(int i = n - 1; i>=0; i--){
            delete [] arr[i];
    }
     delete[] arr;
     n=matx.n;
     m=matx.m;
     arr = new ration*[matx.n];
    for (int i = 0; i < matx.n; i++){
        arr[i] = new ration[matx.m];
    }

    for (int x = 0; x < matx.n; x++){
        for (int y = 0; y < matx.m; y++){
            arr[x][y]=matx.arr[x][y];
        }
    }
    return *this;
}




matrix operator+(const matrix& m1){
        matrix g(n,m), h;
        if(m==m1.m&&n==m1.n){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                g.arr[x][y]=arr[x][y]+m1.arr[x][y];
            }
        }
        return g;
        }
        else{
            return h;
        }
}




matrix operator-(const matrix& m2){
        matrix f(n,m), h;
        if(m==m2.m&&n==m2.n){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                f.arr[x][y]=arr[x][y]-m2.arr[x][y];
            }
        }
        return f;
        }
        else{
            return h;
        }
     }



matrix operator*(const matrix& m3){
         matrix t( n, m3.m), h;
         if(m==m3.n){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m3.m; j++){
                    for (int k = 0; k < m; k++){
                        t.arr[i][j] =t.arr[i][j] + arr[i][k] * m3.arr[k][j];
                    }
                }
            }
         }
         else{
            return h;
         }

   return t;
}



matrix operator*(double d){
    matrix w(n,m);
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            w.arr[x][y]=arr[x][y]*d;
        }
    }
    return w;
}



bool operator==(const matrix& m4){
    int k=0;
    for(int i=0;i<n; i++){
    for(int j=0; j<m; j++){
    if(arr[i][j]==m4.arr[i][j])
            k++;
    }
  }
  if(k==n*m){return 1;}
  else{return 0;}
  }



matrix transp ()  //транспонирование матрицы
{
   matrix c(m, n);
   for (int i = 0; i < n; ++ i)
      for (int j = 0; j <m; ++ j)
         c.arr[j][i] = arr[i][j];
   return c;
}



void print(){    //вывод матрицы
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
          arr[i][j].show();
          cout<<" ";
        }
    cout<<endl;
    }
}



ration determ() {// вычисление определителя по методу Гаусса
  ration d(1), t=0;
  matrix dou(*this);
  if (dou.m<1||(dou.m!=dou.n)){
      cout << "not to calculate determinant";
      return t;
  }
  if (dou.m == 1) {
    d = dou.arr[0][0];
    return d;
  }
  if (dou.m == 2) {
    d = dou.arr[0][0] * dou.arr[1][1]-(dou.arr[1][0] * dou.arr[0][1]);
    return d;
  }
  if (dou.m>2) {
        for(int g=0; g<dou.m; g++){
        if(dou.arr[g][g].a==0){
            int k=g;
            while(dou.arr[k][g].a==0){
                k++;
                if(k>=dou.m){
                    return t;
                }
            }
            for(int x=0; x<dou.m; x++){
                swap(dou.arr[k][x].a,dou.arr[g][x].a);
                swap(dou.arr[k][x].b,dou.arr[g][x].b); //меняем строки, если arr[g][g]=0
                dou.arr[k][x].a=-dou.arr[k][x].a;
            }
        }
        for(int y=g+1; y<dou.m; y++){  //обнуляем g-тый столбец ниже g-того элемента
            ration w=dou.arr[y][g];
            for(int t=0; t<dou.m; t++){
             dou.arr[y][t]=dou.arr[y][t]-w/dou.arr[g][g]*dou.arr[g][t];
            }
        }
    }
    for(int f=0; f<dou.m; f++){
            d=d*dou.arr[f][f];
  }
  }
  return d;
}



~matrix(){  //деструктор
   for(int i = n - 1; i>=0; i--){
       delete [] arr[i];
   }
   delete[] arr;
}

};



matrix operator*(double d,matrix& matri){
    return matri*d;
}



matrix gauss(matrix mn){//находим обратную матрицу по методу Гаусса
    matrix c;
    if(mn.determ()==0){
        cout<<endl<<"it is impossible to calculate an inverse matrix";
        return c;
    }
 matrix g(mn.n); //создание единичной матрицы
 for(int i=0; i<mn.n; i++){
    if(mn.arr[i][i].a==0){
        int k=i;
        while(mn.arr[k][i].a==0){ //нахождение строки, где i элемент !=0
            k++;
        }
        for(int j=0; j<mn.n; j++){ //меняем строки местами, если arr[i][i]=0;
            swap(mn.arr[i][j].a,mn.arr[k][j].a);
             swap(mn.arr[i][j].b,mn.arr[k][j].b);
            swap(g.arr[i][j].a,g.arr[k][j].a);
             swap(g.arr[i][j].b,g.arr[k][j].b);
        }
    }
    ration w=mn.arr[i][i];
    for(int c=0; c<mn.n; c++){//для того, чтобы arr[i][i]=1;
        mn.arr[i][c]=mn.arr[i][c]/w;
        g.arr[i][c]=g.arr[i][c]/w;
    }
    for(int a=i+1;a<mn.n;a++){//a-строка, b-столбец
        ration h=mn.arr[a][i];
        for(int b=0; b<mn.n; b++){
            ration l=mn.arr[i][b];
            mn.arr[a][b]=mn.arr[a][b]-h*l;
            g.arr[a][b]= g.arr[a][b]-h*g.arr[i][b];
        }
    }
 }
 for(int q=mn.n-1; q>=0; q--){
    for(int a=q-1; a>=0; a--){
        ration z=mn.arr[a][q];
        for(int b=mn.n-1; b>=0; b--){
            ration p=mn.arr[q][b];
            mn.arr[a][b]=mn.arr[a][b]-z*p;
            g.arr[a][b]=g.arr[a][b]-z*g.arr[q][b];
        }
    }
 }
return g;
}



void MNK(){

    int xy_size, x_s;
    matrix yy, xx, kk;
    matrix a_t, at_a, ag, ag_at;

    cout<<"enter polynom degree: ";
    cin>>x_s;

    cout<<endl<<"enter the number of experiments: ";
    cin>>xy_size;

    if(xy_size>=x_s){
        matrix x(xy_size, x_s+1), y(xy_size,1);
        double x1;

        cout<<endl;
        for(int i=0; i<xy_size; i++){
            cout<<"enter the value of X in the experiment number "<<i+1<<": ";
            cin>>x1;
            for(int j=1; j<x_s+1; j++){
                x.arr[i][j]=pow(x1, j);
            }
        }

        cout<<endl;
        double qq;
        for(int i=0; i<xy_size; i++){
            cout<<"enter the value of Y in the experiment number "<<i+1<<": ";
            cin>>qq;
            y.arr[i][0]=qq;
            x.arr[i][0]=1;
        }

        matrix k;

        a_t=x.transp();
        at_a=a_t*x;

        if(at_a.determ()==0){
            cout<<endl<<"not to calculate regression model as there was no inverse matrix";
            return;
        }

        else{
        ag=gauss(at_a);
        ag_at=ag*a_t;
        k=ag_at*y;

        cout<<endl<<"f(x)=";
        for(int i=0; i<k.n-2; i++){
            if(double(k.arr[k.n-i-2][0].a)/k.arr[k.n-i-2][0].b>=0){
                cout<<round(double(k.arr[k.n-i-1][0].a)/k.arr[k.n-i-1][0].b*1000)/1000<<"*x^"<<k.n-i-1<<"+";
            }
            else{
                cout<<round(double(k.arr[k.n-i-1][0].a)/k.arr[k.n-i-1][0].b*1000)/1000<<"*x^"<<k.n-i-1;
            }
        }

        if(double(k.arr[0][0].a)/k.arr[0][0].b>=0){
            cout<<round(double(k.arr[1][0].a)/k.arr[1][0].b*1000)/1000<<"*x+"<<round(double(k.arr[0][0].a)/k.arr[0][0].b*1000)/1000<<endl;
        }
        else{
            cout<<round(double(k.arr[1][0].a)/k.arr[1][0].b*1000)/1000<<"*x"<<round(double(k.arr[0][0].a)/k.arr[0][0].b*1000)/1000<<endl;
        }

        yy=y;
        xx=x;
        kk=k;
    }
    }
    else{
        cout<<endl<<"it is impossible to calculate unambiguously"<<endl;
    }
    
    


    ration y_cp=yy.arr[0][0];
    for(int j=1; j<yy.n; j++){
        y_cp=y_cp+yy.arr[j][0];
    }

    y_cp=y_cp/yy.n;  //y среднее
    matrix y_i; // у - теоретические значения
    y_i=xx*kk;

    matrix res;
    res=y_i-yy;
    ration SS_res=0, SS_tot=0;
    for(int ii=0; ii<yy.n; ii++){
        SS_res=SS_res+pow(res.arr[ii][0],2);
    }

    for(int jj=0; jj<yy.n; jj++){
        SS_tot=SS_tot+pow(y_cp-y_i.arr[jj][0], 2);
    }

    double R2, R2_abj;
    R2=1-SS_res.a*SS_tot.b/(double(SS_res.b*SS_tot.a));
    R2_abj=1-(1-R2)*(double(yy.n-1))/(double(yy.n-xx.m+1));
    cout<<endl<<"R^2="<<round(R2_abj*10000)/10000;
}



int main(){
MNK();
return 0;
}


