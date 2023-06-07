#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket* socket, QObject *parent = nullptr);
    QTcpSocket* Socket;
    void Send(QString text);
    std::vector<QString> parser(QString command);
public slots:
    void SlotRead();
    void SlotClose();
signals:
    void Close(Client* client);
private:
    void sift(int *array, int i, int m);

};

#endif // CLIENT_H
