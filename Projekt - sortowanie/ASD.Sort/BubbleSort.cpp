#include <iostream>
#include <fstream>

using namespace std;

//Prosty algorytm sortuj¹cy, który dzia³a przez wielokrotne porównywanie i zamienianie s¹siednich elementów. Nieodpowiedni do du¿ych zestawów danych

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
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

    bubbleSort(array, 99999);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    /*for (int i = 0; i < 100000; i++)
        cout << array[i] << endl;*/

    cout << "Czas: " << elapsed << "s     ";

    clock_t start2 = clock();

    bubbleSort(array, 100000);

    clock_t end2 = clock();

    double elapsed2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Czas: " << elapsed2 << "s";

    return 0;
}