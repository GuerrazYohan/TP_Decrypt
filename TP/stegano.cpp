#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include "stegano.h"

Stegano::Stegano()
{     
}

QString Stegano::Decrypt(QString textRead)
{
    QFile file("C:\\Users\\Yohan Guerraz\\Desktop\\TextOrigine.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Fichier introuvable";

    // Lit le contenu du fichier texte
    QTextStream in(&file);
    QString text = in.readAll();
    //qDebug()<<"text"<< text ;
    QString texteSansSteno = text;
    QString texteAvecSteno = textRead;
    QString message;
    //qDebug()<<"message"<< textRead;
    // On parcourt le texte avec sténographie
    int iBcl = 0;
    for (int i = 0; i < 57; i++)
    {
        // Si le caractère est différent, on l'ajoute au message
        if (texteSansSteno[i] != texteAvecSteno[i])
        {
            message += texteAvecSteno[i];
            qDebug()<<"message"<< message;
            //i--;
        }
        //iBcl++;

    }

    return message;
}

