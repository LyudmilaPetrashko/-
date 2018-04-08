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
         if(n==m3.m){
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
    matrix c(2,2), j(2,2), sum, dif, mult_m_m, mult_m_n;
    c.get();
    j.get();
    sum=j+c;
    dif=j-c;
    mult_m_m=c*j;
    mult_m_n=c*3;
    cout<<c.arr[0][1];
    cout<<endl<<"print c:"<<endl;
    c.print();
    cout<<endl<<"print j:"<<endl;
    j.print();
    cout<<endl<<"print sum:"<<endl;
    sum.print();
    cout<<endl<<"print dif:"<<endl;
    dif.print();
    cout<<endl<<"print mult_m_m:"<<endl;
    mult_m_m.print();
    cout<<endl<<"print mult_m_n:"<<endl;
    mult_m_n.print();
    
    return 0;
}
