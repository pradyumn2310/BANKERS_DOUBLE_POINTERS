#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Bankers
{
private:
    int *allocation;
    int *max;
    int *available;
    int *need;
    int *index;

public:
    void process()
    {
        int rows, col;

        cout << "\nEnter the number of rows:";
        cin >> rows;
        cout << "Enter the number of columns:";
        cin >> col;

        int **alloc = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            alloc[i] = new int[col];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter the value for alloc[" << i << "][" << j << "]: ";
                cin >> alloc[i][j];
            }
        }

        int size;
        cout << "Enter the size of the array: ";
        cin >> size;
        int *avail = new int[size];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> *(avail + i);
        }
        cout << "The elements of the array are: ";
        for (int i = 0; i < size; i++)
        {
            cout << *(avail + i) << " ";
        }

        int **max = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            max[i] = new int[col];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter the value for thr maximum needs for the processes[" << i << "][" << j << "]: ";
                cin >> max[i][j];
            }
        }

        cout << "The allocation for the processes is:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << alloc[i][j] << " ";
            }
            cout << endl;
        }

        cout << "The max needs for the processes is:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << max[i][j] << " ";
            }
            cout << endl;
        }

        int **need = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            need[i] = new int[col];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                need[i][j] = max[i][j] - alloc[i][j];
            }
        }

        cout << "The  needed resources for the processes are:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << need[i][j] << " ";
            }
            cout << endl;
        }

        int end[rows] = {0};
        int answer[rows] = {0};
        int index = 0;

        int y = 0;
        for (int k = 0; k < 5; k++)
        {
            for (int i = 0; i < rows; i++)
            {
                if (end[i] == 0)
                {
                    int flag = 0;
                    for (int j = 0; j < col; j++)
                    {
                        if (need[i][j] > avail[i])
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        answer[index++] = i;
                        for (int y = 0; y < rows; y++)
                        {
                            avail[y] += alloc[i][y];
                        }
                        end[i] = 1;
                    }
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < rows; i++)
        {
            if (end[i] == 0)
            {
                flag = false;
                cout << "System is in deadlock !!";
                break;
            }
        }

        if (flag == true)
        {
            cout << "there is no deadlock so the given process resource allocation is safe!!";
        }
    }
};
int main()
{

    Bankers b;
    b.process();
    return 0;
}
