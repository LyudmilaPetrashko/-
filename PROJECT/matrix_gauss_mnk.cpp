#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;


class matrix{ //класс матриц

public:
int n,m;  //n-кол-во строк,m-кол-во столбцов
double** arr;


matrix(int a, int b): n(a), m(b){//конструктор
    arr = new double*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new double[m];
    }
    for(int e=0; e<a; e++){
        for(int o=0; o<b; o++){
            arr[e][o]=0;
        }
    }
}

matrix(int k): n(k), m(k){ //конструктор для создания единичной матрицы
    arr=new double*[k];
    for (int i=0; i<k; i++){
        arr[i]=new double[k];
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
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cout << "Inter element " << "[" << i << "][" << j << "]:  ";
            cin >> arr[i][j];
        }
    }
}



matrix(const matrix& matr){  //конструктор копирования
        n=matr.n;
        m=matr.m;
        arr = new double*[matr.n];
    for (int i = 0; i < matr.n; i++)
        arr[i] = new double[matr.m];

    for (int a = 0; a < matr.n; a++){
        for (int b = 0; b < matr.m; b++)
        {
         arr[a][b]=matr.arr[a][b];
        }
    }
}


matrix& operator=(const matrix& max){
    for(int i = n - 1; i>=0; i--){
            delete [] arr[i];
    }
     delete[] arr;
     n=max.n;
     m=max.m;
     arr = new double*[max.n];
    for (int i = 0; i < max.n; i++){
        arr[i] = new double[max.m];
    }

    for (int x = 0; x < max.n; x++){
        for (int y = 0; y < max.m; y++){
            arr[x][y]=max.arr[x][y];
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
                        t.arr[i][j] += arr[i][k] * m3.arr[k][j];
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
          cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
}

~matrix(){  //деструктор
   for(int i = n - 1; i>=0; i--){
       delete [] arr[i];
   }
   delete[] arr;
}

};

matrix gauss(matrix mn){
 matrix g(mn.n); //создание единичной матрицы
 for(int i=0; i<mn.n; i++){
    if(mn.arr[i][i]==0){
        int k=i;
        while(mn.arr[k][i]==0){ //нахождение строки, где i элемент !=0
            k++;
        }
        for(int j=0; j<mn.n; j++){ //меняем строки местами, если arr[i][i]=0;
            swap(mn.arr[i][j],mn.arr[k][j]);
            swap(g.arr[i][j],g.arr[k][j]);
        }
    }
    double w=mn.arr[i][i];
    for(int c=0; c<mn.n; c++){//для того, чтобы arr[i][i]=1;
        mn.arr[i][c]/=w;
        g.arr[i][c]/=w;
    }
    for(int a=i+1;a<mn.n;a++){//a-строка, b-столбец
        double h=mn.arr[a][i];
        for(int b=0; b<mn.n; b++){
            double l=mn.arr[i][b];
            mn.arr[a][b]-=h*l;
            g.arr[a][b]-=h*g.arr[i][b];
        }
    }
 }
 for(int q=mn.n-1; q>=0; q--){
    for(int a=q-1; a>=0; a--){
        double z=mn.arr[a][q];
        for(int b=mn.n-1; b>=0; b--){
            double p=mn.arr[q][b];
            mn.arr[a][b]-=z*p;
            g.arr[a][b]-=z*g.arr[q][b];
        }
    }
 }
return g;
}



void MNK(){

    int q;
    cout<<"enter 1 if you work with n degree polynom"<<endl;
    cout<<"      2 if you work with dependence of some variables: ";
    cin>>q;

    int xy_size, x_s;
    matrix yy, xx, kk;
    matrix a_t, at_a, ag, ag_at;

    switch(q){

    case 1:{
        cout<<endl<<"enter polynom degree: ";
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
            for(int i=0; i<xy_size; i++){
                cout<<"enter the value of Y in the experiment number "<<i+1<<": ";
                cin>>y.arr[i][0];
                x.arr[i][0]=1;
            }

            matrix k;

            a_t=x.transp();
            at_a=a_t*x;
            ag=gauss(at_a);
            ag_at=ag*a_t;
            k=ag_at*y;

            cout<<endl<<"f(x)=";
            for(int i=0; i<k.n-2; i++){
                if(k.arr[k.n-i-2][0]>=0){
                    cout<<round(k.arr[k.n-i-1][0]*1000)/1000<<"*x^"<<k.n-i-1<<"+";
                }
                else{
                    cout<<round(k.arr[k.n-i-1][0]*1000)/1000<<"*x^"<<k.n-i-1;
                }
            }

            if(k.arr[0][0]>=0){
                cout<<round(k.arr[1][0]*1000)/1000<<"*x+"<<round(k.arr[0][0]*1000)/1000<<endl;
            }
            else{
                cout<<round(k.arr[1][0]*1000)/1000<<"*x"<<round(k.arr[0][0]*1000)/1000<<endl;
            }

            yy=y;
            xx=x;
            kk=k;
        }
        else{
            cout<<endl<<"it is impossible to calculate unambiguously"<<endl;
        }
    }
    break;


    case 2:{

        cout<<endl<<"enter the number of variables: ";
        cin>>x_s;

        cout<<endl<<"for example: Y=a*Time+b*Speed+... =>  1 variable->Time , 2 variable->Speed..."<<endl<<endl;

        string *ar=new string[x_s];
        for(int r=0; r<x_s; r++){
            cout<<"enter the name of the variable to "<<r+1<<": ";
            cin>>ar[r];
        }

        cout<<endl<<"enter the number of experiments: ";
        cin>>xy_size;
        if(xy_size>=x_s){
            matrix x(xy_size, x_s), y(xy_size,1);

            for(int i=0; i<xy_size; i++){
                for(int j=0; j<x_s; j++){
                    cout<<"enter the value of "<<ar[j]<<" in the experiment number "<<i+1<<": ";
                    cin>>x.arr[i][j];
                }
            }

            cout<<endl;
            for(int i=0; i<xy_size; i++){
                cout<<"enter the value of Y in the experiment number "<<i+1<<": ";
                cin>>y.arr[i][0];
            }

            matrix k;

            a_t=x.transp();
            at_a=a_t*x;
            ag=gauss(at_a);
            ag_at=ag*a_t;
            k=ag_at*y;

            cout<<endl<<"f(";
            for(int t=0; t<k.n-1; t++){
                cout<<ar[t]<<",";
            }
            cout<<ar[k.n-1]<<")=";
            for(int i=0; i<k.n-2; i++){
                if(k.arr[i+1][0]>=0){
                    cout<<round(k.arr[i][0]*1000)/1000<<"*"<<ar[i]<<"+";
                }
                else{
                    cout<<round(k.arr[i][0]*1000)/1000<<"*"<<ar[i];
                }
            }

            if(k.n>1){
                if(k.arr[k.n-1][0]>=0){
                    cout<<round(k.arr[k.n-2][0]*1000)/1000<<"*"<<ar[k.n-2]<<"+"<<round(k.arr[k.n-1][0]*1000)/1000<<"*"<<ar[k.n-1]<<endl;
                }
                else{
                    cout<<round(k.arr[k.n-2][0]*1000)/1000<<"*"<<ar[k.n-2]<<round(k.arr[k.n-1][0]*1000)/1000<<"*"<<ar[k.n-1]<<endl;
                }
            }
            else{
                cout<<round(k.arr[k.n-1][0]*1000)/1000<<"*"<<ar[k.n-1]<<endl;
            }

            yy=y;
            xx=x;
            kk=k;
        }
        else{
            cout<<endl<<"it is impossible to calculate unambiguously"<<endl;
        }
    }
        break;
    }


    double y_cp=0;
    for(int j=0; j<yy.n; j++){
        y_cp+=yy.arr[j][0];
    }
    y_cp/=yy.n;  //y среднее

    matrix y_i; // у - фактические значения
    y_i=xx*kk;

    matrix res;
    res=y_i-yy;
    double SS_res=0, SS_tot=0;
    for(int ii=0; ii<yy.n; ii++){
        SS_res+=pow(res.arr[ii][0],2);
    }

    for(int jj=0; jj<yy.n; jj++){
        SS_tot+=pow(y_cp-y_i.arr[jj][0], 2);
    }

    double R2, R2_abj;
    R2=1-SS_res/SS_tot;

    R2_abj=1-(1-R2)*(double(yy.n-1))/(double(yy.n-xx.m+1));
    cout<<endl<<"R^2="<<round(R2_abj*10000)/10000;
}

int main(){
MNK();
return 0;
}
