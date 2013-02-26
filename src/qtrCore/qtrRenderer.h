/* qtrRenderer.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 24 11:53:08 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Jan 28 14:39:42 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 92
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include "qtrTile.h"

#include <QtCore>
#include <QtGui>

class qtrRenderer
{
public:
    static unsigned int newtonOrder;

public:
    typedef QImage (*qtrRenderImageMethod)(qtrTile&);

public:
    static QImage newtonImage(qtrTile& tile);

public:
    typedef void (*qtrRenderMethod)(qtrTile&);

public:
    static void newton(qtrTile& tile);
};
