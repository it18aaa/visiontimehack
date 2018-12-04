#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    networkManager = new QNetworkAccessManager();

    QObject::connect(networkManager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(managerFinished(QNetworkReply*)));

    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(getFrontPage()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete networkManager;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button clicked!\n";


    ui->label->setText(QString("Doing stuff"));

    QUrl url = ui->lineEdit->text();

    QByteArray dotNetSeshId = "ASP.NET_SessionId=";
    dotNetSeshId.append("23423443223423");


    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::CookieHeader, dotNetSeshId);
    request.setHeader(QNetworkRequest::CookieHeader, "LastRep=AC");
    request.setHeader(QNetworkRequest::CookieHeader, "BadgeID=");


    QByteArray postData;
    postData.append("txtBadge=&");
    postData.append("txtPin=&");
    postData.append("btnClocking=Clocking");
    postData.append("ServerTime= Server Time  12:31:51");

    //post
    networkManager->post(request, postData);

    // get
    //networkManager->get(request);

}

void MainWindow::managerFinished(QNetworkReply *reply) {

    ui->label->setText(QString("Finished"));

    if(reply->error()) {
        qDebug() << reply->errorString();

        return;
    }

    ui->txtEditResponse->clear();
    ui->txtEditResponse->appendPlainText("Headers");
    ui->txtEditResponse->appendPlainText("=======");

    QList<QNetworkReply::RawHeaderPair> *headers = new QList<QNetworkReply::RawHeaderPair>;

    *headers = reply->rawHeaderPairs();
    QList<QNetworkReply::RawHeaderPair>::iterator i;

    for(i = headers->begin(); i != headers->end(); i++) {
        qDebug() << *i;
        QString headerLine = i->first + ": " + i->second;
        ui->txtEditResponse->appendPlainText(headerLine);
    }

    ui->txtEditResponse->appendPlainText("Cookies");
    ui->txtEditResponse->appendPlainText("=======");


    QVariant cookieVar = reply->header(QNetworkRequest::CookieHeader);
    if(cookieVar.isValid())
    {
        QList<QNetworkCookie> cookies = cookieVar.value<QList<QNetworkCookie>>();
        foreach(QNetworkCookie cookie, cookies) {

            QString cookieString = cookie.name() + ": " + cookie.value();
            ui->txtEditResponse->appendPlainText(cookieString);
        }
    }

    QRegularExpression re;

    QString answer = reply->readAll();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(answer);

    ui->browserView->clear();
    ui->browserView->append(answer);

    qDebug() << answer;
}

void MainWindow::getFrontPage() {

    // prepare request
    // connect network manager event to appropriate method


    ui->txtEditResponse->appendPlainText("Loading up front page to get tokens!");
    QUrl url = QString("http://flextime/flextime/VTLogin.aspx");







}

void MainWindow::getStateTokens(QNetworkReply *reply) {

}

void MainWindow::postLoginInfo() {}
void MainWindow::getClockingPage(QNetworkReply *reply) {}


