#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <time.h>

class performance_test{
private:
  int max_rozmiar;

  long unsigned int time[1000];
  long unsigned int comparasions[1000];

public:

  performance_test();
  void analize(int( * func )( int*, int ) );
  void export_to_file(const char* name);
  void random_fill(int *,int );

};
