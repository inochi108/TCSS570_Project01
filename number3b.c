#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int MAX = 10000;
int LARGEST = 5;
double **m1, **m2, **pm1, **pm2, **pm3;
int thread_number, subset_size;
int perfectMatrix;

// Parts, I copied them but you could reference them.
double **A11;
double **A12;
double **A21;
double **A22;
double **B11;
double **B12;
double **B21;
double **B22;

// M matrixes
double **M1; // (A_1,1 + A_2,2)*(B_1,1 + B_2,1)
double **M2; // (A_2,1 + A_2,2)*B_1,1
double **M3; // A_1,1 * (B_1,2 - B_2,2)
double **M4; // A_2,2 * (B_2,1 - B_1,1)
double **M5; // (A_1,1 + A_1,2) * B_2,2
double **M6; // (A_2,1 - A_1,1) * (B_1,1 + B_1,2)
double **M7; // (A_1,2 - A_2,2) * (B_2,1 + B_2,2)

// C matrixes
double **C11;
double **C12;
double **C21;
double **C22;

void print_perfect_matrices() {
    int row, col;
    printf("First matrix:\n");
    for (row = 0; row < MAX; row++) {
        for (col = 0; col < MAX; col++) {
            printf("%f\t", pm1[row][col]);
        }
        printf("\n");
    }

    printf("Second matrix:\n");
    for (row = 0; row < MAX; row++) {
        for (col = 0; col < MAX; col++) {
            printf("%f\t", pm2[row][col]);
        }
        printf("\n");
    }

    printf("Product of entered matrix:\n");
    for (row = 0; row < MAX; row++) {
        for (col = 0; col < MAX; col++) {
            printf("%f\t", pm3[row][col]);
        }
        printf("\n");
    }
}

