import QtQuick 2.9
import assets 1.0

Item {
    property alias iconCharacters: textIcon.text
    property alias description: textDescription.text

    signal navigationButtonClicked

    property color hoverColour: Style.navBar.colourNavigationBarBackground

    width: parent.width
    height: Style.navBar.heightNavigationButton

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.navBar.colourNavigationBarBackground

        Row {
            Text {
                id: textIcon
                width: Style.navBar.widthNavigationButtonIcon
                height: Style.navBar.heightNavigationButtonIcon
                color: Style.navBar.colourNavigationBarIcon
                font {
                    family: Style.icons.name
                    pixelSize: Style.navBar.pixelSizeNavigationBarIcon
                }
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: "\uf11a"

            }
            Text {
                id: textDescription
                width: Style.navBar.widthNavigationButtonDescription
                height: Style.navBar.heightNavigationButtonDescription
                color: Style.navBar.colourNavigationBarFont
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Style.navBar.pixelSizeNavigationBarText

                text: "SET ME!"
            }
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor

            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: navigationButtonClicked()
        }

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: hoverColour
                }
            }
        ]
    }
}
