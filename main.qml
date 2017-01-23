import QtQuick 2.5
import QtQuick.Controls 1.1
import QtQuick.Window 2.2
import QtMultimedia 5.5

Rectangle{
    id: root
    color: "black"
    width: Screen.width
    height: Screen.height
//    width: 1920
//    height: 1080
    property int kkchose: 0;
    property int kkctx: 0;
    property int marge: 100
    property int bsize: 150
    property bool server_dist: false




    /////////////////////////////////////////////////////////////////////////////////// VIDEO /////////////////////////////////////////////////////////////////////////////////////////
    Image {
        id: player
        anchors.centerIn: parent
        source: "image://myprovider/"+ kkchose
    }
    /////////////////////////////////////////////////////////////////////////////////// VIDEO /////////////////////////////////////////////////////////////////////////////////////////



    /////////////////////////////////////////////////////////////////////////////////// CANVAS /////////////////////////////////////////////////////////////////////////////////////////
    Canvas {
        id: canvas
        visible: false
        anchors.fill: parent
       // scale: 3
        property real lastX
        property real lastY
        property color color: "red"
        property int clear: 0
        //property var ctx: getContext('2d')

        onPaint: {
            var ctx = getContext('2d')
            ctx.lineWidth = 2.0
            ctx.strokeStyle = canvas.color
            ctx.beginPath()
            ctx.moveTo(lastX, lastY)
            lastX = area.mouseX
            lastY = area.mouseY
            ctx.lineTo(lastX, lastY)
            ctx.stroke()
        }
        MouseArea {
            id: area
            anchors.fill: parent
            onPressed: {
                canvas.lastX = mouseX
                canvas.lastY = mouseY
            }
            onPositionChanged: {
                canvas.requestPaint()
            }
        }
    }

    Image {
        id: ctx
        visible: false
        anchors.centerIn: parent
        source: "image://myctxprovider/"+ kkctx
    }

    Button{
        id:croix
        opacity:canvas.visible == true?0.7:0
        Behavior on opacity {
            NumberAnimation { duration: 1000 }
        }
        anchors.top:  parent.top
        anchors.left: parent.left
        anchors.topMargin: width/3
        anchors.leftMargin: width/2
        width: bsize
        height: bsize
        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            source: "qrc:/images/croix.png"
        }
        onClicked: {
            var contexte = canvas.getContext("2d")
            contexte.reset()
            canvas.requestPaint()
        }
    }

    Button{
        id: valid
        opacity: canvas.visible == true?0.7:0
        Behavior on opacity {
            NumberAnimation { duration: 1000 }
        }
        anchors.top:  parent.top
        anchors.right: parent.right
        anchors.topMargin: width/3
        anchors.rightMargin: width/2
        width: bsize
        height: bsize
        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            source: "qrc:/images/valid.png"
        }
        onClicked: {
            canvas.save("file:image.png")
//            myctxclient.connectTcp();
//            myctxclient.setData();
        }
    }

    //    Button{
    //        x: parent.width/2-width/2
    //        width: 50
    //        height: 50
    //        onClicked: {
    //            Qt.quit()
    //        }
    //    }


    Button
    {
        id: graph
        anchors.bottom:  parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: marge
        anchors.leftMargin: width + 40
        width: bsize
        height: bsize
        style: Rectangle{
        }

        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            opacity: canvas.visible == true?1:0.3
            Behavior on opacity {
                NumberAnimation { duration: 500 }
            }
            source: "qrc:/images/pencil.png"
        }
        onClicked: {
            //canvas.loadImage("image://myprovider/"+kkchose);
            if (canvas.visible == false){
                canvas.visible = true;
                stop.clicked();
                var contexte = canvas.getContext("2d");
                contexte.drawImage("image://myprovider/"+kkchose, 0, 0);
                canvas.requestPaint();

            }
            else
            {
                canvas.visible = false;
                play.clicked();
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////////// CANVAS/////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////PLAY AND PAUSE////////////////////////////////////////////////////////////////////////////
    Button
    {
        id: stop
        anchors.bottom:  parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: marge
        anchors.leftMargin: parent.width/2 - 3*width/2 - 30
        width: bsize
        height: bsize
        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            source: "qrc:/images/pause.png"
        }
        onClicked: {
            capture.stop();
        }
    }

    Button
    {
        id: play
        //anchors.centerIn: parent
        anchors.bottom:  parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: marge
        anchors.leftMargin: parent.width/2 + width/2 + 30
        width: bsize
        height: bsize

        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            source: "qrc:/images/play.png"
        }
        onClicked: {
           capture.start();
        }
    }

    /////////////////////////////////////////////////////////////////////PLAY AND PAUSE////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////////////////////////////////// RECORDER /////////////////////////////////////////////////////////////////////////////////////////
    Button
    {
        id: record
        anchors.bottom:  parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: marge
        anchors.leftMargin: parent.width/2-width/2
        width: bsize
        height: bsize
        property bool recording: false
        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            id:recordimg
            anchors.fill: parent
            opacity: record.recording == false?0.3:0.8
            Behavior on opacity {
                NumberAnimation { duration: 500 }
            }
            source: "qrc:/images/record-normal.png"
        }
        onClicked: {
            myservo.connectTcp();
            myservo.setData("RECORD")
            if (recording == false){
                recording = true;
            }
            else{
                recording = false;
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////////// RECORDER/////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////////////////////////////////// SERVER /////////////////////////////////////////////////////////////////////////////////////////

    Button
    {
        id: server
        //visible: false
        anchors.bottom:  parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: marge
        anchors.leftMargin: 20
        width: bsize
        height: bsize
        property bool running: false
        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            id:serverimg
            anchors.fill: parent
            opacity: server.running == false?0.3:1
            Behavior on opacity {
                NumberAnimation { duration: 500 }
            }
            source: "qrc:/images/cloud.png"
        }
        onClicked: {
            if (running == false){
                myserver.runServerTcp()
                running = true;
            }
            //            else{
            //                running = false;
            //            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////////// SERVER /////////////////////////////////////////////////////////////////////////////////////////



    /////////////////////////////////////////////////////////////////////////////////// COMMAND/////////////////////////////////////////////////////////////////////////////////////////
    Button
    {
        id: up
        anchors.bottom:  parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: marge + height + 20
        anchors.rightMargin: width + 40
        width: bsize
        height: bsize

        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            opacity:up.hovered == true?1:0.3
            source: "qrc:/images/up.png"
        }
        onPressedChanged:{
            if(pressed == true){
                timer1.running = true;
            }
            else {
                timer1.running=false;
            }
        }
    }
    Button
    {
        id: down
        anchors.bottom:  parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: marge
        anchors.rightMargin: width + 40
        width: bsize
        height: bsize

        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            anchors.fill: parent
            opacity:down.hovered == true?1: 0.3
            source: "qrc:/images/down.png"
        }
        onPressedChanged:{
            if(pressed == true){
                timer2.running = true;
            }
            else {
                timer2.running=false;
            }
        }
    }


//    Button
//    {
//        id: right_b
//        anchors.bottom:  parent.bottom
//        anchors.right: parent.right
//        anchors.bottomMargin: marge+ height/2 + 10
//        anchors.rightMargin: 20
//        width: bsize
//        height: bsize

//        style: Rectangle{
//        }
//        Rectangle{
//            anchors.fill: parent
//            color: "transparent"
//            opacity: 0.3
//            border.width: 2
//            border.color: "gray"
//        }
//        Image{
//            anchors.fill: parent
//            opacity:0.3
//            source: "qrc:/images/right.png"
//        }
//        onPressedChanged:{
//        }
//    }

//    Button
//    {
//        id: left_b
//        anchors.bottom:  parent.bottom
//        anchors.right: parent.right
//        anchors.bottomMargin: marge+ height/2 + 10
//        anchors.rightMargin: 2*width + 60
//        width: bsize
//        height: bsize

//        style: Rectangle{
//        }
//        Rectangle{
//            anchors.fill: parent
//            color: "transparent"
//            opacity: 0.3
//            border.width: 2
//            border.color: "gray"
//        }
//        Image{
//            anchors.fill: parent
//            opacity:0.3
//            source: "qrc:/images/left.png"
//        }
//        onPressedChanged:{
//        }
//    }
    /////////////////////////////////////////////////////////////////////////////////// COMMAND /////////////////////////////////////////////////////////////////////////////////////////







    /////////////////////////////////////////////////////////////////////////////////// GALERIES ///////////////////////////////////////////////////////////////////////////////////////////////

    Button
    {
        id: galery
        anchors.bottom:  parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: marge
        anchors.leftMargin: 2*width + 60
        width: bsize
        height: bsize
        property bool opened: false
        style: Rectangle{
        }
        Rectangle{
            anchors.fill: parent
            color: "transparent"
            opacity: 0.3
            border.width: 2
            border.color: "gray"
        }
        Image{
            id:galeryimg
            anchors.fill: parent
            opacity: galery.opened == false?0.3:1
            Behavior on opacity {
                NumberAnimation { duration: 500 }
            }
            source: "qrc:/images/picture.png"
        }
        onClicked: {
            ctx.visible = !ctx.visible;
            opened = !opened;
        }
    }

    /////////////////////////////////////////////////////////////////////////////////// GALERIES ////////////////////////////////////////////////////////////////////////////////////////////





    /////////////////////////////////////////////////////////////////////////////////// TIMERS /////////////////////////////////////////////////////////////////////////////////////////

    Timer
    {
        id: timer1
        interval: 100
        repeat: true
        running: false
        onTriggered: {
//            move.setPanTiltY(config.getPanTiltYRangeMaxFloat());
//             ptz.continuousMove(move);
        }
    }


    Timer
    {
        id: timer2
        interval: 100
        repeat: true
        running: false
        onTriggered: {
//            move.setPanTiltY(config.getPanTiltYRangeMinFloat());
//            ptz.continuousMove(move);
        }
    }



    /////////////////////////////////////////////////////////////////////////////////// TIMERS /////////////////////////////////////////////////////////////////////////////////////////



    MouseArea{
        anchors.fill:parent
        hoverEnabled: true
        onDoubleClicked: {
            //player.videoCapture.capture();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////// CONNECTIONS /////////////////////////////////////////////////////////////////////////////////////////

    Connections{
        target: myctxprovider
        onNewImageReceive :{
            kkctx = kkctx+1;
        }
    }

    Connections{
        target: myprovider
        onNewImageReceive :{
            kkchose = kkchose+1;
        }
    }

    Connections{
        target: myserver
        onDataChanged :{
            if (myserver.data_string == "RECORD"){
                record.clicked();
            }
            else if (myserver.data_string == "SERVER"){

            }
        }
    }

}
