/* main.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 24 12:40:15 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Jan 28 12:37:26 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 289
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include <QtConcurrent>
#include <QtCore>
#include <QtDebug>
#include <QtGui>
#include <QtWidgets>

#include <qtrCore/qtrRenderer.h>
#include <qtrCore/qtrTile.h>
#include <qtrCore/qtrTiler.h>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

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
