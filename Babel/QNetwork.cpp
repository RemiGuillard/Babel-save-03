#include <QTcpSocket>
#include <QUdpSocket>
#include <QMessageBox>
#include "QNetwork.h"

QNetwork::QNetwork()
{

}

QNetwork::~QNetwork()
{
	delete _sock;
}

QNetwork::QNetwork(const QNetwork &cpy)
{
	*this = cpy;
}

QNetwork&		QNetwork::operator=(const QNetwork &cpy)
{
	return *this;
}

void		QNetwork::createSocket(QAbstractSocket::SocketType sock)
{
	if (sock == QAbstractSocket::TcpSocket)
		_sock = new QTcpSocket;
	else if (sock == QAbstractSocket::UdpSocket)
		_sock = new QUdpSocket;
}

void		QNetwork::socketConnection(const QString & hostName, quint16 port)
{
	_sock->connectToHost(hostName, port);
	QString s(0);
	//QMessageBox::information(NULL, "Connection Status", s.setNum(_sock->state()));
	
//	if (_sock->waitForConnected(3000))
	if (_sock->state() == QAbstractSocket::ConnectedState)
		this->setSocketStatus(true);
	else
		QMessageBox::information(NULL, "Connection Error", s.setNum(_sock->state()));
}

void		QNetwork::packetRcv()
{
}

void		QNetwork::packetSend()
{
}

void		QNetwork::disconnect()
{
	QMessageBox::information(NULL, "Connection Exit", "You're now disconnected");
	_sock->close();
}
