/* main.qml --- 
;; 
;; Author: Julien Wintz
;; Created: Mon Jan 28 22:26:27 2013 (+0100)
;; Version: 
;; Last-Updated: Tue Feb 26 11:05:20 2013 (+0100)
;;           By: Julien Wintz
;;     Update #: 120
*/

/* Change Log:
;; 
*/

import  QtQuick 2.0
import QtrQuick 1.0

Item {

    width: 800;
    height: 360;
    
    QtrCanvas {
        id: canvas;
        
        anchors.centerIn: parent;
        anchors.fill: parent;

        onCurNumberOfThreadsChanged: {
            thread_gauge.value = canvas.curNumberOfThreads;
        }

        onMinProgressValueChanged: {
            progress_gauge.value_min = canvas.minProgressValue;
        }

        onMaxProgressValueChanged: {
            progress_gauge.value_max = canvas.maxProgressValue;
        }

        onCurProgressValueChanged: {
            progress_gauge.value = canvas.curProgressValue;
        }
    }

    QtrGauge {
        id: thread_gauge;
        
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;

        value: 0;
        value_min: 0;
        value_max: canvas.maxNumberOfThreads;

        caption: "Thead usage";

        MouseArea {
            anchors.fill: parent;
            
            onClicked: {
                canvas.newtonOrder = canvas.newtonOrder + 1;
            }

            onDoubleClicked: {
                canvas.newtonOrder = 2;
            }
        }
    }

    QtrGauge {
        id: progress_gauge;

        value: 0;
        value_min: 0;
        value_max: 100;

        caption: "Progress";

        anchors.right: thread_gauge.left;
        anchors.bottom: parent.bottom;
    }
}
