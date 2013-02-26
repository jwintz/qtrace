/* qtrTile.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 24 13:19:16 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jan 25 15:47:46 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 90
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "qtrTile.h"

class qtrTilePrivate
{
public:
    QRect tile;
    QRect whole;

public:
    QImage image;
};

qtrTile::qtrTile(void) : d(new qtrTilePrivate)
{
    
}

qtrTile::qtrTile(const QRect& tile, const QRect& whole) : d(new qtrTilePrivate)
{
    d->tile = tile;
    d->whole = whole;
}

qtrTile::qtrTile(const qtrTile& other) : d(new qtrTilePrivate)
{
    d->tile = other.d->tile;
    d->whole = other.d->whole;
    d->image = other.d->image;
}

qtrTile::~qtrTile(void)
{
    delete d;
    
    d = NULL;
}

qtrTile& qtrTile::operator=(const qtrTile& other)
{
     d->tile = other.d->tile;
    d->whole = other.d->whole;
    d->image = other.d->image;

    return (*this);
}

QPoint qtrTile::tilePos(void) const
{
    return d->tile.topLeft();
}

QSize qtrTile::tileSize(void) const
{
    return d->tile.size();
}

QRect qtrTile::tileRect(void) const
{
    return d->tile;
}

QSize qtrTile::wholeSize(void) const
{
    return d->whole.size();
}

QRect qtrTile::wholeRect(void) const
{
    return d->whole;
}

QImage qtrTile::image(void) const
{
    return d->image;
}

void qtrTile::setTilePos(const QPoint& pos)
{
    d->tile.setTopLeft(pos);
}

void qtrTile::setTileSize(const QSize& size)
{
    d->tile.setSize(size);
}

void qtrTile::setTileRect(const QRect& rect)
{
    d->tile = rect;
}

void qtrTile::setWholeSize(const QSize& size)
{
    d->whole.setSize(size);
}

void qtrTile::setWholeRect(const QRect& rect)
{
    d->whole = rect;
}

void qtrTile::setImage(const QImage& image)
{
    d->image = image;
}
