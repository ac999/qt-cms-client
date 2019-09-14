#include "haveibeenpwned.h"
#include<QDebug>

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
        QStringList hashList = QString(sendRequest(url) )
                .split("\r\n");

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
    return QString::fromLatin1(hash->result().toHex()).toUpper() ;
};

// hash is uppercase & hashList is of format "SHA1:nr_of_apparitions"
int searchHash(QString hash, QStringList hashList) {
    QString re_rule = "^"+hash.mid(5,hash.length())+".+$" ;
    QStringList filteredHashes=hashList.filter(QRegExp(re_rule));

    if (!filteredHashes.count()) {
        return 0;
    }
    return filteredHashes[0].split(':')[1].toInt();

};

QByteArray sendRequest(QString url) {
    QNetworkAccessManager* manager = new QNetworkAccessManager() ;
    QNetworkRequest request;
    QNetworkReply* reply = nullptr ;

    QSslConfiguration config = QSslConfiguration::defaultConfiguration() ;
    config.setProtocol(QSsl::TlsV1_3) ;
    request.setSslConfiguration(config) ;
    request.setUrl(QUrl(url) ) ;

    reply = manager->get(request) ;

    while(!reply->isFinished() ) {
        qApp->processEvents() ;
    }
    QByteArray result = reply->readAll() ;
    reply->deleteLater() ;
    return result ;
};
