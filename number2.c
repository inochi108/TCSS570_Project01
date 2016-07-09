/* 
 * File:   main.c
 * Author: fahad
 *
 * Created on June 28, 2016, 6:30 PM
 */
/**
 * For this project, you will need to write multi-threaded C code
 * to calculate the dot product of two matrices. There are a few
 * specific requirements. First, you must use matrices of at least
 * 10,000 x 10,000 doubles in size. You may initialize each element
 * of each matrix either statically or using a random number generator.
 * You must allocate sufficient space for the result matrix as well,
 * although you may choose to do so either statically or dynamically.
 * 
 * Requirement #2
 * You must write a fully functional, single-threaded version of matrix
 * multiplication in C to ensure the results calculated are correct.
 * This implementation should include timing immediately before the matrix
 * multiplication step as well as another timing call after completing
 * the multiplication and print the time difference. 
 * This will also give you a baseline from which you can measure the
 * performance impact of your threaded version.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
int cr = 10000; // colum row of the matrix

// matrix one size of 1000
int **matixone;
int **matrixtwo;
int **matixmultiply;

// trade off declaring as global variable of for look
int k =0;
int i =0;
int j =0;
int sum = 0;


int main() {
   // randone number 
   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));   
   
    // declaring more data to array
    matixone = (int **)malloc(sizeof(int*)*cr);
    matixone[0] = (int *) malloc(sizeof(int)* cr* cr);
    
    matrixtwo = (int **)malloc(sizeof(int*)*cr);
    matrixtwo[0] = (int *) malloc(sizeof(int)* cr* cr);
    
    matixmultiply = (int **)malloc(sizeof(int*)*cr);
    matixmultiply[0] = (int *) malloc(sizeof(int)* cr* cr);

    for(i = 0; i < cr; i++)
    {
        matixone[i] = (*matixone + cr * i);
        matrixtwo[i] = (*matrixtwo + cr * i);
        matixmultiply[i] = (*matixmultiply + cr * i);
    }
    // generating random number of array and printing array.
    for(i=0;i<cr;i++)
    {
        for(j=0;j<cr;j++)
        {
            matixone[i][j] = 3;//rand() % 20;
            matrixtwo[i][j] = 2;//rand() % 20;
        }
    }
    // Clock
    clock_t time_spend = clock();
   
    for(i=0; i< cr; i++)
    {
        for(j=0; j< cr; j++)
        {
            for(k=0; k < cr; k+=1000)
            {
                sum = sum + matixone[i][k] * matrixtwo[k][j];
                sum = sum + matixone[i][k+1] * matrixtwo[k][j+1];
                sum = sum + matixone[i][k+2] * matrixtwo[k][j+2];   
                sum = sum + matixone[i][k+3] * matrixtwo[k][j+3];   
                sum = sum + matixone[i][k+4] * matrixtwo[k][j+4];   
                sum = sum + matixone[i][k+5] * matrixtwo[k][j+5]; 
                sum = sum + matixone[i][k+6] * matrixtwo[k][j+6];
                sum = sum + matixone[i][k+7] * matrixtwo[k][j+7];   
                sum = sum + matixone[i][k+8] * matrixtwo[k][j+8];   
                sum = sum + matixone[i][k+9] * matrixtwo[k][j+9];   
                sum = sum + matixone[i][k+10] * matrixtwo[k][j+10]; 
                sum = sum + matixone[i][k+11] * matrixtwo[k][j+11];
                sum = sum + matixone[i][k+12] * matrixtwo[k][j+12];   
                sum = sum + matixone[i][k+13] * matrixtwo[k][j+13];   
                sum = sum + matixone[i][k+14] * matrixtwo[k][j+14];   
                sum = sum + matixone[i][k+15] * matrixtwo[k][j+15]; 
                sum = sum + matixone[i][k+16] * matrixtwo[k][j+16];
                sum = sum + matixone[i][k+17] * matrixtwo[k][j+17];   
                sum = sum + matixone[i][k+18] * matrixtwo[k][j+18];   
                sum = sum + matixone[i][k+19] * matrixtwo[k][j+19];   
                sum = sum + matixone[i][k+20] * matrixtwo[k][j+20]; 
                sum = sum + matixone[i][k+21] * matrixtwo[k][j+21];
                sum = sum + matixone[i][k+22] * matrixtwo[k][j+22];   
                sum = sum + matixone[i][k+23] * matrixtwo[k][j+23];   
                sum = sum + matixone[i][k+24] * matrixtwo[k][j+24];   
                sum = sum + matixone[i][k+25] * matrixtwo[k][j+25]; 
                sum = sum + matixone[i][k+26] * matrixtwo[k][j+26];
                sum = sum + matixone[i][k+27] * matrixtwo[k][j+27];   
                sum = sum + matixone[i][k+28] * matrixtwo[k][j+28];   
                sum = sum + matixone[i][k+29] * matrixtwo[k][j+29];
                
                sum = sum + matixone[i][k+30] * matrixtwo[k+30][j];
                sum = sum + matixone[i][k+31] * matrixtwo[k][j+31];
                sum = sum + matixone[i][k+32] * matrixtwo[k][j+32];   
                sum = sum + matixone[i][k+33] * matrixtwo[k][j+33];   
                sum = sum + matixone[i][k+34] * matrixtwo[k][j+34];   
                sum = sum + matixone[i][k+35] * matrixtwo[k][j+35]; 
                sum = sum + matixone[i][k+36] * matrixtwo[k][j+36];
                sum = sum + matixone[i][k+37] * matrixtwo[k][j+7];   
                sum = sum + matixone[i][k+38] * matrixtwo[k][j+8];   
                sum = sum + matixone[i][k+39] * matrixtwo[k][j+39];   
                sum = sum + matixone[i][k+40] * matrixtwo[k][j+40];
                
               
                sum = sum + matixone[i][k+41] * matrixtwo[k][j+41];
                sum = sum + matixone[i][k+42] * matrixtwo[k][j+42];   
                sum = sum + matixone[i][k+43] * matrixtwo[k][j+43];   
                sum = sum + matixone[i][k+44] * matrixtwo[k][j+44];   
                sum = sum + matixone[i][k+45] * matrixtwo[k][j+45]; 
                sum = sum + matixone[i][k+46] * matrixtwo[k][j+46];
                sum = sum + matixone[i][k+47] * matrixtwo[k][j+47];   
                sum = sum + matixone[i][k+48] * matrixtwo[k][j+48];   
                sum = sum + matixone[i][k+49] * matrixtwo[k][j+49];   
                sum = sum + matixone[i][k+50] * matrixtwo[k][j+50]; 
                
                
                sum = sum + matixone[i][k+51] * matrixtwo[k][j+51];
                sum = sum + matixone[i][k+52] * matrixtwo[k][j+52];   
                sum = sum + matixone[i][k+53] * matrixtwo[k][j+53];   
                sum = sum + matixone[i][k+54] * matrixtwo[k][j+54];   
                sum = sum + matixone[i][k+55] * matrixtwo[k][j+55]; 
                sum = sum + matixone[i][k+56] * matrixtwo[k][j+56];
                sum = sum + matixone[i][k+57] * matrixtwo[k][j+57];   
                sum = sum + matixone[i][k+58] * matrixtwo[k][j+58];   
                sum = sum + matixone[i][k+59] * matrixtwo[k][j+59];   
                sum = sum + matixone[i][k+60] * matrixtwo[k][j+60]; 
                
                sum = sum + matixone[i][k+61] * matrixtwo[k][j+61];
                sum = sum + matixone[i][k+62] * matrixtwo[k][j+62];   
                sum = sum + matixone[i][k+63] * matrixtwo[k][j+63];   
                sum = sum + matixone[i][k+64] * matrixtwo[k][j+64];   
                sum = sum + matixone[i][k+65] * matrixtwo[k][j+65]; 
                sum = sum + matixone[i][k+66] * matrixtwo[k][j+66];
                sum = sum + matixone[i][k+67] * matrixtwo[k][j+67];   
                sum = sum + matixone[i][k+68] * matrixtwo[k][j+68];   
                sum = sum + matixone[i][k+69] * matrixtwo[k][j+69];   
                sum = sum + matixone[i][k+70] * matrixtwo[k][j+70];
                
                sum = sum + matixone[i][k+71] * matrixtwo[k][j+71];
                sum = sum + matixone[i][k+72] * matrixtwo[k][j+72];   
                sum = sum + matixone[i][k+73] * matrixtwo[k][j+73];   
                sum = sum + matixone[i][k+74] * matrixtwo[k][j+74];   
                sum = sum + matixone[i][k+75] * matrixtwo[k][j+75]; 
                sum = sum + matixone[i][k+76] * matrixtwo[k][j+76];
                sum = sum + matixone[i][k+77] * matrixtwo[k][j+77];   
                sum = sum + matixone[i][k+78] * matrixtwo[k][j+78];   
                sum = sum + matixone[i][k+79] * matrixtwo[k][j+79];   
                sum = sum + matixone[i][k+80] * matrixtwo[k][j+80]; 
                
                
                sum = sum + matixone[i][k+81] * matrixtwo[k][j+81];
                sum = sum + matixone[i][k+82] * matrixtwo[k][j+82];   
                sum = sum + matixone[i][k+83] * matrixtwo[k][j+83];   
                sum = sum + matixone[i][k+84] * matrixtwo[k][j+84];   
                sum = sum + matixone[i][k+85] * matrixtwo[k][j+85]; 
                sum = sum + matixone[i][k+86] * matrixtwo[k][j+86];
                sum = sum + matixone[i][k+87] * matrixtwo[k][j+87];   
                sum = sum + matixone[i][k+88] * matrixtwo[k][j+88];   
                sum = sum + matixone[i][k+89] * matrixtwo[k][j+89];   
                sum = sum + matixone[i][k+90] * matrixtwo[k][j+90]; 
                
                
                sum = sum + matixone[i][k+91] * matrixtwo[k][j+91];
                sum = sum + matixone[i][k+92] * matrixtwo[k][j+92];   
                sum = sum + matixone[i][k+93] * matrixtwo[k][j+93];   
                sum = sum + matixone[i][k+94] * matrixtwo[k][j+94];   
                sum = sum + matixone[i][k+95] * matrixtwo[k][j+95]; 
                sum = sum + matixone[i][k+96] * matrixtwo[k][j+96];
                sum = sum + matixone[i][k+97] * matrixtwo[k][j+97];   
                sum = sum + matixone[i][k+98] * matrixtwo[k][j+98];   
                sum = sum + matixone[i][k+99] * matrixtwo[k][j+99];   
                sum = sum + matixone[i][k+100] * matrixtwo[k][j+100]; 
                
                
                sum = sum + matixone[i][k+101] * matrixtwo[k][j+102]; 
                sum = sum + matixone[i][k+102] * matrixtwo[k][j+102]; 
                sum = sum + matixone[i][k+103] * matrixtwo[k][j+103]; 
                sum = sum + matixone[i][k+104] * matrixtwo[k][j+104]; 
                sum = sum + matixone[i][k+105] * matrixtwo[k][j+105]; 
                sum = sum + matixone[i][k+106] * matrixtwo[k][j+106]; 
                sum = sum + matixone[i][k+107] * matrixtwo[k][j+107];
                sum = sum + matixone[i][k+108] * matrixtwo[k][j+108]; 
                sum = sum + matixone[i][k+109] * matrixtwo[k][j+109];
                sum = sum + matixone[i][k+110] * matrixtwo[k][j+110];
                
                sum = sum + matixone[i][k+111] * matrixtwo[k][j+111]; 
                sum = sum + matixone[i][k+112] * matrixtwo[k][j+112]; 
                sum = sum + matixone[i][k+113] * matrixtwo[k][j+113]; 
                sum = sum + matixone[i][k+114] * matrixtwo[k][j+114]; 
                sum = sum + matixone[i][k+115] * matrixtwo[k][j+115]; 
                sum = sum + matixone[i][k+116] * matrixtwo[k][j+116]; 
                sum = sum + matixone[i][k+117] * matrixtwo[k][j+117];
                sum = sum + matixone[i][k+118] * matrixtwo[k][j+118]; 
                sum = sum + matixone[i][k+119] * matrixtwo[k][j+119];
                sum = sum + matixone[i][k+120] * matrixtwo[k][j+120]; 
                
                
                sum = sum + matixone[i][k+121] * matrixtwo[k][j+121]; 
                sum = sum + matixone[i][k+122] * matrixtwo[k][j+122]; 
                sum = sum + matixone[i][k+123] * matrixtwo[k][j+123]; 
                sum = sum + matixone[i][k+124] * matrixtwo[k][j+124]; 
                sum = sum + matixone[i][k+125] * matrixtwo[k][j+125]; 
                sum = sum + matixone[i][k+126] * matrixtwo[k][j+126]; 
                sum = sum + matixone[i][k+127] * matrixtwo[k][j+127];
                sum = sum + matixone[i][k+128] * matrixtwo[k][j+128]; 
                sum = sum + matixone[i][k+129] * matrixtwo[k][j+129];
                sum = sum + matixone[i][k+130] * matrixtwo[k][j+130]; 
                
                sum = sum + matixone[i][k+131] * matrixtwo[k][j+131]; 
                sum = sum + matixone[i][k+132] * matrixtwo[k][j+132]; 
                sum = sum + matixone[i][k+133] * matrixtwo[k][j+133]; 
                sum = sum + matixone[i][k+134] * matrixtwo[k][j+134]; 
                sum = sum + matixone[i][k+135] * matrixtwo[k][j+135]; 
                sum = sum + matixone[i][k+136] * matrixtwo[k][j+136]; 
                sum = sum + matixone[i][k+137] * matrixtwo[k][j+137];
                sum = sum + matixone[i][k+138] * matrixtwo[k][j+138]; 
                sum = sum + matixone[i][k+139] * matrixtwo[k][j+139];
                sum = sum + matixone[i][k+140] * matrixtwo[k][j+140]; 
                
                
                
                sum = sum + matixone[i][k+141] * matrixtwo[k][j+141]; 
                sum = sum + matixone[i][k+142] * matrixtwo[k][j+142]; 
                sum = sum + matixone[i][k+143] * matrixtwo[k][j+143]; 
                sum = sum + matixone[i][k+144] * matrixtwo[k][j+144]; 
                sum = sum + matixone[i][k+145] * matrixtwo[k][j+145]; 
                sum = sum + matixone[i][k+146] * matrixtwo[k][j+146]; 
                sum = sum + matixone[i][k+147] * matrixtwo[k][j+147];
                sum = sum + matixone[i][k+148] * matrixtwo[k][j+148]; 
                sum = sum + matixone[i][k+149] * matrixtwo[k][j+149];
                sum = sum + matixone[i][k+150] * matrixtwo[k][j+150]; 
                
                
                sum = sum + matixone[i][k+151] * matrixtwo[k][j+151]; 
                sum = sum + matixone[i][k+152] * matrixtwo[k][j+152]; 
                sum = sum + matixone[i][k+153] * matrixtwo[k][j+153]; 
                sum = sum + matixone[i][k+154] * matrixtwo[k][j+154]; 
                sum = sum + matixone[i][k+155] * matrixtwo[k][j+155]; 
                sum = sum + matixone[i][k+156] * matrixtwo[k][j+156]; 
                sum = sum + matixone[i][k+157] * matrixtwo[k][j+157];
                sum = sum + matixone[i][k+158] * matrixtwo[k][j+158]; 
                sum = sum + matixone[i][k+159] * matrixtwo[k][j+159];
                sum = sum + matixone[i][k+160] * matrixtwo[k][j+160]; 
                
                
                sum = sum + matixone[i][k+161] * matrixtwo[k][j+161]; 
                sum = sum + matixone[i][k+162] * matrixtwo[k][j+162]; 
                sum = sum + matixone[i][k+163] * matrixtwo[k][j+163]; 
                sum = sum + matixone[i][k+164] * matrixtwo[k][j+164]; 
                sum = sum + matixone[i][k+165] * matrixtwo[k][j+165]; 
                sum = sum + matixone[i][k+166] * matrixtwo[k][j+166]; 
                sum = sum + matixone[i][k+167] * matrixtwo[k][j+167];
                sum = sum + matixone[i][k+168] * matrixtwo[k][j+168]; 
                sum = sum + matixone[i][k+169] * matrixtwo[k][j+169];
                sum = sum + matixone[i][k+170] * matrixtwo[k][j+170]; 
                
                
                sum = sum + matixone[i][k+171] * matrixtwo[k][j+171]; 
                sum = sum + matixone[i][k+172] * matrixtwo[k][j+172]; 
                sum = sum + matixone[i][k+173] * matrixtwo[k][j+173]; 
                sum = sum + matixone[i][k+174] * matrixtwo[k][j+174]; 
                sum = sum + matixone[i][k+175] * matrixtwo[k][j+175]; 
                sum = sum + matixone[i][k+176] * matrixtwo[k][j+176]; 
                sum = sum + matixone[i][k+177] * matrixtwo[k][j+177];
                sum = sum + matixone[i][k+178] * matrixtwo[k][j+178]; 
                sum = sum + matixone[i][k+179] * matrixtwo[k][j+179];
                sum = sum + matixone[i][k+180] * matrixtwo[k][j+180]; 
                
                
                sum = sum + matixone[i][k+181] * matrixtwo[k][j+181]; 
                sum = sum + matixone[i][k+182] * matrixtwo[k][j+182]; 
                sum = sum + matixone[i][k+183] * matrixtwo[k][j+183]; 
                sum = sum + matixone[i][k+184] * matrixtwo[k][j+184]; 
                sum = sum + matixone[i][k+185] * matrixtwo[k][j+185]; 
                sum = sum + matixone[i][k+186] * matrixtwo[k][j+186]; 
                sum = sum + matixone[i][k+187] * matrixtwo[k][j+187];
                sum = sum + matixone[i][k+188] * matrixtwo[k][j+188]; 
                sum = sum + matixone[i][k+189] * matrixtwo[k][j+189];
                sum = sum + matixone[i][k+190] * matrixtwo[k][j+190];
                
                sum = sum + matixone[i][k+191] * matrixtwo[k][j+191]; 
                sum = sum + matixone[i][k+192] * matrixtwo[k][j+192]; 
                sum = sum + matixone[i][k+193] * matrixtwo[k][j+193]; 
                sum = sum + matixone[i][k+194] * matrixtwo[k][j+194]; 
                sum = sum + matixone[i][k+195] * matrixtwo[k][j+195]; 
                sum = sum + matixone[i][k+196] * matrixtwo[k][j+196]; 
                sum = sum + matixone[i][k+197] * matrixtwo[k][j+197];
                sum = sum + matixone[i][k+198] * matrixtwo[k][j+198]; 
                sum = sum + matixone[i][k+199] * matrixtwo[k][j+199];
                sum = sum + matixone[i][k+200] * matrixtwo[k][j+200]; 
                
                
                sum = sum + matixone[i][k+201] * matrixtwo[k][j+201]; 
                sum = sum + matixone[i][k+202] * matrixtwo[k][j+202]; 
                sum = sum + matixone[i][k+203] * matrixtwo[k][j+203]; 
                sum = sum + matixone[i][k+204] * matrixtwo[k][j+204]; 
                sum = sum + matixone[i][k+205] * matrixtwo[k][j+205]; 
                sum = sum + matixone[i][k+206] * matrixtwo[k][j+206]; 
                sum = sum + matixone[i][k+207] * matrixtwo[k][j+207];
                sum = sum + matixone[i][k+208] * matrixtwo[k][j+208]; 
                sum = sum + matixone[i][k+209] * matrixtwo[k][j+209];
                sum = sum + matixone[i][k+210] * matrixtwo[k][j+210];
                
                sum = sum + matixone[i][k+211] * matrixtwo[k][j+211]; 
                sum = sum + matixone[i][k+212] * matrixtwo[k][j+212]; 
                sum = sum + matixone[i][k+213] * matrixtwo[k][j+213]; 
                sum = sum + matixone[i][k+214] * matrixtwo[k][j+214]; 
                sum = sum + matixone[i][k+215] * matrixtwo[k][j+215]; 
                sum = sum + matixone[i][k+216] * matrixtwo[k][j+216]; 
                sum = sum + matixone[i][k+217] * matrixtwo[k][j+217];
                sum = sum + matixone[i][k+218] * matrixtwo[k][j+218]; 
                sum = sum + matixone[i][k+219] * matrixtwo[k][j+219];
                sum = sum + matixone[i][k+220] * matrixtwo[k][j+220]; 
                
                
                sum = sum + matixone[i][k+221] * matrixtwo[k][j+121]; 
                sum = sum + matixone[i][k+222] * matrixtwo[k][j+122]; 
                sum = sum + matixone[i][k+223] * matrixtwo[k][j+123]; 
                sum = sum + matixone[i][k+224] * matrixtwo[k][j+124]; 
                sum = sum + matixone[i][k+225] * matrixtwo[k][j+125]; 
                sum = sum + matixone[i][k+226] * matrixtwo[k][j+126]; 
                sum = sum + matixone[i][k+227] * matrixtwo[k][j+127];
                sum = sum + matixone[i][k+228] * matrixtwo[k][j+128]; 
                sum = sum + matixone[i][k+229] * matrixtwo[k][j+129];
                sum = sum + matixone[i][k+230] * matrixtwo[k][j+130]; 
                
                sum = sum + matixone[i][k+231] * matrixtwo[k][j+231]; 
                sum = sum + matixone[i][k+232] * matrixtwo[k][j+232]; 
                sum = sum + matixone[i][k+233] * matrixtwo[k][j+233]; 
                sum = sum + matixone[i][k+234] * matrixtwo[k][j+234]; 
                sum = sum + matixone[i][k+235] * matrixtwo[k][j+235]; 
                sum = sum + matixone[i][k+236] * matrixtwo[k][j+236]; 
                sum = sum + matixone[i][k+237] * matrixtwo[k][j+237];
                sum = sum + matixone[i][k+238] * matrixtwo[k][j+238]; 
                sum = sum + matixone[i][k+239] * matrixtwo[k][j+239];
                sum = sum + matixone[i][k+240] * matrixtwo[k][j+240]; 
                
                
                
                sum = sum + matixone[i][k+241] * matrixtwo[k][j+241]; 
                sum = sum + matixone[i][k+242] * matrixtwo[k][j+242]; 
                sum = sum + matixone[i][k+243] * matrixtwo[k][j+243]; 
                sum = sum + matixone[i][k+244] * matrixtwo[k][j+244]; 
                sum = sum + matixone[i][k+245] * matrixtwo[k][j+245]; 
                sum = sum + matixone[i][k+246] * matrixtwo[k][j+246]; 
                sum = sum + matixone[i][k+247] * matrixtwo[k][j+247];
                sum = sum + matixone[i][k+248] * matrixtwo[k][j+248]; 
                sum = sum + matixone[i][k+249] * matrixtwo[k][j+249];
                sum = sum + matixone[i][k+250] * matrixtwo[k][j+250]; 
                
                
                sum = sum + matixone[i][k+251] * matrixtwo[k][j+251]; 
                sum = sum + matixone[i][k+252] * matrixtwo[k][j+252]; 
                sum = sum + matixone[i][k+253] * matrixtwo[k][j+253]; 
                sum = sum + matixone[i][k+254] * matrixtwo[k][j+254]; 
                sum = sum + matixone[i][k+255] * matrixtwo[k][j+255]; 
                sum = sum + matixone[i][k+256] * matrixtwo[k][j+256]; 
                sum = sum + matixone[i][k+257] * matrixtwo[k][j+257];
                sum = sum + matixone[i][k+258] * matrixtwo[k][j+258]; 
                sum = sum + matixone[i][k+259] * matrixtwo[k][j+259];
                sum = sum + matixone[i][k+260] * matrixtwo[k][j+260]; 
                
                
                sum = sum + matixone[i][k+261] * matrixtwo[k][j+261]; 
                sum = sum + matixone[i][k+262] * matrixtwo[k][j+262]; 
                sum = sum + matixone[i][k+263] * matrixtwo[k][j+263]; 
                sum = sum + matixone[i][k+264] * matrixtwo[k][j+264]; 
                sum = sum + matixone[i][k+265] * matrixtwo[k][j+265]; 
                sum = sum + matixone[i][k+266] * matrixtwo[k][j+266]; 
                sum = sum + matixone[i][k+267] * matrixtwo[k][j+267];
                sum = sum + matixone[i][k+268] * matrixtwo[k][j+268]; 
                sum = sum + matixone[i][k+269] * matrixtwo[k][j+269];
                sum = sum + matixone[i][k+270] * matrixtwo[k][j+270]; 
                
                
                sum = sum + matixone[i][k+271] * matrixtwo[k][j+271]; 
                sum = sum + matixone[i][k+272] * matrixtwo[k][j+272]; 
                sum = sum + matixone[i][k+273] * matrixtwo[k][j+273]; 
                sum = sum + matixone[i][k+274] * matrixtwo[k][j+274]; 
                sum = sum + matixone[i][k+275] * matrixtwo[k][j+275]; 
                sum = sum + matixone[i][k+276] * matrixtwo[k][j+276]; 
                sum = sum + matixone[i][k+277] * matrixtwo[k][j+277];
                sum = sum + matixone[i][k+278] * matrixtwo[k][j+278]; 
                sum = sum + matixone[i][k+279] * matrixtwo[k][j+279];
                sum = sum + matixone[i][k+280] * matrixtwo[k][j+280]; 
                
                
                sum = sum + matixone[i][k+281] * matrixtwo[k][j+281]; 
                sum = sum + matixone[i][k+282] * matrixtwo[k][j+282]; 
                sum = sum + matixone[i][k+283] * matrixtwo[k][j+283]; 
                sum = sum + matixone[i][k+284] * matrixtwo[k][j+284]; 
                sum = sum + matixone[i][k+285] * matrixtwo[k][j+285]; 
                sum = sum + matixone[i][k+286] * matrixtwo[k][j+286]; 
                sum = sum + matixone[i][k+287] * matrixtwo[k][j+287];
                sum = sum + matixone[i][k+288] * matrixtwo[k][j+288]; 
                sum = sum + matixone[i][k+289] * matrixtwo[k][j+289];
                sum = sum + matixone[i][k+290] * matrixtwo[k][j+290];
                
                sum = sum + matixone[i][k+291] * matrixtwo[k][j+291]; 
                sum = sum + matixone[i][k+292] * matrixtwo[k][j+292]; 
                sum = sum + matixone[i][k+293] * matrixtwo[k][j+293]; 
                sum = sum + matixone[i][k+294] * matrixtwo[k][j+294]; 
                sum = sum + matixone[i][k+295] * matrixtwo[k][j+295]; 
                sum = sum + matixone[i][k+296] * matrixtwo[k][j+296]; 
                sum = sum + matixone[i][k+297] * matrixtwo[k][j+297];
                sum = sum + matixone[i][k+298] * matrixtwo[k][j+298]; 
                sum = sum + matixone[i][k+299] * matrixtwo[k][j+299];
                sum = sum + matixone[i][k+300] * matrixtwo[k][j+300];
               
                sum = sum + matixone[i][k+301] * matrixtwo[k][j+301]; 
                sum = sum + matixone[i][k+302] * matrixtwo[k][j+302]; 
                sum = sum + matixone[i][k+303] * matrixtwo[k][j+303]; 
                sum = sum + matixone[i][k+304] * matrixtwo[k][j+304]; 
                sum = sum + matixone[i][k+305] * matrixtwo[k][j+305]; 
                sum = sum + matixone[i][k+306] * matrixtwo[k][j+306]; 
                sum = sum + matixone[i][k+307] * matrixtwo[k][j+307];
                sum = sum + matixone[i][k+308] * matrixtwo[k][j+308]; 
                sum = sum + matixone[i][k+309] * matrixtwo[k][j+309];
                sum = sum + matixone[i][k+310] * matrixtwo[k][j+310];
                
                sum = sum + matixone[i][k+311] * matrixtwo[k][j+311]; 
                sum = sum + matixone[i][k+312] * matrixtwo[k][j+312]; 
                sum = sum + matixone[i][k+313] * matrixtwo[k][j+313]; 
                sum = sum + matixone[i][k+314] * matrixtwo[k][j+314]; 
                sum = sum + matixone[i][k+315] * matrixtwo[k][j+315]; 
                sum = sum + matixone[i][k+316] * matrixtwo[k][j+316]; 
                sum = sum + matixone[i][k+317] * matrixtwo[k][j+317];
                sum = sum + matixone[i][k+318] * matrixtwo[k][j+318]; 
                sum = sum + matixone[i][k+319] * matrixtwo[k][j+319];
                sum = sum + matixone[i][k+320] * matrixtwo[k][j+320]; 
                
                
                sum = sum + matixone[i][k+321] * matrixtwo[k][j+321]; 
                sum = sum + matixone[i][k+322] * matrixtwo[k][j+322]; 
                sum = sum + matixone[i][k+323] * matrixtwo[k][j+323]; 
                sum = sum + matixone[i][k+324] * matrixtwo[k][j+324]; 
                sum = sum + matixone[i][k+325] * matrixtwo[k][j+325]; 
                sum = sum + matixone[i][k+326] * matrixtwo[k][j+326]; 
                sum = sum + matixone[i][k+327] * matrixtwo[k][j+327];
                sum = sum + matixone[i][k+328] * matrixtwo[k][j+328]; 
                sum = sum + matixone[i][k+329] * matrixtwo[k][j+329];
                sum = sum + matixone[i][k+330] * matrixtwo[k][j+330]; 
                
                sum = sum + matixone[i][k+331] * matrixtwo[k][j+331]; 
                sum = sum + matixone[i][k+332] * matrixtwo[k][j+332]; 
                sum = sum + matixone[i][k+333] * matrixtwo[k][j+333]; 
                sum = sum + matixone[i][k+334] * matrixtwo[k][j+334]; 
                sum = sum + matixone[i][k+335] * matrixtwo[k][j+335]; 
                sum = sum + matixone[i][k+336] * matrixtwo[k][j+336]; 
                sum = sum + matixone[i][k+337] * matrixtwo[k][j+337];
                sum = sum + matixone[i][k+338] * matrixtwo[k][j+338]; 
                sum = sum + matixone[i][k+339] * matrixtwo[k][j+339];
                sum = sum + matixone[i][k+340] * matrixtwo[k][j+340]; 
                
                
                
                sum = sum + matixone[i][k+341] * matrixtwo[k][j+341]; 
                sum = sum + matixone[i][k+342] * matrixtwo[k][j+342]; 
                sum = sum + matixone[i][k+343] * matrixtwo[k][j+343]; 
                sum = sum + matixone[i][k+344] * matrixtwo[k][j+344]; 
                sum = sum + matixone[i][k+345] * matrixtwo[k][j+345]; 
                sum = sum + matixone[i][k+346] * matrixtwo[k][j+346]; 
                sum = sum + matixone[i][k+347] * matrixtwo[k][j+347];
                sum = sum + matixone[i][k+348] * matrixtwo[k][j+348]; 
                sum = sum + matixone[i][k+349] * matrixtwo[k][j+349];
                sum = sum + matixone[i][k+350] * matrixtwo[k][j+350]; 
                
                
                sum = sum + matixone[i][k+351] * matrixtwo[k][j+351]; 
                sum = sum + matixone[i][k+352] * matrixtwo[k][j+352]; 
                sum = sum + matixone[i][k+353] * matrixtwo[k][j+353]; 
                sum = sum + matixone[i][k+354] * matrixtwo[k][j+354]; 
                sum = sum + matixone[i][k+355] * matrixtwo[k][j+355]; 
                sum = sum + matixone[i][k+356] * matrixtwo[k][j+356]; 
                sum = sum + matixone[i][k+357] * matrixtwo[k][j+357];
                sum = sum + matixone[i][k+358] * matrixtwo[k][j+358]; 
                sum = sum + matixone[i][k+359] * matrixtwo[k][j+359];
                sum = sum + matixone[i][k+360] * matrixtwo[k][j+360]; 
                
                
                sum = sum + matixone[i][k+361] * matrixtwo[k][j+361]; 
                sum = sum + matixone[i][k+362] * matrixtwo[k][j+362]; 
                sum = sum + matixone[i][k+363] * matrixtwo[k][j+363]; 
                sum = sum + matixone[i][k+364] * matrixtwo[k][j+364]; 
                sum = sum + matixone[i][k+365] * matrixtwo[k][j+365]; 
                sum = sum + matixone[i][k+366] * matrixtwo[k][j+366]; 
                sum = sum + matixone[i][k+367] * matrixtwo[k][j+367];
                sum = sum + matixone[i][k+368] * matrixtwo[k][j+368]; 
                sum = sum + matixone[i][k+369] * matrixtwo[k][j+369];
                sum = sum + matixone[i][k+370] * matrixtwo[k][j+370]; 
                
                
                sum = sum + matixone[i][k+371] * matrixtwo[k][j+371]; 
                sum = sum + matixone[i][k+372] * matrixtwo[k][j+372]; 
                sum = sum + matixone[i][k+373] * matrixtwo[k][j+373]; 
                sum = sum + matixone[i][k+374] * matrixtwo[k][j+374]; 
                sum = sum + matixone[i][k+375] * matrixtwo[k][j+375]; 
                sum = sum + matixone[i][k+376] * matrixtwo[k][j+376]; 
                sum = sum + matixone[i][k+377] * matrixtwo[k][j+377];
                sum = sum + matixone[i][k+378] * matrixtwo[k][j+378]; 
                sum = sum + matixone[i][k+379] * matrixtwo[k][j+379];
                sum = sum + matixone[i][k+380] * matrixtwo[k][j+380]; 
                
                
                sum = sum + matixone[i][k+381] * matrixtwo[k][j+381]; 
                sum = sum + matixone[i][k+382] * matrixtwo[k][j+382]; 
                sum = sum + matixone[i][k+383] * matrixtwo[k][j+383]; 
                sum = sum + matixone[i][k+384] * matrixtwo[k][j+384]; 
                sum = sum + matixone[i][k+385] * matrixtwo[k][j+385]; 
                sum = sum + matixone[i][k+386] * matrixtwo[k][j+386]; 
                sum = sum + matixone[i][k+387] * matrixtwo[k][j+387];
                sum = sum + matixone[i][k+388] * matrixtwo[k][j+388]; 
                sum = sum + matixone[i][k+389] * matrixtwo[k][j+389];
                sum = sum + matixone[i][k+390] * matrixtwo[k][j+390];
                
                sum = sum + matixone[i][k+391] * matrixtwo[k][j+391]; 
                sum = sum + matixone[i][k+392] * matrixtwo[k][j+392]; 
                sum = sum + matixone[i][k+393] * matrixtwo[k][j+393]; 
                sum = sum + matixone[i][k+394] * matrixtwo[k][j+394]; 
                sum = sum + matixone[i][k+395] * matrixtwo[k][j+395]; 
                sum = sum + matixone[i][k+396] * matrixtwo[k][j+396]; 
                sum = sum + matixone[i][k+397] * matrixtwo[k][j+397];
                sum = sum + matixone[i][k+398] * matrixtwo[k][j+398]; 
                sum = sum + matixone[i][k+399] * matrixtwo[k][j+399];
                sum = sum + matixone[i][k+400] * matrixtwo[k][j+400];
            //
                
                sum = sum + matixone[i][k+401] * matrixtwo[k][j+401]; 
                sum = sum + matixone[i][k+402] * matrixtwo[k][j+402]; 
                sum = sum + matixone[i][k+403] * matrixtwo[k][j+403]; 
                sum = sum + matixone[i][k+404] * matrixtwo[k][j+404]; 
                sum = sum + matixone[i][k+405] * matrixtwo[k][j+405]; 
                sum = sum + matixone[i][k+406] * matrixtwo[k][j+406]; 
                sum = sum + matixone[i][k+407] * matrixtwo[k][j+407];
                sum = sum + matixone[i][k+408] * matrixtwo[k][j+408]; 
                sum = sum + matixone[i][k+409] * matrixtwo[k][j+409];
                sum = sum + matixone[i][k+410] * matrixtwo[k][j+410];
                
                sum = sum + matixone[i][k+411] * matrixtwo[k][j+411]; 
                sum = sum + matixone[i][k+412] * matrixtwo[k][j+412]; 
                sum = sum + matixone[i][k+413] * matrixtwo[k][j+413]; 
                sum = sum + matixone[i][k+414] * matrixtwo[k][j+414]; 
                sum = sum + matixone[i][k+415] * matrixtwo[k][j+415]; 
                sum = sum + matixone[i][k+416] * matrixtwo[k][j+416]; 
                sum = sum + matixone[i][k+417] * matrixtwo[k][j+417];
                sum = sum + matixone[i][k+418] * matrixtwo[k][j+418]; 
                sum = sum + matixone[i][k+419] * matrixtwo[k][j+419];
                sum = sum + matixone[i][k+420] * matrixtwo[k][j+420]; 
                
                
                sum = sum + matixone[i][k+421] * matrixtwo[k][j+421]; 
                sum = sum + matixone[i][k+422] * matrixtwo[k][j+422]; 
                sum = sum + matixone[i][k+423] * matrixtwo[k][j+423]; 
                sum = sum + matixone[i][k+424] * matrixtwo[k][j+424]; 
                sum = sum + matixone[i][k+425] * matrixtwo[k][j+425]; 
                sum = sum + matixone[i][k+426] * matrixtwo[k][j+426]; 
                sum = sum + matixone[i][k+427] * matrixtwo[k][j+427];
                sum = sum + matixone[i][k+428] * matrixtwo[k][j+428]; 
                sum = sum + matixone[i][k+429] * matrixtwo[k][j+429];
                sum = sum + matixone[i][k+430] * matrixtwo[k][j+430]; 
                
                sum = sum + matixone[i][k+431] * matrixtwo[k][j+431]; 
                sum = sum + matixone[i][k+432] * matrixtwo[k][j+432]; 
                sum = sum + matixone[i][k+433] * matrixtwo[k][j+433]; 
                sum = sum + matixone[i][k+434] * matrixtwo[k][j+434]; 
                sum = sum + matixone[i][k+435] * matrixtwo[k][j+435]; 
                sum = sum + matixone[i][k+436] * matrixtwo[k][j+436]; 
                sum = sum + matixone[i][k+437] * matrixtwo[k][j+437];
                sum = sum + matixone[i][k+438] * matrixtwo[k][j+438]; 
                sum = sum + matixone[i][k+439] * matrixtwo[k][j+439];
                sum = sum + matixone[i][k+440] * matrixtwo[k][j+440]; 
                
                
                
                sum = sum + matixone[i][k+441] * matrixtwo[k][j+441]; 
                sum = sum + matixone[i][k+442] * matrixtwo[k][j+442]; 
                sum = sum + matixone[i][k+443] * matrixtwo[k][j+443]; 
                sum = sum + matixone[i][k+444] * matrixtwo[k][j+444]; 
                sum = sum + matixone[i][k+445] * matrixtwo[k][j+445]; 
                sum = sum + matixone[i][k+446] * matrixtwo[k][j+446]; 
                sum = sum + matixone[i][k+447] * matrixtwo[k][j+447];
                sum = sum + matixone[i][k+448] * matrixtwo[k][j+448]; 
                sum = sum + matixone[i][k+449] * matrixtwo[k][j+449];
                sum = sum + matixone[i][k+450] * matrixtwo[k][j+450]; 
                
                
                sum = sum + matixone[i][k+451] * matrixtwo[k][j+451]; 
                sum = sum + matixone[i][k+452] * matrixtwo[k][j+452]; 
                sum = sum + matixone[i][k+453] * matrixtwo[k][j+453]; 
                sum = sum + matixone[i][k+454] * matrixtwo[k][j+454]; 
                sum = sum + matixone[i][k+455] * matrixtwo[k][j+455]; 
                sum = sum + matixone[i][k+456] * matrixtwo[k][j+456]; 
                sum = sum + matixone[i][k+457] * matrixtwo[k][j+457];
                sum = sum + matixone[i][k+458] * matrixtwo[k][j+458]; 
                sum = sum + matixone[i][k+459] * matrixtwo[k][j+459];
                sum = sum + matixone[i][k+460] * matrixtwo[k][j+460]; 
                
                
                sum = sum + matixone[i][k+461] * matrixtwo[k][j+461]; 
                sum = sum + matixone[i][k+462] * matrixtwo[k][j+462]; 
                sum = sum + matixone[i][k+463] * matrixtwo[k][j+463]; 
                sum = sum + matixone[i][k+464] * matrixtwo[k][j+464]; 
                sum = sum + matixone[i][k+465] * matrixtwo[k][j+465]; 
                sum = sum + matixone[i][k+466] * matrixtwo[k][j+466]; 
                sum = sum + matixone[i][k+467] * matrixtwo[k][j+467];
                sum = sum + matixone[i][k+468] * matrixtwo[k][j+468]; 
                sum = sum + matixone[i][k+469] * matrixtwo[k][j+469];
                sum = sum + matixone[i][k+470] * matrixtwo[k][j+470]; 
                
                
                sum = sum + matixone[i][k+471] * matrixtwo[k][j+471]; 
                sum = sum + matixone[i][k+472] * matrixtwo[k][j+472]; 
                sum = sum + matixone[i][k+473] * matrixtwo[k][j+473]; 
                sum = sum + matixone[i][k+474] * matrixtwo[k][j+474]; 
                sum = sum + matixone[i][k+475] * matrixtwo[k][j+475]; 
                sum = sum + matixone[i][k+476] * matrixtwo[k][j+476]; 
                sum = sum + matixone[i][k+477] * matrixtwo[k][j+477];
                sum = sum + matixone[i][k+478] * matrixtwo[k][j+478]; 
                sum = sum + matixone[i][k+479] * matrixtwo[k][j+479];
                sum = sum + matixone[i][k+480] * matrixtwo[k][j+480]; 
                
                
                sum = sum + matixone[i][k+481] * matrixtwo[k][j+481]; 
                sum = sum + matixone[i][k+482] * matrixtwo[k][j+482]; 
                sum = sum + matixone[i][k+483] * matrixtwo[k][j+483]; 
                sum = sum + matixone[i][k+484] * matrixtwo[k][j+484]; 
                sum = sum + matixone[i][k+485] * matrixtwo[k][j+485]; 
                sum = sum + matixone[i][k+486] * matrixtwo[k][j+486]; 
                sum = sum + matixone[i][k+487] * matrixtwo[k][j+487];
                sum = sum + matixone[i][k+488] * matrixtwo[k][j+488]; 
                sum = sum + matixone[i][k+489] * matrixtwo[k][j+489];
                sum = sum + matixone[i][k+490] * matrixtwo[k][j+490];
                
                sum = sum + matixone[i][k+491] * matrixtwo[k][j+491]; 
                sum = sum + matixone[i][k+492] * matrixtwo[k][j+492]; 
                sum = sum + matixone[i][k+493] * matrixtwo[k][j+493]; 
                sum = sum + matixone[i][k+494] * matrixtwo[k][j+494]; 
                sum = sum + matixone[i][k+495] * matrixtwo[k][j+495]; 
                sum = sum + matixone[i][k+496] * matrixtwo[k][j+496]; 
                sum = sum + matixone[i][k+497] * matrixtwo[k][j+497];
                sum = sum + matixone[i][k+498] * matrixtwo[k][j+498]; 
                sum = sum + matixone[i][k+499] * matrixtwo[k][j+499];
                sum = sum + matixone[i][k+500] * matrixtwo[k][j+500]; 
                
                
                sum = sum + matixone[i][k+501] * matrixtwo[k][j+501]; 
                sum = sum + matixone[i][k+502] * matrixtwo[k][j+502]; 
                sum = sum + matixone[i][k+503] * matrixtwo[k][j+503]; 
                sum = sum + matixone[i][k+504] * matrixtwo[k][j+504]; 
                sum = sum + matixone[i][k+505] * matrixtwo[k][j+505]; 
                sum = sum + matixone[i][k+506] * matrixtwo[k][j+506]; 
                sum = sum + matixone[i][k+507] * matrixtwo[k][j+507];
                sum = sum + matixone[i][k+508] * matrixtwo[k][j+508]; 
                sum = sum + matixone[i][k+509] * matrixtwo[k][j+509];
                sum = sum + matixone[i][k+510] * matrixtwo[k][j+510];
                
                sum = sum + matixone[i][k+511] * matrixtwo[k][j+511]; 
                sum = sum + matixone[i][k+512] * matrixtwo[k][j+512]; 
                sum = sum + matixone[i][k+513] * matrixtwo[k][j+513]; 
                sum = sum + matixone[i][k+514] * matrixtwo[k][j+514]; 
                sum = sum + matixone[i][k+515] * matrixtwo[k][j+515]; 
                sum = sum + matixone[i][k+516] * matrixtwo[k][j+516]; 
                sum = sum + matixone[i][k+517] * matrixtwo[k][j+517];
                sum = sum + matixone[i][k+518] * matrixtwo[k][j+518]; 
                sum = sum + matixone[i][k+519] * matrixtwo[k][j+519];
                sum = sum + matixone[i][k+520] * matrixtwo[k][j+520]; 
                
                
                sum = sum + matixone[i][k+521] * matrixtwo[k][j+521]; 
                sum = sum + matixone[i][k+522] * matrixtwo[k][j+522]; 
                sum = sum + matixone[i][k+523] * matrixtwo[k][j+523]; 
                sum = sum + matixone[i][k+524] * matrixtwo[k][j+524]; 
                sum = sum + matixone[i][k+525] * matrixtwo[k][j+525]; 
                sum = sum + matixone[i][k+526] * matrixtwo[k][j+526]; 
                sum = sum + matixone[i][k+527] * matrixtwo[k][j+527];
                sum = sum + matixone[i][k+528] * matrixtwo[k][j+528]; 
                sum = sum + matixone[i][k+529] * matrixtwo[k][j+529];
                sum = sum + matixone[i][k+530] * matrixtwo[k][j+530]; 
                
                sum = sum + matixone[i][k+531] * matrixtwo[k][j+531]; 
                sum = sum + matixone[i][k+532] * matrixtwo[k][j+532]; 
                sum = sum + matixone[i][k+533] * matrixtwo[k][j+533]; 
                sum = sum + matixone[i][k+534] * matrixtwo[k][j+534]; 
                sum = sum + matixone[i][k+535] * matrixtwo[k][j+535]; 
                sum = sum + matixone[i][k+536] * matrixtwo[k][j+536]; 
                sum = sum + matixone[i][k+537] * matrixtwo[k][j+537];
                sum = sum + matixone[i][k+538] * matrixtwo[k][j+538]; 
                sum = sum + matixone[i][k+539] * matrixtwo[k][j+539];
                sum = sum + matixone[i][k+540] * matrixtwo[k][j+540]; 
                
                
                
                sum = sum + matixone[i][k+541] * matrixtwo[k][j+541]; 
                sum = sum + matixone[i][k+542] * matrixtwo[k][j+542]; 
                sum = sum + matixone[i][k+543] * matrixtwo[k][j+543]; 
                sum = sum + matixone[i][k+544] * matrixtwo[k][j+544]; 
                sum = sum + matixone[i][k+545] * matrixtwo[k][j+545]; 
                sum = sum + matixone[i][k+546] * matrixtwo[k][j+546]; 
                sum = sum + matixone[i][k+547] * matrixtwo[k][j+547];
                sum = sum + matixone[i][k+548] * matrixtwo[k][j+548]; 
                sum = sum + matixone[i][k+549] * matrixtwo[k][j+549];
                sum = sum + matixone[i][k+550] * matrixtwo[k][j+550]; 
                
                
                sum = sum + matixone[i][k+551] * matrixtwo[k][j+551]; 
                sum = sum + matixone[i][k+552] * matrixtwo[k][j+552]; 
                sum = sum + matixone[i][k+553] * matrixtwo[k][j+553]; 
                sum = sum + matixone[i][k+554] * matrixtwo[k][j+554]; 
                sum = sum + matixone[i][k+555] * matrixtwo[k][j+555]; 
                sum = sum + matixone[i][k+556] * matrixtwo[k][j+556]; 
                sum = sum + matixone[i][k+557] * matrixtwo[k][j+557];
                sum = sum + matixone[i][k+558] * matrixtwo[k][j+558]; 
                sum = sum + matixone[i][k+559] * matrixtwo[k][j+559];
                sum = sum + matixone[i][k+560] * matrixtwo[k][j+560]; 
                
                
                sum = sum + matixone[i][k+561] * matrixtwo[k][j+561]; 
                sum = sum + matixone[i][k+562] * matrixtwo[k][j+562]; 
                sum = sum + matixone[i][k+563] * matrixtwo[k][j+563]; 
                sum = sum + matixone[i][k+564] * matrixtwo[k][j+564]; 
                sum = sum + matixone[i][k+565] * matrixtwo[k][j+565]; 
                sum = sum + matixone[i][k+566] * matrixtwo[k][j+566]; 
                sum = sum + matixone[i][k+567] * matrixtwo[k][j+567];
                sum = sum + matixone[i][k+568] * matrixtwo[k][j+568]; 
                sum = sum + matixone[i][k+569] * matrixtwo[k][j+569];
                sum = sum + matixone[i][k+570] * matrixtwo[k][j+570]; 
                
                
                sum = sum + matixone[i][k+571] * matrixtwo[k][j+571]; 
                sum = sum + matixone[i][k+575] * matrixtwo[k][j+572]; 
                sum = sum + matixone[i][k+573] * matrixtwo[k][j+573]; 
                sum = sum + matixone[i][k+574] * matrixtwo[k][j+574]; 
                sum = sum + matixone[i][k+575] * matrixtwo[k][j+575]; 
                sum = sum + matixone[i][k+576] * matrixtwo[k][j+576]; 
                sum = sum + matixone[i][k+577] * matrixtwo[k][j+577];
                sum = sum + matixone[i][k+578] * matrixtwo[k][j+578]; 
                sum = sum + matixone[i][k+579] * matrixtwo[k][j+579];
                sum = sum + matixone[i][k+580] * matrixtwo[k][j+580]; 
                
                
                sum = sum + matixone[i][k+581] * matrixtwo[k][j+581]; 
                sum = sum + matixone[i][k+582] * matrixtwo[k][j+582]; 
                sum = sum + matixone[i][k+583] * matrixtwo[k][j+583]; 
                sum = sum + matixone[i][k+584] * matrixtwo[k][j+584]; 
                sum = sum + matixone[i][k+585] * matrixtwo[k][j+585]; 
                sum = sum + matixone[i][k+586] * matrixtwo[k][j+586]; 
                sum = sum + matixone[i][k+587] * matrixtwo[k][j+587];
                sum = sum + matixone[i][k+588] * matrixtwo[k][j+588]; 
                sum = sum + matixone[i][k+589] * matrixtwo[k][j+589];
                sum = sum + matixone[i][k+590] * matrixtwo[k][j+590];
                
                sum = sum + matixone[i][k+591] * matrixtwo[k][j+591]; 
                sum = sum + matixone[i][k+592] * matrixtwo[k][j+592]; 
                sum = sum + matixone[i][k+593] * matrixtwo[k][j+593]; 
                sum = sum + matixone[i][k+594] * matrixtwo[k][j+594]; 
                sum = sum + matixone[i][k+595] * matrixtwo[k][j+595]; 
                sum = sum + matixone[i][k+596] * matrixtwo[k][j+596]; 
                sum = sum + matixone[i][k+597] * matrixtwo[k][j+597];
                sum = sum + matixone[i][k+598] * matrixtwo[k][j+598]; 
                sum = sum + matixone[i][k+599] * matrixtwo[k][j+599];
                sum = sum + matixone[i][k+600] * matrixtwo[k][j+600];
               
                sum = sum + matixone[i][k+601] * matrixtwo[k][j+601]; 
                sum = sum + matixone[i][k+602] * matrixtwo[k][j+602]; 
                sum = sum + matixone[i][k+603] * matrixtwo[k][j+603]; 
                sum = sum + matixone[i][k+604] * matrixtwo[k][j+604]; 
                sum = sum + matixone[i][k+605] * matrixtwo[k][j+605]; 
                sum = sum + matixone[i][k+606] * matrixtwo[k][j+606]; 
                sum = sum + matixone[i][k+607] * matrixtwo[k][j+607];
                sum = sum + matixone[i][k+608] * matrixtwo[k][j+608]; 
                sum = sum + matixone[i][k+609] * matrixtwo[k][j+609];
                sum = sum + matixone[i][k+610] * matrixtwo[k][j+610];
                
                sum = sum + matixone[i][k+611] * matrixtwo[k][j+611]; 
                sum = sum + matixone[i][k+612] * matrixtwo[k][j+612]; 
                sum = sum + matixone[i][k+613] * matrixtwo[k][j+613]; 
                sum = sum + matixone[i][k+614] * matrixtwo[k][j+614]; 
                sum = sum + matixone[i][k+615] * matrixtwo[k][j+615]; 
                sum = sum + matixone[i][k+616] * matrixtwo[k][j+616]; 
                sum = sum + matixone[i][k+617] * matrixtwo[k][j+617];
                sum = sum + matixone[i][k+618] * matrixtwo[k][j+618]; 
                sum = sum + matixone[i][k+619] * matrixtwo[k][j+619];
                sum = sum + matixone[i][k+620] * matrixtwo[k][j+620]; 
                
                
                sum = sum + matixone[i][k+621] * matrixtwo[k][j+621]; 
                sum = sum + matixone[i][k+622] * matrixtwo[k][j+622]; 
                sum = sum + matixone[i][k+623] * matrixtwo[k][j+623]; 
                sum = sum + matixone[i][k+624] * matrixtwo[k][j+624]; 
                sum = sum + matixone[i][k+625] * matrixtwo[k][j+625]; 
                sum = sum + matixone[i][k+626] * matrixtwo[k][j+626]; 
                sum = sum + matixone[i][k+627] * matrixtwo[k][j+627];
                sum = sum + matixone[i][k+628] * matrixtwo[k][j+628]; 
                sum = sum + matixone[i][k+629] * matrixtwo[k][j+629];
                sum = sum + matixone[i][k+630] * matrixtwo[k][j+630]; 
                
                sum = sum + matixone[i][k+631] * matrixtwo[k][j+631]; 
                sum = sum + matixone[i][k+632] * matrixtwo[k][j+632]; 
                sum = sum + matixone[i][k+633] * matrixtwo[k][j+633]; 
                sum = sum + matixone[i][k+634] * matrixtwo[k][j+634]; 
                sum = sum + matixone[i][k+635] * matrixtwo[k][j+635]; 
                sum = sum + matixone[i][k+636] * matrixtwo[k][j+636]; 
                sum = sum + matixone[i][k+637] * matrixtwo[k][j+637];
                sum = sum + matixone[i][k+638] * matrixtwo[k][j+638]; 
                sum = sum + matixone[i][k+639] * matrixtwo[k][j+639];
                sum = sum + matixone[i][k+640] * matrixtwo[k][j+640]; 
                
                
                
                sum = sum + matixone[i][k+641] * matrixtwo[k][j+641]; 
                sum = sum + matixone[i][k+642] * matrixtwo[k][j+642]; 
                sum = sum + matixone[i][k+643] * matrixtwo[k][j+643]; 
                sum = sum + matixone[i][k+644] * matrixtwo[k][j+644]; 
                sum = sum + matixone[i][k+645] * matrixtwo[k][j+645]; 
                sum = sum + matixone[i][k+646] * matrixtwo[k][j+646]; 
                sum = sum + matixone[i][k+647] * matrixtwo[k][j+647];
                sum = sum + matixone[i][k+648] * matrixtwo[k][j+648]; 
                sum = sum + matixone[i][k+649] * matrixtwo[k][j+649];
                sum = sum + matixone[i][k+650] * matrixtwo[k][j+650]; 
                
                
                sum = sum + matixone[i][k+651] * matrixtwo[k][j+651]; 
                sum = sum + matixone[i][k+652] * matrixtwo[k][j+652]; 
                sum = sum + matixone[i][k+653] * matrixtwo[k][j+653]; 
                sum = sum + matixone[i][k+654] * matrixtwo[k][j+654]; 
                sum = sum + matixone[i][k+655] * matrixtwo[k][j+655]; 
                sum = sum + matixone[i][k+656] * matrixtwo[k][j+656]; 
                sum = sum + matixone[i][k+657] * matrixtwo[k][j+657];
                sum = sum + matixone[i][k+658] * matrixtwo[k][j+658]; 
                sum = sum + matixone[i][k+659] * matrixtwo[k][j+659];
                sum = sum + matixone[i][k+660] * matrixtwo[k][j+660]; 
                
                
                sum = sum + matixone[i][k+661] * matrixtwo[k][j+661]; 
                sum = sum + matixone[i][k+662] * matrixtwo[k][j+662]; 
                sum = sum + matixone[i][k+663] * matrixtwo[k][j+663]; 
                sum = sum + matixone[i][k+664] * matrixtwo[k][j+664]; 
                sum = sum + matixone[i][k+665] * matrixtwo[k][j+665]; 
                sum = sum + matixone[i][k+666] * matrixtwo[k][j+666]; 
                sum = sum + matixone[i][k+667] * matrixtwo[k][j+667];
                sum = sum + matixone[i][k+668] * matrixtwo[k][j+668]; 
                sum = sum + matixone[i][k+669] * matrixtwo[k][j+669];
                sum = sum + matixone[i][k+670] * matrixtwo[k][j+670]; 
                
                
                sum = sum + matixone[i][k+671] * matrixtwo[k][j+671]; 
                sum = sum + matixone[i][k+672] * matrixtwo[k][j+672]; 
                sum = sum + matixone[i][k+673] * matrixtwo[k][j+673]; 
                sum = sum + matixone[i][k+674] * matrixtwo[k][j+674]; 
                sum = sum + matixone[i][k+675] * matrixtwo[k][j+675]; 
                sum = sum + matixone[i][k+676] * matrixtwo[k][j+676]; 
                sum = sum + matixone[i][k+677] * matrixtwo[k][j+677];
                sum = sum + matixone[i][k+678] * matrixtwo[k][j+678]; 
                sum = sum + matixone[i][k+679] * matrixtwo[k][j+679];
                sum = sum + matixone[i][k+680] * matrixtwo[k][j+680]; 
                
                
                sum = sum + matixone[i][k+681] * matrixtwo[k][j+681]; 
                sum = sum + matixone[i][k+682] * matrixtwo[k][j+682]; 
                sum = sum + matixone[i][k+683] * matrixtwo[k][j+683]; 
                sum = sum + matixone[i][k+684] * matrixtwo[k][j+684]; 
                sum = sum + matixone[i][k+685] * matrixtwo[k][j+685]; 
                sum = sum + matixone[i][k+686] * matrixtwo[k][j+686]; 
                sum = sum + matixone[i][k+687] * matrixtwo[k][j+687];
                sum = sum + matixone[i][k+688] * matrixtwo[k][j+688]; 
                sum = sum + matixone[i][k+689] * matrixtwo[k][j+689];
                sum = sum + matixone[i][k+690] * matrixtwo[k][j+690];
                
                sum = sum + matixone[i][k+691] * matrixtwo[k][j+691]; 
                sum = sum + matixone[i][k+692] * matrixtwo[k][j+692]; 
                sum = sum + matixone[i][k+693] * matrixtwo[k][j+693]; 
                sum = sum + matixone[i][k+694] * matrixtwo[k][j+694]; 
                sum = sum + matixone[i][k+695] * matrixtwo[k][j+695]; 
                sum = sum + matixone[i][k+696] * matrixtwo[k][j+696]; 
                sum = sum + matixone[i][k+697] * matrixtwo[k][j+697];
                sum = sum + matixone[i][k+698] * matrixtwo[k][j+698]; 
                sum = sum + matixone[i][k+699] * matrixtwo[k][j+699];
                sum = sum + matixone[i][k+700] * matrixtwo[k][j+700];
            
            //
                
                sum = sum + matixone[i][k+701] * matrixtwo[k][j+701]; 
                sum = sum + matixone[i][k+702] * matrixtwo[k][j+702]; 
                sum = sum + matixone[i][k+703] * matrixtwo[k][j+703]; 
                sum = sum + matixone[i][k+704] * matrixtwo[k][j+704]; 
                sum = sum + matixone[i][k+705] * matrixtwo[k][j+705]; 
                sum = sum + matixone[i][k+706] * matrixtwo[k][j+706]; 
                sum = sum + matixone[i][k+707] * matrixtwo[k][j+707];
                sum = sum + matixone[i][k+708] * matrixtwo[k][j+708]; 
                sum = sum + matixone[i][k+709] * matrixtwo[k][j+709];
                sum = sum + matixone[i][k+710] * matrixtwo[k][j+710];
                
                sum = sum + matixone[i][k+711] * matrixtwo[k][j+711]; 
                sum = sum + matixone[i][k+712] * matrixtwo[k][j+712]; 
                sum = sum + matixone[i][k+713] * matrixtwo[k][j+713]; 
                sum = sum + matixone[i][k+714] * matrixtwo[k][j+714]; 
                sum = sum + matixone[i][k+715] * matrixtwo[k][j+715]; 
                sum = sum + matixone[i][k+716] * matrixtwo[k][j+716]; 
                sum = sum + matixone[i][k+717] * matrixtwo[k][j+717];
                sum = sum + matixone[i][k+718] * matrixtwo[k][j+718]; 
                sum = sum + matixone[i][k+719] * matrixtwo[k][j+719];
                sum = sum + matixone[i][k+720] * matrixtwo[k][j+720]; 
                
                
                sum = sum + matixone[i][k+721] * matrixtwo[k][j+721]; 
                sum = sum + matixone[i][k+722] * matrixtwo[k][j+722]; 
                sum = sum + matixone[i][k+723] * matrixtwo[k][j+723]; 
                sum = sum + matixone[i][k+724] * matrixtwo[k][j+724]; 
                sum = sum + matixone[i][k+725] * matrixtwo[k][j+725]; 
                sum = sum + matixone[i][k+726] * matrixtwo[k][j+726]; 
                sum = sum + matixone[i][k+727] * matrixtwo[k][j+727];
                sum = sum + matixone[i][k+728] * matrixtwo[k][j+728]; 
                sum = sum + matixone[i][k+729] * matrixtwo[k][j+729];
                sum = sum + matixone[i][k+730] * matrixtwo[k][j+730]; 
                
                sum = sum + matixone[i][k+731] * matrixtwo[k][j+731]; 
                sum = sum + matixone[i][k+732] * matrixtwo[k][j+732]; 
                sum = sum + matixone[i][k+733] * matrixtwo[k][j+733]; 
                sum = sum + matixone[i][k+734] * matrixtwo[k][j+734]; 
                sum = sum + matixone[i][k+735] * matrixtwo[k][j+735]; 
                sum = sum + matixone[i][k+736] * matrixtwo[k][j+736]; 
                sum = sum + matixone[i][k+737] * matrixtwo[k][j+737];
                sum = sum + matixone[i][k+738] * matrixtwo[k][j+738]; 
                sum = sum + matixone[i][k+739] * matrixtwo[k][j+739];
                sum = sum + matixone[i][k+740] * matrixtwo[k][j+740]; 
                
                
                
                sum = sum + matixone[i][k+741] * matrixtwo[k][j+741]; 
                sum = sum + matixone[i][k+742] * matrixtwo[k][j+742]; 
                sum = sum + matixone[i][k+743] * matrixtwo[k][j+743]; 
                sum = sum + matixone[i][k+744] * matrixtwo[k][j+744]; 
                sum = sum + matixone[i][k+745] * matrixtwo[k][j+745]; 
                sum = sum + matixone[i][k+746] * matrixtwo[k][j+746]; 
                sum = sum + matixone[i][k+747] * matrixtwo[k][j+747];
                sum = sum + matixone[i][k+748] * matrixtwo[k][j+748]; 
                sum = sum + matixone[i][k+749] * matrixtwo[k][j+749];
                sum = sum + matixone[i][k+750] * matrixtwo[k][j+750]; 
                
                
                sum = sum + matixone[i][k+751] * matrixtwo[k][j+751]; 
                sum = sum + matixone[i][k+752] * matrixtwo[k][j+752]; 
                sum = sum + matixone[i][k+753] * matrixtwo[k][j+753]; 
                sum = sum + matixone[i][k+754] * matrixtwo[k][j+754]; 
                sum = sum + matixone[i][k+755] * matrixtwo[k][j+755]; 
                sum = sum + matixone[i][k+756] * matrixtwo[k][j+756]; 
                sum = sum + matixone[i][k+757] * matrixtwo[k][j+757];
                sum = sum + matixone[i][k+758] * matrixtwo[k][j+758]; 
                sum = sum + matixone[i][k+759] * matrixtwo[k][j+759];
                sum = sum + matixone[i][k+760] * matrixtwo[k][j+760]; 
                
                
                sum = sum + matixone[i][k+761] * matrixtwo[k][j+761]; 
                sum = sum + matixone[i][k+762] * matrixtwo[k][j+762]; 
                sum = sum + matixone[i][k+763] * matrixtwo[k][j+763]; 
                sum = sum + matixone[i][k+764] * matrixtwo[k][j+764]; 
                sum = sum + matixone[i][k+765] * matrixtwo[k][j+765]; 
                sum = sum + matixone[i][k+766] * matrixtwo[k][j+766]; 
                sum = sum + matixone[i][k+767] * matrixtwo[k][j+767];
                sum = sum + matixone[i][k+768] * matrixtwo[k][j+768]; 
                sum = sum + matixone[i][k+769] * matrixtwo[k][j+769];
                sum = sum + matixone[i][k+770] * matrixtwo[k][j+770]; 
                
                
                sum = sum + matixone[i][k+771] * matrixtwo[k][j+771]; 
                sum = sum + matixone[i][k+775] * matrixtwo[k][j+772]; 
                sum = sum + matixone[i][k+773] * matrixtwo[k][j+773]; 
                sum = sum + matixone[i][k+774] * matrixtwo[k][j+774]; 
                sum = sum + matixone[i][k+775] * matrixtwo[k][j+775]; 
                sum = sum + matixone[i][k+776] * matrixtwo[k][j+776]; 
                sum = sum + matixone[i][k+777] * matrixtwo[k][j+777];
                sum = sum + matixone[i][k+778] * matrixtwo[k][j+778]; 
                sum = sum + matixone[i][k+779] * matrixtwo[k][j+779];
                sum = sum + matixone[i][k+780] * matrixtwo[k][j+780]; 
                
                
                sum = sum + matixone[i][k+781] * matrixtwo[k][j+781]; 
                sum = sum + matixone[i][k+782] * matrixtwo[k][j+782]; 
                sum = sum + matixone[i][k+783] * matrixtwo[k][j+783]; 
                sum = sum + matixone[i][k+784] * matrixtwo[k][j+784]; 
                sum = sum + matixone[i][k+785] * matrixtwo[k][j+785]; 
                sum = sum + matixone[i][k+786] * matrixtwo[k][j+786]; 
                sum = sum + matixone[i][k+787] * matrixtwo[k][j+787];
                sum = sum + matixone[i][k+788] * matrixtwo[k][j+788]; 
                sum = sum + matixone[i][k+789] * matrixtwo[k][j+789];
                sum = sum + matixone[i][k+790] * matrixtwo[k][j+790];
                
                sum = sum + matixone[i][k+791] * matrixtwo[k][j+791]; 
                sum = sum + matixone[i][k+792] * matrixtwo[k][j+792]; 
                sum = sum + matixone[i][k+793] * matrixtwo[k][j+793]; 
                sum = sum + matixone[i][k+794] * matrixtwo[k][j+794]; 
                sum = sum + matixone[i][k+795] * matrixtwo[k][j+795]; 
                sum = sum + matixone[i][k+796] * matrixtwo[k][j+796]; 
                sum = sum + matixone[i][k+797] * matrixtwo[k][j+797];
                sum = sum + matixone[i][k+798] * matrixtwo[k][j+798]; 
                sum = sum + matixone[i][k+799] * matrixtwo[k][j+799];
                sum = sum + matixone[i][k+800] * matrixtwo[k][j+800];
               
                sum = sum + matixone[i][k+801] * matrixtwo[k][j+801]; 
                sum = sum + matixone[i][k+802] * matrixtwo[k][j+802]; 
                sum = sum + matixone[i][k+803] * matrixtwo[k][j+803]; 
                sum = sum + matixone[i][k+804] * matrixtwo[k][j+804]; 
                sum = sum + matixone[i][k+805] * matrixtwo[k][j+805]; 
                sum = sum + matixone[i][k+806] * matrixtwo[k][j+806]; 
                sum = sum + matixone[i][k+807] * matrixtwo[k][j+807];
                sum = sum + matixone[i][k+808] * matrixtwo[k][j+808]; 
                sum = sum + matixone[i][k+809] * matrixtwo[k][j+809];
                sum = sum + matixone[i][k+810] * matrixtwo[k][j+810];
                
                sum = sum + matixone[i][k+811] * matrixtwo[k][j+811]; 
                sum = sum + matixone[i][k+812] * matrixtwo[k][j+812]; 
                sum = sum + matixone[i][k+813] * matrixtwo[k][j+813]; 
                sum = sum + matixone[i][k+814] * matrixtwo[k][j+814]; 
                sum = sum + matixone[i][k+815] * matrixtwo[k][j+815]; 
                sum = sum + matixone[i][k+816] * matrixtwo[k][j+816]; 
                sum = sum + matixone[i][k+817] * matrixtwo[k][j+817];
                sum = sum + matixone[i][k+818] * matrixtwo[k][j+818]; 
                sum = sum + matixone[i][k+819] * matrixtwo[k][j+819];
                sum = sum + matixone[i][k+820] * matrixtwo[k][j+820]; 
                
                
                sum = sum + matixone[i][k+821] * matrixtwo[k][j+821]; 
                sum = sum + matixone[i][k+822] * matrixtwo[k][j+822]; 
                sum = sum + matixone[i][k+823] * matrixtwo[k][j+823]; 
                sum = sum + matixone[i][k+824] * matrixtwo[k][j+824]; 
                sum = sum + matixone[i][k+825] * matrixtwo[k][j+825]; 
                sum = sum + matixone[i][k+826] * matrixtwo[k][j+826]; 
                sum = sum + matixone[i][k+827] * matrixtwo[k][j+827];
                sum = sum + matixone[i][k+828] * matrixtwo[k][j+828]; 
                sum = sum + matixone[i][k+829] * matrixtwo[k][j+829];
                sum = sum + matixone[i][k+830] * matrixtwo[k][j+830]; 
                
                sum = sum + matixone[i][k+831] * matrixtwo[k][j+831]; 
                sum = sum + matixone[i][k+832] * matrixtwo[k][j+832]; 
                sum = sum + matixone[i][k+833] * matrixtwo[k][j+833]; 
                sum = sum + matixone[i][k+834] * matrixtwo[k][j+834]; 
                sum = sum + matixone[i][k+835] * matrixtwo[k][j+835]; 
                sum = sum + matixone[i][k+836] * matrixtwo[k][j+836]; 
                sum = sum + matixone[i][k+837] * matrixtwo[k][j+837];
                sum = sum + matixone[i][k+838] * matrixtwo[k][j+838]; 
                sum = sum + matixone[i][k+839] * matrixtwo[k][j+839];
                sum = sum + matixone[i][k+840] * matrixtwo[k][j+840]; 
                
                
                
                sum = sum + matixone[i][k+841] * matrixtwo[k][j+841]; 
                sum = sum + matixone[i][k+842] * matrixtwo[k][j+842]; 
                sum = sum + matixone[i][k+843] * matrixtwo[k][j+843]; 
                sum = sum + matixone[i][k+844] * matrixtwo[k][j+844]; 
                sum = sum + matixone[i][k+845] * matrixtwo[k][j+845]; 
                sum = sum + matixone[i][k+846] * matrixtwo[k][j+846]; 
                sum = sum + matixone[i][k+847] * matrixtwo[k][j+847];
                sum = sum + matixone[i][k+848] * matrixtwo[k][j+848]; 
                sum = sum + matixone[i][k+849] * matrixtwo[k][j+849];
                sum = sum + matixone[i][k+850] * matrixtwo[k][j+850]; 
                
                
                sum = sum + matixone[i][k+851] * matrixtwo[k][j+851]; 
                sum = sum + matixone[i][k+852] * matrixtwo[k][j+852]; 
                sum = sum + matixone[i][k+853] * matrixtwo[k][j+853]; 
                sum = sum + matixone[i][k+854] * matrixtwo[k][j+854]; 
                sum = sum + matixone[i][k+855] * matrixtwo[k][j+855]; 
                sum = sum + matixone[i][k+856] * matrixtwo[k][j+856]; 
                sum = sum + matixone[i][k+857] * matrixtwo[k][j+857];
                sum = sum + matixone[i][k+858] * matrixtwo[k][j+858]; 
                sum = sum + matixone[i][k+859] * matrixtwo[k][j+859];
                sum = sum + matixone[i][k+860] * matrixtwo[k][j+860]; 
                
                
                sum = sum + matixone[i][k+861] * matrixtwo[k][j+861]; 
                sum = sum + matixone[i][k+862] * matrixtwo[k][j+862]; 
                sum = sum + matixone[i][k+863] * matrixtwo[k][j+863]; 
                sum = sum + matixone[i][k+864] * matrixtwo[k][j+864]; 
                sum = sum + matixone[i][k+865] * matrixtwo[k][j+865]; 
                sum = sum + matixone[i][k+866] * matrixtwo[k][j+866]; 
                sum = sum + matixone[i][k+867] * matrixtwo[k][j+867];
                sum = sum + matixone[i][k+868] * matrixtwo[k][j+868]; 
                sum = sum + matixone[i][k+869] * matrixtwo[k][j+869];
                sum = sum + matixone[i][k+870] * matrixtwo[k][j+870]; 
                
                
                sum = sum + matixone[i][k+871] * matrixtwo[k][j+871]; 
                sum = sum + matixone[i][k+872] * matrixtwo[k][j+872]; 
                sum = sum + matixone[i][k+873] * matrixtwo[k][j+873]; 
                sum = sum + matixone[i][k+874] * matrixtwo[k][j+874]; 
                sum = sum + matixone[i][k+875] * matrixtwo[k][j+875]; 
                sum = sum + matixone[i][k+876] * matrixtwo[k][j+876]; 
                sum = sum + matixone[i][k+877] * matrixtwo[k][j+877];
                sum = sum + matixone[i][k+878] * matrixtwo[k][j+888]; 
                sum = sum + matixone[i][k+879] * matrixtwo[k][j+879];
                sum = sum + matixone[i][k+880] * matrixtwo[k][j+880]; 
                
                
                sum = sum + matixone[i][k+881] * matrixtwo[k][j+881]; 
                sum = sum + matixone[i][k+882] * matrixtwo[k][j+882]; 
                sum = sum + matixone[i][k+883] * matrixtwo[k][j+883]; 
                sum = sum + matixone[i][k+884] * matrixtwo[k][j+884]; 
                sum = sum + matixone[i][k+885] * matrixtwo[k][j+885]; 
                sum = sum + matixone[i][k+886] * matrixtwo[k][j+886]; 
                sum = sum + matixone[i][k+887] * matrixtwo[k][j+887];
                sum = sum + matixone[i][k+888] * matrixtwo[k][j+888]; 
                sum = sum + matixone[i][k+889] * matrixtwo[k][j+889];
                sum = sum + matixone[i][k+890] * matrixtwo[k][j+890];
                
                sum = sum + matixone[i][k+891] * matrixtwo[k][j+891]; 
                sum = sum + matixone[i][k+892] * matrixtwo[k][j+892]; 
                sum = sum + matixone[i][k+893] * matrixtwo[k][j+893]; 
                sum = sum + matixone[i][k+894] * matrixtwo[k][j+894]; 
                sum = sum + matixone[i][k+895] * matrixtwo[k][j+895]; 
                sum = sum + matixone[i][k+896] * matrixtwo[k][j+896]; 
                sum = sum + matixone[i][k+897] * matrixtwo[k][j+897];
                sum = sum + matixone[i][k+898] * matrixtwo[k][j+898]; 
                sum = sum + matixone[i][k+899] * matrixtwo[k][j+899];
                sum = sum + matixone[i][k+900] * matrixtwo[k][j+900];
                
                //
                
                sum = sum + matixone[i][k+901] * matrixtwo[k][j+901]; 
                sum = sum + matixone[i][k+902] * matrixtwo[k][j+902]; 
                sum = sum + matixone[i][k+903] * matrixtwo[k][j+903]; 
                sum = sum + matixone[i][k+904] * matrixtwo[k][j+904]; 
                sum = sum + matixone[i][k+905] * matrixtwo[k][j+905]; 
                sum = sum + matixone[i][k+906] * matrixtwo[k][j+906]; 
                sum = sum + matixone[i][k+907] * matrixtwo[k][j+907];
                sum = sum + matixone[i][k+908] * matrixtwo[k][j+908]; 
                sum = sum + matixone[i][k+909] * matrixtwo[k][j+909];
                sum = sum + matixone[i][k+910] * matrixtwo[k][j+910];
                
                sum = sum + matixone[i][k+911] * matrixtwo[k][j+911]; 
                sum = sum + matixone[i][k+912] * matrixtwo[k][j+912]; 
                sum = sum + matixone[i][k+913] * matrixtwo[k][j+913]; 
                sum = sum + matixone[i][k+914] * matrixtwo[k][j+914]; 
                sum = sum + matixone[i][k+915] * matrixtwo[k][j+915]; 
                sum = sum + matixone[i][k+916] * matrixtwo[k][j+916]; 
                sum = sum + matixone[i][k+917] * matrixtwo[k][j+917];
                sum = sum + matixone[i][k+918] * matrixtwo[k][j+918]; 
                sum = sum + matixone[i][k+919] * matrixtwo[k][j+919];
                sum = sum + matixone[i][k+920] * matrixtwo[k][j+920]; 
                
                
                sum = sum + matixone[i][k+921] * matrixtwo[k][j+921]; 
                sum = sum + matixone[i][k+922] * matrixtwo[k][j+922]; 
                sum = sum + matixone[i][k+923] * matrixtwo[k][j+923]; 
                sum = sum + matixone[i][k+924] * matrixtwo[k][j+924]; 
                sum = sum + matixone[i][k+925] * matrixtwo[k][j+925]; 
                sum = sum + matixone[i][k+926] * matrixtwo[k][j+926]; 
                sum = sum + matixone[i][k+927] * matrixtwo[k][j+927];
                sum = sum + matixone[i][k+928] * matrixtwo[k][j+928]; 
                sum = sum + matixone[i][k+929] * matrixtwo[k][j+929];
                sum = sum + matixone[i][k+930] * matrixtwo[k][j+930]; 
                
                sum = sum + matixone[i][k+931] * matrixtwo[k][j+931]; 
                sum = sum + matixone[i][k+932] * matrixtwo[k][j+932]; 
                sum = sum + matixone[i][k+933] * matrixtwo[k][j+933]; 
                sum = sum + matixone[i][k+934] * matrixtwo[k][j+934]; 
                sum = sum + matixone[i][k+935] * matrixtwo[k][j+935]; 
                sum = sum + matixone[i][k+936] * matrixtwo[k][j+936]; 
                sum = sum + matixone[i][k+937] * matrixtwo[k][j+937];
                sum = sum + matixone[i][k+938] * matrixtwo[k][j+938]; 
                sum = sum + matixone[i][k+939] * matrixtwo[k][j+939];
                sum = sum + matixone[i][k+940] * matrixtwo[k][j+940]; 
                
                
                
                sum = sum + matixone[i][k+941] * matrixtwo[k][j+941]; 
                sum = sum + matixone[i][k+942] * matrixtwo[k][j+942]; 
                sum = sum + matixone[i][k+943] * matrixtwo[k][j+943]; 
                sum = sum + matixone[i][k+944] * matrixtwo[k][j+944]; 
                sum = sum + matixone[i][k+945] * matrixtwo[k][j+945]; 
                sum = sum + matixone[i][k+946] * matrixtwo[k][j+946]; 
                sum = sum + matixone[i][k+947] * matrixtwo[k][j+947];
                sum = sum + matixone[i][k+948] * matrixtwo[k][j+948]; 
                sum = sum + matixone[i][k+949] * matrixtwo[k][j+949];
                sum = sum + matixone[i][k+950] * matrixtwo[k][j+950]; 
                
                
                sum = sum + matixone[i][k+951] * matrixtwo[k][j+951]; 
                sum = sum + matixone[i][k+952] * matrixtwo[k][j+952]; 
                sum = sum + matixone[i][k+953] * matrixtwo[k][j+953]; 
                sum = sum + matixone[i][k+954] * matrixtwo[k][j+954]; 
                sum = sum + matixone[i][k+955] * matrixtwo[k][j+955]; 
                sum = sum + matixone[i][k+956] * matrixtwo[k][j+956]; 
                sum = sum + matixone[i][k+957] * matrixtwo[k][j+957];
                sum = sum + matixone[i][k+958] * matrixtwo[k][j+958]; 
                sum = sum + matixone[i][k+959] * matrixtwo[k][j+959];
                sum = sum + matixone[i][k+960] * matrixtwo[k][j+960]; 
                
                
                sum = sum + matixone[i][k+961] * matrixtwo[k][j+961]; 
                sum = sum + matixone[i][k+962] * matrixtwo[k][j+962]; 
                sum = sum + matixone[i][k+963] * matrixtwo[k][j+963]; 
                sum = sum + matixone[i][k+964] * matrixtwo[k][j+964]; 
                sum = sum + matixone[i][k+965] * matrixtwo[k][j+965]; 
                sum = sum + matixone[i][k+966] * matrixtwo[k][j+966]; 
                sum = sum + matixone[i][k+967] * matrixtwo[k][j+967];
                sum = sum + matixone[i][k+968] * matrixtwo[k][j+968]; 
                sum = sum + matixone[i][k+969] * matrixtwo[k][j+969];
                sum = sum + matixone[i][k+970] * matrixtwo[k][j+970]; 
                
                
                sum = sum + matixone[i][k+971] * matrixtwo[k][j+971]; 
                sum = sum + matixone[i][k+972] * matrixtwo[k][j+972]; 
                sum = sum + matixone[i][k+973] * matrixtwo[k][j+973]; 
                sum = sum + matixone[i][k+974] * matrixtwo[k][j+974]; 
                sum = sum + matixone[i][k+975] * matrixtwo[k][j+975]; 
                sum = sum + matixone[i][k+976] * matrixtwo[k][j+976]; 
                sum = sum + matixone[i][k+977] * matrixtwo[k][j+977];
                sum = sum + matixone[i][k+978] * matrixtwo[k][j+988]; 
                sum = sum + matixone[i][k+979] * matrixtwo[k][j+979];
                sum = sum + matixone[i][k+980] * matrixtwo[k][j+980]; 
                
                
                sum = sum + matixone[i][k+981] * matrixtwo[k][j+981]; 
                sum = sum + matixone[i][k+982] * matrixtwo[k][j+982]; 
                sum = sum + matixone[i][k+983] * matrixtwo[k][j+983]; 
                sum = sum + matixone[i][k+984] * matrixtwo[k][j+984]; 
                sum = sum + matixone[i][k+985] * matrixtwo[k][j+985]; 
                sum = sum + matixone[i][k+986] * matrixtwo[k][j+986]; 
                sum = sum + matixone[i][k+987] * matrixtwo[k][j+987];
                sum = sum + matixone[i][k+988] * matrixtwo[k][j+988]; 
                sum = sum + matixone[i][k+989] * matrixtwo[k][j+989];
                sum = sum + matixone[i][k+990] * matrixtwo[k][j+990];
                
                sum = sum + matixone[i][k+991] * matrixtwo[k][j+991]; 
                sum = sum + matixone[i][k+992] * matrixtwo[k][j+992]; 
                sum = sum + matixone[i][k+993] * matrixtwo[k][j+993]; 
                sum = sum + matixone[i][k+994] * matrixtwo[k][j+994]; 
                sum = sum + matixone[i][k+995] * matrixtwo[k][j+995]; 
                sum = sum + matixone[i][k+996] * matrixtwo[k][j+996]; 
                sum = sum + matixone[i][k+997] * matrixtwo[k][j+997];
                sum = sum + matixone[i][k+998] * matrixtwo[k][j+998]; 
                sum = sum + matixone[i][k+999] * matrixtwo[k][j+999];
                sum = sum + matixone[i][k+1000] * matrixtwo[k][j+1000];
            }
            matixmultiply[i][j] = sum;  
            sum = 0;
        }
    }
    time_spend = clock() - time_spend;
    
   
    /*for(i=0;i< cr;i++)
    {
        for(j=0;j< cr;j++)
        {
            printf("%d\t",matixmultiply[i][j]);
        }
        printf("\n");
    }*/
    printf("\n\n time program take to run\n");
    printf("time: click(%f in sec):", (float)time_spend/ CLOCKS_PER_SEC);
    return 0;
}