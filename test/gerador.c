#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("1000 1001\n");
  for(int i=1;i<1000;i++){
    printf("link %d %d\n", i, i+1);
  }
  return 0;
}