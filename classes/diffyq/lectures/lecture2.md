# Lecture 2 - slope maps

## autoonomous

- Autonomous Equations
The passage highlights a special type of differential equation:
    - Autonomous form: $y' = f(y)$
    - The right side depends only on y, not on the independent variable (usually t or x)

## method of isoclines

# Method of Isoclines - 
**Isoclines** are curves along which the slope (y') has the same constant value.

- For a differential equation y' = f(x, y):

1. **Set y' = c** (where c is a constant)
2. **Solve f(x, y) = c** to find the curve
3. **Draw small line segments with slope c** along this curve
4. **Repeat for different values of c**

## separation of variables

- here, we can clearly separate two variables into different sides.
- Once we do this, we can integrate both sides.

### example

$\frac{dy}{dx} = \frac{x - 5}{y^2}$

- first, we can separe the Xs and Ys

$$
y^2 dy = (x - 5)dx
$$

- next, we can integrate:

$$
\int y^2 dy = \int (x - 5)dx \\

\equiv \\
\frac{1}{3}y^3 = \frac{1}{2}x^2 - 5x + C
$$

finally, wec an solve for y

$$
3\frac{1}{3}y^3 = 3(\frac{1}{2}x^2 - 5x + C) \\
y^3 = \frac{3}{2}x^2 - 15x + 3C \\

y^3 = \frac{3}{2}x^2 - 15x + K
$$
- we can name 3C to K, as 3C is still a constant.


