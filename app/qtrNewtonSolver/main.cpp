/* main.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 22 12:10:05 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jan 25 23:37:42 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 374
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include <qtrMath/qtrPolynomial.h>
#include <qtrMath/qtrSolver.h>

int main(int argc, char **argv)
{
    typedef std::complex<double> complex;

    qtrPolynomial<double>  z1r("z"); qtrPolynomial<double>  p1r = z1r*z1r*z1r-1;
    qtrPolynomial<complex> z1c("z"); qtrPolynomial<complex> p1c = z1c*z1c*z1c-1;

    std::cout << "Polynomial NR computation of z^3-1 in R: " << "guess = " <<  double(+3.0)       << " \t\t- " << qtrSolveNewton<double> (p1r,  double(+3.0)     ) << std::endl;
    std::cout << "Polynomial NR computation in z^3-1 in C: " << "guess = " << complex(+3.0, +0.0) << " \t\t- " << qtrSolveNewton<complex>(p1c, complex(+3.0,+0.0)) << std::endl;
    std::cout << "Polynomial NR computation in z^3-1 in C: " << "guess = " << complex(-3.0, +1.0) << " \t- "   << qtrSolveNewton<complex>(p1c, complex(-3.0,+1.0)) << std::endl;
    std::cout << "Polynomial NR computation in z^3-1 in C: " << "guess = " << complex(-3.0, -1.0) << " \t- "   << qtrSolveNewton<complex>(p1c, complex(-3.0,-1.0)) << std::endl;

    qtrPolynomial<double>  z2r("z"); qtrPolynomial<double>  p2r = z2r*z2r*z2r*z2r-1;
    qtrPolynomial<complex> z2c("z"); qtrPolynomial<complex> p2c = z2c*z2c*z2c*z2c-1;

    std::cout << "Polynomial NR computation of z^4-1 in R: " << "guess = " <<  double(+3.0)       << " \t\t- " << qtrSolveNewton<double> (p2r,  double(+3.0)     ) << std::endl;
    std::cout << "Polynomial NR computation in z^4-1 in C: " << "guess = " << complex(+3.0, +0.0) << " \t\t- " << qtrSolveNewton<complex>(p2c, complex(+3.0,+0.0)) << std::endl;
    std::cout << "Polynomial NR computation in z^4-1 in C: " << "guess = " << complex(-3.0, +0.0) << " \t- "   << qtrSolveNewton<complex>(p2c, complex(-3.0,+0.0)) << std::endl;
    std::cout << "Polynomial NR computation in z^4-1 in C: " << "guess = " << complex(+0.0, +3.0) << " \t\t- " << qtrSolveNewton<complex>(p2c, complex(+0.0,+3.0)) << std::endl;
    std::cout << "Polynomial NR computation in z^4-1 in C: " << "guess = " << complex(+0.0, -3.0) << " \t- "   << qtrSolveNewton<complex>(p2c, complex(+0.0,-3.0)) << std::endl;

    return 0;
}
