# TicTacToe in C without stdlib in 4KBs

## How

I only use these syscalls:

 - write(printing to the screen)
 - read(getting input from user)
 - time(for random)

they are defined in the ```start.S``` assembly file

The result is an 4Kb executable

## Install

Globally:

```
sudo make Install
```

Inside ```build/```

```
make build
```

## Use

Global install:

```
tictactoe
```

```build/``` folder

```
./build/tictactoe
```
