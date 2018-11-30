#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(managerFinished(QNetworkReply*)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::on_pushButton_clicked()
{
    QString str1 = "Doing stuff!";

    ui->label->setText(str1);

    QUrl url = ui->lineEdit->text();

    request.setUrl(QUrl(url));

    manager->get(request);
}

void MainWindow::managerFinished(QNetworkReply *reply) {

    ui->label->setText(QString("Finished"));

    if(reply->error()) {
        qDebug() << reply->errorString();

        return;
    }

    QRegularExpression re;

    QString answer = reply->readAll();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(answer);

    qDebug() << answer;

}

