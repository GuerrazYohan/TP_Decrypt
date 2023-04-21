#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stegano.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_BT_Parcourir_clicked()
{
    qDebug()<<"test";
    // Ouvre le fichier texte
    QFile file("C:\\Users\\Yohan Guerraz\\Desktop\\SecretDoc.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Fichier introuvable";

    // Lit le contenu du fichier texte
    QTextStream in(&file);
    QString text = in.readAll();

    ui->FileSelect->setText(text);
    Stegano steg;
    QString textResult = steg.Decrypt(text);
    ui->textResult->setText(textResult);
}

