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

#include "qtrTiler.h"

#if defined(Q_OS_LINUX)
#include <bsd/stdlib.h>
#endif

#include <QtCore>

class qtrTilerPrivate
{
public:
    QRect whole;

public:
    int resolution_x;
    int resolution_y;
};

qtrTiler::qtrTiler(void) : d(new qtrTilerPrivate)
{

}

qtrTiler::~qtrTiler(void)
{
    delete d;

    d = NULL;
}

void qtrTiler::setWholeSize(const QSize& size)
{
    d->whole.setSize(size);
}

void qtrTiler::setWholeRect(const QRect& rect)
{
    d->whole = rect;
}

void qtrTiler::setResolutionX(int resolution)
{
    d->resolution_x = resolution;
}

void qtrTiler::setResolutionY(int resolution)
{
    d->resolution_y = resolution;
}

qtrTileList qtrTiler::tile(void)
{
    qtrTileList tiles;

    int tile_w = d->whole.width() /d->resolution_x;
    int tile_h = d->whole.height()/d->resolution_y;
    int tile_u = d->whole.width() %d->resolution_x;
    int tile_v = d->whole.height()%d->resolution_y;

    for(int x = 0; x < (d->resolution_x-1)*tile_w; x += tile_w)
        for(int y = 0; y < (d->resolution_y-1)*tile_h; y += tile_h)
            tiles << qtrTile(QRect(x, y, tile_w, tile_h), d->whole);

    for(int x = 0; x < (d->resolution_x-1)*tile_w; x += tile_w)
        tiles << qtrTile(QRect(x, d->whole.height()-tile_h-tile_v, tile_w, tile_h+tile_v), d->whole);

    for(int y = 0; y < (d->resolution_y-1)*tile_h; y += tile_h)
        tiles << qtrTile(QRect(d->whole.width()-tile_w-tile_u, y, tile_w+tile_u, tile_h), d->whole);

    tiles << qtrTile(QRect(d->whole.width()-tile_w-tile_u, d->whole.height()-tile_h-tile_v, tile_w+tile_u, tile_h+tile_v), d->whole);

    qtrTileList shuffled; int n = tiles.count();

    for(int i = 0; i < n; i++) {
	int k = arc4random() % tiles.count();
	qtrTile t = tiles.value(k);
	tiles.remove(k);
	shuffled.append(t);
    }

    return shuffled;
}

//
// qtrTiler.cpp ends here
