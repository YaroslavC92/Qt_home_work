#include "parse_text.h"

#define MIN(a, b) (a < b) ? a : b
ParseText::ParseText()
{
    text = "";
    preText = "";
    pos = 0;
}
bool ParseText::change(QString istr)
{
    qint32 length = MIN(MIN(text.length(), istr.length()), pos);
    preText = "";
    for (qint32 i = 0; i < length; i++)
    {
        if (text[i] != istr[i])
        {
            pos = i;
            break;
        }
    }
    const QChar *arStr = istr.constData();
    qint32 ppos = 0, lastp = -1;
    bool chg = false;
    for (qint32 fnd = istr.indexOf("#", pos);
        fnd != -1 && lastp != pos;
        fnd = istr.indexOf("#", pos))
    {
    preText.insert(preText.length(), &arStr[ppos], fnd);
    lastp = pos;
    pos = fnd;
    int r = istr.indexOf('@', fnd);
    int space = istr.indexOf(' ', fnd);
        if ((r < space || space == -1) && r != -1)
        {
            QString exampl = "";
            exampl.insert(0, &arStr[fnd + 1], r - fnd - 1);
            QString rez = symbol(exampl);
            preText += rez;
            pos = r + 1;
            chg = true;
        }
    preText.insert(preText.length(), &arStr[pos], istr.length() - pos);
    }
    return chg;
}

QString ParseText::symbol(QString example){
    QString str = example;
    QString temp;
    //str[str.length() - 1] = '\0';
    if (str == "RUB")
        temp = QString::fromUtf8("₽");
    else if (str == "TM")
        temp = QString::fromUtf8("®");
    else if (str == "EURO")
        temp = QString::fromUtf8("€");
    else if (str == "PM")
        temp = QString::fromUtf8("‰");
    return temp;
}

QString ParseText::getText()
{
text = preText;
return text;
}
