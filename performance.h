#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <time.h>

#ifndef NUMBER
#define NUMBER 10000
#endif

class performance_test{
private:
  int max_rozmiar;

  long unsigned int time[NUMBER];
  long unsigned int comparasions[NUMBER];

public:

  performance_test();
  void analize(int( * func )( int*, int ) );
  void export_to_file(const char* name);
  void random_fill(int *,int );

};
