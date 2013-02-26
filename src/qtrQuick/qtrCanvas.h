/* qtrCanvas.h --- 
 * 
 * Author: Julien Wintz
 * Created: Mon Jan 28 20:39:34 2013 (+0100)
 * Version: 
 * Last-Updated: Wed Jan 30 15:32:21 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 107
 */

/* Change Log:
 * 
 */

#pragma once

#include <qtrCore/qtrRenderer.h>
#include <qtrCore/qtrTile.h>
#include <qtrCore/qtrTiler.h>

#include <QtQuick>

class qtrCanvasPrivate;

class qtrCanvas : public QQuickPaintedItem
{
    Q_OBJECT

#pragma mark -
#pragma Render method properties

    Q_PROPERTY(int newtonOrder READ newtonOrder WRITE setNewtonOrder)

#pragma mark -
#pragma Thread usage properties

    Q_PROPERTY(int curNumberOfThreads READ curNumberOfThreads WRITE setCurNumberOfThreads NOTIFY curNumberOfThreadsChanged)
    Q_PROPERTY(int maxNumberOfThreads READ maxNumberOfThreads WRITE setMaxNumberOfThreads NOTIFY maxNumberOfThreadsChanged)

#pragma mark -
#pragma Progress monitoring properties
    
    Q_PROPERTY(int minProgressValue READ minProgressValue NOTIFY minProgressValueChanged)
    Q_PROPERTY(int maxProgressValue READ maxProgressValue NOTIFY maxProgressValueChanged)
    Q_PROPERTY(int curProgressValue READ curProgressValue NOTIFY curProgressValueChanged)

public:
     qtrCanvas(QQuickItem *parent = 0);
    ~qtrCanvas(void);
    
public:
    void paint(QPainter *painter);

#pragma mark -
#pragma Render method management

    int     newtonOrder(void);    
    void setNewtonOrder(int order);

    void setRenderMethod(qtrRenderer::qtrRenderMethod method);

#pragma mark -
#pragma Thread usage management

signals:
    void curNumberOfThreadsChanged(void);
    void maxNumberOfThreadsChanged(void);

public:
    int curNumberOfThreads(void);
    int maxNumberOfThreads(void);

public:
    void setCurNumberOfThreads(int);
    void setMaxNumberOfThreads(int);

#pragma mark -
#pragma Progress monitoring management

signals:
    void minProgressValueChanged(void);
    void maxProgressValueChanged(void);
    void curProgressValueChanged(void);

public:
    int minProgressValue(void);
    int maxProgressValue(void);
    int curProgressValue(void);

#pragma mark -
#pragma Internals

protected slots:
    void onResize(void);
    void onTileRendered(int);

protected:
    void geometryChanged(const QRectF& current, const QRectF& previous);

private:
    qtrCanvasPrivate *d;
};
