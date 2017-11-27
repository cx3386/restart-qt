#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QWidget* widget = new QWidget();
    setCentralWidget(widget);
    QPushButton* btn1 = new QPushButton(QStringLiteral("use event loop to restart"));
    connect(btn1, &QPushButton::clicked, [&] { qApp->exit(773); });

    QPushButton* btn2 = new QPushButton(QStringLiteral("use process control to restart"));
    connect(btn2, &QPushButton::clicked, this, &MainWindow::restart);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    widget->setLayout(layout);
}

MainWindow::~MainWindow()
{
}

void MainWindow::restart()
{
    qApp->closeAllWindows();
    QProcess::startDetached(QDir::toNativeSeparators(qApp->applicationFilePath()), QStringList());
}
