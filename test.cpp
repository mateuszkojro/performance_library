#include <iostream>
#include "performance.h"


void swap(int& a, int&b);
int bubble_sort(int* tab,int n);
int insert_sort(int* tab,int n);
int main(){
  performance_test test1;

  test1.analize(sort);
  test1.export_to_json("wyniki.json");

  return 0;
}

int bubble_sort(int* tab,int n){
int licznik = 0;
for (int j = 0; j < n-1 ;j++){
  for (int i =0 ; i < n-1;i++){
    licznik++;
    if (tab[i] > tab[i+1])swap(tab[i],tab[i+1]);
  }
}
return licznik;
}

int insert_sort(int *tab, int size){
    int comp = 0;
    int j = size - 2;
    while (j >= 1){
     comp++;
     int x = tab[j];
     int i = j + 1;

        if(!(i <= size) || x < tab[i]){
            comp++;
            tab[i - 1] = x;
            j--;
        }
        else{
            comp++;
            tab[i - 1] = tab[i];
            i++;
        }
    }
return comp;
}

void swap(int& a, int&b){
  int temp = a;
  a = b;
  b = temp;
}
