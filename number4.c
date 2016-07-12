#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>
#include <omp.h>

int MAX = 10000;
int LARGEST = 3;
int **first, **third, **second;

void print_matrices(){
  int row, col;
  printf("First matrix:\n");
  for (row = 0; row < MAX; row++) {
    for (col = 0; col < MAX; col++) {
        printf("%d\t", first[row][col]);
    }
    printf("\n");
  }

  printf("Second matrix:\n");
  for (row = 0; row < MAX; row++) {
    for (col = 0; col < MAX; col++) {
        printf("%d\t", second[row][col]);
    }
    printf("\n");
  }

  printf("Product of entered matrix:\n");
  for (row = 0; row < MAX; row++) {
    for (col = 0; col < MAX; col++) {
      printf("%d\t", third[row][col]);
    }
    printf("\n");
  }
}

int main() {
  int row, col, i, k, sum =0;
  time_t seed;// for random 
  srand((unsigned) time(&seed));

  first = (int **) malloc(sizeof(int *) * MAX);
  for(i = 0; i < MAX; i++) 
      first[i] = (int *) malloc(sizeof(int) * MAX);
  
  second = (int **) malloc(sizeof(int *) * MAX);
  for(i = 0; i < MAX; i++) 
      second[i] = (int *) malloc(sizeof(int) * MAX);
  
  third = (int **) malloc(sizeof(int *) * MAX);
  for(i = 0; i < MAX; i++) 
      third[i] = (int *) malloc(sizeof(int) * MAX);
  
  for (row = 0; row < MAX; row++)
    for (col = 0; col < MAX; col++) 
      first[row][col] = rand() % LARGEST;
  for (row = 0; row < MAX; row++)
    for (col = 0; col < MAX; col++)
      second[row][col] = rand() % LARGEST;

  printf("Done initiate\n");

  clock_t time_spent = clock();
  #pragma omp parallel private(row, col, k, MAX, first, second, third, sum)
  {
    for (row = 0; row < MAX; row++)
      for (col = 0; col < MAX; col++) {
        for (k = 0; k < MAX; k++) 
          sum += first[row][k]*second[k][col];

        third[row][col] = sum;
        sum = 0;
      }
  }
  time_spent = clock() - time_spent;
  printf("Time: %lu clicks(%f in sec)\n",time_spent, ((float)time_spent) / CLOCKS_PER_SEC);
  // print_matrices();
  return 0;
}