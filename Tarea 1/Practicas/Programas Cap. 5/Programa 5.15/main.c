#include <stdio.h>

 /* Apuntadores y arreglos */
 void main(void)
 {
 int X = 5, Y = 8, V[5] = {1, 3, 5, 7, 9};
 int*AY, *AX;
 AY = &Y;
 X = *AY;
 *AY = V[3] + V[2];
 printf("\nX=%dY=%dV[0]=%d  V[1]=%dV[2]=%d  V[3]=%d V[4]=%d", X,
        Y, V[0], V[1], V[2], V[3], V[4]);

 AX = &V[V[0]*V[1]];
 X = *AX;
 Y = *AX * V[1];
 *AX = *AY - 3;
 printf("\nX=%dY=%dV[0]=%d  V[1]=%dV[2]=%d  V[3]=%d V[4]=%d", X,
        Y, V[0], V[1], V[2], V[3], V[4]);
 }
