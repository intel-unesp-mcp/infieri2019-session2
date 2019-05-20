<a name="top"></a>

# 5th International Summer School on INtelligent signal processing for FrontIEr Research and Industry

## Lab Workbook - Session 2

**April 2019**

UNESP Center for Scientific Computing (an Intel Modern Code Partner)  
São Paulo State University (Universidade Estadual Paulista - UNESP)

São Paulo, Brazil 

**Organized by: Rogério Iope, Jefferson Fialho, Raphael Cóbe, Silvio Stanzani**

______

## Overview

Intel® Xeon Phi™ is a brand name for all Intel Many Integrated Core (MIC)
architecture of processors and coprocessors developed by Intel to enable
performance gains for highly parallel computing workloads. Intel MIC
architecture combines many Intel processor cores onto a single chip and
provides interesting and appealing features, including the ability to use
familiar programming models such as OpenMP and MPI in much the same manner that
they are used on multi-core / multi-socket systems, like the widely used Intel
Xeon processors.

This hands-on, self-paced training has been designed to be a comprehensive, practical
introduction to parallel programming based on the Xeon Phi architecture and
programming models, aiming to demonstrate the processing power of the Intel
Xeon Phi product family. Attendants of these training activities will start
issuing simple command-line tools to get basic information about the second-generation
Intel Xeon Phi processors, by connecting to the servers using the ssh protocol.
They will verify that the second-generation Intel Xeon Phi processor is a
self-booting processor capable of running a usual Linux-based operating system.

During the training activities, participants will learn how to compile and
run simple C/C++ applications, and then compile and run example codes based on
shared-memory parallelism with OpenMP and Cilk Plus and distributed-memory
parallelism with MPI. They will also work on MPI application examples that
should be executed simultaneously on distinct servers with Xeon Phi processors,
explore the use of Intel MKL library, and develop insights on tuning parallel applications.

Participants will have access to a set of dedicated servers equipped
with Intel Xeon Phi processors running a usual Linux-based operating system, as well as the
latest Intel software development tools. The servers are hosted at
the Center for Scientific Computing of the São Paulo State University (UNESP), in
São Paulo, Brazil. The step-by-step hands-on activities have been planned to provide easy to
follow instructions in order to allow the participants to have a real experience on using
a powerful manycore computing system.

## Learning Goals

Attendants of these hands-on labs will work on predefined sets of exercises
that progressively help them get familiar with the Intel Xeon Phi processor
hardware, programming models, and development tools. Exercises have been
developed in such a way that the learners proceed from one topic to the next at
their own speed. Participants will start issuing simple commands to get basic
information about the Intel Xeon Phi processors, then will learn how to compile
and run simple C/C++ applications, including example codes based on shared-memory
parallelism with OpenMP and distributed-memory parallelism with MPI.
They will also work on MPI application examples that should be executed
simultaneously on distinct servers also based on Xeon Phi processors,
explore the use of the Intel Math Kernel Library (MKL), and develop insights
on tuning parallel applications.
______

## Navigation ##

This course is divided into four parts:

