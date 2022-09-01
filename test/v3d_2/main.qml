import QtQuick
import QtQuick.Controls
import QtQuick3D 6.2
import QtQuick.Layouts

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "#bea29999"
    title: qsTr("V3D")
    MenuBar {
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Add...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&BackGround")
            Action { text: qsTr("&Background color") }
            Action { text: qsTr("&Light") }
        }
        Menu {
            title: qsTr("&Model")
            Action { text: qsTr("&Dots") }
            Action { text: qsTr("&Edges") }
            Action { text: qsTr("&Textures") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    ToolBar {
        id: toolBar
        x: 0
        y: 52
        width: maximumWidth
        height: 28

        ToolButton {
            id: toolButtonMove
            x: 0
            y: 0
            text: qsTr("Перемещение")
            onClicked: {
                grid.visible = !grid.visible
                grid2.visible = false;
                slider.visible = false;
            }
            GridLayout {
                id: grid
                x: 0
                y: 50
                width: 200
                height: 200
                columns: 3
                rows: 3
                visible: true

                Button {
                        id: buttonLeft
                        x: 0
                        y: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.column: 0
                        text: qsTr("<-")
                }
                Button {
                        id: buttonForward
                        x: 0
                        y: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 0
                        Layout.column: 1
                        text: qsTr("^")
                }
                Button {
                        id: buttonRight
                        x: 0
                        y: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.column: 2
                        text: qsTr("->")
                }
                Button {
                        id: buttonUp
                        x: 0
                        y: 0
//                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.column: 1
                        text: qsTr("u")
                }
                Button {
                        id: buttonDown
                        x: 0
                        y: 0
//                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.column: 1
                        text: qsTr("d")
                }
                Button {
                        id: buttonBack
                        x: 0
                        y: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 2
                        Layout.column: 1
                        text: qsTr("|")
                }
            }
        }
        ToolButton {
            id: toolButtonRotate
            x: 108
            y: 0
            text: qsTr("Вращение")
            onClicked: {
                grid2.visible = !grid2.visible
                grid.visible = false
                slider.visible = false
            }
            Grid {
                id: grid2
                x: 0
                y: 50
                width: minimumHeight
                height: minimumHeight
                visible:false
                Dial {
                    id: dial
                    x: 0
                    y: 0
                }
                Dial {
                    id: dial1
                    x: 70
                    y: 0
                }
                Dial {
                    id: dial2
                    x: 140
                    y: 0
                }
            }
        }
        ToolButton {
            id: toolButtonScale
            x: 190
            y: 0
            text: qsTr("Размер")
            onClicked: {
                slider.visible = !slider.visible
                grid2.visible = false
                grid.visible = false
            }
            Slider {
                id: slider
                visible: false
                value: 0.5
                x: 0
                y: 50
            }

        }
    }
}
