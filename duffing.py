import argparse
import math
import wave
import struct

# the duffing equation:
#
# xdotdot + delta xdot + alpha x + beta x^3 = gamma cos (omega t)
#
# decomposes to two first-order differential equations by setting
# v = xdot:
#
# vdot = xdotdot = gamma cos (omega t) - delta v - alpha x - beta x^3
# xdot = v = f1(t, x, v)

# xdot
def f1(t, x, v):
    return v

# vdot
def f2(t, x, v, alpha, beta, delta, gamma, omega):
    return gamma * math.cos(omega * t) - delta * v - alpha * x - beta * x**3

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--alpha', type=float, help='stiffness',     default=1.0)
    parser.add_argument('--beta', type=float,  help='non-linearity', default=5.0)
    parser.add_argument('--delta', type=float, help='damping',       default=0.02)
    parser.add_argument('--gamma', type=float, help='amplitude',     default=8.0)
    parser.add_argument('--omega', type=float, help='frequency',     default=0.5)

    parser.add_argument('--time',  type=float, help='total time', default=1000.0)
    parser.add_argument('--step',  type=float, help='step size',  default=0.01)

    parser.add_argument('-x',  type=float, help='initial position', default=0.0)
    parser.add_argument('-v',  type=float, help='initial velocity', default=0.0)

    # alpha = 1.0
    # beta = 5.0
    # delta = 0.01
    # gamma = 0.1
    # omega = 0.5
    args = parser.parse_args()

    alpha = args.alpha
    beta = args.beta
    delta = args.delta
    gamma = args.gamma
    omega = args.omega

    tt = args.time
    h  = args.step

    # initial conditions
    x = args.x
    v = args.v
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
        print("%f %f %f" % (t, x, v))
        output.append(x)
        t = t + h

    # f = wave.open('duffing.wav', 'w')
    # f.setnchannels(1)
    # f.setsampwidth(4)
    # f.setframerate(44100)
    # for sample in output:
    #     value = int(32767.0*10.0*sample)
    #     data = struct.pack('<h', value)
    #     f.writeframesraw( data )
    # f.close()

if __name__ == '__main__':
    main()
