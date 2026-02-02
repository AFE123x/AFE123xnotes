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