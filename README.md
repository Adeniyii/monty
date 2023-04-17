# Montyyy 🐍

The goal of this project is to create an interpreter for Monty ByteCodes files.

The interpreter is written in the `C programming language`, and implements two simple data structures (a stack and a queue) using linked lists.

The opcodes read from the Monty ByteCodes files will be used to execute operations against the stack or the queue.

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```bash
pochita@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
pochita@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account:

```bash
pochita@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
pochita@ubuntu:~/monty$
```

## Usage

1. Compile the program with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

2. Run `monty <file>`. Where `file` is the path to the file containing Monty byte code.

## Opcodes

| Opcode | Usage        | Description                                                             |
| ------ | ------------ | ----------------------------------------------------------------------- |
| push   | `push <int>` | pushes an element to the stack.                                         |
| pall   | `pall`       | prints all the values on the stack, starting from the top of the stack. |
| pint   | `pint`       | prints the value at the top of the stack, followed by a new line.       |
| pop    | `pop`        | pops the value at the top of the stack.                                 |
| swap   | `swap`       | swaps the two top elements of the stack.                                |
| add    | `add`        | adds the two top elements of the stack.                                 |
| sub    | `sub`        | subs the two top elements of the stack.                                 |
| div    | `div`        | divs the top element from the second top element of the stack.          |
| mul    | `mul`        | multiplies the two top elements of the stack.                           |
| nop    | `nop`        | does nothing.                                                           |
