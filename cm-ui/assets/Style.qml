pragma Singleton
import QtQuick 2.9

Item {

    readonly property color colourBackground: "#efefef"
    property alias navBar: _navbar
    property alias commandBar: _commandBar
    property alias icons: _icons

    Item {
        id: _navbar
        readonly property color colourNavigationBarBackground: "#000000"
        readonly property color colourNavigationBarIcon: "#ffffff"
        readonly property color colourNavigationBarFont: "#ffffff"

        readonly property alias pixelSizeNavigationBarIcon: _icons.pixelSizeNavigationBarIcon
        readonly property int pixelSizeNavigationBarText: 20
        readonly property real widthNavigationButtonIcon: 80

        readonly property real heightNavigationButtonIcon: widthNavigationButtonIcon
        readonly property real widthNavigationButtonDescription: 160
        readonly property real heightNavigationButtonDescription: heightNavigationButtonIcon
        readonly property real widthNavigationButton: widthNavigationButtonIcon
                                                      + widthNavigationButtonDescription
        readonly property real heightNavigationButton: Math.max(
                                                           heightNavigationButtonIcon,
                                                           heightNavigationButtonDescription)

        readonly property real widthNavigationBarCollapsed: widthNavigationButtonIcon
        readonly property real heightNavigationBarExpanded: widthNavigationButton
    }

    Item {
        id: _commandBar

        readonly property color colourBackground: "#cecece"
        readonly property color colourFont: "#131313"
        readonly property color colourFontDisabled: "#636363"

        readonly property real widthButton: 80
        readonly property real heightButtom: widthButton
        readonly property real heightCommandBar: heightButtom

        readonly property int pixelSizeIcon: 32
        readonly property int pixelSizeText: 12
    }

    Item {
        id: _icons
        property alias name: fontIconsLoader.name
        property bool useMdiFont: true

        property int pixelSizeNavigationBarIcon: useMdiFont ? 48 : 42

        FontLoader {
            id: fontIconsLoader
            source: _icons.useMdiFont ? "qrc:/assets/materialdesignicons.ttf" : "qrc:/assets/fontawesome.otf"
        }

        readonly property string i_menu: useMdiFont ? "\uf35c" : "\uf0c9"
        readonly property string i_menu_open: useMdiFont ? "\ufb87" : "\uf0c9"
        readonly property string i_dashboard: useMdiFont ? "\uf56e" : "\uf015"
        readonly property string i_newclient: useMdiFont ? "\uf014" : "\uf234"
        readonly property string i_search: useMdiFont ? "\uf016" : "\uf002"
        readonly property string i_settings: useMdiFont ? "\uf493" : "\uf013"

    }
}
