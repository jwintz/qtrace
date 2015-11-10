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

//
// qtrTile.h ends here
