# substitution.c
a program that encrypt the given text with key which is provide as cli argument.

## Table of Contents
- [About](#about)
- [Getting Started](#getting-started)

## About
encrypt a message by replacing every letter with another letter. 
To do so, we use a key: in this case, a mapping of each of the letters of the alphabet 
to the letter it should correspond to when we encrypt it. 
To “decrypt” the message, the receiver of the message would need to know the key, 
so that they can reverse the process: translating the encrypt text 
back into the original message.

## Getting Started
### Prerequisites
To compile and run this program, you’ll need:
- A C compiler, such as GCC or Clang.
- [cs50 c library](https://cs50.readthedocs.io/libraries/cs50/c/)

### Installation
   ```
   git clone https://github.com/Ranjit-Pokharel/CS50X-Problem-Sets.git
   cd CS50X-Problem-Sets/psets2/substitution
   clang -o substitution substitution.c -lcs50
   ./substitution KEY
   plaintext: <text to be encrypted>
   ```
   output ``encrypted ciphertext``
