#pragma once
#ifndef PARSETEXT_H
#define PARSETEXT_H
#include <QString>
class ParseText
{
public:
    ParseText();
    bool change(QString);
    QString symbol(QString);
    QString getText();
    private:
    QString text;
    QString preText;
    qint32 pos;
};

#endif
