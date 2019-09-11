#ifndef HAVEIBEENPWNED_H
#define HAVEIBEENPWNED_H

#include <QString>

class haveibeenpwned
{
private:
    QString user ;
    QString password ;
    QString response ;
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

    QString getUser() ;
    QString getPassword() ;
    QString getResponse() ;
};

#endif // HAVEIBEENPWNED_H
