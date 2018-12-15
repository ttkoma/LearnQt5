import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import CM 1.0

Window {
    id:contentContainer
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Management")

    Connections {
        target: masterController.ui_navigationController
        onGoCreateClientView: contentFrame.replace(Qt.resolvedUrl("CreateClientView.qml"));
        onGoDashBoardView:  contentFrame.replace(Qt.resolvedUrl("DashBoardView.qml"));
        onGoFindClientView: contentFrame.replace(Qt.resolvedUrl("FindClientView.qml"));
        onGoEditClientView: contentFrame.replace(Qt.resolvedUrl("EditClientView.qml", {selectedClient: client}));
    }

    Rectangle {
        id: navigationBar
        width: 100
        color: "#000000"
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
    }

    StackView {
        id: contentFrame
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
