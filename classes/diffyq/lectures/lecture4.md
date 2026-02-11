# lecture 4

## exact differential equations, solving exact equation

- if we see the form, $M(x,y)dx + N(x,y)dy$, we can say it's exact if:
    - $\frac{\partial F}{\partial x}(x, y) = M(x,y)$
    - $\frac{\partial F}{\partial y}(x,y) = N(x,y)$

- if we have an exact differential equation, we can do the following:

$$
F(x, y) = \int M(x,y)dx + g(y)
$$

after integrating, we get the derivative again, then solve for g(y)

$$
\frac{\partial f}{\partial y} = \frac{\partial f}{\partial y}(\int M(x,y)dx + g(y))
$$

then solve for $g'(y)$

$$
\frac{\partial f}{\partial y}(\int M(x,y)dx)  + g(y) = N(x, y)
$$

