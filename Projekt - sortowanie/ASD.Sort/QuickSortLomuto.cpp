#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int partition(int arr[], int p, int r)
{
    int q = arr[r];
    int i = (p - 1);

    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= q)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}


int main()
{
    int array[100000];
    ifstream file;
    file.open("plik.txt", ios::in);

    if (!file.good())
    {
        return 0;
    }
    else
    {

        for (int i = 0; i < 100000; i++)
            file >> array[i];
    }

    file.close();


    clock_t start = clock();
    quickSort(array, 0, 99999);
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Czas: " << elapsed << "s" << endl;

    clock_t start2 = clock();
    quickSort(array, 0, 99999);
    clock_t end2 = clock();
    double elapsed2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Czas: " << elapsed2 << "s" << endl;

    int[100000] arr;
    for (int j = 0, int i = 100000; i >= 0; i--, j++) {
        arr[j] = array[i];
    }


    clock_t start3 = clock();
    quickSort(array, 0, 99999);
    clock_t end3 = clock();
    double elapsed2 = double(end3 - start3) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed3 << "s" << endl;

    return 0;
}