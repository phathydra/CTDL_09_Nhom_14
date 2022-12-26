#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

void shellSort(int M[], int n);

int main()
{
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    int M[100];
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
        cin >> M[i];
    shellSort(M, n);
    return 0;
}

void shellSort(int M[], int n)
{
    int gap, i, j, k = 0;
    int temp;
    
    initgraph();

    for (i = 0; i < n; i++)
    {
        drawSet(200, 200, M, n,13);
        drawText(140, 310, "Gap: ");
        drawText(50, 210, "Temp: ");
        
        Sleep(2000);
        for (gap = n / 2; gap > 0; gap /= 2)
        {
            int l = 0, r = 0;
            setcolor(10);
            rectangle(200, 300, 250, 350);
            drawNumber(210, 310, gap);
            Sleep(400);
            
            for (j = gap; j < n; j++)
            {
                temp = M[j];

                setcolor(8);
                rectangle(130, 200, 180, 250);
                drawNumber(140, 210, temp);
                Sleep(400);

                for (k = j; k >= gap && M[k - gap] > temp; k -= gap)
                {
                    M[k] = M[k - gap];

                    swap(200 + (k - gap) * 50, 200 + (k) * 50, l, r);

                    setcolor(9);
                    rectangle(200 + (k - gap) * 50 + r, 200, 250 + (k - gap) * 50 + r, 250);
                    drawNumber(210 + (k - gap) * 50 + r, 210, M[k-gap]);

                    setcolor(9);
                    rectangle(200 + (k) * 50 - l, 200, 250 + (k) * 50 - l, 250);
                    drawNumber(210 + (k) * 50 - l, 210, temp);

                    

                    Sleep(600);
                }
                M[k] = temp;
                drawSet(200, 200, M, n,13);
                Sleep(2000);
            }
        }
        if (gap == 0)
        {
            break;
        }
        system("cls");
        
    }
    system("cls");
    drawText(100, 200, "Result:");
    drawSet(200, 200, M, n,9);
    Sleep(10000);
}
    