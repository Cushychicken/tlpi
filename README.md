# tlpi
These are my transcriptions of the example programs in _The Linux Programming Interface_, as well as my solutions to the exercise problems.
These are organized by chapter, with each chapter having the following basic structure:

```shell
├── ch04
    ├── examples
    │   ├── copy.c
    │   └── Makefile
    └── exercises
```

For now, the exercises have to be compiled locally, in the respective `/examples` or `/exercises` directory. 

To generate the example code and problem set solutions, just clone the repository and run:

```shell
> make lib
> make all
```
Each program will appear in the directory in which it was compiled. 
