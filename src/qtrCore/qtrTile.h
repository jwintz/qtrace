/* qtrTile.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 24 12:00:08 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jan 25 15:44:55 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 124
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include <QtCore>
#include <QtGui>

class qtrTilePrivate;

class qtrTile
{
public:
     qtrTile(void);
     qtrTile(const QRect& tile, const QRect& whole);
     qtrTile(const qtrTile& other);
    ~qtrTile(void);

#pragma mark -
#pragma mark Tile operators

    qtrTile& operator=(const qtrTile& other);

#pragma mark -
#pragma mark Tile attributes

    QPoint tilePos(void) const;
    QSize tileSize(void) const;
    QRect tileRect(void) const;

#pragma mark -
#pragma mark Whole attributes

    QSize wholeSize(void) const;
    QRect wholeRect(void) const;

#pragma mark -
#pragma mark Rendered image

    QImage image(void) const;

#pragma mark -
#pragma mark Tile setup

    void setTilePos(const QPoint& pos);
    void setTileSize(const QSize& size);
    void setTileRect(const QRect& rect);

#pragma mark -
#pragma mark Whole setup

    void setWholeSize(const QSize& size);
    void setWholeRect(const QRect& rect);

#pragma mark -
#pragma mark Image setup
    
    void setImage(const QImage& image);

private:
    qtrTilePrivate *d;
};

typedef QVector<qtrTile> qtrTileList;
