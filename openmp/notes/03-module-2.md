# Module 2: The Boring Bits: Using an OpenMP Compiler (Hello World)

OpenMP compilers are fairly common these days and it is hard to not be able to
find one.

## Windows

Using Windows Intel compilers (I have not verified this yet), you would type the
following to compile your program:

```
icl /Qopenmp foo.c
```

To set the number of threads on your program, which will be talked about later,
you would type the following if you wanted 4 threads:

```
set OMP_NUM_THREADS=4
```

And to execute your program, you could type in the following:

```
foo.exe
```

## Visual Studio

- Start "New Project"
- Set win 32 console project
- Set name and path
- On next panel, click "Next" instead of finish
- Turn on OpenMP as your compiler
- Set number of threads inside the program
- Build the project in the standard way with Visual Studio
- Can debug

## Mac OS

Using GNU compiler with `gcc`. To compile on OS X, you can type the following:

```
gcc -fopenmp foo.c
```

In the bash shell, in order to set the thread count, you can type the following
to set the environment variable:

```
export OMP_NUM_THREADS=4
```

And to run the program you just compiled, you can type the following if you ran
the above command to compile (`a.out` is I believe the standard output if you do
not specify the output filename):

```
./a.out
```
