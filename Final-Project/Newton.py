import numpy as np


def func(x):
    return np.pi * np.pi * np.sin(np.pi * x) + np.sin(np.pi * x) ** 3


def check(x):
    return np.sin(np.pi * x)


n = 10
h = 1.0 / n
eps = 1E-8
A = np.zeros((n - 1, n - 1), dtype=np.double)
u = np.ones(n - 1, dtype=np.longdouble)
count = 0

sign = 0
while not sign:
    sign = 0
    count += 1
    A = np.zeros((n - 1, n - 1), dtype=np.double)
    for i in range(1, n - 2):
        A[i][i - 1] += -1
        A[i][i] += (2 + 3 * h * h * u[i])
        A[i][i + 1] += -1
    A[0][0] += (2 + 3 * h * h * u[0])
    A[0][1] += -1
    A[n - 2][n - 2] += (2 + 3 * h * h * u[n - 2])
    A[n - 2][n - 3] += -1
    A_inverse = np.linalg.inv(A)
    # if count == 1:
    #     print(A)
    #     print(A_inverse)

    f = np.zeros(n - 1, dtype=np.double)
    for i in range(1, n - 2):
        f[i] = 2 * u[i] - u[i - 1] - u[i + 1] + (u[i] ** 3 - func((i + 1) * h)) * h * h
    f[0] = 2 * u[0] - u[1] + (u[0] ** 3 - func(h)) * h * h
    f[n - 2] = 2 * u[n - 2] - u[n - 3] + (u[n - 2] ** 3 - func((n - 1) * h)) * h * h

    delta_u = np.dot(A_inverse, -f)
    # print(delta_u, '\n')
    u += delta_u
    if np.max(abs(delta_u)) < eps:
        eh = 0.0
        for i in range(n-1):
            eh += (u[i] - check((i + 1) * h)) ** 2
        eh = np.sqrt(eh)
        print("count =", count)
        print(u)
        print("eh =", eh)
        sign = 1
