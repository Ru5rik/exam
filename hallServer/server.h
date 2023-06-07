#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "client.h"


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
public slots:
    void SlotConnection();
    void SlotRemove(Client*);
private:
    QTcpServer* TcpServer;
    QMap<int, Client*> Clients;
};

#endif // SERVER_H
