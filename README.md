# ALX - Morocco

# Custom Printf Implementation

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Authors](#authors)

## Description

In the world of C programming, the `printf()` function is a crucial tool for displaying various data types, including characters, strings, floats, integers, octal, and hexadecimal values. This project aims to recreate the fundamental functionality of `printf()`, as assigned by ALX-SE. It provides a custom implementation of this well-known C function.

## Features

- Supports various conversion specifiers, including `%c` for characters and `%s` for strings.
- Handles additional conversion specifiers like `%d` and `%i` for integers.
- Supports `%b` for binary representation, `%r` for reversing a string, and `%R` for ROT13 encoding.
- Properly handles the `%%` specifier to print a literal '%' character.

## Usage

To use this custom `printf()` function, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/FoNiXPr020/printf.git
   ```

2. Compile your code using the following command:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c _printf
   ```
2. Include the "main.h" header file in your source code that uses the _printf() function.
   ```c
   #include "main.h"

    /**
    * main - Entry point
    *
    * Return: Always 0
    */
    int main(void)
    {
        _printf("Let's try to printf a simple sentence.\n");
        return (0);
    }
   ```
## Authors

- [Hala Rhilane](https://github.com/Haalatoon)
- [Mohamed Barhoun](https://www.github.com/FoNiXPr020)
