#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QNetworkCookie>


namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void managerFinished(QNetworkReply *reply);

    void getFrontPage();
    void getStateTokens(QNetworkReply *reply);

    void postLoginInfo();
    void getClockingPage(QNetworkReply *reply);



private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
    QNetworkRequest request;
    QUrl loginPageUrl;
    QUrl clockPageUrl;
    QString badge;
    QString pin;
};

#endif // MAINWINDOW_H
