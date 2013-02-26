import QtQuick 2.0

Item {
    id : gauge

    width: 200;
    height: 200;

    property int value;
    property int value_min;
    property int value_max;
    property string caption;

    Item {
        width: 200;
        height: 200;

        anchors.centerIn: parent;        

        Image {
            id: background;
            source: "qtrGauge_background.png";
        }

        Image {
            x: 97.5;
            y: 20;

            source: "qtrGauge_needle.png"
            
            transform: Rotation {
                origin.x: 2.5;
                origin.y: 80;

                angle: (gauge.value / gauge.value_max-gauge.value_min) * 180 - 90;

                Behavior on angle {
                    SpringAnimation {
                        spring: 2;
                        damping: 0.2;
                    }
                }
            }
        }
        
        Image {
          anchors.centerIn: background;
          source: "qtrGauge_center.png";
        }

        Text {
            id: gauge_min_value;

            x: 50;
            y: 100 - 8;

            text: gauge.value_min;
            color: "gray";
        }

        Text {
            id: gauge_max_value;

            x: 150 - contentWidth;
            y: 100 - 8;

            text: gauge.value_max;
            color: "gray";
        }

        Text {
            text: gauge.caption;
            color: "#555555";

            anchors {
                horizontalCenter: background.horizontalCenter;
                  verticalCenter: background.verticalCenter;
                  verticalCenterOffset: 30;
            }

            font {
                family: "Menlo";
                pointSize: 13;
                weight: Font.Bold;
            }

            style: Text.Sunken;
            styleColor: "#000000";
        }
    }
}
