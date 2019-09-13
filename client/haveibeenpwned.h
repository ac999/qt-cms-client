#ifndef HIBPURL
#define HIBPURL "https://api.pwnedpasswords.com/range/"
#endif

#ifndef HAVEIBEENPWNED_H
#define HAVEIBEENPWNED_H

#include <QString>
#include <QtNetwork>
#include <QCryptographicHash>
#include <QRegularExpression>

class haveibeenpwned
{
private:
    QString password ;
    QString passwordHash ;
    bool status ;
    int count ;

    void setStatus(bool value) ;
    void setCount(int count) ;
public:
    haveibeenpwned(QString password) ;
    void checkPassword() ;
    bool getStatus() ;
    int getCount() ;

};

QString SHA1(QString password) ;

QByteArray sendRequest(QString url) ;

int searchHash(QString hash, QStringList hashList) ;


#endif // HAVEIBEENPWNED_H
