/* main.cpp --- 
 * 
 * Author: Julien Wintz
 * Created: Mon Jan 28 12:15:05 2013 (+0100)
 * Version: 
 * Last-Updated: Wed Feb 27 16:28:50 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 87
 */

/* Change Log:
 * 
 */

#include <qtrCore>
#include <qtrQuick>
#include <qtrQuickConfig>

#include <QtCore>
#include <QtGui>
#include <QtQuick>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);

    if(application.arguments().count() < 1+1) {
        qDebug() << "Usage:" << argv[0] << "order";
        return 0;
    }

// ///////////////////////////////////////////////////////////////////
// Setup qtrRenderer
// ///////////////////////////////////////////////////////////////////

    qtrRenderer::newtonOrder = application.arguments().value(1).toInt();

// ///////////////////////////////////////////////////////////////////
// Let's go
// ///////////////////////////////////////////////////////////////////

    QQuickView view;
    view.engine()->addImportPath(qtrQuickImportPath);
    view.setColor(Qt::black);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:main.qml"));
    view.setTitle("Newton fractal tracer");
    view.show();

    return application.exec();
}
