#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Sort(int* a, int n) //question 5.1.
{
    //get the count of 0, 1 and 2 in the array.
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            count0++;
        if (a[i] == 1)
            count1++;
        if (a[i] == 2)
            count2++;
    }

    // Putting the 0's in the array in starting.
    for (int i = 0; i < count0; i++)
        a[i] = 0;

    // Putting the 1's in the array after the 0's.
    for (int i = count0; i < (count0 + count1); i++)
        a[i] = 1;

    // Putting the 2's in the array after the 1's
    for (int i = (count0 + count1); i < n; i++)
        a[i] = 2;
}

void swap(int* x, int* y) {
    int tmp;
    tmp = *x; *x = *y; *y = tmp;
}

void insertionSort(int* a, int N) { // question 5.2.
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0; j--)
            if (a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);
            else
                break;
        //display(a, N);
    }
}

void display(int* a, int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swaps(string* x, string* y) {
    string tmp;
    tmp = *x; *x = *y; *y = tmp;
}

int partition(string* a, int lo, int hi) {
    int i = lo, j = hi + 1;
        string pivot = a[lo];

    while (true) {

        while (a[++i] < pivot)
            if (i == hi) break;

        while (pivot < a[--j])
            if (j == lo) break;

        if (i < j)
            swaps(&a[i], &a[j]);
        else
            break;
    }
    swaps(&a[lo], &a[j]);
    return j;
}

void quickSort1(string* a, int lo, int hi) { // question 5.3.a.

    if (hi <= lo) return;

    int j = partition(a, lo, hi);
    quickSort1(a, lo, j - 1);
    quickSort1(a, j + 1, hi);
}

void displays(string* a, int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void lsd_string_radix(string* a, int N, int max_chars){ // question 5.3.b. Running time is N*max_chars.
    string* temp = new string[N];

    for (int i = max_chars - 1; i >= 0; i--){
        int count[27] = { 0 };

        for (int j = 0; j < N; j++)
            count[static_cast<int>(a[j][i]) - 96]++;

        for (int j = 2; j < 26; j++)
            count[j] += count[j - 1];

        for (int j = 0; j < N; j++)
            temp[count[static_cast<int>(a[j][i]) - 97]++] = a[j];

        for (int j = 0; j < N; j++)
            a[j] = temp[j];
    }
}

int main()
{
    int n = 8;
    int a[] = {0,2,1,0,0,1,2,0};
    Sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    n = 12;
    int ages[] = {4,5,12,9,26,14,19,11,16,8,3,22};
    insertionSort(ages,n);
    display(ages, n);
    cout << endl;

    n = 6;
    string str[] = {"cab", "bcd", "axz", "zwy", "mpo", "dcv"};
    quickSort1(str, 0, n-1);
    displays(str,n);

    string str2[] = { "cab", "bcd", "axz", "zwy", "mpo", "dcv" };
    lsd_string_radix(str2, n, 3);
    displays(str2, n);
}