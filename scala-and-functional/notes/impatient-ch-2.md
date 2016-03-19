# Scala for the Impatient Chapter 2

## Conditional Expressions

Scala has this kind of `if/else` control structure.

```Scala
if (x > 0) 1 else -1 // if/else statement
val returnVal = if (x > 0) 1 else -1 // can save as a value
if (x > 0) s = 1 else s = -1 // same as above
```

You can have mixed types for the expression.

```Scala
if (x > 0) "positive" else -1
```

The `if/else` can omit the `else` statement and will return no value. In Scala,
it is a class `Unit` that is written as `()`.

```Scala
if (x > 0) 1 // these statements...
if (x > 0) 1 else () // ...are the same
```

If you use the REPL to execute these control statements, you need brackets if
your control statement is multi-lined.

```Scala
if (x > 0) { 1
} else if (x == 0) else -1
```

## Statement Termination

Semicolons in Scala are optional. However, if you want to have more than one
statement on one line, you will need a semicolon to disambiguiate the two
statements.

```Scala
if (n > 0) { r = r * n; n -= 1 }
```

Additionally, if your expression has to span two lines and you need a break, you
need to end the original line with a symbol that cannot be the end of a
statement.

```Scala
s = s0 + (v - v0) * t + // the plus sign tells Scala this line doesn't end
    0.5 * (a - a0) * t * t
```

## Block Expressions and Assignments

Blocks are set apart with curly brackets (`{` and `}`). These blocks represent
expressions. Here's an example:

```Scala
val distance = { val dx = x - x0; val dy = y - y0; sqrt(dx * dx + dy * dy) }
```

The result of these expressions is also an expression. Meaning that assignments
have no value, strictly speaking.

## Loops

There are two type of loops in Scala, similar to ones found in other programming
languages: `for` and `while` loops.

### `for` Loop

```Scala
// can be written with line breaks
for (i <- 1 to 5)
  println(i)

// or written without line breaks
for (i <- 1 to 5) println(i)
```

Both of these do not require the `initialize; condition; increment` elements in
the `for` loop.

### `while` Loop

```Scala
while (n > 0) {
  r = r * n
  n -= 1
}
```

### Breaking Out of Loops

1. Use a Boolean variables
2. Nested functions to return from the middle function
3. Use break method from `import util.control.Breaks._`

## Advanced `for` Loops and `for` Comprehensions

There are four concepts in advanced `for` loops:

1. Multiple variables
2. Conditions on looping variables
3. Create collection of values

### Multiple Variables

Multiple variables in the `for` loop are separated with a semicolon and the
ranges for the additional variables are defined the same way.

```Scala
for (i <- 1 to 4; j <- 1 to 4) print((10 * i + j) + "\n")
```

### Conditions on Loop Variables

```Scala
for (i <- 1 to 4; j <- 1 to 4 if i != j) print((10 * i + j) + "\n")
```

Note the lack of a semicolon before the `if` statement.

### Create Collection of Values

```Scala
for (i <- 1 to 4) yield i
```

Yields an immutable indexed sequence. This kind of loop is called a `for`
*comprehension*.

## Functions

Functions defined with name, parameters, then body.

```Scala
def abs(x: Double) = if (x >= 0) x else -x
```

Can also define the type for the output.

```Scala
def fac(n: Int): Int = if (n <= 0) 1 else n * fac(n - 1)
```