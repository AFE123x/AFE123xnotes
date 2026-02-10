# linear eqanions

## what is a linear first order equation?

- It's an equation that can be expressed in the following form:

$a_1 (x) \frac{dy}{dx} + a_0(x) y = b(x)$

## solving linear first order differential equation

- first, we need to write our first order diffy q in the following form

$$
\frac{dy}{dx} + P(x)y = Q(x)
$$

we can then find the **integrating factor**, $\mu (x)$

$$
\mu(x) = e^{\int P(x) dx}
$$

once we find $\mu(x)$, we multiply both sides of our equation by $\mu(x)$

$$
\mu(x)\frac{dy}{dx} + \mu(x)P(x)y = \mu(x)Q(x)
$$

finally, we integrate both sides and solve for y

$$
\int \mu(x)\frac{dy}{dx} + \mu(x)P(x)y = \int \mu(x)Q(x)
$$


$d = e^{-1} \pmod{\phi(n)}$