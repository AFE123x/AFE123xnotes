# Lecture 7

## what are linear coefficients

- **linear coefficients** are equations that follow the form:

$$
(a_1 x + b_1 y + c_1)dx + (a_2 x + b_2 y + c_2) dy = 0
$$

## equations of form $\frac{dy}{dx} = G(ax + by)$

- here, if we have this equation, we can use the substitution: $z = ax + by$

### example

$$
\frac{dy}{dx} = (x + y + 2)^2
$$

sub in $z = x + y + 2$

$$
\frac{dy}{dx} = (z)^2
$$

replace $\frac{dy}{dx}$ with $\frac{dz}{dx}$

$$
\frac{dz}{dx} = 1 + \frac{dy}{dx} \\
\frac{dy}{dx} = \frac{dz}{dx} - 1
$$

we can plug our thing in:

$$
\frac{dz}{dx} - 1 = (z)^2 \\
\frac{dz}{dx} = (z)^2 + 1 dx \\
\frac{1}{(z)^2 + 1}dz = 1 dx \\
\arctan(z) = x + c \\
z = tan(x + c) \\
x + y + 2 = tan(x + c) \\
y = tan(x + c) - x - 2
$$

