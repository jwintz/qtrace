/* qtrQuickPlugin.h --- 
 * 
 * Author: Julien Wintz
 * Created: Tue Jan 29 17:22:36 2013 (+0100)
 * Version: 
 * Last-Updated: Tue Jan 29 18:21:48 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 9
 */

/* Change Log:
 * 
 */

#pragma once

#include <QQmlExtensionPlugin>

class qtrQuickPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *);
};
