/* qtrQuick.cpp --- 
 * 
 * Author: Julien Wintz
 * Created: Mon Jan 28 21:33:11 2013 (+0100)
 * Version: 
 * Last-Updated: Tue Feb 26 11:04:14 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 31
 */

/* Change Log:
 * 
 */

#include "qtrCanvas.h"
#include "qtrQuick.h"
#include "qtrThreadGaugeEngine.h"

#include <QtCore>
#include <QtQuick>

qtrQuick *qtrQuick::instance(void)
{
    if(!s_instance)
	s_instance = new qtrQuick;

    return s_instance;
}

void qtrQuick::initialize(void)
{
    qmlRegisterType<qtrCanvas>("QtrQuick", 1, 0, "QtrCanvas");
    qmlRegisterType<qtrThreadGaugeEngine>("QtrQuick", 1, 0, "QtrThreadGaugeEngine");
}

qtrQuick::qtrQuick(void)
{

}

qtrQuick::~qtrQuick(void)
{

}

qtrQuick *qtrQuick::s_instance = NULL;
