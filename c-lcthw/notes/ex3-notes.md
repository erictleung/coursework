# Exercise 3: Formatted Printing

`printf` stands for "print formatted." Characters are echoed literally, while
parameters, which are marked by **format specifiers**, will substitute text or
format the resulting string. These format specifiers are typically introduced by
a `%` character. 

## Syntax

The syntax for a format placeholder is:

```
%[parameter][flags][width][.precision][length]type
```

### Parameter Field

Additionally, you can specify exactly which parameter you want to put where in
your string with the `n$` characters. Here is an example.

```
printf("%2$d %2$#x; %1$d %1$#x",16,17)
```

This produces the string: "17 0x11; 16 0x10."

### Flags Field

| Character | Description                                                                             |
| --------- | --------------------------------------------------------------------------------------- |
| - (minus) | Left-align the output. Default is right-align output.                                   |
| + (plus)  | Prepends a plus for a positive signed-numeric types. Default does not prepend anything. |
|  (space)  | Prepends space for positive signed numeric types.                                       |
| 0 (zero)  | When 'width' specified, will prepend zeros for numeric types.                           |
| # (hash)  | Alternate forms for various numeric types.                                              |

Source: https://en.wikipedia.org/wiki/Printf_format_string
