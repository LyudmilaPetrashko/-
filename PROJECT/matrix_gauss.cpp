#include<iostream>
#include<algorithm>

using namespace std;


class matrix{ //класс матриц

public:
int n,m;  //n-кол-во строк,m-кол-во столбцов
double** arr;


matrix(int a, int b): n(a), m(b){ //конструктор
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
         matrix t(m,m3.n), h;
         t.n=m;
         t.m=m3.n;
         if(m==m3.n){
            for (int i = 0; i < m; ++ i){
                for (int j = 0; j < m; ++ j){
                    for (int k = 0; k < m; ++ k){
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
    cout<<"g print:"<<endl;
    g.print();
    cout<<endl;
    cout<<"mn print:"<<endl;
    mn.print();
    cout<<endl;
 }
 cout<<endl<<endl;
 for(int q=mn.n-1; q>=0; q--){
    for(int a=q-1; a>=0; a--){
        double z=mn.arr[a][q];
        for(int b=mn.n-1; b>=0; b--){
            double p=mn.arr[q][b];
            mn.arr[a][b]-=z*p;
            g.arr[a][b]-=z*g.arr[q][b];
        }
    }
    cout<<"g print:"<<endl;
    g.print();
    cout<<endl;
    cout<<"mn print:"<<endl;
    mn.print();
    cout<<endl;
 }
return g;
}



int main(){
matrix h(2,2);
h.get();
matrix c=gauss(h);
matrix u=h*c;
cout<<"u print:"<<endl;
u.print();
return 0;
}
