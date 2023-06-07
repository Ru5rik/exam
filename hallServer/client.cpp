#include "client.h"

Client::Client(QTcpSocket* socket, QObject *parent) : QObject{parent}
{
    Socket = socket;
    connect(Socket, &QTcpSocket::readyRead, this, &Client::SlotRead);
    connect(Socket, &QTcpSocket::disconnected, this, &Client::SlotClose);
}
void Client::SlotRead() {
    while (Socket->bytesAvailable() > 0) {
        QString command = Socket->readAll();

        for (QString res : parser(command))
            Send(res);
    }
}
std::vector<QString> Client::parser(QString command){
    std::vector<QString> result;
    std::vector<QString> parts;

    for (QString part : command.split("&"))
        parts.push_back(part);
    if (parts.size() <= 0){
        result.push_back("Error!");
        return result;
    }
    if (parts[0] != "sort" || parts[2].isEmpty()){
        result.push_back("Error!");
        return result;
    }
    std::vector<QString> snums;
    for (QString snum : parts[2].split(" "))
        snums.push_back(snum);

    int n = parts[1].toInt(), size = snums.size();
    int* nums = new int[size];
    for (int i = 0; i < size; i++)
        nums[i] = snums[i].toInt();

    int i = 0, m = 0;

    for (i = n/2; i >= 0; i--)
        sift(nums, i, n-1);

    for (m = n - 1; m >= 1; m--)
    {
        std::swap(nums[0], nums[m]);
        sift(nums, 0, m-1);
        QString r = "";

        for (int i = 0; i < size; i++)
            r += QString::number(nums[i]) + " ";
        result.push_back(QString::number(m) + " | " + r + "\r\n");
    }

    delete [] nums;
    return result;
}

void Client::SlotClose(){
    emit Close(this);
}
void Client::Send(QString text){
    Socket->write(text.toUtf8() + "\r\n");
}
void Client::sift(int *array, int i, int m)
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
