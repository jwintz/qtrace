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

#include "qtrCanvas.h"
#include "qtrQuickPlugin.h"

void qtrQuickPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("QtrQuick"));

    qmlRegisterType<qtrCanvas>(uri, 1, 0, "QtrCanvas");
}

//
// qtrQuickPlugin.cpp ends here
