/* qtrNewton.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 22 23:07:44 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Jan 24 11:22:38 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 138
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include "qtrPolynomial.h"

template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess);
template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess, int& count);
template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess, int& count, double& error);

#include "qtrSolver.tpp"
