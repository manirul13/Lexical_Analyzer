# Lexical Analyzer

A simple lexical analyzer implemented in C for educational purposes. This project demonstrates how to tokenize source code into meaningful units like keywords, identifiers, literals, and operators.

---

## Table of Contents

- [About](#about)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Example Tokens](#example-tokens)
- [Contributing](#contributing)

---

## About

A lexical analyzer (lexer) is a core component of compilers and interpreters. It reads input code and splits it into tokens for further processing by a parser. This project is designed to help understand the basics of lexical analysis in C.

---

## Features

- Recognizes keywords, identifiers, numbers, operators, and delimiters.
- Simple, readable C implementation.
- Can be used as a starting point for building a full compiler.
- Includes a `test.c` file for sample input testing.

---

## Project Structure

Lexical_Analyzer/
├── lexer/
│ ├── lexer.c # Lexer implementation
│ └── lexer.h # Lexer header file
├── main.c # Main program demonstrating lexer usage
├── test.c # Test cases for lexer
└── README.md # This file

yaml
Copy code

---

## Getting Started

### Prerequisites

- GCC or any C compiler
- Linux, macOS, or Windows (with C compiler)

### Build


# Compile the project
gcc main.c lexer/lexer.c -o lexical_analyzer

# Or compile test file
gcc test.c lexer/lexer.c -o lexer_test

# Usage
# Run the main program:
 
./lexical_analyzer input_file.c

# Run the test program:
 
./lexer_test

The lexer will output tokens identified from the input source code.

## Example Tokens
# Given a sample input:
int x = 10;
if (x > 0) x = x + 1;

# The lexer identifies:

* int → Keyword

* x → Identifier

* = → Operator

* 10 → Number

* ; → Delimiter

* if → Keyword

* ( ) → Delimiters

* > → Operator

* + → Operator

# Contributing
1. Fork the repository

2. Create a branch (git checkout -b feature/your-feature)

3. Make your changes

4. Add tests if applicable

5. Commit your changes (git commit -m 'Add feature')

6. Push to the branch (git push origin feature/your-feature)

7. Open a Pull Request

