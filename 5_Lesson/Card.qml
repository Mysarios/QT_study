import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0

Rectangle{
    id: layout_for_name;
    width: 500;
    height: 90;
    //color: "#111";
    radius: 8
    Text{
        color: "#bbb";
        font.pixelSize: 15;
        text: card_info._FName;
    }
    Text{
        color: "#bbb";
        text: "Hi = ";
        font.pixelSize: 15;
    }

}
