# lecture 3

## stabilize states

- stabilized a qubit, accounting for error.
- example: performing bit flip, 

| matrix | what it does |
| --- | --- |
| X | stabilized $\ket{+}$ |
| -X | stabilized $\ket{-} |
| Y | stabilizes $\ket{+i}$ |
| -Y  | 

## clifford operators

- gates that changes the quantum state.
    - if you start stabilized.

- examples include:
    - Pauli matrices X, Y, Z
    - Hadamard gate
    - S gate ($\sqrt{z}$)
    - $\sqrt{x}$ gate: $R_x(90\degree)$

## non clifford operators

- $I = \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}$
- $Z = \begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}$
- $S = \sqrt{Z} = zzzzz$

## stabilizer tableau

$[z | x | r]$

$\begin{bmatrix}1 & 0 & 0\end{bmatrix}$
- z is the z state
- x is the pauli matrix x
- r is the phase

- one means the matrix is stabilized by the matrix, 0 mean it isn't.

- we can say $y = ixz$, which you can dedu my doing the multiplication.

## 