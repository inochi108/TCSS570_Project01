#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>

int MAX = 4000;
int LARGEST = 3;

int main() {


    int t, m, n, p, q, c, d, k, i, sum = 0;
    time_t seed;
    srand((unsigned) time(&seed));

    int **first, **second, **third;

    first = (int **)malloc(sizeof(int *)*MAX);
    for(i=0; i < MAX; i++) {
        first[i] = (int *)malloc(sizeof(int)*MAX);
      }
    second = (int **)malloc(sizeof(int *)*MAX);
    for(i=0; i < MAX; i++) {
        second[i] = (int *)malloc(sizeof(int)*MAX);
      }
    third = (int **)malloc(sizeof(int *)*MAX);
    for(i=0; i < MAX; i++) {
        third[i] = (int *)malloc(sizeof(int)*MAX);
      }

    for (c = 0; c < MAX; c++) {
      for (d = 0; d < MAX; d++) {
          first[c][d] = rand() % LARGEST;
      }
    }

    for (c = 0; c < MAX; c++) {
      for (d = 0; d < MAX; d++){
          second[c][d] = rand() % LARGEST;
      }
    }
    printf("Done initiate\n");

    clock_t time_spent = clock();
    // printf("First matrices:\n");

    // for (c = 0; c < MAX; c++) {
    //   for (d = 0; d < MAX; d++) {
    //       printf("%d\t", first[c][d]);
    //   }
    //   printf("\n");
    // }

    // printf("Second matrices:\n");
    // for (c = 0; c < MAX; c++) {
    //   for (d = 0; d < MAX; d++) {
    //       printf("%d\t", second[c][d]);
    //   }
    //   printf("\n");
    // }
    for (c = 0; c < MAX; c++) {
       // if(c%1000 == 0){
       //        printf("mark: %d\n", c);
       //     }
      for (d = 0; d < MAX; d++) {
        for (k = 0; k < MAX; k++) {
          sum += first[c][k]*second[k][d];
        }
 
        third[c][d] = sum;
        sum = 0;
      }
    }

    // printf("Product of entered matrices:\n");

    // for (c = 0; c < MAX; c++) {
    //   for (d = 0; d < MAX; d++) {
    //     printf("%d\t", third[c][d]);
    //   }

    //   printf("\n");
    // }


    time_spent = clock() - time_spent;
    printf("Time: %d clicks(%f in sec)",time_spent, ((float)time_spent) / CLOCKS_PER_SEC);

    return 0;
}