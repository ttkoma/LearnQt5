import QtQuick 2.9
import assets 1.0

Item {
    objectName: "findClientView"
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground

        Text {
            anchors.centerIn: parent
            text: qsTr("FindClient View")
        }
    }
}
