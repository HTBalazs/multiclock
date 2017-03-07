# README #

This repository contains a very basic profiler tool for C++ projects.

### Features ###

* Simple syntax profiling
* Arbitrary number of tic-tac sessions
* Results provided in duration percents of the sessions.

### Installation ###
Dependency: ProLog ([https://bitbucket.org/lempsproject/prolog](Link URL))
Multiclock can be installed executing the following commands:

```
#!shell

cmake CMakeLists.txt
sudo make install
```
The generated lib file should be linked to your project
```
#!shell

/usr/local/lib/multiclock/libmulticlock.a
```
with the header file:
```
#!shell

/usr/local/include/multiclock/cMulticlock.h
```