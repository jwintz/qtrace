/* main.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Jan 25 23:48:53 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Sat Jan 26 01:08:11 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 9
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
