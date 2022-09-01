import QtQuick
import QtQuick.Controls
import QtQuick3D
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
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 30
        height: 90

        //        height:minimumWidth
        //        position: ToolBar.Footer

        Column {
            id: column
            width: maximumWidth
            height: maximumHeight

            ToolButton {
                id: toolButtonScale
                width: 30
                height: 30
                Image {
                    id: scaleIMG
                    anchors.fill: parent
                    source: "misc/3d-cube.png"
                }
                onClicked: {
                    slider.visible = !slider.visible
                    grid2.visible = false
                    grid.visible = false
                }
                Slider {
                    id: slider
                    visible: false
                    value: 0.5
                    x: -96
                    y: 1


                }

            }

            ToolButton {
                id: toolButtonRotate
                width: 30
                height: 30
                Image {
                    id: rotateIMG
                    anchors.fill: parent
                    source: "misc/rotate.png"
                }
                onClicked: {
                    grid2.visible = !grid2.visible
                    grid.visible = false
                    slider.visible = false
                }
                Grid {
                    id: grid2
                    x: -206
                    y: -10
                    width: 200
                    height: 50
                    visible:false
                    anchors.bottom: parent.bottom
                    anchors.rightMargin: 6
                    anchors.bottomMargin: -10
                    anchors.right: parent.parent.left
                    Dial {
                        id: dial
                        x: 0
                        y: 0
                    }
                    Dial {
                        id: dial1
                        x: 0
                        y: 0
                    }
                    Dial {
                        id: dial2
                        x: 0
                        y: 0
                    }
                }
            }

            ToolButton {
                id: toolButtonMove
                width: 30
                height: 30
                bottomPadding: 0
                topPadding: 0
                rightPadding: 0
                leftPadding: 0
                Image {
                    id: moveIMG
                    anchors.fill: parent
                    source: "misc/vectors.png"
                }
                onClicked: {
                    grid.visible = !grid.visible
                    grid2.visible = false;
                    slider.visible = false;
                }
                GridLayout {
                    id: grid
                    width: 150
                    height: 150
                    columns: 3
                    rows: 4
                    visible: false
                    rowSpacing: 0
                    x: -156
                    y: -120
                    anchors.bottom: parent.bottom
                    anchors.rightMargin: 36
                    anchors.bottomMargin: 0
                    anchors.right: parent.right
                    Button {
                        id: buttonLeft
                        x: 0
                        y: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.rowSpan: 2
                        Layout.column: 0
                        text: qsTr("<-")
                        rightPadding: 0
                        leftPadding: 0
                        //                        shortcut: "Right"
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
                        Layout.rowSpan: 2
                        Layout.column: 2
                        text: qsTr("->")
                    }
                    Button {
                        id: buttonUp
                        x: 0
                        y: 0
                        height: 25
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.column: 1
                        text: qsTr("u")
                    }
                    Button {
                        id: buttonDown
                        x: 0
                        y: 0
                        height: 25
                        Layout.fillWidth: true
                        Layout.row: 2
                        Layout.column: 1
                        text: qsTr("d")
                    }
                    Button {
                        id: buttonBack
                        x: 0
                        y: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 3
                        Layout.column: 1
                        text: qsTr("|")
                    }
                }
            }
        }
    }
}
