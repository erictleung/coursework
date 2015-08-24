# Exercise 4: Introducing Valgrind

This lesson is all about `valgrind`, which is a "powerful open-source memory
debugger."

## Installation

You can install it from source [here][download]. 

By command line, here is how you would install it:

```
curl -O http://valgrind.org/downloads/valgrind-3.10.1.tar.bz2
tar -xjvf valgrind-3.10.1.tar.bz2
cd valgrind-3.10.1
./configure
make
sudo make install
```

[download]: http://valgrind.org/downloads/current.html
