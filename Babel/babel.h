#ifndef BABEL_H
#define BABEL_H

#include <QtGui/QMainWindow>
#include "ui_babel.h"
#include "QNetwork.h"

class Babel : public QMainWindow
{
	Q_OBJECT

public:
	Babel(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Babel();

public slots:
	void	changerPage();
	void	connectToServer();

signals:
	void	valueChanged(int);

private:
	Ui::BabelClass	ui;
	QNetwork		_server;
};

#endif // BABEL_H