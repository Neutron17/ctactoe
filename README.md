# TicTacToe in C without stdlib in 1.75 KBs

## How

I only use these syscalls:

 - write(printing to the screen)
 - read(getting input from user)
 - time(for random)

they are defined in the ```start.S``` assembly file

The result is an 1.75 Kb executable

## Install

Globally:

```
sudo make install
```

Inside ```build/```

```
make build
```

## Use

Global install:

```
ctactoe
```

```build/``` folder

```
./build/ctactoe
```
