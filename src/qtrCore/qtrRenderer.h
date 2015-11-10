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

//
// qtrRenderer.h ends here
