#include "equation.h"

struct moment step(struct moment now,
                   double (*f1)(double t, double x, double v),
                   double (*f2)(double t, double x, double v))
{
  extern double h;
  double kx[4], kv[4];
  double x, v;
  struct moment next;

  kx[0] = (*f1)(now.t, now.x, now.v);
  kv[0] = (*f2)(now.t, now.x, now.v);
  kx[1] = h * (*f1)(now.t + h/2, now.x + kx[0]/2, now.v + kv[0]/2);
  kv[1] = h * (*f2)(now.t + h/2, now.x + kx[0]/2, now.v + kv[0]/2);
  kx[2] = h * (*f1)(now.t + h/2, now.x + kx[1]/2, now.v + kv[1]/2);
  kv[2] = h * (*f2)(now.t + h/2, now.x + kx[1]/2, now.v + kv[1]/2);
  kx[3] = h * (*f1)(now.t + h, now.x + kx[2], now.v + kv[2]);
  kv[3] = h * (*f2)(now.t + h, now.x + kx[2], now.v + kv[2]);

  next.t = now.t + h;
  next.x = now.x + h * (kx[0] + 2*kx[1] + 2*kx[2] + kx[3]) / 6;
  next.v = now.v + h * (kv[0] + 2*kv[1] + 2*kv[2] + kv[3]) / 6;

  return next;
}
