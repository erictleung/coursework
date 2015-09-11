# Scala for the Impatient Chapter 1

## The Interpreter

The "interpreter" is the command `scala` once you have installed Scala
correctly. This can be seen as a REPL (or read-execute-print loop). However,
this is not truly a REPL because in the background, the "interpreter" is in
real-time converting the code into byte code and executed by the Java Virtual
Machine (JVM).

## Declaring Variables

There are two ways of storing information in Scala. 

- `val variable_name`: this creates an immutable variable (more like a "constant")
- `var variable_name`: this creates a mutable variable

When saving a variable, you can either specify the type or you can let Scala
figure it out on its own.

```Scala
val hello = "Hello" // you cannot change the value of `hello`
var hello_changes = "Hello, world!" // can change the value of `hello_changes`
```

Within the context of the REPL and related declaring variables is how to use the
output of one command later. When you run a command, say `8*8`, you will get
something like `res0: Int = 64` back. The `res0` can be called in future
commands.

You can also declare multiple variables.

```Scala
var i, j = 0
```

## Data Types

- `Byte`
- `Char`
- `Short`
- `Int`
- `Long`
- `Float`
- `Double`
- `Boolean`

There is no difference between *primitive* data types and *class* data types. 

```Scala
1.toString() // converts 1 to string
1.to(10) // yields Range(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
```

## Arthimetic and Operator Overloading

```Scala
a + b // shorthand
a.+(b) // longhand
```

The `+` is the name of the method the variable `a` is calling. Methods are not
limited to alphanumeric characters. Example, the `BigInt` class defines a method
called `/%` to return a pair containing the quotient and remainder of a
division.

```Scala
1.to(10) // longhand
1 to 10 // same thing
counter += 1 // increments b/c there is no ++ or -- in Scala
```

"Operator overloading" is presume is the ability to encode methods with whatever
characters the programmer deems necessary and appropriate. For example, Java
does not allow operator overloading, meaning you cannot create operators like
`!@$&*`.

## Calling Functions and Methods

```Scala
sqrt(2) // gives 1.4142135623730951
pow(2, 4) // gives 16.0
min(3, Pi) // gives 3.0
```

These mathematical functions are defined in `scala.math` package. You can import
them with `import math._` where the underscore (`_`) is a wildcard. Notice that
the package is `scala.math` but in the import statement you can ignore the
`scala.` part.

```Scala
"Hello".distinct // same as
"Hello".distinct()
```

## The `apply` Method

There is a particular syntax that looks like a function call.

```Scala
"Hello"(4) // returns 4th char of string i.e. "o"
```

The `()` looks overloaded but it is really an implementation of the
`apply` method.

```Scala
def apply(n: Int): Char // method from `StringOps` class

"Hello".apply(4) // this is what is really happening to "Hello"(4)

BigInt("1234567890") // is the same as...
BigInt.apply("1234567890")
```
