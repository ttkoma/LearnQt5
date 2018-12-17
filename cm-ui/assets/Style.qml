pragma Singleton
import QtQuick 2.9

Item {

    readonly property color colourBackground: "#efefef"
    property alias navBar: navbar
    property alias commandBar: _commandBar

    Item {
        id: navbar
        readonly property color colourNavigationBarBackground: "#000000"
        readonly property color colourNavigationBarIcon: "#ffffff"
        readonly property color colourNavigationBarFont: "#ffffff"

        readonly property int pixelSizeNavigationBarIcon: 36
        readonly property int pixelSizeNavigationBarText: 22
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

    property alias fontawesome: fontAwesomeLoader.name

    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.otf"
    }
}
