# chapter 2 - linear algebra

## vector space

- this is the basic object of linear algebra.
- we really care about $C^n$, which is a space of all n-tuples of complex numbers, $(z_1, ..., z_n)$.
    - the element of a vector space is known as a vector.

## vector addition

$$
\begin{bmatrix}
z_1 \\

\vdots\\

z_n
\end{bmatrix}
+
\begin{bmatrix}
z_1' \\

\vdots\\

z_n'
\end{bmatrix}
=
\begin{bmatrix}
z_1 + z_1' \\

\vdots\\

z_n + z_n'
\end{bmatrix}
$$

## vector - multiplication by scalar operation

$$
z
\begin{bmatrix}
z_1 \\
\vdots \\
z_n
\end{bmatrix}
\equiv
\begin{bmatrix}
zz_1 \\
\vdots \\
zz_n
\end{bmatrix}
$$

## complex conjugate

given a complex number z, $(1 + i)^* = 1 - i$

## bases and linear independence

- we can say a set of non-zero vectors is linearly independent if $a_1 \ket{v_1} + a_2 \ket{v_2} + ... + a_n \ket{v_n}= 0$

## pauli matrices

- There are four useful matrices, and are the foundation of quantum computing.

$$
I = 
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
$$

$$
X = \begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix}
$$

$$
Y = \begin{bmatrix}
0 & -i \\
i & 0
\end{bmatrix}
$$

$$
Z = \begin{bmatrix}
1 & 0 \\
0 & -1
\end{bmatrix}
$$

## inner product

- $\vec{v} \cdot \vec{w} = v_1 w_1 + v_2 w_2 + v_3 w_3 + ...$

- The inner product (also known as inner product)
    - it lets us define the notion of angle, and orthogonality.

- $\vec{v} \cdot \vec{w} = |\vec{v}||\vec{w}| \cos \theta$
    - if they're orthogonal, the dot product is zero.

- Lets us define the length of a vector.

$|\vec{v}| = \sqrt{\vec{v} \cdot \vec{v}}$

## what is the complex conjugate

- given $z = a + ib$
- $z^* = a - ib$

## tensor product

- the tensor product lets us combine 2 smaller matrices to create a big one

$$
A \otimes B
=
\begin{bmatrix}
A_{11}B & A_{12}B & \dotsi \\
A_{21}B & A_{22}B & \dotsi \\
\vdots & \vdots
\end{bmatrix}
$$