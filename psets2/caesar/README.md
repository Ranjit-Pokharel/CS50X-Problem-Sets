# caesar.c
a program that encrypt the given text with key which is provide as cli argument.

## Table of Contents
- [About](#about)
- [Getting Started](#getting-started)

## About
encrypt confidential messages by shifting each letter therein by some number (KEY) of places
wrap formula wrap = S + ((O + K - S) % range)
where:
S = starting char or number of the range (A to Z)
O = the char of the given string of text
K = secerate key
range = total length of the range (A - Z) that is 26


## Getting Started
### Prerequisites
To compile and run this program, you’ll need:
- A C compiler, such as GCC or Clang.
- [cs50 c library](https://cs50.readthedocs.io/libraries/cs50/c/)

### Installation
   ```
   git clone https://github.com/Ranjit-Pokharel/CS50X-Problem-Sets.git
   cd CS50X-Problem-Sets/psets2/caesar
   clang -o caesar caesar.c -lcs50
   ./caesar KEY
   plaintext: <text to be encrypted>
   ```
   output ``encrypted ciphertext``
