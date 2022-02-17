#include <stdio.h>
#include <stdlib.h>

int main(){
  int *a=(int*)malloc(10*sizeof(int));
  int b=a[50];
  free(a);
  return 0;
}