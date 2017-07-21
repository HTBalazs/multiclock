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

### Example ###

```
#!c++
#include "multiclock/cMulticlock.h"

int main() {
	cMulticlock mclock;
	double s;
// Start multiclock
	mclock.start();
// Start 0th clock to count ticks
	mclock.tic(0);
	s = 0.0;
	for(int i=0; i<200000; i++) {
		s += rand()%1000/1000.0;
	}
// Start 1st clock to count ticks, 0th counter is stopped
	mclock.tic(1);
	s = 0.0;
	for(int i=0; i<300000; i++) {
		s += rand()%1000/1000.0;
	}
// Start 2nd clock to count ticks, 1st counter is stopped
	mclock.tic(2);
	s = 0.0;
	for(int i=0; i<100000; i++) {
		s += rand()%1000/1000.0;
	}
	mclock.tic(3);
	s = 0.0;
	for(int i=0; i<150000; i++) {
		s += rand()%1000/1000.0;
	}
	mclock.tic(4);
	s = 0.0;
	for(int i=0; i<250000; i++) {
		s += rand()%1000/1000.0;
	}
// Currently active counter is stopped.
	mclock.finish();
// Print report
	mclock.report();
	return 0;
}
```

Result:

 
```
#!shell

Multiclock summary:
  Clock   |   Duration[%]
     0    |      20.1932
     1    |      29.3306
     2    |      10.0621
     3    |      15.0449
     4    |      25.3692
```