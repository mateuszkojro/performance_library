#include "performance.h"

performance_test::performance_test():max_rozmiar(NUMBER){
  //srand(time(NULL));
}

void performance_test::export_to_file(const char* name){
  FILE* f = fopen(name,"w");
  for (int i = 0; i < this->max_rozmiar;i++){
    fprintf(f, "%d\t%lu\t%lu\n",i,this->time[i],this->comparasions[i] );
  }

}


  void performance_test::export_to_css(const char* name){
    FILE* f = fopen(name,"w");
    for (int i = 0; i < this->max_rozmiar;i++){
      fprintf(f, "%d,%lu,%lu\n",i,this->time[i],this->comparasions[i] );
    }

  }


void performance_test::export_to_json(const char* name){
  FILE* f = fopen(name,"w");
  fprintf(f, "{\n");

  fprintf(f,"\"label\": [%d",0);
  for (int i = 1; i < this->max_rozmiar;i++){
    fprintf(f, ",%d",i);
  }
  fprintf(f,"],");

  fprintf(f,"\"time\": [%lu",this->time[0]);
  for (int i = 1; i < this->max_rozmiar;i++){
    fprintf(f, ",%lu",this->time[i]);
  }
  fprintf(f,"],");

  fprintf(f,"\"comparasions\": [%lu",this->comparasions[0]);
  for (int i = 1; i < this->max_rozmiar;i++){
    fprintf(f, ",%lu",this->comparasions[i]);
  }
  fprintf(f,"]");
  fprintf(f, "}");

}

inline void performance_test::random_fill(int * tab,int size){
  for (int i = 0 ; i < size;++i){
    tab[i] = rand() % size;
  }
}

void performance_test::analize(int( * func )( int*, int ) ){

  for (int i = 0 ; i < this->max_rozmiar ; ++i){
    int* tab = new int [i];
    random_fill(tab,i);
    auto start = std::chrono::high_resolution_clock::now();
    this->comparasions[i] = func(tab,i);
    auto end = std::chrono::high_resolution_clock::now();

    this->time[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();


    delete [] tab;
  }

}
