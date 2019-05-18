# MONTY

Interpreter for Monty ByteCodes files

## About

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

GCC 4.8.4 (recommended)

### Installing

Clone the repository and compile with GCC:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Usage

```
./monty bytecodes/<FILE>
```

* filename should contain the operators (listed below)
* one operator per line
* spaces and new lines are ignored
* '#' sign represents comments and rest of line is ignored
* examples can be found in [bytecodes](./bytecodes) directory

### Possible Operators

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


### Files and contents
FILE | DESCRIPTION
----|----
[monty.h](./monty.h) | Header file containing structures and prototypes
[main.c](./main.c) | Entry point for program, parses commands and checks with get_op function, exit helper, function to initialize global struct
[op_1.c](./op_1.c) | Contains push, pall, pint, pop, and swap functions
[op_2.c](./op_2.c) | Contains nop, add, sub, mul, and div functions
[op_3.c](./op_3.c) | Contains mod, pchar, pstr, rotl, and rotr functions
[queue.c](./queue.c) | Contains functions to set to queue or stack mode and function to add node at end of list (queue)
[free.c](./free.c) | Function to free a doubly-linked list and free_everything helper function

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Programming language

## Authors

* [Nga La](https://github.com/sungnga)
* [Thomas Graeff](https://github.com/graefft)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Thank you [David Kwan](https://github.com/dwkwan) for the free_everything idea
* Thank you [Van Duy Pham](https://github.com/vdphan), [Tim Assavarat](https://github.com/tassavarat), and everyone else at Holberton who helped us
