#include <math.h>
#include "equation.h"

/*
    the Duffing equation:

    x'' + delta x' + alpha x + beta x^3 = gamma cos (omega t)

    decomposes to two first-order differential equations by setting v = x':

    v' = x'' = gamma cos (omega t) - delta v - alpha x - beta x^3
    x' = v
*/

double alpha = 1.0;   // stiffness
double beta  = 5.0;   // non-linearity
double delta = 0.02;  // damping
double g = 8.0;       // amplitude
double omega = 0.5;   // frequency

// step size -- this might reasonably go in e.g. rk4.c, but is convenient here
double h = 1.0 / 48000.0;

double f1(double t, double x, double v)
{
  return v;
}

double f2(double t, double x, double v)
{
  extern double alpha;
  extern double beta;
  extern double delta;
  extern double g;      // can't use gamma, because it's in math.h
  extern double omega;
  
  return g * cos(omega * t) - delta * v - alpha * x - beta * pow(x, 3);
}
