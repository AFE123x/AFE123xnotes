# Lecture 6

## BB84

- BB84 is a quantum key distribution scheme that allows alice and bob to generate a shared secret key.
    - they could also tell if someone intercepted.

- Alice will randomly send qubits to bob
    - she'll flip a coin twice
        - first time to determine whether to send 0 or 1
        - again to determine whether to choose the X or Z basis (X basis meaning she applies a hadamard gate)
- Bob will randomly decide whether each incoming qubit is in the Z basis or X basis.
- After alice and bob do their things:
    - alice and bob will communicate over a public channel to filter their data
        - what basis they used for the qubit. From there, get rid of the incorrect basis used.

- this works in quantum, since you cannot clone qubits.
    - if an eavesdropper tries to mess with alice's key, they can't clone it, they affect it directly.
    - if bob's bits are different despite the basis used, the key was tampered with.

## no cloning theorem

- this theorem states that you cannot clone qubits.

- Assume you can clone qubits, this means:

$$
U(\ket{\psi} \otimes \ket{0}) = \ket{\psi} \otimes \ket{\psi} \text{, for all quantum states } \psi
$$

lets create two equations:

$$
U(\ket{\psi}\ket{0}) = \ket{\psi}\ket{\psi} \\
U(\ket{\phi}\ket{0}) = \ket{\phi}\ket{\phi}
$$
