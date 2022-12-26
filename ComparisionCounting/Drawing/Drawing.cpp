#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>


struct  Record
{
    char data;
    int key;

};
void drawRSet(int startx, int starty, Record M[], int n, int color) {
    drawText(0, 0, "");
    for (int i = 0; i < n; i++) {
        setcolor(color);
        rectangle(startx + i * 50, starty, startx + 50 + i * 50, starty + 50);
        drawNumber(startx + 10 + i * 50, starty - 40, i);
        drawNumber(startx + 10 + i * 50, starty + 8, M[i].key);
    }
}
void ComparisionCounting(Record M[], int n);

void swapArr(int M[], int position1, int position2) {
    int temp = M[position1];
    M[position1] = M[position2];
    M[position2] = temp;
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    Record M[100];
    cout << "Nhap Key: ";
    for (int i = 0; i < n; i++)
        cin >> M[i].key;
    initgraph();
    ComparisionCounting(M, n);
    return 0;
}

void ComparisionCounting(Record M[], int n)
{
    int i = 0, j = 0;

    int COUNT[100] ={0};
    int KEY[100] = { 0 };

    drawText(130, 200, "Array: ");

    for (i = 0; i < n; i++)
    {
        drawRSet(200, 200, M, n, 10);
        drawText(100, 350, "COUNT array: ");
        drawSet(200, 350, COUNT, n, 7);
        Sleep(100);
    }

    for (i = n - 1; i >= 1; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            
            if (M[i].key <= M[j].key)
            {
                setcolor(3);
                rectangle(200 + i * 50, 200, 250 + i * 50, 250);
                drawNumber(210 + i * 50, 210, M[i].key);
                Sleep(100);
                COUNT[j] += 1;
            }
            else
            {
                setcolor(8);
                rectangle(200 + j * 50, 200, 250 + j * 50, 250);
                drawNumber(210 + j * 50, 210, M[j].key);
                Sleep(100);
                COUNT[i] += 1;
            }
            
            drawSet(200, 350, COUNT, n, 7);
            Sleep(1000);
            if (j == 0)
            {
                break;
            }
        }

        drawRSet(200, 200, M, n, 10);
    }
    int index[100] = {0};

    drawText(90, 500, "Result Array: ");

    for (i = 0; i < n; i++)
    {
        drawNumber(210 + i * 50, 460, i);
    }

    for (i = 0; i < n; i++)
    {        KEY[COUNT[i]] = M[i].key;
        drawSet(200, 500, KEY, n, 0);
        Sleep(1000);
    }

    drawSet(200, 500, KEY, n, 9);
    Sleep(500);
}