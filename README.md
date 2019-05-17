# MONTY

Interpreter for Monty ByteCodes files

## About

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

Clone the repository and compile with GCC
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Usage

```
./monty bytecodes/<FILE>
```

### Possible Arguments

ARGUMENT | DESCRIPTION
----|----
push <int> | Pushes integer to stack
pall | Prints the stack
pint | Prints the top of stack
pop | Removes top element
swap | Swaps top two elements of stack
add | Adds top two elements of stack
nop | Does nothing
sub | Subtracts top element of stack from second top element
div | Divides
mul | Multiplies
mod | Computes rest of division of second top element by top element
pchar | Prints the char at top of stack (converts int to ASCII)
pstr | Prints the string until stack is over or 0
rotl | Rotates stack to top
rotr | Rotates stack to bottom

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Programming language

## Authors

* [Nga La](https://github.com/sungnga)
* [Thomas Graeff](https://github.com/graefft)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Thank you David Kwan for the free_everything idea
* Thanks to Van Duy Pham and everyone else at Holberton who helped us
