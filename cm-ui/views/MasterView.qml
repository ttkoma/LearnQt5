import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import CM 1.0
import assets 1.0
import components 1.0

ApplicationWindow {
    id: contentContainer
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Management - " + "Qt " + QtQmlVersion)

    Connections {
        target: masterController.ui_navigationController
        onGoCreateClientView: contentFrame.replace(Qt.resolvedUrl(
                                                       "CreateClientView.qml"))
        onGoDashBoardView: contentFrame.replace(Qt.resolvedUrl(
                                                    "DashBoardView.qml"))
        onGoFindClientView: contentFrame.replace(Qt.resolvedUrl(
                                                     "FindClientView.qml"))
        onGoEditClientView: contentFrame.replace(Qt.resolvedUrl(
                                                     "EditClientView.qml", {
                                                         "selectedClient": client
                                                     }))
    }

    NavigationBar {
        id: navigationBar
    }

    StackView {
        id: contentFrame
        clip: true
        anchors {
            left: navigationBar.right
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
    }

    Component.onCompleted: {
        contentFrame.replace(Qt.resolvedUrl("DashBoardView.qml"))
    }
}
