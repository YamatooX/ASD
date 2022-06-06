#include <iostream>
#include <fstream>

using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
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

    heapSort(array, 100000);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << "s     ";

    clock_t start2 = clock();

    heapSort(array, 100000);

    clock_t end2 = clock();

    double elapsed2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Czas: " << elapsed2 << "s";

    int arr[100000];
    int j = 0;
    for (int i = 99999; i >= 0; i--) {
        arr[j] = array[i];
        j++;
    }


    clock_t start3 = clock();
    heapSort(array, 100000);
    clock_t end3 = clock();
    double elapsed3 = double(end3 - start3) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed3 << "s" << endl;
}