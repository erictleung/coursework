# Exercise 2: Make is Your Python Now

## About Make

In Python, you could run a script by running: `python your_script.py`.
Similarly, the `make` command does the hard compiling for you.

According to the [GNU `make` documentation][makedocs], the `make` utility
"determines automatically which pieces of a large program need to be recompiled,
and issues the commands to recompile them."

## Using Make

Say we have a program `ex1.c` and we want to compile it. Using `make`, we can
type the following in our command line: `make ex1`. 

This will set in motion the following process in your computer:

- Does the file `ex1` exist?
- No. Okay, is there another file that exists as `ex1`?
- Yes, but it's called `ex1.c`. Do I know how to build `.c` files?
- Yes, I can run the command `cc ex1.c -o ex1` to build it.
- I shall make you one `ex1` by using `cc` to build it from `ex1.c`

A way to pass some modifiers to `make` is to prepend them to your command:
`CFLAG="-Wall" make ex1`.

A note about makefiles is that they should be tab indented instead of a mixture
of spaces and tabs. 

## What can we do now?

A simple make file could be:

```
CFLAGS=-Wall -g

clean:
    rm -f ex1
``

This allows you to build your program with `make ex1` and remove your compiled
program with `make clean`. 

[makedocs]: http://www.gnu.org/software/make/manual/make.html#Introduction
