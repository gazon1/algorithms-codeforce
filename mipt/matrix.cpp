// Реализовать класс Matrix.
// Публичные поля:
// rows - количество строк
// columns - количество столбцов
// double *data - данные матрицы (лежат в динамически выделенной памяти, к ним должен быть прямой доступ, данные лежат по строкам).
// В том числе реализовать:
// конструктор Matrix(int rows, int columns)
// - конструктор копирования
// - оператор << // возвращает матрицу по строкам
// 1 2 3
// 4 5 6
// - элементы одной строки разделены символом пробела
// - в конце каждой строки стоит символ перевода строки.
// данные хранятся в памяти в виде массива, память под него выделяется динамически.
// построчно, т.е. сначала идут элементы первой строки, затем элементы второй строки и т.д.
// Файл нужно отправлять без функции main, заголовочные файлы не нужны.
// Вводом и выводом данных занимается код Заказчика.


// TODO: узнать, есть библиотека <bits/stdc++.h> в компиляторе контеста?

#include <bits/stdc++.h>
using namespace std;


class Matrix {
public:
  int rows;
  int columns;
  double* data;

  Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
  }

  Matrix(const Matrix &m):
    rows(m.rows), columns(m.columns), data(m.data) { }

  friend ostream& operator<<(std::ostream& out, const Matrix &m);

};


ostream& operator<<(ostream& out, const Matrix &m)
{
  for (int row = 0; row < m.rows; row++) {
    for (int col = 0; col < m.columns; col++) {
      out << m.data[row * m.columns + col] << " ";
    }
    out << endl;
  }
}


int main() {
  Matrix m(2, 3);
  m.data = new double[6]{1, 2, 3, 4, 5, 6};
  cout << m;
  return 0;
}
