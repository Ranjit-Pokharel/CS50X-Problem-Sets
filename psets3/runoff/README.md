# runoff.c
simulation of a type of election
a ranked-choice system

## Table of Contents
- [About](#about)
- [Getting Started](#getting-started)

## About
voters can vote for more than one candidate. 
Instead of just voting for their top choice, they can rank the candidates in order of preference

## Getting Started
### Prerequisites
To compile and run this program, you’ll need:
- A C compiler, such as GCC or Clang.
- [cs50 c library](https://cs50.readthedocs.io/libraries/cs50/c/)

### Installation
   ```
   git clone https://github.com/Ranjit-Pokharel/CS50X-Problem-Sets.git
   cd CS50X-Problem-Sets/psets3/runoff
   clang -o runoff runoff.c -lcs50 -lm
   ./runoff [candidates,.....]
   Number of voters: <number of voters>
   Rank 1: <candidates name>
   ```
   output ``winner candidate name``
