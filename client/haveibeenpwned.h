#ifndef HIBPKEY
#define HIBPKEY "api_key"
#endif

#ifndef HAVEIBEENPWNED_H
#define HAVEIBEENPWNED_H

#include <QString>
#include <QtNetwork>
#include <QCryptographicHash>

class haveibeenpwned
{
private:
    QString user ;
    QString password ;
    QString passwordHash ;
    bool statusUser ;
    bool statusPassword ;
public:
    haveibeenpwned() ;
    haveibeenpwned(
              QString user
            , QString password
            ) ;
    bool checkUser() ;
    bool checkPassword() ;

    void setUser(QString user) ;
    void setPassword(QString password) ;
    void setPasswordHash(QString hash) ;

    QString getUser() ;
    QString getPassword() ;

    bool getStatusUser() ;
    bool getStatusPassword() ;

    QByteArray sendRequest(
              QString url
            , QString ApiKey
            ) ;
};

QString SHA1(QString password) ;


#endif // HAVEIBEENPWNED_H
