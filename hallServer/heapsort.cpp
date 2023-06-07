#include "heapsort.h"

HeapSort::HeapSort(QObject *parent)
    : QObject{parent}
{

}

void HeapSort::Sort(int* array, int n){
    int i, m;
    // построение пирамиды
    for (i = n/2; i >= 0; i--)
        sift(array, i, n-1);
    // сортировка массива
    for (m = n-1; m >= 1; m--)
    {
        std::swap(array[0], array[m]);
        sift(array, 0, m-1);
    }

}
void HeapSort::sift(int *array, int i, int m)
{
    int j = i, k = i*2+1;
    while (k <= m)
    {
        if (k<m && array[k]<array[k+1]) k++;
        if (array[j] < array[k])
        {
            std::swap(array[j], array[k]);
            j = k;
            k = k*2+1;
        }
        else break;
    }
}

