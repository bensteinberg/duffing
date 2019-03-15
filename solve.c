#include <stdio.h>
#include "equation.h"

/*
  See equation.h for how to set up step(), f1(), and f2().
 */

int main()
{
  // initial conditions: time, position, and velocity
  struct moment now = {0.0, 0.0, 1.0};

  double tt = 10.0; // total time

  while (now.t < tt) {
    now = step(now, f1, f2);
    printf("%f %f %f\n", now.t, now.x, now.v);
  }

  return 0;
}
