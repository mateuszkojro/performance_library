#include <iostream>
#include "performance.h"


void swap(int& a, int&b);
int sort(int* tab,int n);

int main(){
  performance_test test1;

  test1.analize(sort);
  test1.export_to_json("wyniki.json");

  return 0;
}

int sort(int* tab,int n){
int licznik = 0;
for (int j = 0; j < n-1 ;j++){
  for (int i =0 ; i < n-1;i++){
    licznik++;
    if (tab[i] > tab[i+1])swap(tab[i],tab[i+1]);
  }
}
return licznik;
}

void swap(int& a, int&b){
  int temp = a;
  a = b;
  b = temp;
}
