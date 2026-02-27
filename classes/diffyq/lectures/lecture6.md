# Lecture 6 - Substitutions and Transformations

## what's homogenous

$$
\frac{dy}{dx} = f(x,y)
$$
- if we can express the right side of the equation as a function of ratio $y:x$ alon, we can say it's homogenous

in other words:

$$
f(tx,ty) = f(x,y) \text{, remember } \frac{dy}{dx} = f(x,y)
$$
if this is true, the equation is homogenous.

if it's homogenous, we can expess $f(x,y) = g(\frac{y}{x})$


### example

$$
\frac{dy}{dx} = \frac{xy + y^2 + x^2}{x^2}
$$

you can check, it's homogenous

we can then express $f(x,y)$ as $g(\frac{y}{x})$

$$
G(\frac{y}{x}) = \frac{\frac{xy}{x^2} + \frac{y^2}{x^2} + \frac{x^2}{x^2}}{\frac{x^2}{x^2}} = \frac{y}{x} + (\frac{y}{x})^2 + 1
$$

- We expressed the original equation in terms of $\frac{y}{x}$

We can then substitute v in for $\frac{y}{x}$

$v^2 + v + 1 = G(v)$

now, lets solve for v:

$$
v = \frac{y}{x} \\
y = v \cdot x \\
y' = v' x + x' v \textbf{, where x' is 1}
y' = v'x + v
$$

$$
\frac{dy}{dx} = G(v) \\
\frac{dv}{dx} \cdot x + v = G(v) \\
... \\
\frac{1}{g(v) - v} dv = \frac{1}{x}dx
$$

- now, we created separable equation, we can integrate it.
    - we plug in g(v) and go about integration

## bernoulli equation

- the first order differential equation that can be written as:

$$
\frac{dy}{dx} + P(x)y = Q(x)y^n
$$

where $P(x)$ and $Q(x)$ is continuous, and y^n2, where n is a real number not equal to 0 or 1, is a bernoulli eqeuation

from here, we can turn this into a linear equation by doing $v = y^{1 - n}$