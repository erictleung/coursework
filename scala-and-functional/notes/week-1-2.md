# Elements of Programming

- Primitive expressions = simplest elements
- Ways to combine expressions
- Ways to abstract expressions e.g. variables

# The Read-Eval-Print Loop

- Interactive shell = REPL = Read-Eval-Print-Loop
- Scala REPL

```
scala
```

# Evaluation

- Evaluate expressions
- Use rules from mathematics
- Go left-to-right
- Apply operator to operands
- Name or variable evaluated by elements on right side of it
- Evaluation will stop when it has a value
    - Value = number (for now)

# Example

```
(2 * pi) * radius
(2 * 3.14159) * radius
6.28318 * radius
6.28318 * 10
62.8318
```

# Parameters

- Definitions can have parameters
- Parameters are elements that are passed into functions or definitions

# Parameter and Return Types

- Function parameters come with their types
- Given after colon

```Scala
def power(x : Double, y: Int): Double = ...
```

- Lots of primitive types
- Same as Java, but capitalized
    - `Int`
    - `Double`
    - `Boolean`

# Evaluation of Function Applications

- Similar to definitions from above
- Evaluate things left to right
- Replace and continue

# Example

```Scala
sumOfSquares(3, 2 + 2)
sumOfSquares(3, 4)
square(3) + square(4)
3 * 3 + square(4)
9 + square(4)
9 + 4 * 4
9 + 16
25
```

# The Substitution Model

- This scheme of substitution
- Idea is reduce expression --> value
- Can be applied to all expressions
- Formalized in Lambda calculus
    - Foundations of functional programming
- Less side effects

# Termination

- Every expression --> value?
- No!

```
def loop: Int = loop
loop
```

# Changing the Evaluation Strategy

- Scala reduces function arguments to values first, then rewrite function
- Another method is to use unreduced arguments

```
sumOfSquare(3, 2 + 2)
square(3) + square(2 + 2)
...
```

# Call-by-name and call-by-value

- First method = call-by-value
- Second method = call-by-name
- Both methods equal as long as:
    - reduced expressions are pure functions
    - both evaluations terminate
