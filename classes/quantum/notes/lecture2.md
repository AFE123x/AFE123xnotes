# lecture 2

## qubit - type of states

- pure states: on the bloch sphere surface
- noisy states: not on the bloch sphere

## pauli matrices

- These are the foundational matrices:

$$
I = \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}
$$
$$
X = \begin{bmatrix}0 & 1 \\ 0 & 1\end{bmatrix}
$$
$$
Y = \begin{bmatrix}0 & -i \\ i & 0\end{bmatrix}
$$
$$
Z = \begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}
$$

- these are the matrices that make the rotations about the bloch sphere work.
- these are the bases of all unitary matrices.
    - $U = \alpha X + \gamma Y + \delta Z$

## hardware noise

- Some errors aren't the programmer's fault, but it could be the hardware's fault.
- this could be due to decoherence, gate or measurement errors.
- there's posilibities that bit flips can occur.
- quantum computer hardware is unreliable, and is prone to noise.
    - when the light beams at the ion, it gets excited. Overtime, the excited state will decay, and could be read as the ground state. 
        - this is random, and there exists a probability.

## types of noise

- bit flip noise
    - $\ket{1}$ decays towards $\ket{0}$
- phase flip noise
- combination of the two
## representing bit flips

- $\ket{0} \rightarrow BitFlip(0.64)$
    - where $P(\ket{0}) = 0.64$
    - and $P(\ket{1}) = 0.36$, which means it got bit flipped from ket 0 to ket 1.

- we can represent them with a density matrix

$$
0.64\ket{0}\bra{0} + 0.36\ket{1}\bra{1}
$$

$$
= 0.64 \begin{bmatrix}1 \\ 0\end{bmatrix} \begin{bmatrix}1 & 0\end{bmatrix}

+

0.36  \begin{bmatrix}0 \\ 1\end{bmatrix} \begin{bmatrix}0 & 1\end{bmatrix}
$$

$$
= 0.64 \begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix} + 0.36 \begin{bmatrix}0 & 0 \\ 0 & 1\end{bmatrix}
$$

$$
= \begin{bmatrix}0.64 & 0 \\ 0 & 0.36\end{bmatrix}
$$

## two types of uncertainty

- phase noise.
- idea quantum state could be both ket 0 and ket 1.

## density matrix

$\rho = \sum_j P_k \ket{\psi}\bra{\psi}$, where the probabilities should add up to one.

## quantum channels

- these are functions that take in a density matrix, and output another density matrix


## krause representation

$$
\epsilon (\rho) = \sum_k E_k \rho E_k^\dagger
$$

- this provides us a way to see how the environment affects the system.

## bloch vector

- we may want to figure out where the quantum state is on the bloch sphere.

- to get this, we can use $\rho = \frac{I + \vec{r} + \vec{\sigma}}{2}$

### example

given $\rho = \begin{bmatrix}0.64 & 0 \\ 0 & 0.36\end{bmatrix}$

- we can multiply both sides by 2:

$$
2\rho = I + \vec{r} + \vec{\sigma}
$$

$$
2 \rho = \begin{bmatrix}1.28 & 0 \\ 0 & 0.72\end{bmatrix}
$$

from here, we can subtract the identity matrix from both sides

$$
2\rho - I = I + \vec{r} + \vec{\sigma} - I
$$

$$
2 \rho - I = \begin{bmatrix}1.28 & 0 \\ 0 & 0.72\end{bmatrix} - \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}
=
\begin{bmatrix}1.28 - 1 & 0 \\ 0 & 0.72 - 1\end{bmatrix}

=

\begin{bmatrix}0.28 & 0 \\ 0 & -0.28\end{bmatrix}

$$

we can see the matrix looks similar to Z, so we can further simplify this:

$$
\vec{r} \cdot \vec{\sigma}.= 0.28\sigma_z
$$

so the block vector is:

$$
\begin{bmatrix}
r_x = 0 \\
r_y = 0 \\
r_z = 0.28
\end{bmatrix}
$$
