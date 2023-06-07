#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QObject>

class HeapSort : public QObject
{
    Q_OBJECT
public:
    explicit HeapSort(QObject *parent = nullptr);

    static void Sort(int* array, int n);
private:
    static void sift(int *array, int i, int m);
};

#endif // HEAPSORT_H
