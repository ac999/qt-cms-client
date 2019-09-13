#include "haveibeenpwned.h"

bool haveibeenpwned::getStatus() {
    return this->status ;
};

int haveibeenpwned::getCount() {
    return this->count ;
};

haveibeenpwned::haveibeenpwned(QString password) {
    this->password = password ;
    this->passwordHash = SHA1(password) ;

    this->checkPassword();
};

void haveibeenpwned::setCount(int count) {
    this->count = count ;
};

void haveibeenpwned::setStatus(bool value) {
    this->status = value ;
};

void haveibeenpwned::checkPassword() {
    // First 5 characters of hash:
    QStringRef SHA1_5char(&this->passwordHash,0,5) ;
    QString url = HIBPURL + SHA1_5char ;
    try {
        QStringList hashList = QString(sendRequest(url))
                .split('\n');

        this->setCount(
            searchHash(
                  this->passwordHash
                , hashList
                )
            ) ;
        this->getCount()>0
                ?this->setStatus(true)
                :this->setStatus(false) ;

    } catch (...) {
        this->setCount(-1) ;
        this->setStatus(false) ;
    }
};


// SHA1 of parameter in uppercase
QString SHA1(QString password) {
    QCryptographicHash* hash = new QCryptographicHash(QCryptographicHash::Sha1) ;
    hash->addData(password.toUtf8() ) ;
    return QString::fromUtf8(hash->result() ).toUpper() ;
};

// hash is uppercase & hashList is of format "SHA1:nr_of_apparitions"
int searchHash(QString hash, QStringList hashList) {
    QString re_rule = hash + ":[0-9]+" ;
    QRegularExpression re(re_rule) ;
    return hashList.filter(re).count();
};

QByteArray sendRequest(QString url) {

};
