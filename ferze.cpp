#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define FIELD_SIZE 64

using namespace std;

void setQueen(int *field, int x, int y);
void clearField(int *field);
bool isStriked(int *field, int x, int y);
bool isFilled(int *field);
void getStriked(int *field, int x, int y);
void printTable(int *field);

int main()
{
    int count = 0;
    int field[FIELD_SIZE];
    double t1, t2;

    t1 = clock();
    for (int f1 = 0; f1 < FIELD_SIZE - 4; f1++)
    {
        for (int f2 = f1 + 1; f2 < FIELD_SIZE - 3; f2++)
        {
            for (int f3 = f2 + 1; f3 < FIELD_SIZE - 2; f3++)
            {
                for (int f4 = f3 + 1; f4 < FIELD_SIZE - 1; f4++)
                {
                    for (int f5 = f4 + 1; f5 < FIELD_SIZE; f5++)
                    {
                        clearField(field);
                        getStriked(field, f1 / 8, f1 % 8);
                        getStriked(field, f2 / 8, f2 % 8);
                        getStriked(field, f3 / 8, f3 % 8);
                        getStriked(field, f4 / 8, f4 % 8);
                        getStriked(field, f5 / 8, f5 % 8);
                        if (isFilled(field))
                            count++;
                    }
                }
            }
        }
    }
    t2 = clock();

    cout << "Count of right positions: " << count << endl << 
    "Time of execution is " << (t2 - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}

void printTable(int *field)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << field[8 * i + j] << "\t";
        cout << endl;
    }
}

void setQueen(int *field, int x, int y)
{
    field[8 * x + y] = 1;
}

bool isFilled(int *field)
{
    for (int i = 0; i < FIELD_SIZE; i++)
        if (field[i] == -1)
            return false;
    return true;
}

void clearField(int *field)
{
    for (int i = 0; i < FIELD_SIZE; i++)
        field[i] = -1;
}

bool isStriked(int *field, int x, int y)
{
    if (field[8 * x + y] == 1)
        return true;
    return false;
}

void getStriked(int *field, int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        field[8 * x + i] = 0;
        field[8 * i + y] = 0;
    }

    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        field[8 * i + j] = 0;

    for (int i = x, j = y; i < 8 && j < 8; i++, j++)
        field[8 * i + j] = 0;

    for (int i = x, j = y; i >= 0 && j < 8; i--, j++)
        field[8 * i + j] = 0;

    for (int i = x, j = y; i < 8 && j >= 0; i++, j--)
        field[8 * i + j] = 0;
}
