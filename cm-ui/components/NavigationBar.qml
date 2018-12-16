import QtQuick 2.9
import assets 1.0

Item {
    property bool isCollapsed: true

    width: isCollapsed ? Style.navBar.widthNavigationBarCollapsed : Style.navBar.heightNavigationBarExpanded
    //clip: true
    anchors {
        left: parent.left
        top: parent.top
        bottom: parent.bottom
    }

    Rectangle {
        id: navigationBar

        anchors.fill: parent
        color: Style.navBar.colourNavigationBarBackground

        Column {
            width: parent.width

            NavigationButton {
                iconCharacters: "\uf0c9"
                description: isCollapsed ? "" : "MENU"
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacters: "\uf015"
                description: "Dashboard"
                hoverColour: "#dc8a00"
                onNavigationButtonClicked: masterController.ui_navigationController.goDashBoardView()
            }
            NavigationButton {
                iconCharacters: "\uf234"
                description: "New Client"
                hoverColour: "#dccd00"
                onNavigationButtonClicked: masterController.ui_navigationController.goCreateClientView()
            }
            NavigationButton {
                iconCharacters: "\uf002"
                description: "Find Client"
                hoverColour: "#8aef63"
                onNavigationButtonClicked: masterController.ui_navigationController.goFindClientView()
            }
        }
    }
}
