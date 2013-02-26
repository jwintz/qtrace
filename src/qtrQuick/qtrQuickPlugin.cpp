/* qtrQuickPlugin.cpp --- 
 * 
 * Author: Julien Wintz
 * Created: Tue Jan 29 17:24:42 2013 (+0100)
 * Version: 
 * Last-Updated: Tue Feb 26 11:08:23 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 15
 */

/* Change Log:
 * 
 */

#include "qtrCanvas.h"
#include "qtrQuickPlugin.h"

void qtrQuickPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("QtrQuick"));

    qmlRegisterType<qtrCanvas>(uri, 1, 0, "QtrCanvas");
}
