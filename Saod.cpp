#include <iostream>
#include <time.h>
#include"Sourse.h"
#include <time.h>
int M, C;
using namespace std;
int main()
{
    srand(time(NULL));
    int c;
    int m;
    int i;
    cout << "n\tK-sort\tInsert Sort\tShell Sort" << endl;

    for (i = 100; i < 501; i += 100)
    {
        int* a = new int[i];
        cout << i << "\t";

        cout << (int)(log(i) / log(2) - 1) << '\t';
        FillDec(a, i);
        InsertSort(a, i);
        cout << M + C << "\t\t";
        FillRand(a, i);
        ShellSort(a, i,1);
        cout << M + C << endl;
        delete[]a;
    }
    cout << endl;

    cout << "n\tK-sort\tShellSort\tSedgvig\tShellSort" << endl;

    for (i = 100; i < 501; i += 100)
    {
        int* a = new int[i];
        cout << i << "\t";

        cout << count_of_step(i, 1) << '\t';
        FillRand(a, i);
        ShellSort(a, i,1);
        cout << M + C << "\t\t";
        cout << count_of_step(i, 0) << '\t';
        ShellSort(a, i, 0);
        cout << M + C << endl;
        delete[]a;
    }
    cout << endl << endl;
    for (int i = 0; i < count_of_step(100, 0); i++) {
            cout << Sedfvig(i) << ' ';
        }
    cout << endl;
    for (int i = count_of_step(100, 1); i >=1; i--)
    {
        cout << knut(i) << ' ';
    }
    
    cout << endl<<endl;
    for (int i = 0; i < count_of_step(200, 0); i++) {
        cout << Sedfvig(i) << ' ';
    }
    cout << endl;
    for (int i = count_of_step(200, 1); i >= 1; i--)
    {
        cout << knut(i) << ' ';
    }
}