void simpleMM(double **a, double **b, double **r, int perfectMatrix) {
    int i, j, k;
    for (i = 0; i < perfectMatrix; i++) {
        for (j = 0; j < perfectMatrix; j++) {
            for (k = 0; k < perfectMatrix; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void simpleAdd(double **a, double **b, double **r, int perfectMatrix) {
    int i, j;
    for (i = 0; i < perfectMatrix; i++) {
        for (j = 0; j < perfectMatrix; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}

void simpleSub(double **a, double **b, double **r, int perfectMatrix) {
    int i, j;
    for (i = 0; i < perfectMatrix; i++) {
        for (j = 0; j < perfectMatrix; j++) {
            r[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Allocate square matrix.
double **allocMatrix(int size) {
    double **matrix;
    int row, i, j;

    matrix = (double **) malloc(size * sizeof (double *));
    if (!matrix)
        exit(1);

    for (row = 0; row < size; row++) {
        matrix[row] = (double *) malloc(size * sizeof (double));
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void initMatrixes(int N) {
    pm3 = allocMatrix(N);
    int half = N / 2;
    
    A11 = allocMatrix(half);
    A12 = allocMatrix(half);
    A21 = allocMatrix(half);
    A22 = allocMatrix(half);

    B11 = allocMatrix(half);
    B12 = allocMatrix(half);
    B21 = allocMatrix(half);
    B22 = allocMatrix(half);

    M1 = allocMatrix(half);
    M2 = allocMatrix(half);
    M3 = allocMatrix(half);
    M4 = allocMatrix(half);
    M5 = allocMatrix(half);
    M6 = allocMatrix(half);
    M7 = allocMatrix(half);

    C11 = allocMatrix(half);
    C12 = allocMatrix(half);
    C21 = allocMatrix(half);
    C22 = allocMatrix(half);
}

// (A_1,1 + A_2,2)*(B_1,1 + B_2,1)
void* calcM1(void* nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleAdd(A11, A22, temp1, perfectMatrix / 2);
    simpleAdd(A11, A22, temp2, perfectMatrix / 2);
    simpleMM(temp1, temp2, M1, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

// (A_2,1 + A_2,2)*B_1,1
void* calcM2(void* nothing) {
    double **temp1;
    temp1 = allocMatrix(perfectMatrix / 2);
    simpleAdd(A21, A22, temp1, perfectMatrix / 2);
    simpleMM(temp1, B11, M2, perfectMatrix / 2);
    free(temp1);
    return 0;
}

// A_1,1 * (B_1,2 - B_2,2)
void* calcM3(void* nothing) {
    double **temp1;
    temp1 = allocMatrix(perfectMatrix / 2);
    simpleSub(B12, B22, temp1, perfectMatrix / 2);
    simpleMM(A11, temp1, M3, perfectMatrix / 2);
    free(temp1);
    return 0;
}

// A_2,2 * (B_2,1 - B_1,1)
void* calcM4(void* nothing) {
    double **temp1;
    temp1 = allocMatrix(perfectMatrix / 2);
    simpleSub(B21, B11, temp1, perfectMatrix / 2);
    simpleMM(A22, temp1, M4, perfectMatrix / 2);
    free(temp1);
    return 0;
}

// (A_1,1 + A_1,2) * B_2,2
void* calcM5(void *nothing) {
    double **temp1;
    temp1 = allocMatrix(perfectMatrix / 2);
    simpleAdd(A11, A12, temp1, perfectMatrix / 2);
    simpleMM(temp1, B22, M5, perfectMatrix / 2);
    free(temp1);
    return 0;
}

// (A_2,1 - A_1,1) * (B_1,1 + B_1,2)
void* calcM6(void* nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleSub(A21, A11, temp1, perfectMatrix / 2);
    simpleAdd(B11, B12, temp2, perfectMatrix / 2);
    simpleMM(temp1, temp2, M6, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

// (A_1,2 - A_2,2) * (B_2,1 + B_2,2)
void* calcM7(void *nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleSub(A12, A22, temp1, perfectMatrix / 2);
    simpleAdd(B21, B22, temp2, perfectMatrix / 2);
    simpleMM(temp1, temp2, M7, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

// (A_1,1 * B_1,1) + (A_1,2 * B_2,1)
void* calcC11(void* nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleMM(A11, B11, temp1, perfectMatrix / 2);
    simpleMM(A12, B21, temp2, perfectMatrix / 2);
    simpleAdd(temp1, temp2, C11, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

// (A_1,1 * B_1,2) + (A_1,2 * B_2,2)
void* calcC12(void* nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleMM(A11, B12, temp1, perfectMatrix / 2);
    simpleMM(A12, B22, temp2, perfectMatrix / 2);
    simpleAdd(temp1, temp2, C12, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

// (A_2,1 * B_1,1) + (A_2,2 * B_2,1)
void* calcC21(void* nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleMM(A21, B11, temp1, perfectMatrix / 2);
    simpleMM(A22, B21, temp2, perfectMatrix / 2);
    simpleAdd(temp1, temp2, C21, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

// (A_2,1 * B_1,2) + (A_2,2 * B_2,2)
void* calcC22(void * nothing) {
    double **temp1, **temp2;
    temp1 = allocMatrix(perfectMatrix / 2);
    temp2 = allocMatrix(perfectMatrix / 2);
    simpleMM(A21, B12, temp1, perfectMatrix / 2);
    simpleMM(A22, B22, temp2, perfectMatrix / 2);
    simpleAdd(temp1, temp2, C22, perfectMatrix / 2);
    free(temp1);
    free(temp2);
    return 0;
}

void copyC(int perfectMatrix) {
    int row, col;
    int half = perfectMatrix / 2;
    for (row = 0; row < half; row++) 
    {
        for (col = 0; col < half; col++) {
            pm3[row][col] = C11[row][col];
            pm3[row][half + col] = C12[row][col];
            pm3[half + row][col] = C21[row][col];
            pm3[half + row][half + col] = C22[row][col];
        }
    }
}
void makeParts(int perfectMatrix) {
    int half = perfectMatrix / 2;
    int row, col;
    
    for (row = 0; row < half; row++) {
        for (col = 0; col < half; col++) {
            A11[row][col] = pm1[row][col];
            A12[row][col] = pm1[row][half + col];
            A21[row][col] = pm1[half + row][col];
            A22[row][col] = pm1[half + row][half + col];

            B11[row][col] = pm2[row][col];
            B12[row][col] = pm2[row][half + col];
            B21[row][col] = pm2[half + row][col];
            B22[row][col] = pm2[half + row][half + col];
        }
    }
}

void strassenMM(int perfectMatrix) 
{
    pthread_t ids[7]; // Has to be 7

    int i;
    makeParts(perfectMatrix);
    pthread_create(&ids[0], NULL, calcM1, NULL); // calcM1(NULL)
    pthread_create(&ids[1], NULL, calcM2, NULL); // calcM2(NULL)
    pthread_create(&ids[2], NULL, calcM3, NULL); // calcM3(NULL)
    pthread_create(&ids[3], NULL, calcM4, NULL); // calcM4(NULL)
    pthread_create(&ids[4], NULL, calcM5, NULL); // calcM5(NULL)
    pthread_create(&ids[5], NULL, calcM6, NULL); // calcM6(NULL)
    pthread_create(&ids[6], NULL, calcM7, NULL); // calcM7(NULL)
    for (i = 0; i < 7; i++)
    {
        pthread_join(ids[i], NULL);
    }
    pthread_create(&ids[0], NULL, calcC11, NULL); // calcC11(NULL)
    pthread_create(&ids[1], NULL, calcC12, NULL); // calcC12(NULL)
    pthread_create(&ids[2], NULL, calcC21, NULL); // calcC21(NULL)
    pthread_create(&ids[3], NULL, calcC22, NULL); // calcC22(NULL)
    for (i = 0; i < 4; i++)
    {
        pthread_join(ids[i], NULL);
    }
        copyC(perfectMatrix);
}

int main() {
    int row, col, i;
    time_t seed; // for random 
    srand((unsigned) time(&seed));

    m1 = (double **) malloc(sizeof (double *) * MAX);
    for (i = 0; i < MAX; i++)
        m1[i] = (double *) malloc(sizeof (double) * MAX);

    m2 = (double **) malloc(sizeof (double *) * MAX);
    for (i = 0; i < MAX; i++)
        m2[i] = (double *) malloc(sizeof (double) * MAX);

    for (row = 0; row < MAX; row++)
        for (col = 0; col < MAX; col++)
            m1[row][col] = rand() % LARGEST;
    for (row = 0; row < MAX; row++)
        for (col = 0; col < MAX; col++)
            m2[row][col] = rand() % LARGEST;

    int exponent = 1;
    while (pow(2, exponent) < MAX) // compare 2^n to see if it is < than input size, if it is then increment exponent.
        exponent++;

    int c;
    c = pow(2, exponent); //c = 2^n
    perfectMatrix = 2;

    if (c >= MAX) 
        perfectMatrix = c;

    pm1 = (double **) malloc(sizeof (double *) * perfectMatrix);
    for (i = 0; i < perfectMatrix; i++)
        pm1[i] = (double *) malloc(sizeof (double) * perfectMatrix);

    pm2 = (double **) malloc(sizeof (double *) * perfectMatrix);
    for (i = 0; i < perfectMatrix; i++)
        pm2[i] = (double *) malloc(sizeof (double) * perfectMatrix);

    pm3 = (double **) malloc(sizeof (double *) * perfectMatrix);
    for (i = 0; i < perfectMatrix; i++)
        pm3[i] = (double *) malloc(sizeof (double) * perfectMatrix);

    // all trailling zeros
    for (row = 0; row < perfectMatrix; row++) {
        for (col = 0; col < perfectMatrix; col++) {
            pm1[row][col] = 0;
            pm2[row][col] = 0;
            pm3[row][col] = 0;
        }
    }

    for (row = 0; row < MAX; row++) {
        for (col = 0; col < MAX; col++) {
            pm1[row][col] = m1[row][col];
            pm2[row][col] = m2[row][col];
        }
    }
  
    initMatrixes(perfectMatrix);
    printf("Done initiate\n");

    time_t start = time(NULL);

    strassenMM(perfectMatrix);

    //printf("Matrix Perfect Size = %d\n",perfectMatrix);
    printf("Calculation Time:%.2f\n", (double)(time(NULL) - start));    
    //print_perfect_matrices();
    return 0;
}