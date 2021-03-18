#include"Sourse.h"
#include<math.h>

int knut(int l) {
    if (l == 1) return 1;
    return(2 * knut(l - 1) + 1);
}

bool m(int a, int b) {
    C++;
    return a < b;
}
int Sedfvig(int i)
{
    if (i % 2 == 0) {
        return 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
    }
    else {
        return 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
    }
}

int count_of_step(int size,bool flag){
    int i=0;
    if(flag) return log(size) / log(2) - 1;
    else {
        while(true)
        {
            i++;
            if (3 * Sedfvig(i) > size) return i - 1;
        }
    }
}

void ShellSort(int* a, int n,bool flag)
{
    M = C = 0;
    int m = count_of_step(n,flag);
    //

    while (true) {
        int k = flag?knut(m):Sedfvig(m);
        int t;
        int j;
        for (int i = k; i < n; i++) {
            t = a[i];
            j = i - k;
            C++;
            while (j >= 0 && (t < a[j])) {
                C++;
                a[j + k] = a[j];
                j = j - k;
                M++;
            }
            a[j + k] = t;
            M = M + 2;
        }
        m--;
        if (m == 0) break;
    }
    if (C != n - 1) C -= n - 1;
}
void InsertSort(int* a, int n) {
    M = 0;
    C = 0;
    int t;
    int j;
    for (int i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;
     //   C++;
        while (j >= 0 && m(t,a[j])) {
       //    C++;
            a[j + 1] = a[j];
            j = j - 1;
            M++;
        }
        a[j + 1] = t;
        M = M + 2;
    }
   //if(C!= n-1) C -= n - 1;
}
void SelectSort(int* a, int n)   //сортировка прямым выбором
{
    int min, tmp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
            C++;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
        M += 3;

    }
}

void BubbleSort(int* a, int n)//Сортировка методом пузырька
{
    M = C = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 2; j >= i; j--) {
            if (a[j] > a[j + 1])
            {
                int c;
                c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
                M += 3;
            }
            C++;
        }
}

void ShakerSort(int* a, int n)
{
    int L = 0, R = n - 1, k = n - 1;
    M = C = 0;
    while (L < R)
    {
        for (int i = R; i > L; i--)
        {
            C++;
            if (a[i] < a[i - 1]) {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                M += 3;
                k = i;
            }
        }
        L = k;
        for (int i = L; i < R; i++)
        {
            C++;
            if (a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                M += 3;
                k = i;
            }
        }
        R = k;
    }

}



int CheckSum(int* A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int RunNumber(int* A, int n)
{
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) s++;
    }
    return s + 1;
}

void PrintMas(int* A, int n)
{
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void FillRand(int* A, int n)
{

    for (int i = 0; i < n; i++) {
        A[i] = 1 + rand() % n;
    }
}

void FillInc(int* A, int n)
{
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
}

void FillDec(int* A, int n)
{

    for (int i = 0; i < n; i++) {
        A[i] = n - i;
    }
}

