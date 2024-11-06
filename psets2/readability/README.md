# readability.c
a program that calculates the approximate grade level needed to comprehend some text.

## Table of Contents
- [About](#about)
- [Getting Started](#getting-started)

## About
A number of “readability tests” have been developed over the years 
that define formulas for computing the reading level of a text. 
One such readability test is the Coleman-Liau index. 
The Coleman-Liau index of a text is designed to output that (U.S.) 
grade level that is needed to understand some text. The formula is
``index = 0.0588 * L - 0.296 * S - 15.8``
where L is the average number of letters per 100 words in the text, 
and S is the average number of sentences per 100 words in the text.


## Getting Started
### Prerequisites
To compile and run this program, you’ll need:
- A C compiler, such as GCC or Clang.
- [cs50 c library](https://cs50.readthedocs.io/libraries/cs50/c/)

### Installation
   ```
   git clone https://github.com/Ranjit-Pokharel/CS50X-Problem-Sets.git
   cd CS50X-Problem-Sets/psets2/readability
   clang -o readability readability.c -lcs50 -lm
   ./readability
   Text: <text to be calculted>
   ```
   output ``Grade of the text``
