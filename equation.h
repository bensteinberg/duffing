/*

  Header for solving a second-order differential equation, decomposed
  into two first-order differential equations. Implement a step function,
  as in rk4.c, f1 and f2 as in duffing.c, and use as in solve.c.

 */

struct moment {
  double t, x, v;
};

struct moment step(struct moment n,
                   double (*f1)(double t, double x, double v),
                   double (*f2)(double t, double x, double v));

double f1(double t, double x, double v);
double f2(double t, double x, double v);
