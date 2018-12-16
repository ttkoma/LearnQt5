import QtQuick 2.9
import QtQuick.Controls 2.4
import assets 1.0

Item {
    objectName: "settingsView"
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground

        Text {
            anchors.centerIn: parent
            text: qsTr("Settings View")
        }
        Button {
            anchors.centerIn: parent
            anchors.verticalCenterOffset: 50
            text: "Toggle icon style\r\n"+
                  "Current: "+Style.icons.name
            onClicked: {
                Style.icons.useMdiFont = !Style.icons.useMdiFont
            }
        }
    }
}
