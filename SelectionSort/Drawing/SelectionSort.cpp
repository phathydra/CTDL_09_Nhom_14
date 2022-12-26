#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void swapArr(int M[], int position1, int position2) {
    int temp = M[position1];
    M[position1] = M[position2];
    M[position2] = temp;
}

void selectionSort(int M[], int n)
{
    
    int i, t;
    int l = 0, r = 0;
    initgraph();
   
    drawSet(100, 300, M, n, n, n);
    for (int i = n - 1; i >= 0; i--) {
        int max = M[i];
        t = i;
        int temp = 0;
        int maxfirst = i;
        int d = i;

        for (int k = i; k >= 0; k--) {
            if (M[k] > M[maxfirst]) {
                temp++;
            }
            else {
                drawText(50, 400, "Number: ");
                //rectangle(120, 420, 160, 420);
                drawNumber(150, 400, M[i]);
                drawSet(100, 300, M, n, n, n);
                arrow(120 + i * 55, 360, 30, 9);
                Sleep(70);
            }
        }
        
        if (temp != 0)
        {
            for (int h = i; h >= 0; h--) {
                drawText(50, 400, "Number: ");
                //rectangle(120, 420, 160, 420);
                drawNumber(150, 400, M[i]);
                drawSet(100, 300, M, n, n, n);
                Sleep(70);
                if (M[h] > M[maxfirst]) {

                    arrow(120 + h * 55, 360, 30, 9);
                    arrow(120 + maxfirst * 55, 360, 30, 9);
                    drawSet(100, 300, M, n, n, n);
                    Sleep(200);
                    maxfirst = h;
                    d = h;
                }

                if (h == 0) {
                    break;
                }
                system("cls");
            }
        }

        if (d != t) {
            drawSet(100, 300, M, n, n, n);
            rectangle(120 + i * 55 + r, 360, 150 + r, 360);
            rectangle(200 + d * 55 - l, 360, 250 - l, 360);
            swap(200 + d * 55 - l, 120 + i * 55 + r, l, r);
            Sleep(100);
            swapArr(M, i, d);
            drawSet(100, 300, M, n, n, n);
            Sleep(50);
            system("cls");
            
        }

        if (i == 0) {
            drawSet(100, 300, M, n, n, n);
            break;
        }
        system("cls");
    }
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);
    int M[100];
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &M[i]);
    }
    selectionSort(M, n);
    return 0;
}
