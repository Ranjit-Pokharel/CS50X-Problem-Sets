# plurality.c
simulation of a type of election
“plurality vote” (also known as “first-past-the-post” or “winner take all”).

## Table of Contents
- [About](#about)
- [Getting Started](#getting-started)

## About
In the plurality vote, every voter gets to vote for one candidate. 
At the end of the election, whichever candidate has the greatest number of votes 
is declared the winner of the election.

## Getting Started
### Prerequisites
To compile and run this program, you’ll need:
- A C compiler, such as GCC or Clang.
- [cs50 c library](https://cs50.readthedocs.io/libraries/cs50/c/)

### Installation
   ```
   git clone https://github.com/Ranjit-Pokharel/CS50X-Problem-Sets.git
   cd CS50X-Problem-Sets/psets3/plurality
   clang -o plurality plurality.c -lcs50
   ./plurality [candidates,.....]
   Number of voters: <number of voters>
   Vote: <candidates name>
   ```
   output ``winner candidate name``
