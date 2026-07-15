# Linear-Algebra-Algorithms

[cite_start]This repository contains C++ implementations of three direct methods to solve systems of linear equations ($Ax = b$)[cite: 1, 7]. [cite_start]This project was developed by Umair Asif as part of a Project-Based Learning (PBL) project[cite: 3].

## System Solved in this Project
[cite_start]The implemented algorithms are tested against the following system of three linear equations[cite: 5, 6]:
$$2x + y + z = 8$$
$$-3x - y + 2z = -11$$
$$-2x + y + 2z = -3$$

[cite_start]All three methods correctly yield the unique solution[cite: 232]:
* [cite_start]**x** = 2.0 [cite: 233]
* [cite_start]**y** = 3.0 [cite: 233]
* [cite_start]**z** = -1.0 [cite: 233]

---

## Solvers Included

### 1. Gaussian Elimination
* [cite_start]**How it works:** Transforms the coefficient matrix into an upper triangular form using row operations (with partial pivoting) and solves using back substitution[cite: 18, 21, 22, 23].
* [cite_start]**Complexity:** $O(n^3/3)$ elimination, $O(n^2/2)$ back substitution[cite: 25].
* [cite_start]**Best use case:** Best choice for a simple, single-system solve[cite: 237].

### 2. Gauss-Jordan Elimination
* [cite_start]**How it works:** Extends Gaussian elimination by zeroing out elements both above and below the pivots to yield a reduced row echelon form (RREF), reading the solution directly[cite: 85, 91, 92].
* [cite_start]**Complexity:** $O(n^3/2)$ elimination phase[cite: 94].
* [cite_start]**Best use case:** Best utilized when computing a matrix inverse[cite: 238].

### 3. LU Decomposition
* [cite_start]**How it works:** Factors the coefficient matrix $A$ into a lower triangular matrix $L$ and an upper triangular matrix $U$ ($A = LU$)[cite: 151]. [cite_start]It solves the system in two phases: forward substitution ($Ly = b$) and backward substitution ($Ux = y$)[cite: 152, 154, 155].
* [cite_start]**Complexity:** $O(n^3/3)$ for decomposition, $O(n^2)$ for each subsequent vector $b$[cite: 158].
* [cite_start]**Best use case:** Highly recommended for professional software where multiple right-hand side vectors $b$ must be solved cheaply once $A$ is factored[cite: 235].

---

## Performance Summary

| Method | Elimination Complexity | Solution Complexity | Overall Complexity |
| :--- | :--- | :--- | :--- |
| **Gaussian Elimination** | [cite_start]$O(n^3/3)$ [cite: 225] | [cite_start]$O(n^2/2)$ [cite: 25] | [cite_start]$O(n^3)$ [cite: 225] |
| **Gauss-Jordan** | [cite_start]$O(n^3/2)$ [cite: 225] | [cite_start]$O(1)$ [cite: 225] | [cite_start]$O(n^3)$ [cite: 225] |
| **LU Decomposition** | [cite_start]$O(n^3/3)$ [cite: 225] | [cite_start]$O(n^2)$ per $b$ [cite: 225] | [cite_start]$O(n^3)$ [cite: 225] |

---

## How to Run the Code

Ensure you have a C++ compiler installed (such as `g++`).

1. Clone this repository:
   ```bash
   git clone [https://github.com/your-username/Linear-Algebra-Algorithms.git](https://github.com/your-username/Linear-Algebra-Algorithms.git)
