import QtQuick 2.9
import CM 1.0
import assets 1.0

Item {

    property Command command

    width: Style.commandBar.widthButton
    height: Style.commandBar.heightButtom

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.commandBar.colourBackground
        Text {
            id: iconText
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -10
            text: command.ui_iconCharacter
            font {
                family: Style.fontawesome
                pixelSize: Style.commandBar.pixelSizeIcon
            }
            color: command.ui_canExecute ? Style.commandBar.colourFont : Style.commandBar.colourFontDisabled
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: descriptionText
            anchors {
                left: parent.left
                right: parent.right
                top: iconText.bottom
                bottom: parent.bottom
            }
            font.pixelSize: Style.commandBar.pixelSizeText
            text: command.ui_description
            color: command.ui_canExecute ? Style.commandBar.colourFont : Style.commandBar.colourFontDisabled
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: if (command.ui_canExecute) {
                           command.executed()
                       }
        }

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: Qt.darker(Style.commandBar.colourBackground)
                }
            }
        ]
    }
}
