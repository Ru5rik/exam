#include "server.h"


Server::Server(QObject *parent): QObject{parent}
{
    TcpServer = new QTcpServer(this);
    connect(TcpServer, &QTcpServer::newConnection, this, &Server::SlotConnection);

    if (!TcpServer->listen(QHostAddress::Any, 25565)) {
        qDebug() << "Server is not started";
    }
    else {
        qDebug() << "Server is started";
    }
}
void Server::SlotConnection() {
    QTcpSocket* socket = TcpServer->nextPendingConnection();
    Client* client = new Client(socket);
    Clients.insert(client->Socket->socketDescriptor(), client);
    connect(client, &Client::Close, this, &Server::SlotRemove);
    socket->write("Welcome to the server!\r\n");
}
void Server::SlotRemove(Client* client) {
    Clients.remove(client->Socket->socketDescriptor());
    client->Socket->close();
}
