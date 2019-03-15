#include <math.h>
#include "equation.h"

/*
    the duffing equation:

    xdotdot + delta xdot + alpha x + beta x^3 = gamma cos (omega t)

    decomposes to two first-order differential equations by setting v = xdot:

    vdot = xdotdot = gamma cos (omega t) - delta v - alpha x - beta x^3
    xdot = v = f1(t, x, v)
*/

double alpha = 1.0;   // 
double beta  = 5.0;   //
double delta = 0.02;  //
double g = 8.0;       //
double omega = 0.5;   //

double h = 1.0 / 48000.0;  // step size

double f1(double t, double x, double v)
{
  return v;
}

double f2(double t, double x, double v)
{
  extern double alpha;
  extern double beta;
  extern double delta;
  extern double g;
  extern double omega;
  
  return g * cos(omega * t) - delta * v - alpha * x - beta * pow(x, 3);
}
