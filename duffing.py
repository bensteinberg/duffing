import math
import wave
import struct

# the duffing equation:
# xdotdot + delta xdot + alpha x + beta x^3 = gamma cos (omega t)
# decomposes to:
# v = xdot
# vdot = xdotdot = gamma cos (omega t) - delta v - alpha x - beta x^3
# xdot = v = f1(t, x, v)

# xdot
def f1(t, x, v):
    return v

# vdot
def f2(t, x, v, alpha, beta, delta, gamma, omega):
    return gamma * math.cos(omega * t) - delta * v - alpha * x - beta * x**3

def main():
    alpha = 1.0
    beta = 5.0
    delta = 0.01
    gamma = 0.1
    omega = 0.5

    tt = 1000   # total time
    h  = 0.01   # step size

    x = 0.0
    v = 0.0
    t = 0.0

    output = []

    while (t < tt):
        k1x = f1(t, x, v)
        k1v = f2(t, x, v, alpha, beta, delta, gamma, omega)
        k2x = h * f1(t + h/2, x + k1x/2, v + k1v/2)
        k2v = h * f2(t + h/2, x + k1x/2, v + k1v/2, alpha, beta, delta, gamma, omega)
        k3x = h * f1(t + h/2, x + k2x/2, v + k2v/2)
        k3v = h * f2(t + h/2, x + k2x/2, v + k2v/2, alpha, beta, delta, gamma, omega)
        k4x = h * f1(t + h, x + k3x, v + k3v)
        k4v = h * f2(t + h, x + k3x, v + k3v, alpha, beta, delta, gamma, omega)
        x = x + h * (k1x + 2*k2x + 2*k3x + k4x) / 6
        v = v + h * (k1v + 2*k2v + 2*k3v + k4v) / 6
        #print(t, x, v)
        #print("%f %f" % (x, v))
        #print("%f" % (x))
        output.append(x)
        t = t + h
        
    f = wave.open('duffing.wav', 'w')
    f.setnchannels(1)
    f.setsampwidth(4)
    f.setframerate(44100)
    for sample in output:
        value = int(32767.0*10.0*sample)
        data = struct.pack('<h', value)
        f.writeframesraw( data )
    f.close()

if __name__ == '__main__':
    main()
