import QtQuick 2.9
import assets 1.0

Item {
    objectName: "createClientView"
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground

        Text {
            anchors.centerIn: parent
            text: qsTr("CreateClient View")
        }
    }
}

