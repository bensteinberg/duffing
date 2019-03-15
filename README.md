duffing
=======

This is a set of experiments with approximating the Duffing equation
using RK4.

When duffing.py produces text output, pipe it to gnuplot like this:

```
python ./duffing.py | gnuplot -p -e 'plot "/dev/stdin" with dots'
```

The ChucK player is not working yet, hence the WAV file output in
duffing.py.

Useful sources have included

- https://en.wikipedia.org/wiki/Duffing_equation
- https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods
- https://www.youtube.com/watch?v=TjZgQa2kec0

C code
------
At the moment, compile like this:

    gcc solve.c duffing.c rk4.c
