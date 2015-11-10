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

#include "qtrTile.h"

class qtrTilerPrivate;

class qtrTiler
{
public:
     qtrTiler(void);
    ~qtrTiler(void);

#pragma mark -
#pragma mark Whole setup

    void setWholeSize(const QSize& size);
    void setWholeRect(const QRect& rect);

#pragma mark -
#pragma mark Resolution setup

    void setResolutionX(int resolution);
    void setResolutionY(int resolution);

#pragma mark -
#pragma mark Processing

    qtrTileList tile(void);

private:
    qtrTilerPrivate *d;
};

//
// qtrTiler.h ends here
