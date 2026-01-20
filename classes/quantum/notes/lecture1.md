# Lecture 1 - Introduction to quantum computing

## four principles needed to understand quantum computing

1. state space: how are quantum states described
2. composite systems: how are the quantum states composed?
3. evolution: how do qubit states evolve?
4. quantum measurements: once you allow your qubit to interract with the environment, what would the qubit look like?

- 1 to 3 describe closed quantum systems.
    - the particle states are closed off from the environment.
- 4 describes open quantum systems.
    - here, the quantum system is exposed to the 

## what is a quantum state, qubit?

- when looking at qunatum mechanics, we assume the state of a system is a continuous state space: $\int_{-\infty}^{\infty} \psi(x) \ket{x} dx$
- one simplification is we discretize the state space: $\sum_{i = 0}^{\infty} \psi(x_i)\ket{x_i}$
- next, we need to further simplify this to assume a descrete binary state space: $\sum_{i = 0}^1 \psi(x_i)\ket{x_i}$
    - now this state is a sum of $\psi(0)\ket{0} + \psi(1)\ket{1}$
- this is a qubit

## qubit - binary abstraction

- qubits can have one of two states:
    - $\begin{bmatrix}1 \\ 0\end{bmatrix}$, or $\ket{0}$
    - $\begin{bmatrix}0 \\ 1\end{bmatrix}$, or $\ket{1}$

## Dirac notation

- there are two parts, bra and ket notation

- $\ket{0} = \begin{bmatrix}1 \\ 0\end{bmatrix}$
- $\bra{0} = (\ket{0}^t)^* = \ket{0}^\dagger = \begin{bmatrix}1 & 0\end{bmatrix}$
    - bra 0 equals the conjugate transpose of ket 0

## conjugate

- given $z = a + ib$
- $z^* = a - ib$

## not gate

- we can represent the not gate using the NOT operator X

$$
X = \begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix}
$$

$$
X\ket{0} = \begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix} \begin{bmatrix}1 \\ 0\end{bmatrix} = \ket{1}
$$

$$
X\ket{1} = \ket{0}
$$

## hadamard gate

- the hadamard operator is the following matrix:

$$
H = \begin{bmatrix}
\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\
\frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}}
\end{bmatrix}
$$

$$
H\ket{0} = \frac{1}{\sqrt{2}}\ket{0} + \frac{1}{\sqrt{2}}\ket{1} = \ket{+}
$$

$$
H\ket{1} = \frac{1}{\sqrt{2}}\ket{0} - \frac{1}{\sqrt{2}}\ket{1} = \ket{-}
$$

- unlike the not gate, there's a probability the output state could either be $\ket{0}$ or $\ket{1}$

- we can nickname the output of the hadamard with $\ket{+}$ or $\ket{-}$

## passing ket + or - through hadamard gate.

- if you pass $\ket{+}$ or $\ket{-}$ into a hadamard gate, it'll remove the probability

$$
H\ket{+} = \ket{0}
$$

$$
H\ket{-} = \ket{1}
$$

## quantum superposition, normalized condition

- As we've seen, gates will output a probability of being in $\ket{0}$ or $\ket{1}$
    - $\alpha\ket{0} + \beta \ket{1} = \begin{bmatrix}\alpha \\ \beta\end{bmatrix}$

- we state that the probabilities are normalize if $|\alpha|^2 + |\beta|^2 = 1$

## unitary matrix

- a matrix is unitary only if $U^\dagger U = I$

## phase shift gate

- this is the pauli Z gate

$$
Z = \begin{bmatrix}
1 & 0 \\
0 & -1
\end{bmatrix}
$$

$Z \ket{0} = \ket{0}$

$Z \ket{1} = -\ket{1}$

## bloch sphere

- one way to understand the state of a qubit, is it has two parameters:
    - distribution of which basis state it's in, or if it's in the superposition of the two
    - the phase shift

$\ket{\psi} = \cos\frac{\theta}{2}\ket{0} + e^{i\phi} \sin \frac{\theta}{2}\ket{1}$, where $e^{i\phi} = \cos \phi + i\sin \phi$

- where $\theta$ is how much $\ket{1}$ there is.
- and $\phi$ determines the phase shift between the ket 0 and ket one bases


### drawing sphere with angles

- we can use these two angles to then draw the bloch sphere.

![alt text](image.png)

- the middle means half probability of $\ket{0}$ and $\ket{1}$, hence why $\ket{+}$ and $\ket{-}$ is on the x axis.
    - Also, there's no phase

## rotations around bloch sphere

- $R_x(\theta) = \cos \frac{\theta}{2} I - i \sin \frac{\theta}{2} X$
- $R_y(\theta) = \cos \frac{\theta}{2} I - i \sin \frac{\theta}{2} Y$
- $R_z(\theta) = \cos \frac{\theta}{2} I - i \sin \frac{\theta}{2} Z$
