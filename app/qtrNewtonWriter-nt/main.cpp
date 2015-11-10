// Version: $Id$
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include <QtConcurrent>
#include <QtCore>
#include <QtDebug>
#include <QtGui>

#include <qtrCore/qtrRenderer.h>
#include <qtrCore/qtrTile.h>

int main(int argc, char **argv)
{
    QCoreApplication application(argc, argv);

    if(application.arguments().count() < 4+1) {
        qDebug() << "Usage:" << argv[0] << "order" << "width" << "height" << "output";
        return 0;
    }

    qtrRenderer::newtonOrder = application.arguments().value(1).toInt();

    qtrTile tile;
    tile.setWholeRect(QRect(0, 0,
        application.arguments().value(2).toInt(),
        application.arguments().value(3).toInt()));
    tile.setTileRect(QRect(0, 0,
        application.arguments().value(2).toInt(),
        application.arguments().value(3).toInt()));

    qtrRenderer::newton(tile);

    tile.image().save(application.arguments().value(4));

    return 0;
}

//
// main.cpp ends here
