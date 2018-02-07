/*3-4) Реализовать структуру(а лучше класс) для работы со строками(можно довести до ума структуру из 
прошлом домашнем по структурам) и программу с примером работы этой структуры. Структура должна уметь
не меньше чем в прошлом дз, но кроме того: удовлетворять Правилу Трёх,иметь конструктор принимающий
C-style строки и конструктор принимающий длину строки ,иметь перегруженным оператор квадратные скобки 
для доступа к символам по индексам. Пример, кроме всего прочего, должен содержать замену некоторой строки
на строку с Вашим ФИО. В данной программе запрещено пользоваться стандартными строками C++.*/



#include<iostream>
#include<algorithm>
using namespace std;


class str{

long int size;
char *arr_string;


char *ret_string(char *d, const char *c) {
char *s = d;
while (*d++ = *c++);
return s;
}

long int what_size(const char * t) { 
const char *s;
for(s=t; *s; ++s);
return (s-t);
}


public:

str (char *arr_string=" "): 
size(what_size(arr_string)), arr_string(new char[size+1]){
ret_string(this->arr_string, arr_string);
}

int length(){
return size;
}

str(long int n, char s='\0'): size(n), arr_string(new char[size+1]){
for(int i=0; i<n; i++){
arr_string[i]=s;
}
arr_string[n]='\0';
}

void operator+=(str &new_string) {
char *temp = new char[size + new_string.size + 1];
ret_string(temp, arr_string);
for (int i = size; i < size + new_string.size; ++i)
temp[i] = new_string.arr_string[i - size];
delete [] arr_string;
size += new_string.size;
temp[size] = '\0';
arr_string= temp;
}

char operator[](unsigned int idx) const {
if (idx > size) {
cout << "Index out of range\n";
return 0;
}
return arr_string[idx];
}

char &operator[](unsigned idx) {
if (idx >= size) {
cout << "Index is out of range\n";
return arr_string[0];
}
return arr_string[idx];
}

~str() {
delete [] arr_string;
}

str(const str &new_string) : size(new_string.size), arr_string(new char[size+1]) {
for (int i = 0; i < size; ++i)
arr_string[i] = new_string.arr_string[i];
arr_string[size] = '\0';
}

str operator=(const str &new_string) {
str(new_string).sw(*this);
return *this;
}

void sw(str &s) { //swap
swap(size, s.size);
swap(arr_string, s.arr_string);
}

char get(int i){
return arr_string[i];
}

void set(int i, char u){
arr_string[i] = u;
for(int i=0; i<size; i++){
cout<<arr_string[i];
}}





bool operator==(str st){
 bool pr=1;     
 for (int i=0; i<st.length(); i++)
 {
  if (arr_string[i]!=st.arr_string[i] || size!=st.length()) {
      return pr=0;
      }
 }
 return pr;
 
}


};




int main(){
str fio="000", name=" Lyudmila Ruslanovna", str_swap="765";
str pat="Ruslan";
fio="Petrashko";
fio+=name;
for(int i=0; i<fio.length(); ++i){
cout<<fio[i];
}
cout<<"(operators= and +=)"<<endl<<"how many characters: "<<fio.length()<<endl;
cout<<"string[i](get): "<<fio.get(2)<<endl;
cout<<"string[i](set): ";
fio.set(10, 'c');
fio.sw(str_swap);
cout<<endl<<"swap: fio=";
for(int j=0; j<fio.length(); j++){
    cout<<fio[j];
}

return 0;
}
