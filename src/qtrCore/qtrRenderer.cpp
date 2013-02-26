/* qtrRenderer.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 24 11:53:42 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Jan 30 16:41:15 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 303
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "qtrRenderer.h"

#include <qtrMath/qtrPolynomial.h>
#include <qtrMath/qtrSolver.h>

unsigned int qtrRenderer::newtonOrder = 2;

QImage qtrRenderer::newtonImage(qtrTile& tile)
{
    newton(tile);
    return tile.image();
}

void qtrRenderer::newton(qtrTile& tile)
{
          int c;
    const int w = tile.wholeSize().width();
    const int h = tile.wholeSize().height();

    const qreal ratio = (qreal)w/(qreal)h;
    const qreal y_min = -1.5;
    const qreal y_max = +1.5;
    const qreal x_min = y_min*ratio;
    const qreal x_max = y_max*ratio;
    
    const qreal d_x = -(qreal)w/2.0;
    const qreal d_y = -(qreal)h/2.0;
    const qreal s_x = (x_max-x_min)/w;
    const qreal s_y = (y_max-y_min)/h;
    
    QImage image(tile.tileSize().width(), tile.tileSize().height(), QImage::Format_RGB32);
    image.fill(Qt::black);

    typedef std::complex<double> complex;
    
    qtrPolynomial<complex> z("z");
    qtrPolynomial<complex> f = z;
    for(unsigned int k = 1; k < qtrRenderer::newtonOrder; k++)
        f = f*z;
    f = f - 1;

            complex  root;
    QVector<complex> roots;

    for(int k = 0; k < qtrRenderer::newtonOrder; k++)
        roots << complex(
            cos(k*((2*M_PI)/qtrRenderer::newtonOrder)),
            sin(k*((2*M_PI)/qtrRenderer::newtonOrder)));

    for(int x = tile.tilePos().x(); x < tile.tilePos().x()+tile.tileSize().width(); x++) {
        
        for(int y = tile.tilePos().y(); y < tile.tilePos().y()+tile.tileSize().height(); y++) {
            
            int i = x-tile.tilePos().x();
            int j = y-tile.tilePos().y();

            root = qtrSolveNewton<complex>(f, complex((x+d_x)*s_x, -(y+d_y)*s_y), c);

            for(int k = 0; k < qtrRenderer::newtonOrder; k++)
                if(abs(root-roots[k]) < 1e-6)
                    image.setPixel(i, j, QColor::fromHsv((k*((2*M_PI)/qtrRenderer::newtonOrder))/M_PI*180, 255, 255-((10*c)%255)).rgb());
        }
    }

    tile.setImage(image);
}
