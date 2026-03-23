# 2nd order Diffy Q Homogenous Linear Equations

## linear second-order differential equations

these equations follow the form:

$$
ay'' + by' + cy = f(t) (a \neq 0)
$$

If $f(t) = 0$:

$$
ay'' + by' + cy = 0
$$


### stategy

because the derivative of an exponent function is $e^{rt}$ is itself, we can say the solution must take the form $y = e^{rt}$. Substituting $y = e^{rt}$ yields

$$
e^{rt}(ar^2 + br + c) = 0
$$

to find r, we can solve the equation: $ar^2 + br + c = 0$. We can do this by eye, or the quadratic formula:

$$
r = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a} 
$$

### cases for roots

1. **distinct real roots**: if $b^2 - 4ac > 0$, then there are two distinct real roots, $r_1$ and $r_2$. The general solution is:

    $$ y = C_1e^{r_1t} + C_2e^{r_2t}$$

2. **repeated real roots**: if $b^2 - 4ac = 0$, then there is one repeated real root, $r$. The general solution is:

    $$ y = (C_1 + C_2t)e^{rt}$$

3. **complex conjugate roots**: if $b^2 - 4ac < 0$, then the roots are complex and come in conjugate pairs, $r \pm i\omega$. The general solution is:

    $$ y = e^{rt}(C_1\cos(\omega t) + C_2\sin(\omega t))$$

## example

$y'' - y' - 2y = 0$

We can factor out $y = e^{rt}$

$$
e^{rt}(r^2 - r - 2)
$$

we can factor it into:

$$
e^{rt}((r-2)(r+1))
$$

, so we can deduce $r = 2,-1$

, hence $y = e^{2t}$ and $y = e^{-t}$

we can then do $y = c_1e^{2t} + c_2 e^{-t}$

## example two

$$
y'' - 5y' + 6y = 0
$$

we can factor out $y = e^{rt}$

$$
e^{rt}(r^2 - 5r + 6)
$$

we can factor $r^2 - 5r + 6$

$$
(r - 3)(r - 2)
$$

we can solve for r = 3 and 2.

hence we can say $y = c_1e^{3t} + c_2e^{2t}$

## example three

$$
6y'' + y' - 2y = 0
$$

factor:

$$
e^{rt}(6r^2 + r - 2)
$$

we can factor using the quadratic formula

$$
r = \frac{-1 \pm \sqrt{1^2 - 4(6)(-2)}}{2 \times 6} \\

r = \frac{-1 \pm \sqrt{1 + 48}}{12} \\

r = \frac{-1 \pm 7}{12} \\

r = -\frac{2}{3} and r = \frac{+6}{12} = \frac{1}{2}
$$

## example four

$$
y'' + y' = 0
$$

given $y'(0) = 1$ and $y(0) = 2$

we can get $r^2 + r = 0$

we can factor out r, giving us $r(r + 1) = 0$

so we can say $r = 0$ and $r = -1$

this way, we'll get $y(t) = c_1 + c_2e^{-t}$

lets find the derivative:

$$
y'(t) = -c_2 e^{-t}
$$

we can plug our values in:

$$
y'(0) = 1, 1 = -c_2e^{0}, c_2 = -1 \\
y(0) = 2, 2 = c_1 + c_2e^{0}, 2 = c_1 - 1, c_1 = 3
$$

so, we can conclude the final equation is $y(t) = 3 - e^{-t}$

## example five

$$
y'' - 4y' + 3y = 0, \text{ where } y(0) = 1, y'(0) = \frac{1}{3}
$$

we can factor our $y = e^{rt}$

$$
e^{rt}(r^2 - 4r + 3)
$$

we can factor our equation into the following:

$$
(r - 3)(r - 1)
$$

to get $r = 1$ and $r = 3$.

we can then apply this into our differential equation, to eventually get:

$$
y(t) = -\frac{1}{3} + \frac{4}{3}e^t
$$

## repeated roots

A repeated real root is a solution whene there's only one distinct solution instead of two. In the quadratic formula, this would be $b^2 - 4ac = 0$

### example

$$
y'' + 6y' + 9y = 0, \text{ given } y(0) = 2, \text{ and } y'(0) = \frac{25}{3}
$$

We can pull out $y = e^{rt}$ to get:

$$
r^6 + 6r + 9 = (r + 3)(r + 3)
$$

we can deduce r = -3

so we get the following:

$$
c_1 e^{-3t} + c_2 te^{-3t}
$$

we have the t in there to make the equation linearly independent. Now, we need to solve for $c_1$ and $c_2$

$$
y(0) = 2, \text{ and } y'(0) = \frac{25}{3}
$$

$$
2 = c_1e^{-3(0)} + c_2 (0)e^{-3(0)}
$$

We can say that $c_1 = 2$

We need to also find $y'(t)$

$$
y'(t) = -3c_1e^{-3t} + c_2 e^{-3t} - 3c_2t e^{-3t}
$$

now we can solve for $y'(0) = \frac{25}{3}$

$$
\frac{25}{3} = -3(2)e^{-3(0)} + c_2 e^{-3(0)} - 3c_2t e^{-3(0)} \\
. \\
\frac{25}{3} = -6 + c_2 - 3c_2(0) \\
. \\
3(\frac{25}{3}) = 3(-6 + c_2) \\
25 + 18 = -18 + 3c_2 + 18 \\
\frac{1}{3} \times 43 = 3c_2 \times \frac{1}{3} \\
. \\
c_2 = \frac{43}{3}
$$

### another example

$$
y''' + y'' - 6y' + 4y = 0
$$

we can pull out $y = e^{rt}$

$$
r^3 + r^2 - 6r + 4
$$

we can first use the rational root theorem, looking at possible roots, aka, looking at factors of the constant 4.

$$
\pm 1, \pm 2, \pm 4
$$

test r = 1

$$
1^3  + 1^2 - 6(1) + 4 = 1 + 1 - 6 + 4 = 0
$$

so we know $(r - 1)$ is a factor.

we can then use synthetic division, writing the root, 1, on the left

```
1 |  1   1   -6   4
  |      1    2  -4
  ------------------
     1   2   -4   0  <-- Remainder is 0 (Perfect!)
```

now, we have $(r - 1)(r^2 + 2r - 4)$, which will give us the two additional root: $r = -1 \pm \sqrt{5}$.

## Euler's Formula

$$
e^{it}=\cos(t)+i\sin(t) \\
e^{-it}=\cos(-t)+i\sin(-t)
$$