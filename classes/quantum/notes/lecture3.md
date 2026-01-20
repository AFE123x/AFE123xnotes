# lecture 3

## phase flip noise channel

- the phase flip channel flips the phase of a qubit with probability $1 - p$. There are two elements:

$$
E_0 = \sqrt{p}I = \sqrt{p}\begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}
$$
$$
E_1 = \sqrt{1 - p}Z = \sqrt{p}\begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}
$$

## phase flip on bloch sphere

$\epsilon_{phaseflip}(0.64)$ on $\ket{+i}$

First, lets define $\ket{+i}$, it's between $\ket{-}$ and $\ket{+}$

$$
\ket{+i} = \frac{1}{\sqrt{2}}\begin{bmatrix}1 \\ +i \end{bmatrix}
$$

- $\ket{+i}$ lies on the y axis.

now, we can define the density matrix:

$\rho = \ket{+i} \bra{+i}$

$$
\frac{1}{\sqrt{2}}\begin{bmatrix}1 \\ +i\end{bmatrix} \frac{1}{\sqrt{2}}\begin{bmatrix}1 &-i\end{bmatrix} = \frac{1}{\sqrt{2}}\begin{bmatrix}1 & -i \\ +i &1 \end{bmatrix}


$$

$$
\sum_k E_k \begin{bmatrix}1 & -i \\ +i & 1\end{bmatrix} E_k^\dagger
$$

## depolarizing noise

$\delta_n \ket{\rho} = \sum_{i=0}^{3}{k_i \rho k_i^\dagger}$

$k_0 = \sqrt{1 - \frac{3}{4}\lambda} I$

$k_1 = \sqrt{\frac{\lambda}{4}}X$

$k_2 = \sqrt{\frac{\lambda}{4}} Y$

$k_3 = \sqrt{\frac{\lambda}{4}} Z$


- this is a universal compression from all axis' of the sphere.
    - in the bloch sphere it'll collapse towards the origin.

what's $\lambda$? it should be $\lambda = 1$


## stabilize state

- A stabilized state:
    - stabilizes a qubit.
    - account for error.
- bit flip noise is an example of an error that stabilizes itself.

| matrix | effect on qubit |
| --- | --- |
| I | stabilizes everything |
| X | stabilizes $\ket{+}$ |
| -X | stabilizes $\ket{-}$ |
| Y | stabilizes \ket{+i} |
| -Y | stabilizes \ket{-i} |
| Z | stabilizes $\ket{0}$ |
| -Z | stabilizes $\ket{1}$ |

## clifford operators

- clifford operators are operation that take us between the stabilized states.
    - these are significant since they take us between the 6 stabilized states, they're not very useful to quantum computing.
- examples include all the pauli vectors, Z gate, $S = \sqrt{Z}$,  etc.

- in order for clifford operators to be useful, you need at least one non-clifford operator that can free up your movement across the bloch sphere.

## non clifford operators

- thse are operators that can free up movement accross the bloch sphere.
- I = $\begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}$
- Z = $\begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}$
- S = $\sqrt{Z}$

## clifford operator example

$X \ket{1} = \ket{0}$

lets find the density matrix:

$$
X \ket{1} \bra{1} X^\dagger \\

= \bra{0}\ket{0}
$$

- this is all in the matrix view, now lets look at the stabilizer view

- what stabilizes $\ket{1}$? -Z

$$
-Z \ket{1} = \begin{bmatrix}-1 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}0 \\ 1\end{bmatrix} = \begin{bmatrix}0 \\ 1\end{bmatrix} = \ket{1}
$$

we can apply $X|-Z|x^\dagger$

$$
X|-Z|x^\dagger =
\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix} \begin{bmatrix}-1 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix} = \begin{bmatrix}0 & -1 \\ 1 & 0\end{bmatrix}\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix} = \begin{bmatrix}-1 & 0 \\ 0 & 1\end{bmatrix}
$$

**how do we get from -Z to Z**?

## apply gates to mixed state

- We use a density matrix to represent mixed states.
- We can't simply multiply a gate to a mixed state like we can for a pure state.
    - for this reason, we use the density matrix like below

$$
X \ket{\phi}\bra{\phi}X^\dagger
$$

## tensor product

- here, we multiply the matrices with matrices

$$
\ket{+} \otimes \ket{-} = \begin{bmatrix}\frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{2}}\end{bmatrix} \otimes \begin{bmatrix}\frac{1}{\sqrt{2}} \\ -\frac{1}{\sqrt{2}}\end{bmatrix}

=

\begin{bmatrix}\frac{1}{\sqrt{2}} \begin{bmatrix}\frac{1}{\sqrt{2}} \\ -\frac{1}{\sqrt{2}}\end{bmatrix} \\ \frac{1}{\sqrt{2}} \begin{bmatrix}\frac{1}{\sqrt{2}} \\ -\frac{1}{\sqrt{2}}\end{bmatrix}\end{bmatrix} = \begin{bmatrix}\frac{1}{2} \\ -\frac{1}{2} \\ \frac{1}{2} \\ -\frac{1}{2}\end{bmatrix}
$$
