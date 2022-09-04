import QtQuick
import QtQuick.Controls
import QtQuick3D
import QtQuick.Layouts
import QtQuick.Controls.Material
//import QtQuick.Dialogs
import QtQuick.Dialogs 1.3

Window {
    id: window
    width: 640
    height: 482
    visible: true
    color: "#be3e3737"
    title: qsTr("V3D")
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    Material.background: Material.Dark


    MenuBar {
        Menu {
            title: qsTr("&File")
            Action {
                text: qsTr("&Open...")
                onTriggered: fileDialog.open()
            }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action {
                text: qsTr("&Quit");
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("&BackGround")
            Action {
                text: qsTr("&Background color")
                onTriggered: colorDialog.open()
            }
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
        bottomPadding: 0
        rightPadding: 0
        leftPadding: 0
        Column {
            ToolButton {
                width: 30
                height: 30
                Image {
                    anchors.fill: parent
                    source: "misc/3d-cube.png"
                }
                onClicked: {
                    slider.visible = !slider.visible
                    grid2.visible = false
                    grid.visible = false
                }
                Slider {
                    anchors.right: parent.left
                    anchors.bottom: parent.bottom
                    id: slider
                    visible: false
                    value: 0.5
                    x: -96
                    y: 1
                }
            }

            ToolButton {
                width: 30
                height: 30
                Image {
                    anchors.fill: parent
                    source: "misc/rotate.png"
                }
                onClicked: {
                    grid2.visible = !grid2.visible
                    grid.visible = false
                    slider.visible = false
                }
                GridLayout {
                    id: grid2
                    visible:false
                    anchors.bottom: parent.bottom
                    rowSpacing: 0
                    columnSpacing: 0
                    anchors.right: parent.left
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
                width: 30
                height: 30
                Image {
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
                    columnSpacing: 0
                    anchors.bottom: parent.bottom
                    anchors.right: parent.left
                    Button {
                        id: buttonLeft
                        x: 0
                        y: 0
                        Layout.rightMargin: 6
                        topInset: 0
                        bottomInset: 0
                        padding: 0
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.rowSpan: 2
                        Layout.column: 0
                        autoRepeat: true
                        Image {
                            anchors.fill: parent
                            scale: 0.5
                            source: "misc/arrow.png"
                            rotation: 180
                        }
                        Shortcut {
                            sequences: ["a", StandardKey.Left]
                            onActivated: buttonLeft.clicked()
                        }
                    }
                    Button {
                        id: buttonForward
                        x: 0
                        y: 0
                        Layout.bottomMargin: 6
                        bottomInset: 0
                        padding: 0
                        topPadding: 0
                        bottomPadding: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 0
                        Layout.column: 1
                        Layout.preferredHeight: 50
                        autoRepeat: true
                        Shortcut {
                            sequences: ["w", StandardKey.Forward]
                            onActivated: buttonForward.clicked()

                        }
                        Image {
                            anchors.fill: parent
                            scale: 0.5
                            source: "misc/arrow.png"
                            rotation: 270
                        }
                    }
                    Button {
                        id: buttonRight
                        x: 0
                        y: 0
                        Layout.leftMargin: 6
                        bottomInset: 0
                        topInset: 0
                        padding: 0
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.rowSpan: 2
                        Layout.column: 2
                        autoRepeat: true
                        Shortcut {
                            sequences: ["d", StandardKey.Right]
                            onActivated: buttonRight.clicked()

                        }
                        Image {
                            anchors.fill: parent
                            scale: 0.5
                            source: "misc/arrow.png"
                        }
                    }
                    Button {
                        id: buttonUp
                        x: 0
                        y: 0
                        Layout.preferredHeight: 25
                        Layout.fillWidth: true
                        Layout.row: 1
                        Layout.column: 1
                        text: qsTr("up")
                        font.pointSize: 10
                        Layout.bottomMargin: 3
                        topInset: 0
                        bottomInset: 0
                        padding: 0
                        verticalPadding: 0
                        topPadding: 0
                        bottomPadding: 0
                        autoRepeat: true
                        Shortcut {
                            sequences: ["e", StandardKey.Space]
                            onActivated: buttonUp.clicked()

                        }
                    }
                    Button {
                        id: buttonDown
                        x: 0
                        y: 0
                        Layout.preferredHeight: 25
                        visible: true
                        Layout.fillWidth: true
                        Layout.row: 2
                        Layout.column: 1
                        text: qsTr("down")
                        font.pointSize: 10
                        rightPadding: 0
                        leftPadding: 0
                        bottomInset: 0
                        spacing: 0
                        topInset: 0
                        padding: 0
                        topPadding: 0
                        autoRepeat: true
                        Shortcut {
                            sequences: ["f", StandardKey.Ctrl]
                            onActivated: buttonDown.clicked()
                        }
                    }
                    Button {
                        id: buttonBack
                        Layout.topMargin: 6
                        topInset: 0
                        padding: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.row: 3
                        Layout.column: 1
                        Layout.preferredHeight: 50
                        Image {
                            anchors.fill: parent
                            scale: 0.5
                            source: "misc/arrow.png"
                            rotation: 90
                        }
                        Shortcut {
                            sequences: ["s", StandardKey.Back]
                            onActivated: buttonBack.clicked()
                        }
                        autoRepeat: true
                    }
                }
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: [ "Object files (*.obj)", "All files (*)" ]
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)

        }
        onRejected: {
            console.log("Canceled")
            console.log("You version: " + QtQuick.Dialogs.version);
        }
    }

//    ColorDialog {
//        id: colorDialog
//        title: "Please choose a color"
//        onAccepted: {
//            console.log("You chose: " + colorDialog.color)
//        }
//        onRejected: {
//            console.log("Canceled")
//        }
//    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}
}
##^##*/
