# Scala for the Impatient Chapter 3

## Fixed Size Arrays

```Scala
val a = new Array[String](10) // string array with ten elements, init to null
val s = Array("Hello", "World") // no "new" when you init with values
val s(0) = "Goodbye"
```

## Variable Size Arrays: Array Buffers

```Scala
import collection.mutable.ArrayBuffer
val b = ArrayBuffer[Int]()
b += 1 // ArrayBuffer(1)
b += 2 // ArrayBuffer(1, 2)
b ++= Array(3, 4, 5) // Add any collection with ++=
b.trimEnd(3) // Remove last three elements
b.insert(2, 6) // Insert 6 at index 2
b.remove(2) // Remove element at index 2
b.toArray.toBuffer
```
