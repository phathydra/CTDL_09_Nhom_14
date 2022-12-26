#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

int maxArr(int M[], int n) {
    int max = M[0];
    for (int i = 1; i < n; i++) {
        if (M[i] > max) max = M[i];
    }
    return max;
}

int minArr(int M[], int n) {
    int min = M[0];
    for (int i = 1; i < n; i++) {
        if (M[i] < min) min = M[i];
    }
    return min;
}

void distributionCounting(int M[], int n) {
    int max = maxArr(M, n);
    int min = minArr(M, n);
    int a = max - min + 1;
    int N[100];
    int Count[100] = { 0 };
    int result[100] = { 0 };
    int i, j, k, l = 0;
    int r1 = 0, r2 = 0;
    int x = 0, y = 0;
    for (int i = 0; i < a; i++) {
        N[i] = min + i;
    }
    initgraph();
    for (i = 0; i < n; i++) {
        for (j = 0; j < 10; j++) {
            drawSet(100, 100, M, n);
            drawSet(100, 400, N, a);
            drawSet(100, 450, Count, a);
            drawText(30, 460, "COUNT");
            arrow(75 + r1, 160, 30, 9);
            move(75 + i * 50, 125 + i * 50, r1);
            Sleep(10);
            system("cls");
        }
        for (k = 0; k < a; k++) {
            if (N[k] == M[i]) {
                for (l = 0; l < 10; l++) {
                    drawSet(100, 100, M, n);
                    drawSet(100, 400, N, a);
                    drawSet(100, 450, Count, a);
                    drawText(25, 460, "COUNT");
                    arrow(75 + r1, 160, 30, 9);
                    arrow(75 + r2, 510, 30, 9);
                    move(75, 75 + (k + 1) * 50, r2);
                    Sleep(10);
                    system("cls");
                }
                Count[k]++;
                break;
            }
        }
        drawSet(100, 450, Count, a);
        arrow(75 + r2, 510, 30, 9);
        Sleep(200);
        r2 = 0;
    }
    r2 = 0;
    for (i = 1; i < a; i++) {
        Count[i] += Count[i - 1];
        drawSet(100, 100, M, n);
        drawSet(100, 400, N, a);
        drawSet(100, 450, Count, a);
        drawText(30, 460, "COUNT");
        Sleep(500);
        system("cls");
    }
    r1 = r2 = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 10; j++) {
            drawSet(100, 100, M, n);
            drawSet(100, 400, N, a);
            drawSet(100, 450, Count, a);
            drawText(30, 460, "COUNT");
            arrow(75 + r1, 160, 30, 9);
            move(75 + i * 50, 125 + i * 50, r1);
            Sleep(10);
            system("cls");
        }
        for (k = 0; k < a; k++) {
            if (N[k] == M[i]) {
                for (l = 0; l < 10; l++) {
                    drawSet(100, 100, M, n);
                    drawSet(100, 400, N, a);
                    drawSet(100, 450, Count, a);
                    drawText(25, 460, "COUNT");
                    arrow(75 + r1, 160, 30, 9);
                    arrow(75 + r2, 510, 30, 9);
                    move(75, 75 + (k + 1) * 50, r2);
                    Sleep(10);
                    system("cls");
                }
                break;
            }
        }
        for (j = 0; j < 10; j++) {
            drawSet(100, 100, M, n);
            drawSet(100, 400, N, a);
            drawSet(100, 450, Count, a);
            drawText(25, 460, "COUNT");
            drawText(25, 260, "Result");
            drawSet(100, 250, result, n);
            arrow(75 + r1, 160, 30, 9);
            arrow(75 + r2, 510, 30, 9);
            setcolor(8);
            rectangle(100 + i * 50 + x, 100 + y, 150 + i * 50 + x, 150 + y);
            drawNumber(110 + i * 50 + x, 100 + 8 + y, M[i]);
            movexy(100 + i * 50, 100, 100 + (Count[k] - 1) * 50, 250, x, y);
            Sleep(10);
            if (j == 9) break;
            system("cls");
        }
        result[Count[k] - 1] = M[i];
        drawText(25, 260, "Result");
        drawSet(100, 250, result, n);
        Sleep(100);
        system("cls");
        x = y = r2 = 0;
    }
    for (l = n - 2; l >= 0; l--) {
        if (result[l] == 0) result[l] = result[l + 1];
    }
    for (int i = 0; i <= 1; i++) {
        drawText(25, 260, "Result");
        drawSet(100, 250, result, n);
        if (i == 1) {
            break;
        }
        system("cls");
    }
    Sleep(1000);
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
    initgraph();
    distributionCounting(M, n);
    return 0;
}