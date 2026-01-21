# Linear Algebra for quantum computing

## What is a Vector?

- A vector is simply a coordinate with a direction.
    - think of it in the context of x, y coordinates

$$
\mathbf{x} =
\begin{bmatrix}
x \\
y \\
\end{bmatrix}
$$


## Vector Addition

We can easily add coordinates

$$
\mathbf{x} =
\begin{bmatrix}
x_1 \\
y_1 \\
\end{bmatrix}

+

\begin{bmatrix}
x_2 \\
y_2 \\
\end{bmatrix}

=

\begin{bmatrix}
x_1 + x_2 \\
y_1 + y_2 \\
\end{bmatrix}
$$

## Vector Multiplication

$$
2
\begin{bmatrix}
x \\
y \\
\end{bmatrix}

=
\begin{bmatrix}
2 \times x \\
2 \times y \\
\end{bmatrix}
$$


## basis vector values

- $\hat{i}$, x axis.
- $\hat{j}$, y axis.

- we can say vectors are these values with scaled up values.

$$
\begin{bmatrix}
3 \\
-2 \\
\end{bmatrix}

=

\begin{bmatrix}
3 \times \hat{i} \\
-2 \times \hat{j} \\
\end{bmatrix}

\rightarrow

(3\hat{i}) + (-2 \hat{j})
$$

## span

the span of two vectors $\vec{v}$ and $\vec{w}$ is the set of all their linear combinations:

$a\vec{v} + b\vec{w}$, where a and b can be all real numbers.

## vectors vs. points

- a point implies there's a vector that passes through the point from the origin.
    - you can say a point is a set of vectors.

## 3D space

- Span becomes more interesting in 3D space.
    - what does it mean for the span?

- When you add a third dimension, and scale it?

- linear combination: $a\vec{v} + b\vec{w} + c\vec{u}$
    - for span, a, b and c can vary.

## linear dependency

- If a vector doesn't change the span, it's said to be linearly dependent.

## Linear Transformations

$$
\begin{bmatrix}
1 & -3 \\
2 & 4 \\
\end{bmatrix}

\begin{bmatrix}
5 \\
7 \\
\end{bmatrix}

= 

\begin{bmatrix}
(1)(5) + (-3)(7) \\
(2)(5) + (4)(7)
\end{bmatrix}
$$

- transformation is simply a function.
- **Linear transformations** has two properties:
    - lines must remain lines
    - origin must not change.
    - simply, grid lines remain evenly spaced.


an easier way to visualize

$$
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix}
\begin{bmatrix}
x \\
y \\
\end{bmatrix}

=
x
\begin{bmatrix}
a \\
c
\end{bmatrix}
+
y
\begin{bmatrix}
b \\
d
\end{bmatrix}
$$

## matrix multiplication

$$
\begin{bmatrix}
a & b \\
c & d 
\end{bmatrix}

\begin{bmatrix}
e & f \\
g & h
\end{bmatrix}

\rightarrow

\begin{bmatrix}
a_{out} \\
c_{out}
\end{bmatrix}
= \begin{bmatrix}
a & b \\
c & d 
\end{bmatrix}
\begin{bmatrix}
e \\ 
g
\end{bmatrix}
,
\begin{bmatrix}
b_{out} \\
d_{out}
\end{bmatrix}
= \begin{bmatrix}
a & b \\
c & d 
\end{bmatrix}
\begin{bmatrix}
f \\ 
h
\end{bmatrix}
$$

order matters here, depending on how you do multiplication.

## determinant

- tells us how much the area increases or decreases.

$$
det(
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix}
)
=
(a)(d) - (b)(c)
$$

$$
det(
\begin{bmatrix}
a & b & c \\
d & e & f \\
g & h & i 
\end{bmatrix}
)
=
a\ det(
\begin{bmatrix}
e & f \\
h & i 
\end{bmatrix}
)
-
b\ 
det(
\begin{bmatrix}
d & f \\
g & i \\
\end{bmatrix}
)
+
c\ 
det(
\begin{bmatrix}
d & e \\
g & h 
\end{bmatrix}
)
$$

## Inverse of Matrix

- A is a matrix, and $A^{-1}$ is the inverse of A.
- The inverse of a matrix is pretty similar to the reciprocal.

We know that $A A^{-1} = I$, where I is the identity matrix

$$
\text{identity matrix} \rightarrow
\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}
$$

Given a matrix A, we need to find $A^{-1}$

## calculating inverse

given matrix A

$$
A = 
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}
$$

$$
A^{-1} = det(
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}
)
\begin{bmatrix}
d & -b \\
-c & a
\end{bmatrix}
$$

## why would we want to inverse?

$$
XA = B \text{ we cannot divide both sides by A, so we multiply by the inverse}
$$

$$
XAA^{-1} = BA^{-1} \\
XI = BA^{-1}
$$

## Example inverse

