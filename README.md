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
