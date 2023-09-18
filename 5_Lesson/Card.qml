import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

//_FName = Fname;
//_SName = SName;
//_Phone = PhoneNumber;
//_Email = email;
//_SiteName = site;
//_Address = Addres;
//qDebug()<<_FName;

Rectangle{
    id: layout_for_name;
    width: 531;
    height: 321
    color: "lightgray"
    radius: 8
    RowLayout{
    id: names_layuot;
    anchors.horizontalCenter: layout_for_name.horizontalCenter
        Text{
            color:"#2f4f4f";
            //anchors.horizontalCenter: layout_for_name.horizontalCenter
            text: card_info._FName;
            y: 50;
            font.pixelSize: 50;
        }
        Text{
            //anchors.horizontalCenter: layout_for_name.horizontalCenter
            color: "#2f4f4f";
            text: card_info._SName;
            y: 50;
            font.pixelSize: 50;
        }
    }
    Text{
        color: "#2f4f4f";
        anchors.horizontalCenter: layout_for_name.horizontalCenter
        text: "Russia";
        y: 80;
        font.pixelSize: 40;
    }
    ColumnLayout{
        id: column_layout_first;
        y: 150;
        Text{
            color:"#2f4f4f";
            //anchors.horizontalCenter: layout_for_name.horizontalCenter
            text: card_info._Phone;
            font.pixelSize: 25;
        }
        Text{
            color:"#2f4f4f";
            //anchors.horizontalCenter: layout_for_name.horizontalCenter
            text: card_info._Email;
            font.pixelSize: 25;
        }
        Text{
            color:"#2f4f4f";
            //anchors.horizontalCenter: layout_for_name.horizontalCenter
            text: card_info._SiteName;
            font.pixelSize: 25;
        }
        Text{
            color:"#2f4f4f";
            //anchors.horizontalCenter: layout_for_name.horizontalCenter
            text: card_info._Address;
            font.pixelSize: 25;
        }
    }
}
