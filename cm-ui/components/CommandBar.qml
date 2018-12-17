import QtQuick 2.9
import assets 1.0
Item {

    property alias listCommand: commandRepeater.model

    width: parent.width
    height: Style.commandBar.heightCommandBar
    anchors {
        left: parent.left
        right: parent.right
        bottom: parent.bottom
    }

    Rectangle {
        anchors.fill: parent
        color: Style.commandBar.colourBackground
        Row {
            anchors {
                top: parent.top
                bottom: parent.bottom
                right: parent.right
            }

            Repeater {
                id: commandRepeater
                delegate: CommandButton {
                    command: modelData
                }
            }

        }
    }
}
