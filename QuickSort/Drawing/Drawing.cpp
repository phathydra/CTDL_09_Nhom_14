#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

void swapArr(int M[], int position1, int position2) {
    int temp = M[position1];
    M[position1] = M[position2];
    M[position2] = temp;
}

int partition(int M[], int n, int low, int high) {
    int pivot = M[high];
    int i = (low - 1);
    int mov = 0, k;
    int l = 0, r = 0;
    for (int j = low; j < high; j++) {
        for (k = 0; k < 10; k++) {
            drawSet(100, 300, M, n, 8);
            setcolor(9);
            rectangle(100 + high * 50, 300, 150 + high * 50, 350);
            drawNumber(110 + high * 50, 308, M[high]);
            arrow(75 + low * 50 + mov, 360, 30, 9);
            move(75 + low * 50, 125 + low * 50, mov);
            Sleep(10);
            if (k == 9) break;
            system("cls");
        }
        Sleep(100);
        if (M[j] <= pivot) {
            i++;
            if (i != j) {
                for (k = 0; k <= 10; k++) {
                    drawSet(100, 300, M, n, 8);
                    setcolor(9);
                    rectangle(100 + high * 50, 300, 150 + high * 50, 350);
                    drawNumber(110 + high * 50, 308, M[high]);
                    arrow(75 + low * 50 + mov, 360, 30, 9);
                    setcolor(8);
                    rectangle(100 + i * 50 + r, 300, 150 + i * 50 + r, 350);
                    drawNumber(110 + i * 50 + r, 308, M[i]);
                    rectangle(100 + j * 50 + l, 300, 150 + j * 50 + l, 350);
                    drawNumber(110 + j * 50 + l, 308, M[j]);
                    swap(100 + i * 50, 100 + j * 50, l, r);
                    Sleep(10);
                    system("cls");
                }
                l = r = 0;
                swapArr(M, i, j);
            }
        }
        drawSet(100, 300, M, n, 8);
        setcolor(9);
        rectangle(100 + high * 50, 300, 150 + high * 50, 350);
        drawNumber(110 + high * 50, 308, M[high]);
        arrow(75 + low * 50 + mov, 360, 30, 9);
        Sleep(100);
    }
    if (i + 1 != high) {
        for (k = 0; k <= 10; k++) {
            drawSet(100, 300, M, n, 8);
            setcolor(9);
            rectangle(100 + high * 50, 300, 150 + high * 50, 350);
            drawNumber(110 + high * 50, 308, M[high]);
            setcolor(8);
            rectangle(100 + (i + 1) * 50 + r, 300, 150 + (i + 1) * 50 + r, 350);
            drawNumber(110 + (i + 1) * 50 + r, 308, M[i + 1]);
            rectangle(100 + high * 50 + l, 300, 150 + high * 50 + l, 350);
            drawNumber(110 + high * 50 + l, 308, M[high]);
            swap(100 + i * 50, 100 + high * 50, l, r);
            Sleep(10);
            system("cls");
        }
        l = r = 0;
        swapArr(M, i + 1, high);
    }
    drawSet(100, 300, M, n, 8);
    setcolor(9);
    rectangle(100 + high * 50, 300, 150 + high * 50, 350);
    drawNumber(110 + high * 50, 308, M[high]);
    Sleep(500);
    return (i + 1);
}

void quickSort(int M[], int n, int low, int high) {
    if (low < high) {
        int pi = partition(M, n, low, high);
        quickSort(M, n, low, pi - 1);
        quickSort(M, n, pi + 1, high);
    }
    drawSet(100, 300, M, n, 7);
    if(low == 0 & high == n - 1)
        drawText(30, 308, "Result");
    Sleep(500);
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
    quickSort(M, n, 0, n - 1);
    return 0;
}