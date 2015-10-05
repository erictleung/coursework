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
if (x > 0) 1 // there statements...
if (x > 0) 1 else () // ...are the same
```

If you use the REPL to execute these control statements, you need brackets if
your control statement is multi-lined.

```Scala
if (x > 0) { 1
} else if (x == 0) else -1
```
