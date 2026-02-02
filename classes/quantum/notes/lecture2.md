# Lecture 2

## things to know about qubit

- Pure states: states that are represented by surface of bloch sphere.
    - aka, idealized states for qubits
    - on the surface, it has two vectors, similar to longitude and latitude
- noisy states: these are less than ideal states, needs to correctly 
    - we use stabilizer states to bring the noisy states to pure states.

## pauli matrix

- The pauli matrix has four vectors:
    - $I = \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}$
    - $X = \begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}$
    - $Y = \begin{bmatrix}0 & -1 \\ i & 0\end{bmatrix}$
    - $Z = \begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}$

- these are three complex matrices that are traceless, hermitian, involutory and unitary.

## hardware noise

- quantum bits can be unreliable due to:
    - decoherence error
        - chemistry stuff: ion will get excited, but will get tired.
        - basically, the qubit will become incoherent.
    - gate error
        - imprecise control of single qubit, two qubit gates.
        - the 
    - measurement error:
        - the way to extract data from the qubit is incorrect.

## types of noise

- bit flip noise: when 0 flips to 1
- phose flip noise
- combination of the prior 2.
- types of noise where the balance between $\ket{1}$ and $\ket{0}$ **ask**

## modeling bit noise mathmatically

$\ket{0} \rightarrow BitFlip(0.64) \rightarrow \begin{cases} P(\ket{0}) = 0.64 \\ P(\ket{1}) = 0.36\end{cases}$

- we can represent this probability as a **density matrix**

$$
0.64\ket{0}\bra{0} + 0.36 \ket{1} \ket{1}
$$

- two variables of uncertainty:
    - noise: there's a distribution.
    - quantum uncertainty: the qstate can be both 0 and 1.

- $0.64|\ket{+}\bra{+}| + 0.36|\ket{-}\bra{-}|$
    - this is flipped with a phase flip

## density matrices

$\rho = \sum_{j} P_j \ket{\psi_j} \bra{\psi_j} = 1$


## quantum channel

- what are channels?
    - these are links between two things, we're transmitting qubit data

$\epsilon(\rho) = \sum_{k} E_k \rho E_k ^\dagger = \sum_k E_k\ket{\psi}\bra{\psi}E_k ^\dagger$, this is Kraus Operators.

## bit flip noise channel

- the bit flip channel flips the state of qubit with probability of 1 - p. there are two elements:

$$
E_0 = \sqrt{p}I = \sqrt{p} \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix} \\
E_0 = \sqrt{1 - p}I = \sqrt{1 - p} \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}
$$

### example

$$
\epsilon_{bitflip}(\begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix}) = \sum_{k} E_k \begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix} E_k^\dagger \\

0.8 \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix} 0.8 \begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix} + 0.6 \begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}\begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix}0.6\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix} = \begin{bmatrix}0.64 & 0 \\ 0 & 0.36\end{bmatrix}
$$

## bloch vector

$$
\rho = \frac{I + \vec{r} \cdot \vec{\sigma}}{2}
$$

## depolarizing noise

$$
\triangle_\lambda (\rho) = \sum_{i = 0}^3 K-i p k_i ^\dagger\\

K_0 = \sqrt{1 - \frac{3}{4}\lambda} I \\
K_1 = \sqrt{\frac{\lambda}{4}} X
K_2 = \sqrt{\frac{\lambda}{4}} Y
K_3 = \sqrt{\frac{\lambda}{4}} Z \\
\text{what should } \lambda \text{ be?}

$$

- it models the destrucction of information.
- it's not unbalanced, biased or correlated.
    - aka, it the's simplest model of noise, with few free noise.


**what should lambda be?**

- the maximally mixed state:
    - $\rho = \frac{I}{2} \\ = \frac{I + \vec{r} + \vec{\sigma}}{2} \\ \vec{r} = \begin{bmatrix}0 \\ 0 \\ 0\end{bmatrix}$

## Phase flip noise channel

- The phase flip noise chanel.

$E_0 = \sqrt{p} I = \sqrt{p} \begin{bmatrix} 1 & 0 \\ 0 & 1\end{bmatrix}$

$E_1 = \sqrt{1 - p} Z = \sqrt{p} \begin{bmatrix}1 & 0 \\ 0 & -1 \end{bmatrix}$

- on the bloch sphere, it'll span on the x and y axis

## key i states

$\ket{+1}$ is at one end of the y axis
