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
#include <qtrCore/qtrTiler.h>

int main(int argc, char **argv)
{
    QCoreApplication application(argc, argv);

    if(application.arguments().count() < 4+1) {
        qDebug() << "Usage:" << argv[0] << "order" << "width" << "height" << "output";
        return 0;
    }

// /////////////////////////////////////////////////////////////////
// Multiple concurrent run preprocessing
// /////////////////////////////////////////////////////////////////

    qtrRenderer::newtonOrder = application.arguments().value(1).toInt();

    qtrTiler tiler;
    tiler.setWholeSize(QSize(
        application.arguments().value(2).toInt(),
        application.arguments().value(3).toInt()));
    tiler.setResolutionX(QThread::idealThreadCount());
    tiler.setResolutionY(QThread::idealThreadCount());

    QVector<qtrTile> tiles = tiler.tile();

// /////////////////////////////////////////////////////////////////
// Multiple concurrent run
// /////////////////////////////////////////////////////////////////

    QFuture<void> future = QtConcurrent::map(tiles, qtrRenderer::newton);

    QFutureWatcher<void> watcher;
    watcher.setFuture(future);
    watcher.waitForFinished();

// /////////////////////////////////////////////////////////////////
// Multiple concurrent run postprocessing
// /////////////////////////////////////////////////////////////////

    QImage image(
        application.arguments().value(2).toInt(),
        application.arguments().value(3).toInt(),
        QImage::Format_RGB32);
    image.fill(Qt::black);

    QPainter painter(&image);
    foreach(qtrTile tile, tiles)
        painter.drawImage(tile.tileRect(), tile.image());

    image.save(application.arguments().value(4));

    return 0;
}

//
// main.cpp ends here
