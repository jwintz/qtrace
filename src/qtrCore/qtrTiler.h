/* qtrTiler.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 24 11:50:56 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Jan 24 22:40:33 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 41
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

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
