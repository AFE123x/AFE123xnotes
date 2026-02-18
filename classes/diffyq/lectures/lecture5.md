# Lecture 5 - Special Integrating factors

## integrating factor

- lets say you have the formula: $M(x,y) dx + N(x,y) dy = 0$, which isn't exact
- lets say you add a factor, $\mu(x,y)$, $\mu(x,y)M(x,y) dx + \mu(x,y)N(x,y) dy = 0$, and it becomes exact, $\mu(x,y)$, is the integrating factor.

### special integrating factor

- if $\frac{\frac{\partial M}{\partial y} - \frac{\partial N}{\partial x}}{N}$ is continuous and depends only on x, then we can say the following is the integrating factor for non exact equation that resembles $M(x,y)dx + N(x,y)dy = 0$

$$
\mu(x) = e^{\int(\frac{\frac{\partial M}{\partial y} - \frac{\partial N}{\partial x}}{N}) dx}
$$

- if $\frac{\frac{\partial M}{\partial x} - \frac{\partial N}{\partial y}}{M}$ is continuous and depends only on y, then we can say the following is the integrating factor for non exact equation that resembles $M(x,y)dx + N(x,y)dy = 0$

$$
\mu(x) = e^{\int(\frac{\frac{\partial M}{\partial x} - \frac{\partial N}{\partial y}}{N}) dy}
$$

### example

$$
(2xy)dx + (y^2 - 3x^2)dy = 0
$$

we can pick M and N

$$
M(x,y) = 2xy \\
N(x,y) = y^2 - 3x^2
$$

we can try to find the partial derivatives

$$
\frac{\partial M}{\partial y} = 2x \\
\frac{\partial N}{\partial x} = -6x
$$

we can try to check the conditions above

$$
\frac{\frac{\partial M}{\partial y} - \frac{\partial N}{\partial x}}{N} \\
\frac{2x - 6x}{y^2 - 3x^2}\text{, which contains x and y} \\
\frac{\frac{\partial M}{\partial x} - \frac{\partial N}{\partial y}}{M}

$$