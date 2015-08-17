# Introduction to OpenMP

This course is an entire video course given by Intel's Tim Mattson.

Lecture:
https://www.youtube.com/playlist?list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG

Slide Deck: http://openmp.org/mp-documents/Intro_To_OpenMP_Mattson.pdf

Exercise Files: http://openmp.org/mp-documents/Mattson_OMP_exercises.zip

## Outline

- Unit 1: Getting started with OpenMP
    - [Module 1: Introduction to parallel programming][intro]
    - Module 2: The boring bits: Using an OpenMP compiler (hello world)
    - Discussion 1: Hello world and how threads work
- Unit 2: The core features of OpenMP
    - Module 3: Creating Threads (the Pi program)
    - Discussion 2: The simple Pi program and why it sucks
    - Module 4: Synchronization (Pi program revisited)
    - Discussion 3: Synchronization overhead and eliminating false sharing
    - Module 5: Parallel Loops (making the Pi program simple)
    - Discussion 4: Pi program wrap-up
- Unit 3: Working with OpenMP
    - Module 6: Synchronize single masters and stuff
    - Module 7: Data environment
    - Discussion 5: Debugging OpenMP programs
    - Module 8: Skills practice ... linked lists and OpenMP
    - Discussion 6: Different ways to traverse linked lists
- Unit 4: a few advanced OpenMP topics
    - Module 9: Tasks (linked lists the easy way)
    - Discussion 7: Understanding Tasks
    - Module 10: The scary stuff ... Memory model, atomics, and flush (pairwise synch).
    - Discussion 8: The pitfalls of pairwise synchronization
    - Module 11: Threadprivate Data and how to support libraries (Pi again)
    - Discussion 9: Random number generators
- Unit 5: Recapitulation 

[intro]:
https://www.youtube.com/watch?v=nE-xN4Bf8XI&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG&index=1
