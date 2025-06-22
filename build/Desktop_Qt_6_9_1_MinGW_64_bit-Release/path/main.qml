import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls.Fusion
import QtQuick.Controls

import WControl

Window {
    title: qsTr("GraphTest")
    visible: true
    minimumWidth: 1200
    minimumHeight: 550
    maximumWidth: 1200
    maximumHeight: 550
    width: 1200
    height: 600

    property var xpos: []
    property var ypos: []
    property int count: 0
    property int canvasMyPadding: 100
    property bool dataReady: false
    property var path

    WControl {id: wControl}

    Row {
        spacing: 10

        Column {
            spacing: 10
            anchors.leftMargin: 20
            topPadding: 10
            leftPadding: 10

            Button {
                id: selectFileBut
                height: 30
                width: 120
                hoverEnabled: true

                onClicked: wControl.openFileButton()

                background: Rectangle {
                    id: rectSelBut
                    anchors.fill: parent
                    radius: 6
                    border.color: "#2d485b"
                    color: selectFileBut.pressed ? "#9fcffb" :
                           selectFileBut.hovered ? "#bee0ff" : "#d6ebff"

                }
                Text {
                    id: textSelBut
                    text: "Выбрать файл"
                    font.family: "Arial"
                    font.pixelSize: 14

                    anchors.centerIn: parent
                }
            }
            Button {
                id: selectDirBut
                height: 30
                width: 120
                onClicked: wControl.openFolderButton()
                hoverEnabled: true

                background: Rectangle {
                    id: rectSelDirBut
                    anchors.fill: parent
                    border.color: "#2d485b"
                    color: selectDirBut.pressed ? "#9fcffb" :
                           selectDirBut.hovered ? "#bee0ff" : "#d6ebff"
                    radius: 6
                }
                Text {
                    id: selDirBut
                    text: "Выбрать папку"
                    font.family: "Arial"
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }
            }
            Button {
                id: resetBut
                height: 30
                width: 120
                hoverEnabled: true

                background: Rectangle {
                    id: rectResetBut
                    anchors.fill: parent
                    border.color: "#2d485b"
                    color: resetBut.pressed ? "#9fcffb" :
                           resetBut.hovered ? "#bee0ff" : "#d6ebff"
                    radius: 6
                }
                Text {
                    id: resetTextBut
                    text: "Сброс"
                    font.family: "Arial"
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }
                onClicked: {
                    dataReady = false;
                    modelListDir.clear()
                    const context = canvas.getContext("2d");
                    context.clearRect(0, 0, canvas.width, canvas.height);
                    canvas.requestPaint();
                }
            }
            Rectangle {
                width: 120
                height: Math.min(modelListDir.count * 20 + 2, 380)
                border.color: "gray"
                border.width: 1

                ListView {
                    id: listDirEl
                    anchors.fill: parent
                    anchors.margins: 1
                    clip: true
                    focus: true

                    highlight: Rectangle {
                        color: "lightsteelblue"
                    }
                    model: ListModel {
                        id: modelListDir
                    }
                    delegate: Item {
                        width: parent.width
                        height: 20

                        Text {
                            text: name
                            anchors.left: parent.left
                            anchors.leftMargin: 2
                            font.pixelSize: 12
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked:
                            {
                                listDirEl.currentIndex = index
                                wControl.openFile(path + name)
                            }
                        }
                    }
                }
            }
        }
        Column {
            spacing: 10
            anchors.leftMargin: 20
            topPadding: 10

            Rectangle {
                id: graphRect
                width: 1000
                height: 500
                border.color: "black"

                Canvas {
                    id : canvas
                    anchors.fill: parent
                    onPaint: {
                        const context = getContext("2d");
                        context.strokeStyle = 'red';
                        context.lineWidth = 1.5;

                        const minX = Math.min(...xpos);
                        const maxX = Math.max(...xpos);
                        const minY = Math.min(...ypos);
                        const maxY = Math.max(...ypos);

                        function chooseUnitFreq(minVal, maxVal) {
                            const range = maxVal - minVal;
                            if (range >= 1e9) return { dev: 1e9, unit: "GHz" };
                            else if (range >= 1e6) return { dev: 1e6, unit: "MHz" };
                            else if (range >= 1e3) return { dev: 1e3, unit: "kHz" };
                            else return { dev: 1, unit: "Hz" };
                        }

                        context.clearRect(0, 0, width, height);

                        // Drawing the axes
                        context.beginPath();
                        // Axis X
                        context.moveTo(canvasMyPadding / 2, height - canvasMyPadding / 2);
                        context.lineTo(width - canvasMyPadding / 2 + 1, height - canvasMyPadding / 2);
                        // Axis Y
                        context.moveTo(canvasMyPadding / 2, canvasMyPadding / 2 - 1);
                        context.lineTo(canvasMyPadding / 2, height - canvasMyPadding / 2);

                        context.strokeStyle = 'black';
                        context.lineWidth = 2;
                        context.stroke();
                        context.closePath();

                        const { dev: devX, unit: unitX } = chooseUnitFreq(minX, maxX);

                        // Dividing the axis X
                        for (let k = 0; k <= 20; k++) {
                            const xTick = k * ((width - canvasMyPadding) / 20);
                            context.moveTo(xTick + canvasMyPadding / 2, height - canvasMyPadding / 2);
                            context.lineTo(xTick + canvasMyPadding / 2, height - canvasMyPadding / 2 + 5);

                            // Tags X
                            if (dataReady) {
                                if (k % 2 === 0) {
                                    const label = (minX + (maxX - minX) * (k / 20));
                                    context.fillText((label / devX).toFixed(2), xTick + canvasMyPadding / 2 - 10, height - canvasMyPadding / 2 + 20);
                                }
                            }
                        }
                        if (dataReady) context.fillText(unitX, width - canvasMyPadding / 2 + 10, height - canvasMyPadding / 2 + 5);


                        // Dividing the axis Y
                        for (let j = 0; j <= 20; j++) {
                            const yTick = j * ((height - canvasMyPadding) / 20);
                            context.moveTo(canvasMyPadding / 2 - 5, yTick + canvasMyPadding / 2);
                            context.lineTo(canvasMyPadding / 2, yTick + canvasMyPadding / 2);

                            // Tags Y
                            if (dataReady) {
                                if (j % 2 === 0) {
                                    const label = (maxY - (maxY - minY) * (j / 20)).toFixed(2);
                                    context.fillText(label, canvasMyPadding / 2 - 45, yTick + canvasMyPadding / 2 + 5);
                                }
                            }
                        }

                        if (dataReady) context.fillText("dB", canvasMyPadding / 2 - 10, canvasMyPadding / 2 - 10);

                        context.strokeStyle = 'black';
                        context.lineWidth = 1;
                        context.stroke();
                        context.closePath();

                        // Grid X
                        for (let j2 = 0; j2 <= 20; j2++) {
                            const xTick = j2 * ((width - canvasMyPadding) / 20);
                            context.moveTo(xTick + canvasMyPadding / 2, canvasMyPadding / 2);
                            context.lineTo(xTick + canvasMyPadding / 2, height - canvasMyPadding / 2);
                        }
                        context.strokeStyle = 'gray';
                        context.lineWidth = 0.5;
                        context.stroke();
                        context.closePath();

                        // Grid Y
                        for (let j3 = 0; j3 <= 20; j3++) {
                            const YTick = j3 * ((height - canvasMyPadding) / 20);
                            context.moveTo(canvasMyPadding / 2, YTick + canvasMyPadding / 2);
                            context.lineTo(width - canvasMyPadding / 2, YTick + canvasMyPadding / 2);
                        }
                        context.strokeStyle = 'gray';
                        context.lineWidth = 0.5;
                        context.stroke();
                        context.closePath();

                        // Curve
                        if (dataReady) {
                            context.beginPath();
                            for (let i = 0; i < count; i++) {
                                const x = canvasMyPadding / 2 + (xpos[i] - minX) / (maxX - minX) * (width - canvasMyPadding);
                                const y = (height - canvasMyPadding / 2) - (ypos[i] - minY) / (maxY - minY) * (height - canvasMyPadding);

                                context.lineTo(x, y);
                                context.moveTo(x, y);
                            }
                            context.strokeStyle = 'red';
                            context.lineWidth = 1.5;
                            context.stroke();
                            context.closePath();
                        }
                    }
                }
            }
        }
    }
    Connections {
        target: wControl
        function onDataPos(newXpos, newYpos, cnt) {
            xpos = newXpos;
            ypos = newYpos;
            count = cnt
            dataReady = true
            canvas.requestPaint();
        }

        function onListFiles(listFiles, cnt) {
            modelListDir.clear();
            for (var i = 0; i < cnt; i++) {
                var fullPath = listFiles[i];
                var parts = fullPath.split("/");
                var fileName = parts.pop();
                path = parts.join("/") + "/";
                modelListDir.append({ "name": fileName});
            }
        }
    }
}

