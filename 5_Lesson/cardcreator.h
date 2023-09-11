#ifndef CARDCREATOR_H
#define CARDCREATOR_H

#include <QObject>
#include <QQuickItem>
#include <QString>
#include <QStringList>

class CardCreator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString FName READ getFName WRITE setFName NOTIFY FNameChanged)
    Q_PROPERTY(QString SName READ getSName WRITE setSName NOTIFY SNameChanged)
    Q_PROPERTY(QString Phone READ getPhone WRITE setPhone NOTIFY PhoneChanged)
    Q_PROPERTY(QString Address READ getAddress WRITE setAddress NOTIFY AddressChanged)
    Q_PROPERTY(QString SiteName READ getSiteName WRITE setSiteName NOTIFY SiteNameChanged)
    Q_PROPERTY(QString Email READ getEmail WRITE setEmail NOTIFY EmailChanged)
public:
    explicit CardCreator(QObject *parent = nullptr);
    CardCreator(QString Fname,QString SName,QString PhoneNumber,QString emal,QString site,QString Addres);
    QString getFName();
    QString getSName();
    QString getPhone();
    QString getAddress();
    QString getSiteName();
    QString getEmail();

    void setFName(QString FName);
    void setSName(QString SName);
    void setPhone(QString Phone);
    void setAddress(QString Address);
    void setSiteName(QString SiteName);
    void setEmail(QString Email);
public slots:
    void CreateCard();
signals:
    void FNameChanged();
    void SNameChanged();
    void PhoneChanged();
    void AddressChanged();
    void SiteNameChanged();
    void EmailChanged();

private:
    QString _FName;
    QString _SName;
    QString _Phone;
    QString _Address;
    QString _SiteName;
    QString _Email;

};

#endif // CARDCREATOR_H
