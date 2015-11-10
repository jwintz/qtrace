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

#include <math.h>

template <typename T> double qtrSolveNewtonError(T current, T previous)
{
    return fabs((current-previous)/current);
}

template <typename T> double qtrSolveNewtonError(std::complex<T> current, std::complex<T> previous)
{
    return fabs((abs(current)-abs(previous))/abs(current));
}

template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess)
{
       int count;
    double error;

    return qtrSolveNewton(polynomial, guess, count, error);
}

template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess, int& count)
{
    double error;

    return qtrSolveNewton(polynomial, guess, count, error);
}

template <typename T> T qtrSolveNewton(qtrPolynomial<T> polynomial, T guess, int& count, double& error)
{
    int iteration;

    qtrPolynomial<T> ff0 = polynomial;
    qtrPolynomial<T> ff1 = Diff(ff0, "z");

    T p_guess = zero(T());
    T c_guess = guess;
    T n_guess;

    double c_error = 1e+6;
    double m_error = 1e-6;

    for(iteration = 0; ((c_error > m_error) && (iteration < 255)); iteration++) {
        p_guess =  c_guess;
        c_guess = (c_guess - (ff0(c_guess)/ff1(c_guess)));
        c_error = qtrSolveNewtonError(c_guess, p_guess);
    }

    count = iteration-1;
    error = c_error;

    return c_guess;
}

//
// qtrSolver.tpp ends here
