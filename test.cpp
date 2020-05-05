#include <iostream>
#include "performance.h"


void swap(int& a, int&b);
int bubble_sort(int* tab,int n);
int insert_sort(int* tab,int n);
int main(){
  performance_test test1;
  performance_test test2;

  test1.analize(bubble_sort);
  test1.export_to_json("bubble.json");

  test2.analize(insert_sort);
  test2.export_to_json("insert.json");

  return 0;
}

int bubble_sort(int* tab,int size){
int licznik = 0;
bool flag =true;

    int i = 0;
  while (flag)
  {
    flag = false;
    for (int i = 0; i < size-1 ;i++){
    licznik++;
    if (tab[i] > tab[i+1]){swap(tab[i],tab[i+1]),flag = true;}
    }
    size--;
  }
    
return licznik;
}

int insert_sort(int *tab, int size){
    int comp = 0;
    int j = size - 1;
    while (j >= 0){
        int x = tab[j];
        int i = j+ 1;
        while (i < size){
            comp++;
            if(x <= tab[i])break;
            tab[i -1] = tab[i];
            i++;
        }
        tab[i -1] = x;
        j--;
    }
return comp;
}
void swap(int& a, int&b){
  int temp = a;
  a = b;
  b = temp;
}
