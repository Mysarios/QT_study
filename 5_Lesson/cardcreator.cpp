#include "cardcreator.h"
#include <QFile>
#include <QProcess>
#include <QDebug>

CardCreator::CardCreator(QObject *parent) : QObject(parent)
{

}

CardCreator::CardCreator(QString Fname,QString SName,QString PhoneNumber,QString email,QString site,QString Addres){
    _FName = Fname;
    _SName = SName;
    _Phone = PhoneNumber;
    _Email = email;
    _SiteName = site;
    _Address = Addres;
    qDebug()<<_FName;
}
QString CardCreator::getFName(){
  qDebug()<<_FName + "hi_get";
  return _FName;
}
QString CardCreator::getSName(){
   return _SName;
}
QString CardCreator::getPhone(){
    return _Phone;
}
QString CardCreator::getAddress(){
    return _Address;
}
QString CardCreator::getSiteName(){
   return _SiteName;
}
QString CardCreator::getEmail(){
    return _Email;
}

void CardCreator::setFName(QString FName){
    _FName = FName;
    qDebug()<<FName + "hi";
    emit FNameChanged();
}
void CardCreator::setSName(QString SName){
    _SName = SName;
    emit FNameChanged();
}
void CardCreator::setPhone(QString Phone){
    _Phone = Phone;
    emit PhoneChanged();
}
void CardCreator::setAddress(QString Address){
    _Address = Address;
    emit EmailChanged();
}
void CardCreator::setSiteName(QString SiteName){
    _SiteName = SiteName;
    emit SiteNameChanged();
}
void CardCreator::setEmail(QString Email){
    _Email = Email;
    emit AddressChanged();
}
void CardCreator::CreateCard(){

}
