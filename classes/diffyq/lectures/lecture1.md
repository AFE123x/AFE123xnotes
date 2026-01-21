# Lecture 1: Introduction

**real stuff starts ~15 minutes**

We know derivatives:

$h(t) = \frac{-gt^2}{2} + c_1 t + c_2$

$h'(t) = \frac{dh}{dt} = -gt + c_1$

$h''(t) = \frac{d^2h}{dt^2} = -g$

## Radioactive decay math

- $\frac{dA}{dt} = -kA$, where k > 0.
- We can move the deltas to get $\frac{1}{A} dA = -k dt$
- We can integrate $\int \frac{1}{A} dA = \int -k dt$, giving us $A + C_1 = -kt + C_2$.
- we can then move C1 to the other side to get $A = -kt + c_2 - c_1$


## dependent vs. independent variables

- in functions, we say y = f(x).
    - y is dependent on x, hence y is dependent.

## types of differential equations

- ordinary differential equtains: there's only one independent variables
- partial differential equations: there are multiple independent variables

## first order vs. second order

- first order is when the highest order is 1
- second order is when the highest order is 2

## linear vs. non linear

- a linear differential equation is a differential equation where the dependent variable doesn't show up as a coefficient.
- a non-linear differential equation is when it's not linear.
    - example: $\frac{d^2 y}{dx^2} + y^3 = 0$ is non linear, because we don't have.

## ordinary vs. partial diffy q

- look for partial derivations, it's partial.

## practice

- $\frac{d^2 y}{dx^2} - 2x \frac{dy}{dx} + 2y = 0$
    - ordinary
    - second order differential equation.
    - linear
    - x is dependent, y is independent

- $\frac{\partial ^ 2 u}{\partial x ^ 2} + \frac{\partial ^ 2 u}{\partial y ^ 2} = 0$
    - partial
    - second order
    - x and y are independent, u is dependent.
    - linear

- $\frac{dx}{dt} = k(4 - x)(1 - x)$
    - ordinary 
    - first order
    - x is dependent, t is independent.
    - non linear.

- $\sqrt{1 - y} \frac{d^2 y}{dx^2} + 2x\frac{dy}{dx}$
    - non linear, as the coefficient for our second order contains a dependent variable y.
    - ordinary
    - second order
    - y is dependent, x is independent.


Drag Race.  Two drivers, Alison and Kevin, are par-ticipating in a drag race. Beginning from a standing start,  they each proceed with a constant acceleration. Alison  covers the last 1/4 of the distance in 3 seconds, whereas  Kevin covers the last 1/3 of the distance in 4 seconds.  Who wins and by how much time?

- velocity of allison = 1/12
- velocity of kevin = 1/12