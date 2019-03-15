#include <stdio.h>
#include <math.h>

double alpha = 1.0;
double beta  = 5.0;
double delta = 0.02;
double g = 8.0;
double omega = 0.5;

double h = 1.0 / 48000.0;  // step size

double f1(double t, double x, double v);
double f2(double t, double x, double v);


struct moment {
  double t, x, v;
};


struct moment rk4step(struct moment n);

int main()
{
  // initial conditions
  struct moment now = {0.0, 0.0, 0.5};

  double tt = 1.0; // total time

  while (now.t < tt) {
    now = rk4step(now);
    // printf("%f %f %f\n", now.t, now.x, now.v);
  }

  return 0;
}

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

struct moment rk4step(struct moment now)
{
  extern double h;
  double kx[4], kv[4];
  double x, v;
  struct moment next;

  kx[0] = f1(now.t, now.x, now.v);
  kv[0] = f2(now.t, now.x, now.v);
  kx[1] = h * f1(now.t + h/2, now.x + kx[0]/2, now.v + kv[0]/2);
  kv[1] = h * f2(now.t + h/2, now.x + kx[0]/2, now.v + kv[0]/2);
  kx[2] = h * f1(now.t + h/2, now.x + kx[1]/2, now.v + kv[1]/2);
  kv[2] = h * f2(now.t + h/2, now.x + kx[1]/2, now.v + kv[1]/2);
  kx[3] = h * f1(now.t + h, now.x + kx[2], now.v + kv[2]);
  kv[3] = h * f2(now.t + h, now.x + kx[2], now.v + kv[2]);

  next.t = now.t + h;
  next.x = now.x + h * (kx[0] + 2*kx[1] + 2*kx[2] + kx[3]) / 6;
  next.v = now.v + h * (kv[0] + 2*kv[1] + 2*kv[2] + kv[3]) / 6;

  return next;
}
