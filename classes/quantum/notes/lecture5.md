# Lecture 5

## entanglement

- entangement is a unique quantum correlation between qubits, where the state of one qubit cannot be described independently of the other

## measuement

- a quantum postulate
- Quantum computers are usually closed systems.
    - when there's an interaction with the outside world, which is the process of measurement.
- when measurement happens, the quantum state can collapse into one of three processes.
- there are many ways to interpret measurement:
    - one is you get something about the state
    - another way to think of it is how measuring introduces noise, and how the quantum state can suffer


### more detail

- quantum postulate that stands out:
    - we're no longer working with a closed system, rather we're interacting with the outside world (either in a controlled or uncontrolled way.)

- two states make in into measurements:
    - pure state
    - entangled
    - noisy states

- in this class, we're talking about the first two.

- $P(\ket{a_n})$, the probability of the measured quantum state becomes the final state, is $\bra{\psi}\ket{a_n}\bra{a_n}\ket{\psi}$
    - we can simplify the expression to $|\bra{a_n}\ket{\psi}|^2$

- we can also say $\sum_n \ket{a_n}\bra{a_n} = I$
## example measurement

$\ket{\psi} = \ket{-} = \begin{bmatrix}\frac{1}{\sqrt{2}} \\ - \frac{1}{\sqrt{2}}\end{bmatrix}$

- you have this superposition state in the interferometer.
    - this described some superposition that the photon is taking both paths at one, but one of them has a delay.
- now, the photon is phase-shifted with respects to eachother.
    - one suffered a delay while the other one didn't.
    - now, we're asking which detector the photon went into.

- We're finding what's the probability of the photon going into the $\ket{1}$ basis.

$$
P(\ket{1}) = \bra{-}\ket{1}\bra{1}\ket{-} = |\bra{1}\ket{-}|^2 \\
\begin{bmatrix}0 & 1\end{bmatrix}\begin{bmatrix}\frac{1}{\sqrt{2}} \\ -\frac{1}{\sqrt{2}}\end{bmatrix} = |-\frac{1}{\sqrt{2}}|^2 = \frac{1}{2}
$$

hence the probability the qubit $\ket{-}$ will be measured by the $\ket{1}$ detector is $\frac{1}{2}$

## tensor flow example

$\ket{0} = \begin{bmatrix}\alpha \\ \beta\end{bmatrix}$

- $\ket{\Psi} = \begin{bmatrix}\alpha_0 \\ \alpha_1 \\ \alpha_2 \\ \alpha_3\end{bmatrix} = \alpha_1\ket{00} + \alpha_2\ket{01} + \alpha_3\ket{10} + \alpha_4\ket{11}$
- here, we add the second qubit, hence we need four probability amplitudes

## CNOT gate

- a gate containing two qubits:
    - one control bit
    - another control bit that can flip depending on control bit.

|input| output|
| --- | --- |
| $\ket{00}$ | $\ket{00}$ |
| $\ket{01}$ | $\ket{01}$ |
| $\ket{10}$ | $\ket{11}$ |
| $\ket{11}$ | $\ket{10}$ |

$CNOT = \ket{00}\bra{00} + \ket{01}\bra{01} + \ket{10}\ket{11} + \ket{11}\bra{10}$

we can use this equation to evaluate the result of the matrix:

given input $\ket{10}$
$$
\ket{11}\bra{10}\ket{10} \\

\ket{11}(\bra{10}\ket{10}) \\

= \ket{11}
$$

## evolution of a qubit

- You can think of qubits, not as just matrices, but matrices that undergo transformations.
    - we represent transformations with $U$
    - hence, $\ket{\psi_1} = U\ket{\psi_0}$

- in a closed system, $\bra{\psi_1}\ket{\psi_1} = \bra{\psi_0} U^\dagger U\ket{\psi_0} = \bra{\psi_0}\ket{\psi_0} = 1$

- in other words, if the sum of the probability isn't one, that means we didn't cover all transformations

## cloning qubits

- You cannot clone qubits!!!