* [Practical Exercises - **Part 1**: Task parallelism using OpenMP](#part1)
* [Practical Exercices - **Part 2**: Intel MPI programming models](#part2)
* [Practical Exercices - **Part 3**: Optimizing a real-world code example](#part3)
* [Practical Exercices - **Part 4**: Running a basic N-body simulation](#part4)

______

## Useful References

-   _Intel® Xeon Phi™ Processor High Performance Programming - Knights Landing Edition (2016)_  
    <https://www.elsevier.com/books/intel-xeon-phi-processor-high-performance-programming/jeffers/978-0-12-809194-4/>

-   _High Performance Parallelism Pearls - Vol. I (2014)_  
    <https://www.elsevier.com/books/high-performance-parallelism-pearls-volume-one/reinders/978-0-12-802118-7/>

-   _High Performance Parallelism Pearls - Vol. II (2015)_  
    <https://www.elsevier.com/books/high-performance-parallelism-pearls-volume-two/jeffers/978-0-12-803819-2/>
    
-   _Books on Programming Multicore and Many-core by James Reinders and Jim Jeffers_  
    <http://www.lotsofcores.com/>
    
-   _Knights Landing - An Overview for Developers (webinar)_  
    <https://software.intel.com/en-us/videos/knights-landing-an-overview-for-developers/>
    
-   _Best Practice Guide - Knights Landing (2017)_  
    <http://www.prace-ri.eu/IMG/pdf/Best-Practice-Guide-Knights-Landing.pdf/>    
    
-   _Get Ready for Intel’s Knights Landing (KNL) – 3 papers: AVX-512, Clustering Modes, MCDRAM_  
    <https://colfaxresearch.com/get-ready-for-intel-knights-landing-3-papers/>        
    
-   _Parallel Programming and Optimization with Intel® Xeon Phi™ Coprocessors, 2nd Edition (Colfax, 2015)_  
    <https://colfaxresearch.com/second-edition-of-parallel-programming-and-optimization-with-intel-xeon-phi-coprocessors/>
    
-   _Intel® C++ Compiler 19.0 Developer Guide and Reference_  
    <https://software.intel.com/en-us/cpp-compiler-developer-guide-and-reference>

-   _Intel® Xeon Phi™ x200 Product Family_  
    <https://ark.intel.com/content/www/us/en/ark/products/series/92650/intel-xeon-phi-x200-product-family.html>

-   _Tutorial on OpenMP - Lawrence Livermore National Laboratory_  
    <https://computing.llnl.gov/tutorials/openMP/>

-   _Tutorial on MPI - Lawrence Livermore National Laboratory_  
    <https://computing.llnl.gov/tutorials/mpi/>

## Remote access to the testing platform

This document assumes that the testing platforms have been setup and are
ready to use. We will use a total of six servers, each with one second-generation
Intel Xeon Phi processor (68 cores, 4 threads/core), as well
as several Intel software development tools. To simplify nomenclature,
we will refer to each server as “the host” (or “the host system”).

Participants should work alone on a workstation (desktop PC or laptop) - preferably
running Linux or Mac - with Internet access. All the exercises are
command-line based and should be executed on the host system by means of
a secure shell (SSH) connection. Ideally, the participant workstation
should be able to open X11 connections with the server.

<a name="remote_access"></a>

Use the following command to log in to the host system.

```bash
$ ssh –X KNL-SERVER –l traineeN 
```

**(N is a number assigned to each participant)**

**Note:** ssh -X allows you to log into a remote computer and have its graphical user interface X displayed on your local machine.

Please refer to the teaching assistant(s) for more details.

<a name="get_repo"></a>

## GIT repository - getting the source files

**Git** is a free and open source distributed version control system (DVCS)
designed to track changes in source files or other content and coordinate work
on them among multiple people with flexibility, security, and efficiency.

**GitHub** is a web-based Git repository hosting service.

The files used during these activities are stored at GitHub and in order to
obtain them, you have to perform a copy (clone) of the remote repository to
your user directory, in order to do so, you should run the following command in
the host system console:

```bash
[KNL-SERVER]$ git clone https://github.com/intel-unesp-mcp/infieri-2017-advanced.git
```

The source files will be available at the `infieri-2017-advanced/src` directory:

```bash
[KNL-SERVER]$ cd infieri-2017-advanced/src
```

From now on, the full path for these files will be referred as **SOURCE-DIR**.

Please refer to the teaching assistant(s) for more details.

## Intel's environment variables

After you connect to the remote server, set the environment variables necessary
for the Intel development tools by running the following command:

```bash
[KNL-SERVER]$ source /opt/tools/intel/parallel_studio_xe_2018/psxevars.sh intel64
```

```bash
[KNL-SERVER]$ source /opt/tools/intel/parallel_studio_xe_2018/compilers_and_libraries_2018/linux/mpi/intel64/bin/mpivars.sh
```
______

### Quick Navigation ###

[Top](#top "Top of the page") | [Part 1](#part1 "Task parallelism using OpenMP and Cilk Plus") | [Part 2](#part2 "Intel MPI programming models") | [Part 3](#part3 "Optimizing a real-world code example") | [Part 4](#part4 "Running a basic N-body simulation") | [Bottom](#bottom "Bottom of the page")

______

<a name="part1"></a>

# Practical Exercises - Part 1

## Task parallelism using OpenMP

### 1.1 Goals

In the first part of Session 2 we set focus on multi-threaded
programming, or task parallelism, using the Intel Open Multi-Processing
(OpenMP). While POSIX threads[^1] - also known as Pthreads - can be used to implement parallelism in
shared memory multiprocessor architectures, this programming interface does not contain HPC-specific
features such as workload balancing, processor affinity, reducers, etc. Computationally intensive algorithms
in general perform better when implemented using one of the specialized standards for building thread-parallel
applications such as OpenMP. Moreover, OpenMP provides a simple way of introducing parallelism in existing sequential
programs, providing the programmer with a mostly declarative style of programming where all the parallelization
is handled at the compiler level.

### 1.2 Overview of OpenMP

OpenMP is a traditional, well-established cross-platform standard with
which many high performance application developers are familiar. It
provides high-level abstraction for task parallelism, and eliminates the
low-level details of iteration space partitioning, data sharing, and
thread creation, scheduling, and synchronization. In order to
parallelize an application with OpenMP, the programmer supplements the
code with OpenMP pragma directives[^2]. These pragmas instruct
OpenMP-aware compilers to produce parallel versions of the respective
statements and to bind to the OpenMP implementation. It is possible to
disable OpenMP support in the compiler, and the code with OpenMP pragmas
will still compile. In this case the pragmas will be treated as simple
comments, and parallelization will not occur - the program will still
yield correct behavior, but without any parallelism.

A program with OpenMP directives begins execution as a single thread,
called the initial thread of execution. It is executed sequentially
until the first parallel construct is encountered. After that the
initial thread creates a team of threads to be executed in parallel, and
becomes the master of this team. All program statements enclosed by the
parallel construct are executed in parallel by each thread in the team,
including all routines called from within the enclosed statements. At
the end of the parallel construct each thread wait for others to arrive.
When that happens the team is dissolved, and only the master thread
continues execution of the code following the parallel construct. The
other threads in the team enter a wait state until they are needed to
form another team.

In order to compile a C/C++ program with OpenMP pragmas using the Intel
C++ Compiler the programmer must specify the compiler argument -qopenmp.
Without this argument, the code will still compile, but all code will be
executed with only one thread. In order to make certain functions and
variables of the OpenMP library available, the directive `#include <omp.h>`
must be used at the beginning of the code.

### 1.3 Hands-on Activities

**Notes:**  

* The following set of activities are mainly based on exercises extracted from the book:

_"Parallel Programming and Optimization with Intel Xeon Phi Coprocessors"_ (Colfax International, 2013, pp. 285-290).  

* All the source codes we will be using in this section are located in **SOURCE-DIR**. For more information, check the [**"getting the source files"**](#get_repo) section.

**1.3.1** To help you recall how to compile and execute an OpenMP code, have a look at the source code `openmp.c`, located at **SOURCE-DIR**, which prints out the total number of OpenMP threads and for each fork-join branch prints out **“Hello world from thread %d"**. Compile the code using `icc` and do not forget the appropriate flag `-qopenmp` to enable OpenMP. Before running it, set the environment variable `OMP_NUM_THREADS` to a number N between 1 and the maximum number of threads available on the host (272 for the servers we are using), by issuing the command:

```bash
[SERVER]$ export OMP_NUM_THREADS=N 
```

Execute the binary code and make sure that you understand how it works. 

Test yourself by answering these simple questions:

-   What OpenMP function returns the total number of available threads?

-   What OpenMP function returns the current thread number?

**1.4.2** Modify the source code `openmp.c` by inserting a parallel for
loop that prints out the current thread number and the number of
iteration. Use the directive `#pragma omp for` (**hint:** `#pragma omp parallel`
spawns a group of threads, while `#pragma omp for` divides
loop iterations between the spawned threads; you can do both things at
once with the fused `#pragma omp parallel for` directive). Save the
modified source as `openmp_v1.c`, compile and execute the binary on the
host system, checking the result.

**1.4.3** Have a look at source file `openmp_v2.c`. In this slightly
modified version, constant variable `nthreads` is initialized with the
maximum value of OpenMP threads and is made available for all threads.
Notice that a private integer has been defined, which should be
independent for each parallel region. Any variable declared inside the
parallel region is private to each thread, and any variable declared
before the parallel region is available (`shared`) for every thread.
Compile and execute the code on the host system, and check the result.

**1.4.4** Control over the variables scope can also be done with OpenMP
parallel clauses `private`, `shared`, and `firstprivate`. Have a look at the
source file `openmp_v3.c`, which uses these three variables. Check what
values will be assigned to them within the parallel region and how they
will react to the modifications of their values. Then compile the source
and execute it several times on the host system, and check if your assumptions were
correct. Notice that the value of `varShared` is different at each execution; in
fact, its value is unpredictable. Why does this happen?

**1.4.5** A common mistake when implementing parallel algorithms is
creating racing conditions, which occur when shared variables are
accessed for reading and writing by different threads at the same time.
Have a look at the source file `openmp_v4.c`, which uses a parallel for
loop over the sequence of N = 10000 numbers added together in a shared
variable sum. Correct value should be equal to `(N−1)*N/2` (note: lower
and upper boundaries of the loop are, respectively, 0 and N–1). Compile
the source code using the `-qopenmp` flag and execute the binary
several times, comparing the results. Why the result is different at
each execution?

**1.4.6** There are several ways to fix racing conditions in OpenMP
parallel codes. One of them is applying `#pragma omp critical` to the
region where the racing conditions occur. Have a look at file
`openmp_v5.c`, which is an example that uses this solution to fix the
summation problem. It should be noted, however, that only one thread
will execute the critical region marked with the critical 'pragma' at a
time. Therefore, the parallel code technically becomes serial, since
only one thread will be executing it at a time. As always, compile the
source code, execute it several times, and check the results.

**1.4.7** `Reduction` is a clause of OpenMP for loop, which indicates
what operation will be used on what reduction variable. OpenMP will
automatically take care of avoiding racing conditions and receiving
correct result. Have a look at example `openmp_v6.c`, which implements
the proposed solution. Compile the source code, execute it several times,
and check the results.

______

### Quick Navigation ###

[Top](#top "Top of the page") | [Part 1](#part1 "Task parallelism using OpenMP and Cilk Plus") | [Part 2](#part2 "Intel MPI programming models") | [Part 3](#part3 "Optimizing a real-world code example") | [Part 4](#part4 "Running a basic N-body simulation") | [Bottom](#bottom "Bottom of the page")

______

<a name="part2"></a>

# Practical Exercises - Part 2

## Intel MPI programming models

### 2.1 Goals

This set of exercises will show you practical aspects of heterogeneous
execution of parallel application in distributed memory with MPI, widely
recognized as the de facto standard for parallel programming.

### 2.2 Overview of MPI

The Message Passing Interface (MPI) has been the de facto standard for
parallel programming for nearly two decades. It defines a set of library
routines that can be called from C and Fortran programs, and includes a
communication protocol that allows multiple processes, which do not
share common memory, to perform parallel calculations, communicating
with each other by passing messages through a communication channel. MPI
messages are arrays of predefined and user-defined data types. The
purpose of MPI messages range from task scheduling to exchanging large
amounts of data necessary to perform calculations. MPI guarantees that
the order of sent messages is preserved on the receiver side.

In the old era of single-core compute nodes, the dominant MPI usage
model in clusters of computers was to run one MPI process per physical
machine. Nowadays, with the advent of multi-core, multi-socket, and now
heterogeneous many-core systems, the range of usage models of MPI has
grown. It is possible, for example, to run one MPI process per compute
node, exploiting parallelism in each machine by means of a shared-memory
parallel framework, such as OpenMP or Intel Cilk Plus. Alternatively,
one single-threaded MPI process can run on each physical or logical core
of each machine in a cluster of servers. In this case, MPI processes
running on the same compute node still do not share memory address
space. However, message passing between these processes is more
efficient, because fast virtual fabrics can be used for communication.
Another possible option is to run multiple multi-threaded MPI processes
per compute node. In this case, each process exploits parallelism in
shared memory, and MPI communication between processes adds
distributed-memory parallelism. This hybrid approach may yield optimum
performance for with a high frequency or large volume of communication.

MPI programs typically employ a single-program, multiple-data (SPMD)
approach. Multiple instances, or MPI ranks, of the same program run
concurrently on different data. Each rank computes a different part of a
larger problem and uses MPI calls to communicate data between ranks.
From the programmer's perspective, ranks may run either on the same node
or in different nodes; the communication path may be different but that
is transparent to the MPI program.

As we have seen in Session 1, Intel Xeon Phi coprocessors run its own
operating system, independent of the host processor, and have their own
memory domain. In other words, a Xeon Phi coprocessor behaves like an
independent compute node. From this perspective, MPI is a natural fit.
In principle, any existing MPI program can be run on a mixture of hosts
and coprocessors without source code modification.

In heterogeneous clusters with Intel Xeon processors and Xeon Phi
coprocessors, MPI programmers have a choice of running MPI processes on
hosts and coprocessors natively, or running MPI processes only on hosts
and performing offload to coprocessors.

### 2.3 Hands-on Activities

**2.3.1** Please review exercises [2.2.5 and 2.2.6 from Session 1](https://intel-unesp-mcp.github.io/infieri2019-session1/#part2{:target="_blank"}. As we have seen, MPI applications must be compiled with special wrapper
applications – `mpiicc` for C and `mpiicpc` for C++, and the resulting
executable is launched using the `mpirun` script.

**2.3.2** Intel MPI distribution includes a test directory, which contains a simple MPI program coded
in C, C++, or Fortran. In directory **SOURCE-DIR** you will find a copy of the source file `test.c` from
the Intel MPI distribution. You can also retrieve this file from its original folder:

```bash
[KNL-SERVER]$ cp /opt/tools/intel/parallel_studio_xe_2018/compilers_and_libraries_2018/linux/mpi/test/test.c .
```

**Note:** All the source codes we will be using in this section are located in **SOURCE-DIR**. For more information, check the [**"getting the source files"**](#get_repo) section.

Let us start working on this code as a quick remind on how to run an MPI program on
the Intel Xeon Phi coprocessor. Compile the source file with the Intel
compiler for the host with the usual Intel MPI wrapper:

```bash
[KNL-SERVER]$ mpiicc -o test test.c
```

Execute the binary file with 4 MPI processes on your server:

```bash
[KNL-SERVER]$ mpirun -n 4 ./test
```

Now let us execute the same code simultaneously on all six servers. Now we are going to execute the
test application on distinct hosts. To do this we need to copy the executable file to the other servers:

```bash
[KNL-SERVER]$ for i in {01..06}; do scp test knl$i:~; done
```

```bash
[KNL-SERVER]$ mpirun -host knl01 -n 4 ~/test : -host knl02 -n 4 ~/test : -host knl03 -n 4 ~/test : -host knl04 -n 4 ~/test : -host knl05 -n 4 ~/test : -host knl06 -n 4 ~/test
```

There is an easier way of doing this, by using the parameter `-machinefile`, but we need to create a new file that
will inform the available hosts. Create this file and name it `hosts`, using the sequence of commands below:

```bash
[KNL-SERVER]$ cat > hosts
knl01
knl02
knl03
knl04
knl05
knl06
[hit Ctrl+D to save and exit]
```

Now run again the test application using the following syntax:

```bash
[KNL-SERVER]$ mpirun -n 24 -machinefile hosts ~/test
```

Do you see any difference in the output, compared to the previous mpirun execution?

**Note:**  

* The following four exercises, from 2.3.3 to 2.3.6, have been extracted from a collection of tutorial
presentations developed by William Gropp and Ewing Lusk from the Mathematics and Computer Science Division
of the Argonne National Laboratory. William Gropp, Ewing Lusk and two collaborators were the authors of
an important paper entitled “A high-performance, portable implementation of the MPI message passing
interface standard”, that described the first full implementation of the MPI standard, known as MPICH.
The complete set of exercises are available here:

	_Tutorial material on MPI, by William Gropp and Ewing Lusk_  
	<https://www.mcs.anl.gov/research/projects/mpi/tutorial/mpiexmpl/>        


**2.3.3** In this exercise we are going to address a common need in most MPI programs, which is for one
process to get data from the user, either by reading from the terminal or command line arguments, and then
to distribute this information to all other processes. Have a look at source code `mpi_ex01.c`, which reads an integer
value from the terminal and distributes the value to all of the MPI processes. Each process then prints out its
rank and the value it received. Values are received until a negative integer is given as input. Compile the source
file with the Intel compiler using the usual Intel MPI wrapper (mpiicc), execute it (mpirun) on a few nodes and
check the results.

**Note:**

* The `fflush(stdout)` after the printf calls are commonly used on MPI programs; if we do not insert it,
output may not appear when we expect it.

**2.3.4** Now we will analyse a program that takes data from process zero and sends it to all of the
other processes by sending it as in a ring. That is, process with rank i should receive the data and send it
to process with rank i+1, until the last process is reached. Process zero reads the data from the user. Have
a look at source code `mpi_ex02.c`, compile it using mpiicc, execute it (mpirun) on a few nodes and check the results.

**2.3.5** This exercise presents a simple program to determine the value of pi. The method used evaluates the
integral of 4/(1+x*x) between 0 and 1. The method is simple: the integral is approximated by a sum of
n intervals; the approximation to the integral in each interval is (1/n)*4/(1+x*x). The master process
(rank 0) asks the user for the number of intervals; the master should then broadcast this number to all of
the other processes. Each process then adds up every n'th interval (x = rank/n, rank/n+size/n,...). Finally,
the sums computed by each process are added together using a reduction. Have a look at source code `mpi_ex03.c`,
compile it using mpicc, execute it (mpirun) on a few nodes and check the results.

**2.3.6** In this exercise we are going to have all processes, from 1 to N, send 100 messages to process 0.
Process 0 will then print out the messages as it receives them, using MPI_ANY_SOURCE and MPI_ANY_TAG in MPI_Recv.
As usual, Have a look at source code `mpi_ex_04.c`, compile it using mpicc, execute it (mpirun) on a few nodes and
check the results.

**2.3.7** As a preparation for the next exercise on hybrid programming,
the mapping/pinning of Intel MPI processes will be investigated step by step.
Set the environment variable `I_MPI_DEBUG` equal to 4 to see the mapping information:

```bash
[KNL-SERVER]$ export I_MPI_DEBUG=4
```

To unset the value of any environment variable, we can use the command unset:

```bash
[KNL-SERVER]$ unset I_MPI_DEBUG
```

For pure (non-hybrid) MPI programs the environment variable
`I_MPI_PIN_PROCESSOR_LIST` controls the mapping/pinning. For hybrid
codes the variable `I_MPI_PIN_DOMAIN` takes precedence. It splits the
(logical) processors into non-overlapping domains for which this rule
applies: "one MPI process for one domain".

Repeat the Intel MPI test from before with `I_MPI_DEBUG` set. Because of
the amount of output use the flag "-prepend-rank", which puts the MPI
rank number in front of each output line:

```bash
[KNL-SERVER]$ mpirun -prepend-rank -n 4 ./test
[KNL-SERVER]$ mpirun -prepend-rank -machinefile hosts -n 24 ~/test
```

Now set the variable `I_MPI_PIN_DOMAIN` with the `-env` flag. Possible
values are `auto`, `omp` (which relies on the `OMP_NUM_THREADS`
variable), or a fixed number of logical cores. We have learned before
(session 1, exercise 2.2.4) that by exporting `I_MPI_PIN_DOMAIN` in the
host’s command shell, the variable is identically exported to the host
and to the Xeon Phi coprocessors. Typically this is not beneficial and
an architecture adapted setting using `-env` is recommended:

```bash
[KNL-SERVER]$ mpirun -prepend-rank -env I_MPI_PIN_DOMAIN auto -n 4 ./test
[KNL-SERVER]$ mpirun -prepend-rank -env I_MPI_PIN_DOMAIN 4 -host localhost -n 4 ~/test : -env I_MPI_PIN_DOMAIN 12 -host knl02 -env I_MPI_PIN_DOMAIN 12 -n 4 ~/test
```

Experiment with pure Intel MPI mapping by setting
`I_MPI_PIN_PROCESSOR_LIST` if you like. (See the Intel MPI reference
manual for details).

**2.3.8** Now we are going to run a hybrid MPI/OpenMP program on the
Intel Xeon Phi processor. Have a look at the source code
`test_openmp.c`, in which a simple printout from the OpenMP threads was
added to the previous Intel MPI test code. You can compare the
difference between the two files by means of the diff utility:

```bash
[KNL-SERVER]$ diff test.c test_openmp.c
```

Compile the source code with the `-qopenmp` compiler flag:

```bash
[KNL-SERVER]$ mpiicc -qopenmp test_openmp.c -o test_openmp
```

Copy the binary file to all servers:

```bash
[KNL-SERVER]$ for i in {01..06}; do scp test_openmp knl$i:~; done
```

Because of the `-qopenmp` flag, Intel MPI will link the code with the
thread-safe version of the Intel MPI library `libmpi_mt.so` by default.
Run the Intel MPI tests from before:

```bash
[KNL-SERVER]$ unset I_MPI_DEBUG
[KNL-SERVER]$ mpirun -prepend-rank -n 4 ./test_openmp
[KNL-SERVER]$ mpirun -prepend-rank -host localhost -n 4 ~/test_openmp : -host knl02 -n 4 ~/test_openmp
```
  
Because of the large amount of output we use the flag "-prepend-rank", which adds the MPI
rank number in front of each output line. The default for the OpenMP
library is to assume as many OpenMP threads as there are logical
processors. For the next steps, explicit `OMP_NUM_THREADS` values will be set.

In the following test the default OpenMP affinity is checked. Please
notice that the range of logical processors is always defined by the
splitting the threads based on the `I_MPI_PIN_DOMAIN` variable. This
time we also use `I_MPI_PIN_DOMAIN=omp`, see how it depends on the
`OMP_NUM_THREADS` setting:

```bash
[KNL-SERVER]$ mpirun -prepend-rank -env KMP_AFFINITY verbose -env OMP_NUM_THREADS 4 -env I_MPI_PIN_DOMAIN auto -n 4 ./test_openmp 2>&1 | sort
[KNL-SERVER]$ mpirun -prepend-rank -env KMP_AFFINITY verbose -env OMP_NUM_THREADS 4 -env I_MPI_PIN_DOMAIN omp -host knl02 -env ./test_openmp 2>&1 | sort
[KNL-SERVER]$ mpirun -prepend-rank -env KMP_AFFINITY verbose -env OMP_NUM_THREADS 4 -env I_MPI_PIN_DOMAIN 4 -host localhost -n 2 ./test_openmp : -env KMP_AFFINITY verbose -env OMP_NUM_THREADS 6 -env I_MPI_PIN_DOMAIN 12 -host knl02 -n 4 ./test_openmp 2>&1 | sort
```

Remember that it is usually beneficial to avoid splitting of logical
cores on Intel Xeon Phi coprocessor between MPI processes; either the
number of MPI processes should be chosen so that
`I_MPI_PIN_DOMAIN=auto` creates domains which cover complete cores or
the environment variable should be a multiply of 4.

Use `scatter`, `compact`, or `balanced` (Intel Xeon Phi processor/coprocessor
specific) to modify the default OpenMP affinity.

```bash
[KNL-SERVER]$ mpirun -prepend-rank -env KMP_AFFINITY verbose,granularity=thread,scatter -env OMP_NUM_THREADS 4 -env I_MPI_PIN_DOMAIN auto -n 4 ~/test_openmp
[KNL-SERVER]$ mpirun -prepend-rank -env KMP_AFFINITY verbose,granularity=thread,compact -env OMP_NUM_THREADS 4 -env I_MPI_PIN_DOMAIN 4 -host localhost -n 2 ~/test_openmp : -env KMP_AFFINITY verbose,granularity=thread,balanced -env OMP_NUM_THREADS 6 -env I_MPI_PIN_DOMAIN 12 -host knl02 -n 4 ~/test_openmp 2>&1 | sort
```

Notice that, as well as other options, the OpenMP affinity can be set
differently per Intel MPI argument set, i.e. different on the host and
on the Intel Xeon Phi coprocessor.

______

### Quick Navigation ###

[Top](#top "Top of the page") | [Part 1](#part1 "Task parallelism using OpenMP and Cilk Plus") | [Part 2](#part2 "Intel MPI programming models") | [Part 3](#part3 "Optimizing a real-world code example") | [Part 4](#part4 "Running a basic N-body simulation") | [Bottom](#bottom "Bottom of the page")

______


<a name="part3"></a>


# Practical Exercises - Part 3

## Optimizing a real-world code example

### 3.1 Goals

In this final set of activities we will make use of a real scientific
code example that comes from Naoya Maruyama of Riken Advanced Institute
for Computational Science, in Japan[^5]. The code simulates diffusion of
a solute through a volume of liquid. We will start with a baseline C
code and implement successive optimizations on it, aiming to improve
performance.

**Note:**  

* The following activities (and corresponding source codes) have been extracted from chapter 4 of this outstanding book: “*Intel Xeon Phi Coprocessor High-Performance Programming*”, by Jim Jeffers and James Reinders (Elsevier, 2013).  

* All the source codes we will be using in this section are located in **SOURCE-DIR**. For more information, check the [**"getting the source files"**](#get_repo) section.

### 3.2 Overview of the diffusion simulation algorithm

The purpose of the code is to simulate the diffusion of a solute through
a volume of liquid over time within a 3D fluid container, such as a
cube, as shown in Figure 1. A three-dimensional seven-point stencil
operation is used to calculate the effects on the neighboring sub-volume
sections on each other over time.

![infieri02_pic01](img/infieri02_pic01.png)

**Figure 1: Diffusion of a compound over time through an enclosed volume (Jeffers & Reinders book)**

We need to understand enough about the algorithm being used to ensure we
perform correct and complete calculations. As shown in Figure 2, we are
going to apply a seven-point stencil to calculate a new density in the
volume using weighted values in the stencil applied to the current
target sub-volume and its neighbors. This calculation will be repeated
for every section of the volume, creating a new baseline volume. The
code then iterates over the number of time steps selected to create the
final diffused volume state.

![infieri02_pic02](img/infieri02_pic02.png)

**Figure 2: Illustration of the 7-point 3D stencil (Jeffers & Reinders book)**

The baseline C code that shows the primary diffusion algorithm
implementation is shown below:

```c
for (i = 0; i < niter; i++) {
	for (z = 0; z < nz; z++)
		for (y = 0; y < ny; y++)
			for (x = 0: x < nx; x++)
				f2[x,y,z] = cc*f1[z,y,x] + cw*f1[z,y,x-1] + ce*f1[z,y,x+1] + cn*f1[z,y-1,x] + cs*f1[z,y+1,x] + cb*f1[z-1,y,x] + ct*f1[z+1,y,x]
	temp = f2; f2 = f1; f1 = temp;
}

```

The f1\[ \] array contains the current volume data and the f2\[ \] array
is used to store the results of the current time step iteration. There
are four loops, one for each dimension and one for the number of time
steps requested. The inner loop applies the stencil calculations using
the target center sub-volume section and its neighboring north, south,
east, west, top, and bottom sections. Once all sub-volumes for the
current time step are processed, the f1\[ \] and f2\[ \] array pointers
are swapped, setting the new reference state.

The diffusion simulation must also account for a structural issue: the
three dimensional container has boundary walls. Since the stencil
operates on each sub-volume section that comprises the whole, we need to
consider how to properly calculate the molecular density for sub-volumes
that sit next to the edges of the container. At a minimum, we need to
avoid calculating array index values that go outside our allocated
memory space representing the container volume. The code snippet below
shows an evolved implementation that accounts for the boundary
conditions:


```c
for (int i = 0; i < count; ++i){
	for (int z = 0; z < nz; z++){
		for (int y = 0; y < ny; y++){
			for (int x = 0; x < nx; x++){
				int c, w, e, n, s, b, t;
				c = x + y * nx + z * nx * ny;
				w = (x == 0) ? c : c - 1;
				n = (y == 0) ? c : c - nx;
				b = (z == 0) ? c : c - nx * ny;
				e = (x == nx-1) ? c : c + 1;
				s = (y == ny-1) ? c : c + nx;
				t = (z == nz-1) ? c : c + nx * ny;
				f2_t[c] = cc * f1_t[c] + cw * f1_t[w] + ce * f1_t[e] + cs * f1_t[s] + cn * f1_t[n] + cb * f1_t[b] + ct * f1_t[t];

			}
		}
	}		
	REAL *t = f1_t; f1_t = f2_t; f2_t = t;
}
```

The implementation also simplifies the f1\[ \] array access by
linearizing the stencil indices through the addition of variables w, e,
n, s, b, t (west, east, north, south, bottom, top). The boundary
conditions occur for any sub-volume that has an x, y, or z value of zero
or a value at the full width, height, or depth of the volume as
represented by the variables nx, ny, nz. In these cases, we simply
replace the value of the neighbor volume with the target central density
value to get a reasonable approximation of the diffusion at that point.
Now, we have reached the first important stage of implementing a
real-world algorithm; it will provide the correct results when run.

### 3.3 Hands-on Activities

**3.3.1** Take a careful look at the complete code listing,
`diffusion_base.c`, that can be found at
**SOURCE-DIR**. The function
`diffusion_baseline()` implements the key computational processing.
Find the `main()` function, and see that two arrays of equal size, f1\[ \]
and f2\[ \], are allocated to support the double buffering used in the
primary calculation function. The double buffering is required to ensure
the stencil processing is completed without modifying the in-place
target volume data, which will be used in subsequent calculations when
its neighboring sub-volumes are calculated. After initializing the f1\[
\] array, and the east, west, north, south, bottom, top, stencil
diffusion weights, ce, cw, cn, cs, cb, ct, and the time step dt, based
on the size of the volume, the time step is used to determine the
iteration count. Next, a time stamp is taken and the diffusion
calculation function is called to perform count time steps. Upon
completion of the function, the resultin floating-point performance is
calculated based on the thirteen floating-point operations per inner
loop iteration, and the memory bandwidth (in GB/s) is determined, using
number of bytes of volume data read and written during the call.

Since we have not applied any optimizations, such as scaling across
cores, when compiled and run we can expect this single-threaded code to
perform quite slowly. You can skip compiling and running this baseline
code yourself, as it will indeed take well over an hour for the run to
complete. However, to establish an initial baseline performance we will
show the result. Use the following command to compile the code to run
natively on the Intel Xeon Phi coprocessor:

```bash
[SERVER]$ icc -qopenmp -std=c99 -O3 -vec-report=3 diffusion_base.c -o diffusion_base
```

Upload the executable program `diffusion_base` to the coprocessor as
usual. On the coprocessor command prompt the code can be executed by
just typing (you do not need to do that because execution will take an
excessively long time):

```bash
[SERVER]$ ./diffusion_base
```

On the Xeon Phi card we are using the output is:

> Running diffusion kernel 6553 times  
Elapsed time : 5653.587 (s)  
FLOPS : 252.801 (MFlops)  
Throughput : 0.233 (GB/s)  
Accuracy : 1.592295e-05  


As you can see, this is a substantial set of calculations and took close
to 95 minutes using just one core and one thread of the coprocessor. Our
next step is to exploit the available parallelism through scaling the
code across the many cores of the coprocessor.

<a name="4-3-2"></a>

**3.3.2** To start off, we will look at scaling the code using OpenMP.
Source file `diffusion_omp.c` is an updated version of the code that
adds OpenMP directives to distribute and scale the work across the
available cores and threads. The key OpenMP clause is the `#pragma omp for collapse(2)` before
the z loop, which tells the compiler to collapse
the next two loops (z and y) into one loop and then apply the OpenMP
`omp for` work division mechanism to split the loop calculations among
the current available threads. Conceptually, the for loop changes to a
single loop that executes as

```c
for (yz=0; yz<ny*nx; ++yz)
```

with the associated similar implied mapping for the use of y and z in
the body of the loop. This will enable each thread to be assigned larger
chunks of data to process more calculations, and therefore, allow more
efficiency on each pass through the loop.

Now, compile and run the code to see what performance you get; use the
following command:

```bash
[SERVER]$ icc -qopenmp -std=c99 -O3 -vec-report=3 diffusion_omp.c -o diffusion_omp
```

Upload the file to one of the coprocessors, issue and ssh to it and
then, on the coprocessor command prompt, set the number of threads and
affinity and run the program:

```bash
[KNL-SERVER]$ export OMP_NUM_THREADS=272 
[KNL-SERVER]$ export KMP_AFFINITY=scatter
[KNL-SERVER]$ ./diffusion_omp
```
**Note:** Remember that `OMP_NUM_THREADS=272` means that we are using four threads per core.

Take note of the output and compare with the result for the baseline
code shown before.

**3.3.3** Now we can experiment with the number of threads per core to
ensure that we consider balancing the access to resources to avoid
conflicts and resource saturation, particularly with respect to memory.
Set for three, two, and one thread(s) per core and run again for each
change of the parameter `OMP_NUM_THREADS`, and take note of the result
of each execution:

```bash
[SERVER-MIC]$ export OMP_NUM_THREADS=204
[SERVER-MIC]$ ./diffusion_omp
[SERVER-MIC]$ export OMP_NUM_THREADS=136
[SERVER-MIC]$ ./diffusion_omp
[SERVER-MIC]$ export OMP_NUM_THREADS=68
[SERVER-MIC]$ ./diffusion_omp
```

Compare the outputs and assess which gives the best result. How many
times the scaled code runs compared to the baseline?

**3.3.4** Our next goal is speed up the code by vectorizing it. Look back
at the output of the vector report after compilation finishes [(exercise
4.3.2)](#4-3-2). Now have a look at source file `diffusion_ompvect.c`. The line
`#pragma omp simd` requests the compiler to vectorize the loop regardless
of potential dependencies or other potential constraints. That was a
pretty simple one line change but should provide an extra improvement.
Compile it using the following command:

```bash
[SERVER]$ icc -qopenmp -std=c99 -O3 -vec-report=3 diffusion_ompvect.c -o diffusion_ompvec
```

Note that now you should see that the vector report indicates the inner
loop was indeed vectorized. Upload the file to one of the coprocessors
and perform four runs from the coprocessor prompt adjusting the threads
per core based on the number of cores for the coprocessor on each run as
indicated below:

```bash
[KNL-SERVER]$ export KMP_AFFINITY=scatter
[KNL-SERVER]$ export OMP_NUM_THREADS=272
[KNL-SERVER]$ ./diffusion_ompvect
```

As in the previous exercise, set for three, two, and one thread(s) per
core and run again, and take note of the results:

```bash
[SERVER-MIC]$ export OMP_NUM_THREADS=204
[SERVER-MIC]$ ./diffusion_ompvect
[SERVER-MIC]$ export OMP_NUM_THREADS=136
[SERVER-MIC]$ ./diffusion_ompvect
[SERVER-MIC]$ export OMP_NUM_THREADS=68
[SERVER-MIC]$ ./diffusion_ompvect
```

Take note of each result and compare with previous results. How many times the scaled code runs
compared to the baseline? We can see the significant impact of vectorization.

**3.3.5** We have both scaled and vectorized our code, and we have seen
very significant performance improvement over the baseline. Now we will
start looking towards finer-grained tuning to see if we can gain a bit
more performance. The idea is to remove unneeded code from the inner
loop. Reviewing the code carefully, we see that the boundary check might
be a candidate. Consider that for a volume of any significant size, the
code will encounter a boundary that requires altering the baseline
stencil usage relatively rarely. If possible, we want to look for a way
to “peel out“ the boundary checks from the inner loop portions because
we know that the code does the bulk of its processing without
encountering a boundary condition.

Have a look at the source code `diffusion_peel.c` and compare with the
previous version, `diffusion_ompvect.c`. Since only our starting and
ending x coordinates 0 and nx-1 will hit the boundary condition, we can
create an inner loop without any boundary checks by simply ensuring we
process x indices from 1 to nx-2. Furthermore, since the stencil always
traverses in single units across the x row of sub-volumes, we can update
the stencil positions by simply incrementing them. Also, we can
eliminate calculating the east and west locations by referencing their
positions directly in the arrayindex (e=c-1 and w=c+1). This new inner
loop now has the X-edge checks removed. The file `diffusion_peel.c`
contains the code with the modifications. Compile and run it to see if
we achieved any improvement:

```bash
[SERVER]$ icc -qopenmp -std=c99 -O3 -vec-report=3 diffusion_peel.c -o diffusion_peel
```

Upload the file to one of the coprocessors, set the affinity and number
of threads at the coprocessor prompt iterating through the number of
threads needed (based on core count) to perform one to four threads per
core in the same way you have done in the previous two exercises. Take
note of the results, choose the best one and compare it with the result
of the previous exercises. Did you get a measurable improvement?

**3.3.6** In many circumstances, improvements can be found by analyzing
the data access patterns to take advantage of data locality. We want to
create a more optimal pattern of data reuse within our innermost loops
to maintain data in the L1 and L2 caches for much faster access. Stencil
operations contain data reuse patterns that make them strong candidates
for exploiting data locality. Tiling and blocking are terms used to
describe a technique often used for improving data reuse in cache
architectures. Cache architectures generally employ “least recently
used“ (LRU) methods to determine which data is evicted from the cache as
new data is requested. Therefore, the longer the data remains unused,
the more likely it will be evicted from the cache and no longer
available immediately when needed. Since memory accesses are
significantly longer than cache accesses, a goal is to find techniques
and usage patterns that can help reduce memory accesses by reusing
cached data. To most successful, reusing data in cache lines have been
used very recently or local to current code sequence is really
important.

Tiling the access pattern can exploit data that remains in the cache
from recent, previous iterations. For instance, in our diffusion stencil
code, each innermost loop iteration processes the x elements of a y row
sequentially, and then moves on to the following y row. Ignoring the
work division from scheduling multiple threads for a moment, there is a
high likelihood of accessing data in the L1 or L2 cache we have used
before from the current and previous y rows since our access of those y
data is recent. However, the bottom and top data on the adjacent z pane
are used once and then not accessed again until the next full y plane is
processed at the same row. Therefore, there is a low likelihood that the
z data are being reused and so they must be fetched again from main
memory on the next iteration of the z loop. If we consider processing a
rectangular tile of y – actually a slab of yx values across a range of
z, the top row in a given z iteration will still be in cache to serve as
left, center, and right rows for the next z, and the bottom row for the
z after that. This usage avoids additional memory requests and a
performance improvement is likely possible.

A code implementation with these improvements is `diffusion_tiled.c`.
We select a blocking factor value YBF for the number of y rows we will
process in each slab; the goal being to select an optimal number that
will maintain the sufficient amounts of y and z data in the cache long
enough to be reused during computation.

Since we will be processing a portion - or tile - of y rows across the
full z dimension, we add an outer y loop to control stepping to the
start of each tile. The x processing with the peeled out boundary
management is maintained so we keep that optimization intact. That said,
let us compile, upload and run the code on one of the coprocessors. Use
the following command:

```bash
[KNL-SERVER]$ icc -qopenmp -std=c99 -O3 -vec-report=3 diffusion_tiled.c -o diffusion_tiled
```

Upload the code and go to the processor command prompt, set the affinity
and number of threads iterating through the number of threads needed to
perform one to four threads per core in the same way you have done in
previous exercises. Take note of the results, choose the best one and
compare it with the result of the previous exercise. Did you get a
measurable improvement? Now compare this result with the original
single-threaded baseline. How many times faster does this tuned code run
compared to the baseline code?


______

### Quick Navigation ###

[Top](#top "Top of the page") | [Part 1](#part1 "Task parallelism using OpenMP and Cilk Plus") | [Part 2](#part2 "Intel MPI programming models") | [Part 3](#part3 "Optimizing a real-world code example") | [Part 4](#part4 "Running a basic N-body simulation") | [Bottom](#bottom "Bottom of the page")

______

<a name="part4"></a>


# Practical Exercises - Part 4 #

## Running a basic N-body simulation ##

### 4.1 Goals ###

You are invited to follow the N-body simulation example developed by Dr. Fabio Baruffa, which describes
a step by step code optimization journey to boost performance of a simple N-body simulation algorithm on
a single KNL server, using data and task parallelism.

Dr. Fabio Baruffa is a software technical consulting engineer in the Developer Products Division (DPD) at Intel. 
He is working in the compiler team and provides customer support in the high performance computing (HPC) area.
Prior at Intel, he has been working as HPC application specialist and developer in the largest supercomputing
centers in Europe, mainly the Leibniz Supercomputing Center and the Max-Plank Computing and Data Facility in Munich,
as well as Cineca in Italy. He has been involved in software development, analysis of scientific code and optimization
for HPC systems. He holds a PhD in Physics from University of Regensburg for his research in the area of spintronics
device and quantum computing.

### 4.2 Hands-on Activities ###

Please access the link below, read it carefully and try to reproduce the optimization steps described by the author
of the article, which describes an example code based on a simple N-body simulation written in C++. There are
varios specific topics that we need to adapt to our environment, so pleasse refer to the instructor or a teaching
assistant before you start or anytime you find a difficulty.

<https://github.com/fbaru-dev/nbody-demo>

To obtain the source files, you have to perform a copy (clone) of the remote repository to
your user directory, by running the following command in the host system console:

```bash
[KNL-SERVER]$ git clone https://github.com/fbaru-dev/nbody-demo.git
```

The source files will be available at the `nbody-demo` directory:

```bash
[KNL-SERVER]$ cd infieri-2017-advanced/src
```


______

### Quick Navigation ###

[Top](#top "Top of the page") | [Part 1](#part1 "Task parallelism using OpenMP and Cilk Plus") | [Part 2](#part2 "Intel MPI programming models") | [Part 3](#part3 "Optimizing a real-world code example") | [Part 4](#part4 "Running a basic N-body simulation") | [Bottom](#bottom "Bottom of the page")

______

<a name="bottom"></a>

### Other references:

[^1]: <https://computing.llnl.gov/tutorials/pthreads/>

[^2]: <http://en.wikipedia.org/wiki/Directive_(programming)>

[^3]: <http://en.wikipedia.org/wiki/Cilk_Plus>

[^4]: <https://software.intel.com/en-us/articles/intelr-xeon-phitm-advanced-workshop-labs>

[^5]: <http://www.exastencils.org/histencils/2014/papers/histencils2014_optimizing_stencil_computations_for_nvidia_kepler_gpus.pdf>