$$
\begin{bmatrix}
1 & 2 & 3 \\
0 & 1 & 4 \\
5 & 6 & 0 \\
\end{bmatrix}

\rightarrow

\begin{bmatrix}
-24 & -20 & -5 \\
-18 & -15 & -4 \\
5 & 4 & 1 \\
\end{bmatrix}

$$

next, we create the matrix of cofactors

$$
\begin{bmatrix}
-24 & -20 & -5 \\
-18 & -15 & -4 \\
5 & 4 & 1 \\
\end{bmatrix}
\rightarrow
\begin{bmatrix}
+ & - & + \\
- & + & - \\
+ & - & + 
\end{bmatrix}
\rightarrow

\begin{bmatrix}
-24 & 20 & -5 \\
18 & -15 & 4 \\
5 & -4 & 1 
\end{bmatrix}
$$

next, get the adjugate/adjoint

$$

\begin{bmatrix}
-24 & 20 & -5 \\
18 & -15 & 4 \\
5 & -4 & 1 
\end{bmatrix}

\rightarrow

\begin{bmatrix}
-24 & - & - \\
- & -15 & - \\
- & - & 1 
\end{bmatrix}
$$

we then flip the other corners non diagonal

$$
\begin{bmatrix}
-24 & 18 & 5 \\
20 & -15 & -4 \\
-5 & 4 & 1 
\end{bmatrix}
$$

finally, we'll get the determinant of the original matrix, then divide all factors in the adjugate matrix with the determinant number.

$$
\begin{bmatrix}
-24 & 18 & 5 \\
20 & -15 & -4 \\
-5 & 4 & 1 
\end{bmatrix}

\div
det(
\begin{bmatrix}
1 & 2 & 3 \\
0 & 1 & 4 \\
5 & 6 & 0
\end{bmatrix} 
)
$$


hence our inverse matrix is

$$
A^{-1} = \begin{bmatrix}
-24 & 18 & 5 \\
20 & -15 & -4 \\
-5 & 4 & 1 
\end{bmatrix}
$$

## eigenvector and eigenvalues

- We see eigenvalues:
    - to solve systems of linear differential equations
    - describe natural frequencies of vibrations
    - separate modes of motion
    - distinguish states of energy.


- Given a N x N matrix A, we can say an eigenvector, $\vec{x}$, and the eigenvalue, $\lambda$ has the following relation:

$$
A \vec{x} = \lambda \vec{x}
$$

eigenvectors must be non-trivial, meaning they can't be the zero vector.

- to find the eigenvector, you can derive the following:

$$
A\vec{x} = \lambda \vec{x} \\
A\vec{x} - \lambda \vec{x} = \vec{0} \\
A\vec{x} - \lambda I \vec{x} = \vec{0} \text{ add identity matrix} \\
(A - \lambda I )\vec{x} = \vec{0} \\
$$
- x cannot be a zero matrix, and $(A - \lambda I)$ cannot be invertible, hence it's determinant can't be zero.

**example**

$$
A = \begin{bmatrix}
1 & 1 \\
4 & 1
\end{bmatrix}
$$

$$
A - \lambda I =
\begin{bmatrix}
1 & 1 \\
4 & 1
\end{bmatrix}

-
\lambda
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
$$

$$
A - \lambda I =
\begin{bmatrix}
1 & 1 \\
4 & 1
\end{bmatrix}

-

\begin{bmatrix}
\lambda & 0 \\
0 & \lambda
\end{bmatrix}

\rightarrow

\begin{bmatrix}
1 - \lambda & 1 \\
4 & 1 - \lambda
\end{bmatrix}
$$

- we need to find the determinant, and set it equal to zero.

$$
\begin{bmatrix}
1 - \lambda & 1 \\
4 & 1 - \lambda
\end{bmatrix}

=
(1-\lambda)(1 - \lambda) - (1)(4)
=
1 - 2\lambda + \lambda^2 - 4 = \lambda^2 - 2\lambda - 3 = 0
$$

- we can find $\lambda = 3, \lambda = -1$

next, we can plug in these eigenvalues into our equation $(A - \lambda I)\vec{x} = \vec{0}$

example:

$$
A - 3I = 
\begin{bmatrix}
1 & 1 \\
4 & 1
\end{bmatrix}
-
\begin{bmatrix}
3 & 0 \\
0 & 3
\end{bmatrix}
=
\begin{bmatrix}
-2 & 1 \\
4 & -2 \\
\end{bmatrix}
\rightarrow
\begin{bmatrix}
-2 & 1 \\
0 & 0 \\
\end{bmatrix}
$$

write out the equation, then solve

$$
-2x_1 + x_2 = 0 \\
x_2 = 2x_1 \\
\text{if } x_1 = 1, x_2 = 2 \\
\text{hence, a valid eigenvector is } \begin{bmatrix}
1 \\ 2
\end{bmatrix}
$$
