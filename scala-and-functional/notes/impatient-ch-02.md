# Scala for the Impatient Chapter 2

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [Conditional Expressions](#conditional-expressions)
- [Statement Termination](#statement-termination)
- [Block Expressions and Assignments](#block-expressions-and-assignments)
- [Loops](#loops)
  - [`for` Loop](#for-loop)
  - [`while` Loop](#while-loop)
  - [Breaking Out of Loops](#breaking-out-of-loops)
- [Advanced `for` Loops and `for` Comprehensions](#advanced-for-loops-and-for-comprehensions)
  - [Multiple Variables](#multiple-variables)
  - [If Conditions on Loop Variables](#if-conditions-on-loop-variables)
  - [Definitions in looping variables](#definitions-in-looping-variables)
  - [Create Collection of Values](#create-collection-of-values)
- [Functions](#functions)
- [Default and Named Arguments](#default-and-named-arguments)
- [Variable Arguments](#variable-arguments)
- [Procedures](#procedures)
- [Lazy Values](#lazy-values)
- [Exceptions](#exceptions)
  - [`throw` an Exception](#throw-an-exception)
  - [Try/Catch](#trycatch)
  - [Try/Finally](#tryfinally)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

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

Additionally, if your expression has to span two lines and you need a break,
you need to end the original line with a symbol that cannot be the end of a
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

There are two type of loops in Scala, similar to ones found in other
programming languages: `for` and `while` loops.

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

Traversing a string/array you go from `0` to `n - 1`, use `until`.

```Scala
for (i <- 0 until size) println(i)
```

### Breaking Out of Loops

1. Use a Boolean variables
2. Nested functions to return from the middle function
3. Use break method from `import util.control.Breaks._`

## Advanced `for` Loops and `for` Comprehensions

There are four concepts in advanced `for` loops:

1. Multiple variables/generators (*generators*)
2. If conditions on looping variables (*guard*)
3. Definitions in looping variables (*definitions*)
4. Create collection of values (*comprehensions*)

### Multiple Variables

Multiple variables in the `for` loop are separated with a semicolon and the
ranges for the additional variables are defined the same way.

```Scala
for (i <- 1 to 4; j <- 1 to 4) print((10 * i + j) + "\n")
```

### If Conditions on Loop Variables

```Scala
for (i <- 1 to 4; j <- 1 to 4 if i != j) print((10 * i + j) + "\n")
```

Note the lack of a semicolon before the `if` statement.

### Definitions in looping variables

Here we define `from` to be used in the `for` loop.

```Scala
for (i <- 1 to 3; from = 4 - i; i <- from to 3) print((10 * i + j) + " ")
```

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

Can also define the type for the output. But you must define this for recursive
functions, such as the one below.

```Scala
def fac(n: Int): Int = if (n <= 0) 1 else n * fac(n - 1)
```

## Default and Named Arguments

Sometimes you want default parameters. And you can define things based on their
parameter names

```Scala
// Define function
def decorate(word: String, left: String = "[", right: String = "]") {
  left + word + right
}
decorate("Hello") // "[Hello]"
decorate("Hello", "<<<") // "<<<Hello]"
decorate(left = "<<<", word = "Hello", right = ">>>") // "<<<Hello>>>"
```

## Variable Arguments

Use the `*` character to extend arguments.

```Scala
def capitalize(args: String*) = { args.map(_.capitalize) }
```

## Procedures

Procedures are functions that have no return value. There are created as a
normal function would but removing the equals sign.

```Scala
def box(s: String) { // Notice no equals sign
  val border = "-" * s.size + "--\n"
  println(border + "|" + s + "|\n" + border)
}
```

## Lazy Values

You can make a variable such that it will only initialize after the first time
you use it. Hence being "lazily" initialized.

```Scala
// Should be "words" not "wors"
// This will not create an error
lazy val words = io.Source.fromFile("/usr/share/dict/wors").mkString
words // This will create the error
```

## Exceptions

You can create exceptions using `throw` and `try/catch`, along with `finally`.

### `throw` an Exception

```Scala
// Exception
val x = -4
if (x >= 0) {
  sqrt(x)
} else {
  throw new IllegalArgumentException("x should not be negative")
}
```

### Try/Catch

Try/catch statements are to *try* a statement(s) and do something else if the
first try fails in order to *catch* any errors.

```Scala
// Try/Catch
try {
  process(new FileReader(filename))
} catch {
  case _: FileNotFoundException => println(filename + " not found")
  case ex: IOException => ex.printStackTrace()
}
```

### Try/Finally

The `finally` statement will execute regardless of whether the `try` raises an
exception or not.

```Scala
// Try/Finally
val reader = new FileReader(filename)
try {
  process(reader)
} finally {
  reader.close()
}
```
