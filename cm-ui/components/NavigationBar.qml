import QtQuick 2.9
import assets 1.0

Item {
    property bool isCollapsed: true

    width: isCollapsed ? Style.navBar.widthNavigationBarCollapsed : Style.navBar.heightNavigationBarExpanded
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
            height: parent.height
            NavigationButton {
                iconCharacters: isCollapsed ? Style.icons.i_menu : Style.icons.i_menu_open
                description: isCollapsed ? "" : "MENU"
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacters: Style.icons.i_dashboard
                description: "Dashboard"
                hoverColour: "#dc8a00"
                onNavigationButtonClicked: masterController.ui_navigationController.goDashBoardView()
            }
            NavigationButton {
                iconCharacters: Style.icons.i_newclient
                description: "New Client"
                hoverColour: "#dccd00"
                onNavigationButtonClicked: masterController.ui_navigationController.goCreateClientView()
            }
            NavigationButton {
                iconCharacters: Style.icons.i_search
                description: "Find Client"
                hoverColour: "#8aef63"
                onNavigationButtonClicked: masterController.ui_navigationController.goFindClientView()
            }
            Item {
                id: expander
                height: parent.height - (parent.children.length-1)*Style.navBar.heightNavigationButton
                width: 1
            }
            NavigationButton {
                iconCharacters: Style.icons.i_settings
                description: "Settings"
                hoverColour: "#993333"
                onNavigationButtonClicked: masterController.ui_navigationController.goSettingsView()
            }
        }
    }
}
