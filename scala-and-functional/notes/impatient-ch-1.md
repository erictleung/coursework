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
