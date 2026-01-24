# lecture 2: introduction

- in QC, we have various aspects of QC:
    - states
    - gates
    - protocols
    - algortihms
    - repetition

## QECC
- Quantum Error Correction Code
- This is the main focus in 2026.

## Quantum mechanics - postulates

- Fourset of principles to build an understanding of quantum computing:
    - state space
    - composite system
    - evolution
    - quantum measurement.


```
    - state space. --------------------
    - composite system                | closed Quantum Systems
    - evolution  ----------------------
    - quantum measurement (non linear and describes open quantum system.)
````

- state space - how are quantum states described.
- composite systems: how do we put the states together.
- evolution: how do qubits evolve.
- quantum measurement: once you let the qubit interract with the interaction, what does the qubit state look like?
    - We want to get information out the quantum state.

## QIP vs. QM

- QIP = Quantum Information Processing
    - treat as discrete state, and time
- QM = Quantum Mechanics:
    - continuous time and continuous state.

## state of a single qubit

```
What is the qubit state represented by the geographical location of Old Queens?
```
- what exactly does this question mean?

## Transition from physics to discrete


- first we need to transition from a continuous state space to a discrete state space

- before, we assumed a continuous state space:
    - $| \psi > \int^\infty _{-\infty} \Psi (x) | x> dx$, there's no limit.
- after, we assume a discrete state space:
    - $|\psi > = \sum ^\infty _{i = 0} \pi (x_i)|x_i>$

- here, we're transitioning from the continuous state space to a discrete state space.

**Next, we need to go from a descrete state space to a discrete binarized state space**

- we first assume a discrete state space
    - $| \psi > = \sum^\infty _{i = 0} \psi (x_i) | x_i >$
- we can then transition nto the discrete binary state space:
    - $|\psi > = \sum^1 _ {i = 0} \psi (x_i) | x_i >$,
        - which says we assume combinations of two states.

## binary abstraction

- we have two states in quantum computer

- there's high and low voltage

- we have two main states:
$$
\begin{bmatrix}
1 \\
0
\end{bmatrix} = |0>, \text{ which wi call "ket" 0}

\begin{bmatrix}
0 \\
1
\end{bmatrix} = |1>, \text{ which wi call "ket" 1}
$$

the $|1>$ is known as derock notation

$|1> = \begin{bmatrix} 1 0\end{bmatrix}$
$<0| = \begin{bmatrix} 1 & 1\end{bmatrix}$

$<0|0> = \begin{bmatrix} 1 & 1\end{bmatrix}  \begin{bmatrix} 1 \\ 0\end{bmatrix} = 0$, read as bra zero, ket zero.

**is this just the binary abstraction on QC, or just classical computing.**

## Working on bra, ket states

- $X|0> = \begin{bmatrix} 0 & 1 \\ 1 & 0\end{bmatrix}\begin{bmatrix}1 \\ 0\end{bmatrix} = \begin{bmatrix}0 & 1\end{bmatrix} = | 1 >$
- $X|1> = \begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}\begin{bmatrix} 0 \\ 1\end{bmatrix} = \begin{bmatrix}1 \\ 0\end{bmatrix}$

## hadamard gate

- the hadamard gate is the matrix $H = \begin{bmatrix}\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{2}} & \frac{-1}{\sqrt{2}}\end{bmatrix}$


- This matches the idea of the photon detector thing pretty well. It's probabilistic in nature.
- We usually pass our value into multiple gates to get a final value.

## superposition

- in a single qubit state, you have matrices n stuff.

- there are other physical phenomena that can be used to represent qubits.

**ask mary for notes**