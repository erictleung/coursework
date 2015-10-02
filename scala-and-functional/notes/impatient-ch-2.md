# Scala for the Impatient Chapter 2

## Conditional Expressions

Scala has this kind of `if/else` control structure.

```Scala
if (x > 0) 1 else -1 // if/else statement
val returnVal = if (x > 0) 1 else -1 // can save as a value
if (x > 0) s = 1 else s = -1 // same as above
```

The `if/else` can have not `else` statement and will return no value. In Scala,
it is a class `Unit` that is written as `()`. 

```Scala
if (x > 0) 1 // there statements...
if (x > 0) 1 else () // ...are the same
```
