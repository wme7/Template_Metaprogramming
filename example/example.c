#include <stdio.h>

int main() {

  // 0. receive an integer form user
  int myNumber;
  printf("Enter an integer: ");
  scanf("%d", &myNumber);
  printf("You entered: %d\n",myNumber);

  // 1. array init
  int arr[4][4][4] = {};

  // 2. fill the array
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
       arr[i][j][k] = myNumber; 
      } 
    }
  }
  
  // 3. diplay the array
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        printf("%d ", arr[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  // if everything goes well, then
  return 9;
}