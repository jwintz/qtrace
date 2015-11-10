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

#include "qtrPolynomial.h"

template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess);
template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess, int& count);
template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess, int& count, double& error);

#include "qtrSolver.tpp"

//
// qtrSolver.h ends here
