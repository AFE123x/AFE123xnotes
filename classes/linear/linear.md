# Linear Algebra Notes

## what's a matrix, components

$$
A = \begin{bmatrix}
2 & 6 \\ -1 & 0
\end{bmatrix} \\
B = \begin{bmatrix}
9 & -2 & 1 & 8 \\ 0 & 0 & -1 & 4
\end{bmatrix} \\
C = \begin{bmatrix}
1 \\ -4 \\ 2
\end{bmatrix} \\
D = \begin{bmatrix}
-3 & 4 & 0 & 6
\end{bmatrix}
$$

- matrices vary, we may want to know the following components:
    - dimensions: $Rows \times Columns$
    - entries: $a_{1,2}$, $a_{2,1}, a_{row,column}$

## pivot entries

- Pivot Entries are the first non-zero entry in each row

$$
\begin{bmatrix}
4 & 1 & 0 & 17 \\
0 & 2 & 4 & 10 \\
0 & 0 & -3 & 2
\end{bmatrix}
$$

- 4, 2 and -3 are pivot entries.

## Row echelon forms, Reduced Row Echelon Form

- row echelon form means:
    - all pivot entries are 1
    - any rows that consists of zeroes are at the bottom of the matrix
    - the pivot sits in a diagonal pattern.
- Reduced Row Echelon form means each pivot column has only the pivot entry.

## numbe of solutions to linear system

- Matrices can have:
    - one solution (unique solution).
    - no soution
    - infinitely many solutions


### unique solution

- if we get a reduced row echelon matrix, we have a unique solution

$$
\begin{bmatrix}
    1 & 0 & 0 & a \\
    0 & 1 & 0 & b \\
    0 & 0 & 1 & c
\end{bmatrix}
$$

### no solution

$$
\begin{bmatrix}
    1 & 0 & 0 & a \\
    0 & 1 & 0 & b \\
    0 & 0 & 0 & c
\end{bmatrix}
$$

- here, if we assume c is non zero, this equation says 0 = c, which is never true, hence we can conclude no solution exitss

### infinitely many solutions

If you end up with something like this:

$$
\begin{bmatrix}
    1 & 0 & 0 & a \\
    0 & 1 & 0 & b \\
    0 & 0 & 0 & 0
\end{bmatrix}
$$

- this is accurate, as 0 = 0, hence we can conclude this matrix has infinitely many solutions.