#include <iostream>

using namespace std;

template <typename T>
T Sqr(T x) {
  return x * x;
  
}


int main(int argc, char *argv[])
{
  cout << Sqr(5);
  return 0;
}
