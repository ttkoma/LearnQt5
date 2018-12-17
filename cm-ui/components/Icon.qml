import QtQuick 2.9
import QtGraphicalEffects 1.0

Item {
    id:container
    property color color: "teal"
    property string iconName: "image.svg"
    property alias imageSource: img.source
    property alias imageSize: img.sourceSize

    width: parent.width
    height: parent.height
    antialiasing: true
    smooth: true
    //anchors.centerIn: parent
    Image {
        id: img
        anchors.centerIn: parent
        //sourceSize: Qt.size(24, 24)
        visible: false
        source: "qrc:/icons/"+container.iconName
    }
    ColorOverlay {
        anchors.fill: img
        source: img
        color: container.color
        antialiasing: container.antialiasing
        smooth: container.smooth
    }
}
