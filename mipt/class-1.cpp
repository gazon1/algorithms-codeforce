/*
  В начале программы директивы препроцессора
*/
// Начало мантры

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
// Конец директив и выбора пространства имён

class Time{
  public:
   int hour;
   int min;
};

Time add(Time a, int min){
  min += a.hour * 60 + a.min;
  a.hour = (min / 60) % 24;
  a.min = min % 60;

  return a;
}


int main() {
    Time a,newtime;
    int min;

    cin>>a.hour>>a.min;

    cin>>min;
    newtime = add(a,min);
    cout << newtime.hour << ":" << newtime.min << endl;
}
