#include<iostream>

using namespace std;


class matrix{ //класс матриц

int n,m;  //n-кол-во строк,m-кол-во столбцов
double** arr;

public:

matrix(int a, int b): n(a), m(b){ //конструктор
    arr = new double*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new double[m];
}

matrix(double h, int k): n(k), m(k){ //конструктор для перевода double чисел в matrix для перемножения
    arr=new double*[k];
    for (int i=0; i<k; i++){
        arr[i]=new double[k];
    }
    for(int j=0; j<k; j++){
        for(int s=0; s<k; s++){
        arr[j][s]=0;
    }
    }
    for(int j=0; j<k; j++){
        arr[j][j]=h;
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
        for (int y = 0; y < max.m; y++)
        {
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
         matrix t(m,m3.n), h;
         if(*this==matrix(*this)){
            if(m==m3.n){
                for (int i = 0; i < m; ++ i){
                    for (int j = 0; j < m3.n; ++ j){
                        for (int k = 0; k < m; ++ k){
                            t.arr[i][j] += arr[i][k] * m3.arr[k][j];
                        }
                    }
                }
            }
            else{
                return h;
            }
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


int main(){

    matrix c(2,2), j(2,2), sum, dif, mult_m_m, mult_m_n, multt, trans;
    matrix t(7.0,2);
    int boo;
    cout<<"show double=>matrix"<<endl;
    t.print();

    c.get();
    cout<<endl<<"print c:"<<endl;
    c.print();

    cout<<"mult double*matrix"<<endl;
    multt=t*c;
    multt.print();
    cout<<endl;

    j.get();
    cout<<endl<<"print j:"<<endl;
    j.print();

    sum=j+c;
    cout<<endl<<"print sum:"<<endl;
    sum.print();

    dif=j-c;
    cout<<endl<<"print difference:"<<endl;
    dif.print();

    mult_m_m=c*j;
    cout<<endl<<"print product_m_m:"<<endl;
    mult_m_m.print();

    mult_m_n=c*3;
    cout<<endl<<"print product_m_n:"<<endl;
    mult_m_n.print();

    trans=c.transp();
    cout<<endl<<"print transp:"<<endl;
    trans.print();

    if(c==j){boo=1;}
    else{boo=0;}
    cout<<endl<<"print boo:"<<endl;
    cout<<boo<<endl;

    return 0;
}
