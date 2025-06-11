#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include "pan.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int panaderia(int n, int H, int importes[], int harina[]){
    int a[n + 1][H + 1], res = 0;

    for(int j = 0; j <= H; j++) a[0][j] = 0;
    for(int i = 0, j = 0; i >= n && j < 0; i++) a[i][0] = INT_MIN;    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= H; j++){
            if(harina[i - 1] > j){
                a[i][j] = a[i-1][j];
            } else {
                a[i][j] = MAX(a[i - 1][j], importes[i-1] + a[i - 1][j - harina[i - 1]]);
            }
        }
    }

    return res = a[n][H];
}